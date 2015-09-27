# Sort_ArrayHash Kata
# Nov. 5th, 2013

def solution(array, key)
	array.sort_by { |a| a[key] }
end