// Queue implementation in C using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node *NodePtr;

// define front and rear globally
NodePtr front = NULL;
NodePtr rear = NULL;

// inserts an item at the rear of the queue
void enqueue(int item) {
	NodePtr node = malloc(sizeof(NodePtr));
	node->data = item;
	node->next = NULL;
	node->prev = NULL;

	// if the queue is empty, make this node front and rear
	// else insert it at the end of the queue
	if (rear == NULL) {
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
	if (front == NULL) {
		printf("%s\n", "ERROR: Queue is empty");
		return -999999;
	}
	
	// destory the front and make the next item new front
	item = front->data;	
	NodePtr next = front->next;

	if (next != NULL) {
		next->prev = NULL;
	} else {
		rear = NULL;
	}

	free(front);
	front = next;
	return item;
}


// returns the item at the front of the queue
int getFront() {
	if (front == NULL) {
		printf("%s\n", "ERROR: Queue is empty");
		return -999999;
	}

	return front->data;
}

int main() {
	enqueue(34);
	enqueue(35);
	enqueue(41);
	enqueue(56);
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	enqueue(70); 
	printf("%d\n", getFront());
	return 0;
}