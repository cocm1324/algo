import collections

def mps(grid):
    xLen, yLen = len(grid[0]), len(grid)
    dist = [float('inf')] * (xLen * yLen)
    dist[0] = grid[0][0]
    grey = collections.deque()
    grey.append((0, 0))
    
    while len(grey) > 0:
        x,  y = grey.pop()
        if x + 1 < xLen:
            dist[y * xLen + x + 1] = min(dist[y *xLen + x + 1], dist[y*xLen + x] + grid[y][x + 1])
            grey.append((x + 1, y))
        if y + 1 < yLen:
            dist[(y + 1) * xLen + x] = min(dist[(y + 1) * xLen + x], dist[y * xLen + x] + grid[y + 1][x])
            grey.append((x, y + 1))

    return dist[xLen * yLen - 1]

l = [[1,3,1],[1,5,1],[4,2,1]]
r = mps(l)
print(r)
