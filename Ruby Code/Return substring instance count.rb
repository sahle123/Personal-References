# Return substring instance count
# Nov. 17th, 2013

def solution(full_text, search_text)
	return full_text.scan(search_text).count
end