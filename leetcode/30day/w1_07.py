def ce(arr):
	counterSum = 0
	counter = dict()
	setConversion = set(arr)
	for el in arr:
		if (not(el + 1 in counter)):
			counter[el + 1] = 1
		else:
			counter[el + 1] += 1
	for el in setConversion:
		if (el in counter):
			counterSum += counter[el]
	
	return counterSum
		

a = [1,2,3]
b = [1,3,2,3,5,0]
c = [1,1,2,2]
d = [1,1,3,3,5,5,7,7]
e = [100]
print(a, ce(a))
print(b, ce(b))
print(c, ce(c))
print(d, ce(d))
print(e, ce(e))

