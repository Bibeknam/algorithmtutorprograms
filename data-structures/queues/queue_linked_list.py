# Python implementation of queue using linked list

class Node:
	def __init__(self, item):
		self.data = item
		self.prev = None
		self.next = None

class QueueLinkedList:
	def __init__(self):
		self.front = None
		self.rear = None

	# inserts an item at the rear of the queue
	def enqueue(self, item):
		node = Node(item)

		# if the queue is empty, make this node front and rear
		# else insert it at the end of the queue
		if self.rear == None:
			self.rear = node
			self.front = node
		else:
			self.rear.next = node
			node.prev = self.rear
			self.rear = node

	# remove the item at the front of the queue
	def dequeue(self):
		if self.front == None:
			print "ERROR: Queue is empty"
			return -999999
		
		# destory the front and make the next item new front
		item = self.front.data
		next_node = self.front.next

		if next_node != None:
			next_node.prev = None
		else:
			self.rear = None

		self.front = next_node;
		return item

	# returns the item at the front of the queue
	def getFront(self):
		if self.front == None:
			print "ERROR: Queue is empty"
			return -999999

		return self.front.data

if __name__ == "__main__":
	queue = QueueLinkedList()
	queue.enqueue(34)
	queue.enqueue(35)
	queue.enqueue(41)
	queue.enqueue(56)
	print queue.dequeue()
	print queue.dequeue()
	print queue.dequeue()
	print queue.dequeue()
	queue.enqueue(70) 
	print queue.getFront()