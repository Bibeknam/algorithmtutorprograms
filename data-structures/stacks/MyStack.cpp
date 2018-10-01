// C++ implementation of Stack using array

#include<iostream>

using namespace std;

class MyStack {
private:
	const static int MAX_SIZE = 10;
	int stack[MAX_SIZE];
	int top;
public:
	MyStack() {
		top = -1;
	}

	// inserts item at the top of the stack
	void push(int item) {
		// check for overflow
		if (top >= MAX_SIZE - 1) {
			cout<<"Error: Can not push item. Stack Overflow"<<endl;
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
			cout<<"Error: Can not pop item. Stack Underflow"<<endl;
			return -999999;
		}

		top = top - 1;
		return stack[top + 1];
	}

	// returns the item at the top
	int peek() {
		// check for underflow
		if (top <= -1) {
			cout<<"Error: Can not read item. Stack Underflow"<<endl;
			return - 999999;
		}

		return stack[top];
	}
};

int main() {
	MyStack stack;
	stack.push(33);
	stack.push(34);
	stack.push(35);
	cout<<stack.peek()<<endl;
	cout<<stack.pop()<<endl;
	cout<<stack.peek()<<endl;
	return 0;
}