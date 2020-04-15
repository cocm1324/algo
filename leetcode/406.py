import copy

def rq(people):
	cp = copy.deepcopy(people)
	cp.sort(key = sortKey, reverse = True)
	reconstructedPart = 1
	
	while reconstructedPart < len(cp):
		if (cp[reconstructedPart][1] == 0):
			cp.insert(0, cp[reconstructedPart])
			cp.pop(reconstructedPart + 1)
			reconstructedPart += 1
		else:
			count = 0
			for i in range(reconstructedPart):
				if (cp[i][0] >= cp[reconstructedPart][0]):
					count += 1
				if (count == cp[reconstructedPart][1]):
					if (i + 1 != reconstructedPart):
						cp.insert(i + 1, cp[reconstructedPart])
						cp.pop(reconstructedPart + 1)
						break
			reconstructedPart += 1
		print(cp)

	return cp


def sortKey(el):
	return el[0] + 1 - el[1] / (el[1] + 1)

a = [[9,0],[7,0],[1,9],[3,0],[2,7],[5,3],[6,0],[3,4],[6,2],[5,2]]

r = rq(a)
print(r)
