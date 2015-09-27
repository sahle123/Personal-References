# keyAndValue_kata.rb
#
# Sahle A. Alturaigi
# Nov. 1st, 2013

### My code for keyAndValues kata. ###
def keysAndValues(data)
  dataVals = {}
  dataVals = dataVals.to_a
  dataKeys = {}
  dataKeys = dataKeys.to_a
  result = {}
  result = result.to_a
  
  data.each { |key, value| 
    dataKeys << key
    dataVals << value }
  
  if(dataKeys.size != dataVals.size)
    raise ArgumentError
  end
  
  result[0] = dataKeys
  result[1] = dataVals
  
  return result
end

### Most optimal code ###
def keysAndValues(data)
  [data.keys, data.values]
end

############ Test cases ###############
keys, values = keysAndValues({d: 4, e: 5, f: 6, g: 7})
Test.expect(keys, 'function did not return keys')
Test.expect(values, 'function did not return values')
Test.expect(keys.length == 4, 'function did not return enough keys')
Test.expect(values.length == 4, 'function did not return enough values')
Test.expect(keys[1] == :e, 'function did not return correct keys')
Test.expect(values[2] == 6, 'function did not return correct values')