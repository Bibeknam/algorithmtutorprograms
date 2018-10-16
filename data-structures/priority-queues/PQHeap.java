// Java implementation of a max priority queue

class PQHeap {
	private static final int MAX_SIZE = 15;
	private int [] heap;
	private int size;

	public PQHeap() {
		heap = new int[MAX_SIZE];
		size = 0;
	}

	// returns the index of the parent node
	public static int parent(int i) {
		return (i - 1) / 2;
	}

	// return the index of the left child 
	public static int leftChild(int i) {
		return 2*i + 1;
	}

	// return the index of the right child 
	public static int rightChild(int i) {
		return 2*i + 2;
	}

	// insert the item at the appropriate position
	public void enqueue(int data) {
		if (size >= MAX_SIZE) {
			System.out.println("The queue is full. Cannot insert");
			return;
		}

		// first insert the time at the last position of the array 
		// and move it up
		heap[size] = data;
		size = size + 1;


		// move up until the heap property satisfies
		int i = size - 1;
		while (i != 0 && heap[PQHeap.parent(i)] < heap[i]) {
			int temp = heap[i];
			heap[i] = heap[parent(i)];
			heap[parent(i)] = temp;
			i = PQHeap.parent(i);
		}
	}

	// moves the item at position i of array a
	// into its appropriate position
	public void maxHeapify(int i){
		// find left child node
		int left = PQHeap.leftChild(i);

		// find right child node
		int right = PQHeap.rightChild(i);

		// find the largest among 3 nodes
		int largest = i;

		// check if the left node is larger than the current node
		if (left <= size && heap[left] > heap[largest]) {
			largest = left;
		}

		// check if the right node is larger than the current node 
		// and left node
		if (right <= size && heap[right] > heap[largest]) {
			largest = right;
		}

		// swap the largest node with the current node 
		// and repeat this process until the current node is larger than 
		// the right and the left node
		if (largest != i) {
			int temp = heap[i];
			heap[i] = heap[largest];
			heap[largest] = temp;
			maxHeapify(largest);
		}

	}

	// returns the  maximum item of the heap
	public int peek() {
		return heap[0];
	}

	// deletes the max item and return
	public int dequeue() {
		int maxItem = heap[0];

		// replace the first item with the last item
		heap[0] = heap[size - 1];
		size = size - 1;

		// maintain the heap property by heapifying the 
		// first item
		maxHeapify(0);
		return maxItem;
	}

	// prints the queue
	public void printQueue() {
		for (int i = 0; i < size; i++) {
			System.out.print(heap[i] + " ");
		}
		System.out.println();
	}

	public static void main(String [] args) {
		PQHeap queue = new PQHeap();
		queue.enqueue(43);
		queue.enqueue(333);
		queue.enqueue(345);
		queue.enqueue(45);
		queue.enqueue(3);
		queue.enqueue(400);
		System.out.println(queue.dequeue());
		System.out.println(queue.dequeue());
	}
}