def fibs(size)
  fib_array = [0, 1]
  #=> base
  if size == 1
    fib_array.pop()
    return fib_array
  elsif size == 2
    return fib_array
  end

  correct_size = size - 2
  i = 0
  while correct_size > 0
    fib_array.push(fib_array[i] + fib_array[i+1])
    i+=1
    correct_size-=1
  end
  return fib_array
end

puts fibs(8)