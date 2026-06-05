-- Decode data:image/...;base64,... URIs into Pandoc's mediabag for PDF/LaTeX output.
-- GFM reader drops these images otherwise.

local function decode_data_uri(src)
  local mime, data = src:match("^data:([^;]+);base64,(.+)$")
  if not mime or not data then
    return nil
  end
  local decoded = pandoc.pipe("base64", {"-d"}, data)
  if not decoded or #decoded == 0 then
    return nil
  end
  local ext = mime:match("/([^/]+)$") or "bin"
  if ext == "jpeg" then
    ext = "jpg"
  end
  local fname = "embedded-" .. pandoc.utils.sha1(data):sub(1, 10) .. "." .. ext
  pandoc.mediabag.insert(fname, mime, decoded)
  return fname
end

function Image(el)
  if el.src:match("^data:") then
    local fname = decode_data_uri(el.src)
    if fname then
      el.src = fname
      return el
    end
  end
end
