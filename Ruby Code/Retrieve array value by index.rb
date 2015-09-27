# Retrieve array value by index with default
# Nov. 14th, 2013


def solution(items, index, default_value)
    
  size = items.size()
  
  if index.abs > size
    return default_value
  else
    return items[index]
  
  end
end