# Merge Sort and Quick Sort

## Intro

Sorting Algorithms are really important to organize data effectively and effieciently. We'll be covering **Merge Sort** and **Quick Sort**!


## Merge Sort
### Basic Steps:

1. Divide the array in half
2. Recursively sort each half
3. Merge the sorted halves

### The Code

```ruby
def merge_sort(array)
  return array if array.length <= 1

  mid = array.length / 2
  left = merge_sort(array[0...mid])
  right = merge_sort(array[mid...array.length])

  merge(left, right)

end

def merge(left, right)
  sorted = []
  until left.empty? || right.empty?
    if left.first <= right.first
      sorted << left.shift
    else
      sorted << right.shift
    end
  end
  sorted + left + right
end
```
### Time Complexity
* Best Case: O(nlogn)
* Worst Case: O(nlogn)
* Space Complexity: O(n)

## Quick Sort

### Steps
1. Choose a pivot element 
2. Partition the array into two halves
    
    * Elements less than or equal to the pivot
    * Elements greater than the pivot
3. Recurisvely apply quick sort to both halves!

### The Code:

```ruby
def quick_sort(array)
  return array if array.length <= 1
  pivot = array.delete_at(rand(array.length))
  left, right = array.partition do |x|
    x<=pivot
  end

  quick_sort(left) + [pivot] + quick_sort(right)
end
```

### Time Complexity

* Best Case: O(n log n)
* Worst Case: O(nˆ2)
* Space Complexity: O(log n)



