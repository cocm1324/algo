def searchInsert(nums, target: int) -> int:
    print(binarySearch(nums, 0, len(nums) - 1, target))


def binarySearch(nums, startIndex: int, endIndex: int, target: int):
    median = int((startIndex + endIndex) / 2)

    print('------------------------------')
    print(startIndex, endIndex, median)

    if (nums[median] == target):
        return median
    elif (nums[median] < target):
        if (len(nums[median + 1: endIndex + 1]) == 1):
            if (nums[endIndex] < target):
                return endIndex + 1
            else:
                return endIndex
        elif (len(nums[median + 1: endIndex + 1]) == 0):
            return median + 1
        else:
            return binarySearch(nums, median + 1, endIndex, target)
    else:
        if (len(nums[startIndex: median]) == 1):
            if (nums[startIndex] < target):
                return startIndex + 1
            else:
                return startIndex
        elif (len(nums[startIndex: median]) == 0):
            return median
        else:
            return binarySearch(nums, startIndex, median, target)

searchInsert([1], 2)
