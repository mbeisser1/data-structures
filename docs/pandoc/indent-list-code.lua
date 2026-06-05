-- Indent fenced code blocks that appear inside bullet or numbered lists.

local function indent_for_depth(depth)
  if depth <= 1 then
    return "2.5em"
  end
  return string.format("%.1fem", 2.5 + (depth - 1) * 1.5)
end

local function wrap_list_code(block, depth)
  local indent = indent_for_depth(depth)
  return {
    pandoc.RawBlock("latex", "{\\leftskip=" .. indent .. "\\relax"),
    block,
    pandoc.RawBlock("latex", "}"),
  }
end

local function process_blocks(blocks, list_depth)
  local out = {}
  for _, block in ipairs(blocks) do
    if block.t == "CodeBlock" and list_depth > 0 then
      local wrapped = wrap_list_code(block, list_depth)
      for _, b in ipairs(wrapped) do
        table.insert(out, b)
      end
    elseif block.t == "BulletList" then
      local items = {}
      for _, item in ipairs(block.content) do
        table.insert(items, process_blocks(item, list_depth + 1))
      end
      block.content = items
      table.insert(out, block)
    elseif block.t == "OrderedList" then
      local items = {}
      for _, item in ipairs(block.content) do
        table.insert(items, process_blocks(item, list_depth + 1))
      end
      block.content = items
      table.insert(out, block)
    elseif block.t == "BlockQuote" then
      block.content = process_blocks(block.content, list_depth)
      table.insert(out, block)
    elseif block.t == "Div" then
      block.content = process_blocks(block.content, list_depth)
      table.insert(out, block)
    else
      table.insert(out, block)
    end
  end
  return out
end

function Pandoc(doc)
  doc.blocks = process_blocks(doc.blocks, 0)
  return doc
end
