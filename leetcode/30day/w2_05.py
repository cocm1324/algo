import heapq

class Solution:
	def lsw(self, stones) -> int:
		_1, _2 = 0, 0
		l = stones.copy()
		heapq._heapify_max(l)
		while len(l) > 1:
			_1 = heapq._heappop_max(l)
			_2 = heapq._heappop_max(l)
			if _1 != _2:
				l.append(_1 - _2)
				heapq._heapify_max(l)
		if len(l) == 1:
			return l[0]
		return 0

s = Solution()
l = [2,7,4,1,8,1,13,9,21,22,101]
r = s.lsw(l)
print(r)
