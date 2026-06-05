-- Keep #### headings with following code blocks (including optional intro paragraphs).

local SKIPPABLE = {
  Para = true,
  Plain = true,
  LineBlock = true,
  BulletList = true,
  OrderedList = true,
}

local function followed_by_codeblock(blocks, idx)
  local j = idx + 1
  while j <= #blocks do
    local block = blocks[j]
    if block.t == "Header" and block.level <= 4 then
      return false
    end
    if block.t == "CodeBlock" then
      return true
    end
    if SKIPPABLE[block.t] then
      j = j + 1
    else
      return false
    end
  end
  return false
end

local function process_blocks(blocks)
  local out = {}
  for i, block in ipairs(blocks) do
    if block.t == "Header" and block.level == 4 and followed_by_codeblock(blocks, i) then
      table.insert(out, pandoc.RawBlock("latex", "\\Needspace{28\\baselineskip}"))
    end
    if block.content then
      block.content = process_blocks(block.content)
    end
    table.insert(out, block)
  end
  return out
end

function Pandoc(doc)
  doc.blocks = process_blocks(doc.blocks)
  return doc
end
