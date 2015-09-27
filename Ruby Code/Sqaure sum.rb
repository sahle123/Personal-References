# Square(n) sum 
# Nov. 19th, 2013

def squareSum(numbers)
  result = 0
  numbers.each do |i|
    result = result + i*i
  end
  return result
end