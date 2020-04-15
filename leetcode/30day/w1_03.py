import sys

def msa(nums):
	mxn = -sys.maxsize
	cur = 0

	for num in nums:
		if (num + cur <= 0):
			cur = 0
			if (mxn < num):
				mxn = num
		else:
			cur = num + cur
			if (mxn < cur):
				mxn = cur

	return mxn
ls1 = [-2, -1, -5]
ls = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
r = msa(ls1)
print(r)
