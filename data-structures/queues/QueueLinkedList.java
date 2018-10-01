// Java implementation of Queue using linked list

class Node {
	int data;
	Node prev;
	Node next;

	public Node(int item) {
		data = item;
		prev = null;
		next = null;
	}
}

public class QueueLinkedList {
	private Node front;
	private Node rear;

	public QueueLinkedList() {
		front = null;
		rear = null;
	}

	// inserts an item at the rear of the queue
	public void enqueue(int item) {
		Node node = new Node(item);

		// if the queue is empty, make this node front and rear
		// else insert it at the end of the queue
		if (rear == null) {
			rear = node;
			front = node;
		} else {
			rear.next = node;
			node.prev = rear;
			rear = node; 
		}
	}

	// remove the item at the front of the queue
	public int dequeue() {
		int item;
		if (front == null) {
			System.out.println("ERROR: Queue is empty");
			return -999999;
		}
		
		// destory the front and make the next item new front
		item = front.data;	
		Node next = front.next;

		if (next != null) {
			next.prev = null;
		} else {
			rear = null;
		}

		front = next;
		return item;
	}

	// returns the item at the front of the queue
	public int getFront() {
		if (front == null) {
			System.out.println("ERROR: Queue is empty");
			return -999999;
		}

		return front.data;
	}

	public static void main(String [] args) {
		QueueLinkedList queue = new QueueLinkedList();
		queue.enqueue(34);
		queue.enqueue(35);
		queue.enqueue(41);
		queue.enqueue(56);
		System.out.println(queue.dequeue());
		System.out.println(queue.dequeue());
		System.out.println(queue.dequeue());
		System.out.println(queue.dequeue());
		queue.enqueue(70); 
		System.out.println(queue.getFront());
	}

}