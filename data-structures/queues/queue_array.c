// Circular queue implementation in C using array

#include <stdio.h>
#define MAX_SIZE 10
int front = -1;
int rear = -1;

int queue[MAX_SIZE];

// insert an item at the rear of the queue
void enqueue(int item) {
	// Check if the queue is full
	if ((rear + 1) % MAX_SIZE == front) {
		printf("%s\n", "ERROR: Queue is full");
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
		printf("%s\n", "ERROR: Queue is empty");
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
		printf("%s\n", "ERROR: Queue is empty");
		return -999999;
	}

	return queue[front];
}

int main() {
	enqueue(34);
	enqueue(35);
	enqueue(41);
	enqueue(56);
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	enqueue(62);
	enqueue(63);
	enqueue(64);
	enqueue(65);
	enqueue(66);
	enqueue(67);
	enqueue(68); 
	enqueue(69); 
	printf("%d\n", dequeue());
	enqueue(70); 
	return 0;
}