# Ruby enumerable method
# Nov 14th, 2013

def check_ages?(data, sex, age_is_older_than)
  data.each do |d|
    if d[:sex] == sex && d[:age] <= age_is_older_than 
      return false
    end
  end
  return true
end