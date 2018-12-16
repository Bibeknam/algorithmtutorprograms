# Binary search tree implementation in Java
# Author: AlgorithmTutor

# data structure that represents a node in the tree

import sys

class Node:
	def  __init__(self, data):
		self.data = data
		self.parent = None
		self.left = None
		self.right = None

class BST:

	def __init__(self):
		self.root = None

	def createSampleTree1(self):
		node50 =  Node(50)
		node30 =  Node(30)
		node70 =  Node(70)

		node30.parent = node50
		node70.parent = node50
		node50.left = node30
		node50.right = node70

		node23 =  Node(23)
		node35 =  Node(35)

		node23.parent = node30
		node35.parent = node30
		node30.left = node23
		node30.right = node35

		node11 =  Node(11)
		node25 =  Node(25)

		node11.parent = node23
		node25.parent = node23
		node23.left = node11
		node23.right = node25

		node31 =  Node(31)
		node42 =  Node(42)

		node31.parent = node35
		node42.parent = node35
		node35.left = node31
		node35.right = node42

		node80 =  Node(80)

		node80.parent = node70
		node70.right = node80

		node73 =  Node(73)
		node85 =  Node(85)

		node73.parent = node80
		node85.parent = node80
		node80.left = node73
		node80.right = node85

		self.root = node50

	def __printHelper(self, currPtr, indent, last):
		# print the tree structure on the screen
	   	if currPtr != None:
			sys.stdout.write(indent)
			if last:
			  	sys.stdout.write("R----")
			  	indent += "     "
			else:
				sys.stdout.write("L----")
				indent += "|    "

			print currPtr.data

			self.__printHelper(currPtr.left, indent, False)
			self.__printHelper(currPtr.right, indent, True)
	
	def __searchTreeHelper(self, node, key):
		if node == None or key == node.data:
			return node

		if key < node.data:
			return self.__searchTreeHelper(node.left, key)
		return self.__searchTreeHelper(node.right, key)

	def __deleteNodeHelper(self, node, key):
		# search the key
		if node == None: 
			return node
		elif key < node.data:
			node.left = self.__deleteNodeHelper(node.left, key)
		elif key > node.data: 
			node.right = self.__deleteNodeHelper(node.right, key)
		else:
			# the key has been found, now delete it

			# case 1: node is a leaf node
			if node.left == None and node.right == None:
				node = None

			# case 2: node has only one child
			elif node.left == None:
				temp = node
				node = node.right

			elif node.right == None:
				temp = node
				node = node.left

			# case 3: has both children
			else:
				temp = minimum(node.right)
				node.data = temp.data
				node.right = self.__deleteNodeHelper(node.right, temp.data)
		return node

	def __preOrderHelper(self, node):
		if node != None:
			sys.stdout.write(node.data + " ")
			self.__preOrderHelper(node.left)
			self.__preOrderHelper(node.right)

	def __inOrderHelper(self, node):
		if node != None:
			self.__inOrderHelper(node.left)
			sys.stdout.write(node.data + " ")
			self.__inOrderHelper(node.right)

	def __postOrderHelper(self, node):
		if node != None:
			self.__postOrderHelper(node.left)
			self.__postOrderHelper(node.right)
			std.out.write(node.data + " ")

	# Pre-Order traversal
	# Node->Left Subtree->Right Subtree
	def preorder(self):
		self.__preOrderHelper(self.root)

	# In-Order traversal
	# Left Subtree -> Node -> Right Subtree
	def __inorder(self):
		self.__inOrderHelper(self.root)

	# Post-Order traversal
	# Left Subtree -> Right Subtree -> Node
	def __postorder(self):
		self.__postOrderHelper(self.root)

	# search the tree for the key k
	# and return the corresponding node
	def searchTree(self, k):
		return self.__searchTreeHelper(self.root, k)

	# find the node with the minimum key
	def minimum(self, node):
		while node.left != None:
			node = node.left
		return node

	# find the node with the maximum key
	def maximum(self, node):
		while node.right != None:
			node = node.right
		return node

	# find the successor of a given node
	def successor(self, x):
		# if the right subtree is not null,
		# the successor is the leftmost node in the
		# right subtree
		if x.right != None:
			return self.minimum(x.right)

		# else it is the lowest ancestor of x whose
		# left child is also an ancestor of x.
		y = x.parent
		while y != None and x == y.right:
			x = y
			y = y.parent
		return y

	# find the predecessor of a given node
	def predecessor(self, x):
		# if the left subtree is not null,
		# the predecessor is the rightmost node in the 
		# left subtree
		if x.left != None:
			return self.maximum(x.left)

		y = x.parent
		while y != None and x == y.left:
			x = y
			y = y.parent
		return y

	# insert the key to the tree in its appropriate position
	def insert(self, key):
		node =  Node(key)
		y = None
		x = self.root

		while x != None:
			y = x
			if node.data < x.data:
				x = x.left
			else:
				x = x.right

		# y is parent of x
		node.parent = y
		if y == None:
			root = node
		elif node.data < y.data:
			y.left = node
		else:
			y.right = node

	# delete the node from the tree
	def deleteNode(self, data):
		return self.__deleteNodeHelper(self.root, data)

	# print the tree structure on the screen
	def prettyPrint(self):
		self.__printHelper(self.root, "", True)

if __name__ == '__main__':
	tree = BST()
	tree.createSampleTree1()
	tree.prettyPrint()