class Solution:
    def numIslands(self, grid) -> int:
        count = 0
        self.height, self.width = len(grid), len(grid[0])
        self.grid = []
        for s in grid:
            self.grid += s
        self.visited = [False] * (self.width * self.height)
        

        for i in range(self.width * self.height):
            if self.grid[i] == '1' and not self.visited[i]:
                self.bfs(i)
                count += 1
        return count
        
    def bfs(self, pos):
        self.visited[pos] = True
        if pos - self.width >= 0:
            if not self.visited[pos - self.width] and self.grid[pos - self.width] == '1':
                self.bfs(pos - self.width)
        if pos + self.width < self.width * self.height:
            if not self.visited[pos + self.width] and self.grid[pos + self.width] == '1':
                self.bfs(pos + self.width)
        if pos % self.width != 0:
            if not self.visited[pos - 1] and self.grid[pos - 1] == '1':
                self.bfs(pos - 1)
        if pos % self.width != self.width - 1:
            if not self.visited[pos + 1] and self.grid[pos + 1] == '1':
                self.bfs(pos + 1) 

s = Solution()
a = [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
r = s.numIslands(a)
print(r)
