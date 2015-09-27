# No odds array kata
# Nov. 12, 2013

def no_odds( values )
  array = Array.new
  values.each do |n|
    array << n if n.even?
  end
  array
end