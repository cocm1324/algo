import collections

class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution:
	def diameterOfBinaryTree(self, root: TreeNode):	
		self.answer = 0
		if not root: return 0
		def height(node: TreeNode):
			lh, rh = 0, 0
			if node.left:
				lh = height(node.left) + 1
			if node.right:
				rh = height(node.right) + 1
			self.answer = max(self.answer, lh + rh)
			return max(lh, rh)

		height(root)
		return self.answer


a = TreeNode(1)
a.left = TreeNode(2)
a.right = TreeNode(3)
a.left.left = TreeNode(4)
a.left.right = TreeNode(5)
#a.right.right = TreeNode(7)
b = Solution()
r = b.diameterOfBinaryTree(a)
print(r)
r = b.diameterOfBinaryTree(None)
print(r)
