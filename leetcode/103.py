import collections

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def zz(root: TreeNode):
    if not root: return []
    traversalMap = []
    queue = collections.deque()
    temp = None
    queue.append((1, root))

    while len(queue) > 0:
        temp = queue.pop()
        while len(traversalMap) < temp[0]:
            traversalMap.append([])
        if temp[0] % 2 == 0:
            traversalMap[temp[0] - 1].append(temp[1].val)
        else:
            traversalMap[temp[0] - 1].insert(0, temp[1].val)

        if temp[1].left:
            queue.append((temp[0] + 1, temp[1].left))
        if temp[1].right:
            queue.append((temp[0] + 1, temp[1].right))

    return traversalMap

a = TreeNode(3)
a.left = TreeNode(9)
a.right = TreeNode(20)
a.right.left = TreeNode(15)
a.right.right = TreeNode(7)

r = zz(a)

print(r)
print(zz(None))
