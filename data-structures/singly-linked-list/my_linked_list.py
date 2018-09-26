# Python implementation of Singly linked list 
import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class MyLinkedList:
    def __init__(self):
        self.head = None 

    # Insert 'value' at the front of the list
    def insert_at_front(self, value):
        node = Node(value)
        if self.is_empty():
            self.head = node
        else:
            node.next = self.head
            self.head = node
     
    #  insert value at the back of the linked list
    def insert_at_back(self, value):
        node = Node(value)
        if self.is_empty():
            self.head = node
        else:
            curr = self.head
            while curr.next != None:
                curr = curr.next
            curr.next = node

    # inserts value after key
    def insert_after(self, key, value):
        node = Node(value)

        # find the position of key
        curr = self.head
        while curr != None and curr.data != key:
            curr = curr.next

        if curr == None:
            print 'Key not found'
            return

        if curr.next == None:
            curr.next = node
        else:
            next_node = curr.next
            curr.next = node
            node.next = next_node

    # returns the data at first node 
    def top_front(self):
        if self.is_empty():
            print 'List is empty'
            return

        return self.head.data

    # returns the data at last node 
    def top_back(self): 
        if self.is_empty():
            print 'List is empty'
            return

        curr = self.head
        while curr.next != None:
            curr = curr.next

        return curr.data

    # removes the item at front of the linked list and return 
    def pop_front(self):
        if self.is_empty():
            print 'List is empty'
            return

        next_node = self.head.next
        item = self.head.data
        self.head = next_node
        return item

    # remove the item at the end of the list and return 
    def pop_back(self):
        if self.is_empty():
            print 'List is empty'
            return

        # get to the last node
        curr = self.head
        prev = None

        while curr.next != None:
            prev = curr
            curr = curr.next

        item = curr.data

        if prev == None:
            # the list has only one item
            self.head = None
        else:
            prev.next = None
            curr = None

        return item

    # removes an item with value 'key'
    def remove(self, key):
        if self.is_empty():
            print 'List is empty'
            return

        # find the position of the key
        curr = self.head
        prev = None

        while curr != None and curr.data != key:
            prev = curr
            curr = curr.next

        if curr == None:
            print 'key not found'
            return

        # if curr is head, delete the head
        if prev == None:
            self.head = self.head.next
            curr = None
        elif curr.next == None: # if curr is last item
            prev.next = None
            curr = None
        else: #anywhere between first and last node
            next_node = curr.next
            prev.next = next_node
            curr = None

    # check if the key is in the list
    def find(self, key):
        if self.is_empty():
            print 'List is empty'
            return False

        curr = self.head
        while curr != None and curr.data != key:
            curr = curr.next

        if curr == None:
            return False

        return True

    # check if the list is empty
    def is_empty(self):
        return self.head == None

    # print all the items
    def printlist(self):
        if self.is_empty():
            print "Nothing to display"
        else:
            curr = self.head
            while (curr != None):
                sys.stdout.write(str(curr.data) + ' ')
                curr = curr.next

            print ''
       
if __name__ == '__main__':
    list = MyLinkedList()
    # write code