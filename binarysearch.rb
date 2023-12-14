def binary_search(arr, target)
    left = 0
    right = arr.length - 1
  
    while left <= right
      mid = left + (right - left) / 2
      if arr[mid] == target
        return mid  
      elsif arr[mid] < target
        left = mid + 1
      else
        right = mid - 1
      end
    end
  
    return -1  
  end
  
  arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
  target = 5
  result = binary_search(arr, target)
  
  if result != -1
    puts "Element #{target} found at index #{result}"
  else
    puts "Element #{target} not found in the array"
  end
  