def quick_sort(array)
  return array if array.length <= 1
  pivot = array.delete_at(rand(array.length))
  left, right = array.partition do |x|
    x<=pivot
  end

  quick_sort(left) + [pivot] + quick_sort(right)
end

array = [34, 7, 23, 32, 5, 62]
puts quick_sort(array)