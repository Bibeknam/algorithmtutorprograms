// C implementation of stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node *NodePtr;

// globally define tail
NodePtr tail = NULL;

// Push operation
void push(int item) {
	NodePtr node = malloc(sizeof(NodePtr));
	node->data = item;
	node->next = NULL;
	node->prev = NULL;

	if (tail == NULL) {
		tail = node;
	} else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

// pop operation
int pop() {
	int item;
	if (tail == NULL){
		printf("%s\n", "ERROR: Stack is empty");
		return -999999;
	}

	item = tail->data;
	NodePtr prev = tail->prev;
	if (prev != NULL) {
		prev->next = NULL;
	}
	tail->prev = NULL;
	free(tail);
	tail = prev;
	return item;

}

// top (peek) operation
int peek() {
	if (tail == NULL){
		printf("%s\n", "ERROR: Stack is empty");
		return -999999;
	}

	return tail->data;
}

int main() {
	push(33);
	push(22);
	push(44);
	printf("%d\n", pop());
	printf("%d\n", peek());
	return 0;
}