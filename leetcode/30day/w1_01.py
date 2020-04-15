class Solution:
	def singleNumber(self, nums) -> int:
		temp: int = 0
		for el in nums:
			temp ^= el
		return temp
	

li = [4, 1, 2, 1, 2]

s = Solution()

res = s.singleNumber(li)

print(res)

