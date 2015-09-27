# Hash array keys to default value hash
# Nov. 11th, 2013
#
#

def solution(keys, default_value)
  hash = {}
  keys.each do |key|
    hash[key] = default_value
  end
  hash
end