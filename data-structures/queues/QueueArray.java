// Java implementation of Queue using array

public class QueueArray {
	private static final int MAX_SIZE = 10;
	private int[] queue;
	private int front; 
	private int rear; 
	
	public QueueArray() {
	    queue = new int[MAX_SIZE];
		front = -1;
		rear = -1;
	}

	// insert an item at the rear of the queue
	public void enqueue(int item) {
		// Check if the queue is full
		if ((rear + 1) % MAX_SIZE == front) {
			System.out.println("ERROR: Queue is full");
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
	public int dequeue() {
	    int item;
		// Check if the queue is empty
		if (rear == -1 && front == -1) {
			System.out.println("ERROR: Queue is empty");
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
	public int getFront() {
		// Check if the queue is empty
		if (rear == -1 && front == -1) {
			System.out.println("ERROR: Queue is empty");
			return -999999;
		}

		return queue[front];
	}

	public static void main(String [] args) {
		QueueArray queue = new QueueArray();
		queue.enqueue(34);
		queue.enqueue(35);
		queue.enqueue(41);
		queue.enqueue(56);
		System.out.println(queue.dequeue());
		System.out.println(queue.dequeue());
		queue.enqueue(62);
		queue.enqueue(63);
		queue.enqueue(64);
		queue.enqueue(65);
		queue.enqueue(66);
		queue.enqueue(67);
		queue.enqueue(68); 
		queue.enqueue(69); 
		System.out.println(queue.dequeue());
		queue.enqueue(70);
	}
}