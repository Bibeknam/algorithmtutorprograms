// C implementation of stack using arrays

#include <stdio.h>
#define MAX_SIZE 10

// global variables 
int stack[MAX_SIZE];
int top = -1;

// inserts item at the top of the stack
void push(int item) {
	// check for overflow
	if (top >= MAX_SIZE - 1) {
		printf("%s\n", "Error: Can not push item. Stack Overflow");
		return;
	}

	// insert the item and update the top
	stack[top + 1] = item;
	top = top + 1;
}


// removes item from the top of the stack
int pop() {
	// check for underflow
	if (top <= -1) {
		printf("%s\n", "Error: Can not pop item. Stack Underflow");
		return -999999;
	}

	top = top - 1;
	return stack[top + 1];
}

// returns the item at the top
int peek() {
	// check for underflow
	if (top <= -1) {
		printf("%s\n", "Error: Can not read item. Stack Underflow");
		return - 999999;
	}

	return stack[top];
}

int main() {
	push(12);
	push(45);
	push(33);
	push(35);
	push(39);
	push(53);
	push(30);
	push(98);
	push(34);
	push(78);
	push(3100);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", peek());
	printf("%d\n", peek());
	return 0;
}
