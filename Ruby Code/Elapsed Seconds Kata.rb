Elapsed Seconds Kata

def elapsed_seconds(start_time, end_time)
  start_time = start_time.to_f
  end_time = end_time.to_f
  if(end_time < start_time)
    raise ArgumentError
  else
    result = end_time - start_time
  end
  return result
end