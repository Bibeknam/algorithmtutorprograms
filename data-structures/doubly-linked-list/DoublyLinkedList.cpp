// C++ implementation of doubly linked list
#include <iostream>

using namespace std;

// data structure for Node
// data -> the actual value
// next -> address of the next node
struct Node {
    int data;
    Node *next;
    Node *prev;
};

typedef Node *NodePtr;

class MyLinkedList {
    private:
    NodePtr head;
    NodePtr tail;

    public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;

    }
    
    // Insert 'value' at the front of the list
    void insertAtFront(int value) {
        NodePtr node = new Node;
        node->data = value;
        node->next = nullptr;
        node->prev = nullptr;
        
        if (isEmpty()) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    
    // insert value at the back of the linked list
    void insertAtBack(int value) {
        NodePtr node = new Node;
        node->data = value;
        node->next = nullptr;
        
        if (isEmpty()) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    
    // inserts value after key
    void insertAfter(int key, int value) {
        NodePtr node = new Node;
        node->data = value;
        node->next = nullptr;

        // find the position of key
        NodePtr currPtr = head;
        while (currPtr != nullptr && currPtr->data != key) {
            currPtr = currPtr->next;
        }
        
        // if key is not there, raise error
        if (currPtr == nullptr) {
            cout<<"key not found";
        } else if (currPtr->next == nullptr) {
            // if key is the last node, insert right after it 
            currPtr->next = node;
            node->prev = currPtr;
            tail = node;
        } else {
            // insert between key and item next to key 
            NodePtr nextPtr = currPtr->next;
            currPtr->next = node;
            node->prev = currPtr;
            node->next = nextPtr;
            nextPtr->prev = node;
        }
    }
    
    // returns the data at first node 
    int topFront() {
        if (isEmpty()) {
            cout<<"List is empty"<<endl;
        } else {
            return head->data;
        }
    }
    
    // returns the data at last node 
    int topBack() {
        if (isEmpty()) {
            cout<<"List is empty"<<endl;
        } else if (head->next == nullptr) {
            return head->data;
        } else {
            NodePtr currPtr = head;
            while (currPtr->next != nullptr) {
                currPtr = currPtr->next;
            }
            return currPtr->data;
        }
    }
    
    // removes the item at front of the linked list and return 
    int popFront() {
        int item;
        if (isEmpty()) {
            cout<<"List is empty"<<endl;
            return -99999;
        } else {
            NodePtr nextPtr = head->next;
            if (nextPtr->next != nullptr) {
                nextPtr->prev = nullptr;
            }
            item = head->data;
            // remove head
            delete head;
            
            // make nextptr head 
            head = nextPtr;
        }
        
        return item;
    }
    
    // remove the item at the list of the linked list and return 
    int popBack() {
        int item;
        if (isEmpty()) {
            cout<<"List is empty"<<endl;
            return -99999;
        } else {
            item = tail->data;
            NodePtr prev = tail->prev;
            if (prev != nullptr) {
                prev->next = nullptr;
            }

            tail->prev = nullptr;
            delete tail;
            tail = prev;
        }
        
        return item;
    }
    
    // removes an item with value 'key'
    void remove(int key) {
        if (isEmpty()) {
            cout<<"List is empty"<<endl;
            return;
        }
        
        // get to the position of key
        NodePtr currPtr = head;
        while(currPtr != nullptr && currPtr->data != key) {
            currPtr = currPtr->next;
        }
        
        if (currPtr == nullptr) {
            cout<<"Key is not found in the list"<<endl;
            return;
        }
        
        if (currPtr->prev == nullptr) {
            // this is the first item
            popFront();
          
        } else if (currPtr->next == nullptr) {
            // this is the last item
            popBack();
        } else {
            // anywhere in between first and last
            NodePtr nextPtr = currPtr->next;
            NodePtr prevPtr = currPtr->prev;
            nextPtr->prev = prevPtr;
            prevPtr->next = nextPtr;

            currPtr->next = nullptr;
            currPtr->prev = nullptr;
            delete currPtr;
            currPtr = nullptr;
        }
    }
    
    // print the linked list 
    void print() {
        NodePtr currPtr = head;
        while (currPtr != nullptr) {
            cout<<currPtr->data<<" ";
            currPtr = currPtr->next;
        }
        cout<<endl;
    }

    void printReverse() {
        NodePtr currPtr = tail;
        while (currPtr != nullptr) {
            cout<<currPtr->data<<" ";
            currPtr = currPtr->prev;
        }
        cout<<endl;
    }

    // check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // check if key is in the list
    bool find(int key) {
        if (isEmpty()) {
            return false;
        }

        NodePtr currPtr = head;
        while (currPtr != nullptr && currPtr->data != key) {
            currPtr = currPtr->next;
        }

        if (currPtr == nullptr) {
            return false;
        }

        return true;
    }
};

int main() {
    MyLinkedList list;
    list.insertAtFront(34);
    list.insertAtFront(44);
    list.insertAtBack(52);
    list.insertAtBack(22);
    list.printReverse();
    list.insertAfter(22, 33);
    list.insertAfter(52, 100);
    list.print();
    cout<<list.popFront()<<endl;
    list.print();
    cout<<list.popBack()<<endl;
    list.print();
    list.remove(100);
    list.printReverse();
    // operations
    return 0;
}