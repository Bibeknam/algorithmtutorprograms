// Java implementation of stack using linked list

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

public class MyStackLinkedList {
	private Node tail;

	public MyStackLinkedList() {
		tail = null;
	}

	public void push(int item) {
		Node node = new Node(item);

		if (tail == null) {
			tail = node; 
		} else {
			node.prev = tail;
			tail.next = node;
			tail = node;
		}
	}

	public int pop() {
		if (tail == null) {
			System.out.println("ERROR: Stack is empty");
			return -999999;
		}
		int item = tail.data;
		Node prev = tail.prev;
		if (prev != null) {
			prev.next = null;
		}

		tail.prev = null;
		tail = prev;
		return item;
	} 

	public int peek() {
		if (tail == null) {
			System.out.println("ERROR: Stack is empty");
			return -999999;
		}

		return tail.data;
	}

	public static void main(String [] args) {
		MyStackLinkedList stack = new MyStackLinkedList();
		stack.push(45);
		stack.push(66);
		System.out.println(stack.pop());
		System.out.println(stack.peek());
		System.out.println(stack.pop());
		System.out.println(stack.pop());
	}
}
