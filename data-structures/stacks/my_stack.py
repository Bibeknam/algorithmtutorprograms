# Python implementation of stack using linked list

class Node:
	def __init__(self, item):
		self.data = item
		self.prev = None
		self.next = None

class MyStack:
	def __init__(self):
		self.tail = None

	def push(self, item):
		node = Node(item)

		if self.tail == None:
			self.tail = node
		else:
			node.prev = self.tail
			self.tail.next = node
			self.tail = node

	def pop(self):
		if self.tail == None:
			print "ERROR: Stack is empty"
			return

		item = self.tail.data
		prev = self.tail.prev
		if prev != None:
			prev.next = None
		self.tail.prev = None
		self.tail = prev
		return item

	def peek(self):
		if self.tail == None:
			print "ERROR: Stack is empty"
			return
		return self.tail.data

if __name__ == '__main__':
	stack = MyStack()
	stack.push(44)
	stack.push(34)
	stack.push(22)
	print stack.pop()
	print stack.pop()
	print stack.peek()