def bubble_sort(array)
  n = array.length

  (n-1).times do 
    (0...(n-1)).each do |i|
      if array[i] > array[i+1]
        array[i], array[i+1] = array[i+1], array[i]
      end
    end
  end
  array
end

puts bubble_sort([5, 3, 51, 53, 643])