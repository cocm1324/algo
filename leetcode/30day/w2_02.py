def bsc(S,T):
	bs = 0
	t = 0
	for i in reversed(S):
		if (i == '#'):
			bs += 1
		else:
			if (bs > 0):
				bs -= 1
			else:
				t += hash(i)
	bs = 0
	for i in reversed(T):
		if (i == '#'):
			bs += 1
		else:
			if (bs > 0):
				bs -= 1
			else:
				t -= hash(i)
	return t == 0

s='a#cc'
t='c#b#c'

print(bsc(s,t))
