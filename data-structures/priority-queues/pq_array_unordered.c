// Priority queue implementation an unordered array
#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int n = 0;

// insert an item at the rear of the queue
void enqueue(int item) {
	// Check if the queue is full
	if (n == MAX_SIZE - 1) {
		printf("%s\n", "ERROR: Queue is full");
		return;
	}
	queue[n++] = item;
}

// removes the item with the maximum priority
// search the maximum item in the array and replace it with 
// the last item
int dequeue() {
    int item;
	// Check if the queue is empty
	if (n == 0) {
		printf("%s\n", "ERROR: Queue is empty");
		return -999999;
	}
	int i, max = 0;
	// find the maximum priority
	for (i = 1; i < n; i++) {
		if (queue[max] < queue[i]) {
			max = i;
		}
	}
	item = queue[max];

	// replace the max with the last element
	queue[max] = queue[n - 1];
	n = n - 1;
	return item;
}

int main() {
	enqueue(12);
	enqueue(33);
	enqueue(45);
	enqueue(9);
	enqueue(26);
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	return 0;
}