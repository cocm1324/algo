import math

class Solution:
	def findComplement(self, num: int) -> int:
		if(num == 0):
			return 1
		elif(num == 1):
			return 0

		b = math.floor(math.pow(2,math.floor(math.log(num,2)+1))) - 1
		return num ^ b
a = 2
s = Solution()
r = s.findComplement(a)
print(r)

print(math.ceil(2.0))
