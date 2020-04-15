def um(matrix):
	limit = 30000
	x_len = len(matrix[0])
	y_len = len(matrix)

	adjacent = []	
	q = []

	for y in range(y_len):
		adjacent.append([])
		for x in range(x_len):
			if matrix[y][x] == 0:
				adjacent[y].append(0)
			else:
				adjacent[y].append(limit)
				q.append([y, x])

	while len(q) > 0:
		target = q.pop()
		dist = adjacent[target[0]][target[1]]
		if (target[0] != 0):
			dist = min(adjacent[target[0] - 1][target[1]], dist)
		if (target[1] != 0): 
			dist = min(adjacent[target[0]][target[1] - 1], dist)
		if (target[0] != y_len - 1): 
			dist = min(adjacent[target[0] + 1][target[1]], dist)
		if (target[1] != x_len - 1): 
			dist = min(adjacent[target[0]][target[1] + 1], dist)
		if (dist == limit):
			q.append(target)
		else:
			adjacent[target[0]][target[1]] = dist + 1

	return adjacent

i = [[1,0,1,1,0,0,1,0,0,1],[0,1,1,0,1,0,1,0,1,1],[0,0,1,0,1,0,0,1,0,0],[1,0,1,0,1,1,1,1,1,1],[0,1,0,1,1,0,0,0,0,1],[0,0,1,0,1,1,1,0,1,0],[0,1,0,1,0,1,0,0,1,1],[1,0,0,0,1,1,1,1,0,1],[1,1,1,1,1,1,1,0,1,0],[1,1,1,1,0,1,0,0,1,1]]
r = um(i)
for el in r:
	print(el)
