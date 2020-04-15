def fmx(nums):
	sums = {0: [-1, -1]}
	currentSums = 0

	for i in range(len(nums)):
		if nums[i] == 0:
			currentSums -= 1
		else:
			currentSums += 1
		if currentSums in sums:
			sums[currentSums][1] = i
		else:
			sums[currentSums] = [i, i]
	
	return max(list(map(lambda x: x[1] - x[0], sums.values())))

l = [0,1,0,1,1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0]
r = fmx(l)
print(r)
