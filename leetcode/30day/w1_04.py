import math

def moveZeroes(nums):
	count = 0
	nums.append(float('nan'))
	while True:
		if (nums[count] != nums[count]):
			nums.pop(count)
			break
		if (nums[count] == 0):
			nums.pop(count)
			nums.append(0)
		else:
			count += 1
	


i = [0,0,1,0,3,12]

print(i)
moveZeroes(i)
print(i)
