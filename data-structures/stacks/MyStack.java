// Java implementation of Stack using array

public class MyStack {
	private static final int MAX_SIZE = 10;
	private int[] stack;
	private int top;
	
	public MyStack() {
	    stack = new int[MAX_SIZE];
		top = -1;
	}

	// inserts item at the top of the stack
	public void push(int item) {
		// check for overflow
		if (top >= MAX_SIZE - 1) {
			System.out.println("Error: Can not push item. Stack Overflow");
			return;
		}

		// insert the item and update the top
		stack[top + 1] = item;
		top = top + 1;
	}

	// removes item from the top of the stack
	public int pop() {
		// check for underflow
		if (top <= -1) {
			System.out.println("Error: Can not pop item. Stack Underflow");
			return -999999;
		}

		top = top - 1;
		return stack[top + 1];
	}

	// returns the item at the top
	public int peek() {
		// check for underflow
		if (top <= -1) {
			System.out.println("Error: Can not read item. Stack Underflow");
			return - 999999;
		}

		return stack[top];
	}

	public static void main(String [] args) {
		MyStack stack = new MyStack();
		stack.push(22);
		stack.push(44);
		System.out.println(stack.peek());
		System.out.println(stack.pop());
		System.out.println(stack.peek());
	}
}