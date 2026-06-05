-- Indent fenced code blocks inside bullet/numbered lists, including "loose"
-- blocks that follow a list item but sit outside the list in the AST (common GFM).

local function indent_for_depth(depth)
  if depth <= 1 then
    return "2.5em"
  end
  return string.format("%.1fem", 2.5 + (depth - 1) * 1.5)
end

local function wrap_list_code(block, depth, embedded)
  if embedded then
    -- Inside \item after merge: LaTeX list indent is enough; extra margin doubles it
    return { block }
  end
  local indent = indent_for_depth(depth)
  -- Loose code outside enumerate: mdframed needs leftmargin to align with list text
  return {
    pandoc.RawBlock("latex", "\\begingroup\\mdfsetup{leftmargin=" .. indent .. ",rightmargin=0pt}"),
    block,
    pandoc.RawBlock("latex", "\\endgroup"),
  }
end

local function clears_loose_list_code(block)
  return block.t == "Header"
    or block.t == "HorizontalRule"
    or block.t == "Table"
    or block.t == "Figure"
    or block.t == "Para"
end

-- GFM often emits list → code → list; merge into one list with code inside items
local function merge_loose_list_code(blocks)
  local out = {}
  local i = 1
  while i <= #blocks do
    local block = blocks[i]
    if block.t == "OrderedList" or block.t == "BulletList" then
      local list_type = block.t
      local merged_items = {}
      for _, item in ipairs(block.content) do
        table.insert(merged_items, item)
      end
      i = i + 1
      while i <= #blocks do
        local next_block = blocks[i]
        if next_block.t == "CodeBlock" then
          local last_item = merged_items[#merged_items]
          table.insert(last_item, next_block)
          i = i + 1
        elseif next_block.t == list_type then
          for _, item in ipairs(next_block.content) do
            table.insert(merged_items, item)
          end
          i = i + 1
        else
          break
        end
      end
      block.content = merged_items
      table.insert(out, block)
    else
      table.insert(out, block)
      i = i + 1
    end
  end
  return out
end

local function process_blocks(blocks, list_depth)
  local out = {}
  local pending_list_indent = 0

  for _, block in ipairs(blocks) do
    if block.t == "CodeBlock" then
      local embedded = list_depth > 0
      local depth = embedded and list_depth or pending_list_indent
      if depth > 0 then
        local wrapped = wrap_list_code(block, depth, embedded)
        for _, b in ipairs(wrapped) do
          table.insert(out, b)
        end
      else
        table.insert(out, block)
      end
    elseif block.t == "BulletList" then
      local items = {}
      for _, item in ipairs(block.content) do
        table.insert(items, process_blocks(item, list_depth + 1))
      end
      block.content = items
      table.insert(out, block)
      pending_list_indent = list_depth + 1
    elseif block.t == "OrderedList" then
      local items = {}
      for _, item in ipairs(block.content) do
        table.insert(items, process_blocks(item, list_depth + 1))
      end
      block.content = items
      table.insert(out, block)
      pending_list_indent = list_depth + 1
    elseif block.t == "BlockQuote" then
      block.content = process_blocks(block.content, list_depth)
      table.insert(out, block)
    elseif block.t == "Div" then
      block.content = process_blocks(block.content, list_depth)
      table.insert(out, block)
    else
      table.insert(out, block)
      if clears_loose_list_code(block) then
        pending_list_indent = 0
      end
    end
  end
  return out
end

function Pandoc(doc)
  doc.blocks = merge_loose_list_code(doc.blocks)
  doc.blocks = process_blocks(doc.blocks, 0)
  return doc
end
