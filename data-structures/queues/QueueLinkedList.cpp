// C++ implementation of Queue using linked list

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
};

typedef Node *NodePtr;

class QueueLinkedList {
private:
	NodePtr front;
	NodePtr rear;
public:
	QueueLinkedList() {
		front = nullptr;
		rear = nullptr;
	}

	// inserts an item at the rear of the queue
	void enqueue(int item) {
		NodePtr node = new Node;
		node->data = item;
		node->next = nullptr;
		node->prev = nullptr;

		// if the queue is empty, make this node front and rear
		// else insert it at the end of the queue
		if (rear == nullptr) {
			rear = node;
			front = node;
		} else {
			rear->next = node;
			node->prev = rear;
			rear = node; 
		}
	}

	// remove the item at the front of the queue
	int dequeue() {
		int item;
		if (front == nullptr) {
			cout<<"ERROR: Queue is empty"<<endl;
			return -999999;
		}
		
		// destory the front and make the next item new front
		item = front->data;	
		NodePtr next = front->next;

		if (next != nullptr) {
			next->prev = nullptr;
		} else {
			rear = nullptr;
		}

		delete front;
		front = next;
		return item;
	}

	// returns the item at the front of the queue
	int getFront() {
		if (front == nullptr) {
			cout<<"ERROR: Queue is empty"<<endl;
			return -999999;
		}

		return front->data;
	}
};

int main() {
	QueueLinkedList queue;
	queue.enqueue(34);
	queue.enqueue(35);
	queue.enqueue(41);
	queue.enqueue(56);
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
	cout<<queue.dequeue()<<endl;
	queue.enqueue(70); 
	cout<<queue.getFront()<<endl;
	return 0;
}