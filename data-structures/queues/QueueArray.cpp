// C++ implementation of queue using array

#include <iostream>
using namespace std;

class QueueArray {
private:
	const static int MAX_SIZE = 10;
	int queue[MAX_SIZE];
	int rear;
	int front;
public:
	QueueArray() {
		rear = front = -1;
	}

	// insert an item at the rear of the queue
	void enqueue(int item) {
		// Check if the queue is full
		if ((rear + 1) % MAX_SIZE == front) {
			cout<<"ERROR: Queue is full"<<endl;
			return;
		}

		// if there are no items, make front and rear 1
		// else increment the rear by 1
		if (front == -1 && rear == -1) {
			front = rear = 0;
		} else {
			rear = (rear + 1) % MAX_SIZE;
		}

		// insert the time at rear
		queue[rear] = item;
	}

	// removes the item from the front of the queue
	int dequeue() {
	    int item;
		// Check if the queue is empty
		if (rear == -1 && front == -1) {
			cout<<"ERROR: Queue is empty"<<endl;
			return -999999;
		}
		item = queue[front];
		
		if (front == rear) {
		    front = rear = -1;
		} else {
	    	// increase the front
	    	front = (front + 1) % MAX_SIZE;
		}
		return item;

	}

	// returns the item from the front of the queue
	int getFront() {
		// Check if the queue is empty
		if (rear == -1 && front == -1) {
			cout<<"ERROR: Queue is empty"<<endl;
			return -999999;
		}

		return queue[front];
	}	
};

int main() {
	QueueArray queue;
	queue.enqueue(34);
	queue.enqueue(35);
	queue.enqueue(41);
	queue.enqueue(56);
	printf("%d\n", queue.dequeue());
	printf("%d\n", queue.dequeue());
	queue.enqueue(62);
	queue.enqueue(63);
	queue.enqueue(64);
	queue.enqueue(65);
	queue.enqueue(66);
	queue.enqueue(67);
	queue.enqueue(68); 
	queue.enqueue(69); 
	printf("%d\n", queue.dequeue());
	queue.enqueue(70); 
	return 0;
}