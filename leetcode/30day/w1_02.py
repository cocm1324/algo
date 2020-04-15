import math

def ih(n):
	counter = 0;
	isHappy = False
	inGray = False
	gray = set()
	cur = n
	nxt = 0
	while counter < 100:
		nxt = nextNum(cur)
		if (sameHash(1, nxt)):
			isHappy = True
			break
		for el in gray:
			if (sameHash(el, nxt)):
				inGray = True
				break
		if (inGray):
			break
		gray.add(nxt)
		print(gray)
		cur = nxt
		counter += 1
	return isHappy

def nextNum(n):
	s = 0
	l = numToRadixList(n)
	for e in l:
		s += int(math.pow(e, 2))
	return s

def sameHash(a, b):
	la = numToRadixList(a)
	lb = numToRadixList(b)
	
	if (len(la) == len(lb)):
		for i in range(len(la)):
			if(la[i] != lb[i]):
				return False
		return True
	return False

def numToRadixList(a):
	l = []
	d = a
	while d != 0:
		l.append(d % 10)
		d = int(d / 10)
	l.sort()
	return l

i = 78
r = ih(i)
print(r)
