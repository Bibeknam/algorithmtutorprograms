// C++ implementation of singly linked list
#include <iostream>

using namespace std;

// data structure for Node
// data -> the actual value
// next -> address of the next node
struct Node {
    int data;
    Node *next;
};

typedef Node *NodePtr;

class MyLinkedList {
    private:
    NodePtr head;

    public:
    MyLinkedList() {
        head = nullptr;
    }
    
    // Insert 'value' at the front of the list
    void insertAtFront(int value) {
        NodePtr node = new Node;
        node->data = value;
        node->next = nullptr;
        
        if (isEmpty()) {
            head = node;
        } else {
            node->next = head;
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
        } else {
            // find the last node 
            NodePtr currPtr = head;
            while (currPtr->next != nullptr) {
                currPtr = currPtr->next;
            }
            
            // insert it 
            currPtr->next = node;
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
        } else {
            // insert between key and item next to key 
            NodePtr nextPtr = currPtr->next;
            currPtr->next = node;
            node->next = nextPtr;
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
            cout<<"List if empty"<<endl;
            return -99999;
        } else if (head->next == nullptr) {
           item = head->data;
           delete head;
           head = nullptr;
        } else {
            NodePtr currPtr = head;
            NodePtr prevPtr = nullptr;
            while (currPtr->next != nullptr) {
                prevPtr = currPtr;
                currPtr = currPtr->next;
            }
            item = currPtr->data;
            delete currPtr;
            currPtr = nullptr;
            prevPtr->next = nullptr;
        } 
        
        return item;
    }
    
    // removes an item with value 'key'
    void remove(int key) {
        if (isEmpty()) {
            cout<<"list is empty"<<endl;
            return;
        }
        
        // get to the position of key
        NodePtr prevPtr = nullptr;
        NodePtr currPtr = head;
        while(currPtr != nullptr && currPtr->data != key) {
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }
        
        if (currPtr == nullptr) {
            cout<<"Key is not found in the list"<<endl;
            return;
        }
        
        if (prevPtr == nullptr) {
            // this is the first item
            head = head->next;
            delete currPtr;
            currPtr = nullptr;
            return;
        }
        
        if (currPtr->next == nullptr) {
            // this is the last item
            prevPtr->next = nullptr;
            delete currPtr;
            currPtr = nullptr;
        } else {
            // anywhere in between first and last
            NodePtr nextPtr = currPtr->next;
            prevPtr->next = nextPtr;
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
    // operations
    return 0;
}