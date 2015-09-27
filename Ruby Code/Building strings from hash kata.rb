# Building Strings from a hash kata
# Nov. 8th, 2013

def solution(pairs)
  result = ""
  pairs.each do |key, value|
    result = result + "#{key} = #{value},"
  end
  return result.chop()
end

# Another, more concise solution
def solution2(pairs)
  # TODO: complete
  pairs.map{|k,v| "#{k} = #{v}"}.join(',')
end