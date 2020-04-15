import math

def ds(n, rollMax):
	limit = int(math.pow(10, 9)) + 7

	case = int(math.pow(6, n)) % limit

	dict = {}
	
	for i in rollMax:
		if(i in dict):
			case -= dict[i] % limit
		else:
			dict[i] = calc(n, i)
			case -= dict[i] % limit
	return case;

def calc(n, i):
	sum = 0;
	for i in range(n - i):
		sum += math.pow(6, i)
	return int(sum)

n = 2
rm = [1,1,1,1,1,1]

print(ds(n, rm))
