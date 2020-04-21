def gsl(buildings):
	el1, el2 = None, None
	points = []
	b = sorted(buildings, key = lambda x: x[0])
	while len(b) > 1:
		el1 = b.pop(0)
		el2 = b.pop(0)

		if el1[2] < el2[2]:
			if el1[0] == el2[0]:
				if el1[1] <= el2[1]:
					b.insert(0, el2)
				else:
					b.append([el2[1], el1[1], el1[2]])
					b.insert(0, el2)
					b.sort(key = lambda x: x[0])
			elif el1[0] < el2[0] and el2[0] < el1[1]:
				if el1[1] <= el2[1]:
					points.append([el1[0], el1[2]])
					b.insert(0, el2)
				else:
					points.append([el1[0], el1[2]])
					b.append([el2[1], el1[1], el1[2]])
					b.insert(0, el2)
					b.sort(key = lambda x: x[0])
			elif el1[1] == el2[0]:
				points.append([el1[0], el1[2]])
				b.insert(0, el2)
			else:
				points.append([el1[0], el1[2]])
				points.append([el1[1], 0])
				b.insert(0, el2)
		elif el1[2] > el2[2]:
			if el1[1] == el2[0]:
				points.append([el1[0], el1[2]])
				b.insert(0, el2)
			elif el1[1] < el2[0]:
				points.append([el1[0], el1[2]])
				points.append([el1[1], 0])
				b.insert(0, el2)
			else:
				if el2[1] <= el1[1]:
					b.insert(0, el1)
				else:
					b.append([el1[1], el2[1], el2[2]])
					b.insert(0, el1)
					b.sort(key = lambda x: x[0])
		else:
			if el1[1] < el2[1]:
				b.insert(0, [el1[0], el2[1], el1[2]])
			else:
				b.insert(0, [el1[0], el1[1], el1[2]])
	points.append([b[0][0], b[0][2]])
	points.append([b[0][1], 0])

	return points

b = [ [2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 10], [19, 24, 8], [24, 26, 10] ]
r = gsl(b)
print(r)
