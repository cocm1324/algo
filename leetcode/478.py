import random, math, datetime

class Solution:
	def __init__(self, radius: float, x_center: float, y_center: float):
		random.seed(datetime.datetime.now())
		self.r, self.x, self.y = radius, x_center, y_center

	def randPoint(self):
		angle = random.random() * math.pi * 2
		return [self.r * math.cos(angle) + self.x, self.r * math.sin(angle) + self.y]

s = Solution(10,5,-7.5)
print(s.randPoint())
print(s.randPoint())
print(s.randPoint())
