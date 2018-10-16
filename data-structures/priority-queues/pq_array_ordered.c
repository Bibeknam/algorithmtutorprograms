// Priority queue implementation an ordered array
#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int n = 0;

// insert an item at the appropriate position of the
// queue so that the queue is always ordered
void enqueue(int item) {
	// Check if the queue is full
	if (n == MAX_SIZE - 1) {
		printf("%s\n", "ERROR: Queue is full");
		return;
	}
	
	int i = n-1;
    while (i >= 0 && item < queue[i]) {
        queue[i+1] = queue[i];
        i--;
    }
    queue[i+1] = item;
    n++;
}

// remove the last element in the queue
int dequeue() {
    int item;
	// Check if the queue is empty
	if (n == 0) {
		printf("%s\n", "ERROR: Queue is empty");
		return -999999;
	}
	item = queue[n - 1];
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