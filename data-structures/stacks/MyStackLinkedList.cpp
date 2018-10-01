// C++ implementation of stack using linked list
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
};

typedef Node *NodePtr;

class MyStackLinkedList {
private:
	NodePtr tail;
public:
	MyStackLinkedList() {
		tail = nullptr;
	}

	// push operation
	void push(int item) {
		NodePtr node = new Node;
		node->data = item;
		node->next = nullptr;
		node->prev = nullptr;

		if (tail == nullptr) {
			tail = node;
		} else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
	}
    
    // pop operation
	int pop() {
		if (tail == nullptr) {
			cout<<"ERROR: stack is empty"<<endl;
			return -999999;
		}

		int item = tail->data;
		NodePtr prev = tail->prev;
		if (prev != nullptr) {
			prev->next = nullptr;
		}
		tail->prev = nullptr;
		delete tail;
		tail = prev;
		return item;
	}
	

	// peek (top) operation
	int peek() {
		if (tail == nullptr) {
			cout<<"ERROR: stack is empty"<<endl;
			return -999999;
		}

		return tail->data;
	}

};

int main() {
    MyStackLinkedList stack;
    stack.push(44);
    stack.push(33);
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    stack.push(45);
    cout<<stack.peek()<<endl;
	return 0;
}