class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

def zz(root: TreeNode):
	
	return None

def bfs(root: TreeNode):


a = TreeNode(3)
a.left = TreeNode(9)
a.right = TreeNode(20)
a.right.left = TreeNode(9)
a.right.right = TreeNode(20)

r = zz(a)

print(r)
