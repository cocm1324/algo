class MinStack:
	
	def __init__(self):
		self.min = float('inf')
		self.data = []

	def push(self, x):
		self.data.append(x)
		if self.min > x:
			self.min = x

	def pop(self):
		if len(self.data) > 0:
			if self.data.pop() == self.min:
				if len(self.data) > 0:
					self.min = min(self.data)
				else:
					self.min = float('inf')

	def top(self):
		if len(self.data) > 0:
			return self.data[-1]
		else:
			return

	def getMin(self):
		if len(self.data) > 0:
			return self.min
		else:
			return


o = MinStack()
o.push(-2)
o.push(0)
o.push(-3)
print(o.getMin())
o.pop()
print(o.top())
print(o.getMin())
