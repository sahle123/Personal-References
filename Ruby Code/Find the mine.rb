# Find the mine kata
# Nov. 28th, 2013

# Solution 1
def mineLocation field
  i = 0
  j = 0
  for i in (0 .. field.size-1)
    for j in (0 .. field.size-1)
      if field[i][j] == 1
        return [i, j]
      end
    end
  end
end

# Solution 2 (preferred)
def mineLocation(field)
  index = field.flatten.index(1)
  [index / field.length, index % field.length]
end