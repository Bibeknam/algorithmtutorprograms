// C implementation of singly linked list
#include <stdio.h>
#include <stdlib.h>



// data structure for Node
// data -> the actual value
// next -> address of the next node
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *NodePtr;

// global variable head. It points to the 
// first node of the list
NodePtr head = NULL;

// check if the list is empty
int isEmpty() {
    return head == NULL;
}

// Insert 'value' at the front of the list
void insertAtFront(int value) {
    NodePtr node = malloc(sizeof(NodePtr));
    node->data = value;
    node->next = NULL;
    
    if (isEmpty()) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }

}
    
// insert value at the back of the linked list
void insertAtBack(int value) {
    NodePtr node = malloc(sizeof(NodePtr));
    node->data = value;
    node->next = NULL;
    
    if (isEmpty()) {
        head = node;
    } else {
        // find the last node 
        NodePtr currPtr = head;
        while (currPtr->next != NULL) {
            currPtr = currPtr->next;
        }
        
        // insert it 
        currPtr->next = node;
    }
}
    
// inserts value after key
NodePtr insertAfter(int key, int value) {
    NodePtr node = malloc(sizeof(NodePtr));
    node->data = value;
    node->next = NULL;

    // find the position of key
    NodePtr currPtr = head;
    while (currPtr != NULL && currPtr->data != key) {
        currPtr = currPtr->next;
    }
    
    // if key is not there, raise error
    if (currPtr == NULL) {
        printf("%s", "key not found");
    } else if (currPtr->next == NULL) {
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
        printf("%s", "List is empty");
    } else {
        return head->data;
    }
}

// returns the data at last node 
int topBack() {
    if (isEmpty()) {
        printf("%s", "List is empty");
    } else if (head->next == NULL) {
        return head->data;
    } else {
        NodePtr currPtr = head;
        while (currPtr->next != NULL) {
            currPtr = currPtr->next;
        }
        return currPtr->data;
    }
}

// removes the item at front of the linked list and return 
int popFront() {
    int item;
    if (isEmpty()) {
        printf("%s", "List is empty");
        return -99999;
    } else {
        NodePtr nextPtr = head->next;
        item = head->data;
        // remove head
        free(head);
        
        // make nextptr head 
        head = nextPtr;
        
    }
    
    return item;
}

// remove the item at the list of the linked list and return 
int popBack() {
    int item;
    if (isEmpty()) {
        printf("%s", "List is empty");
        return -99999;
    } else if (head->next == NULL) {
       item = head->data;
       free(head);
       head = NULL;
    } else {
        NodePtr currPtr = head;
        NodePtr prevPtr = NULL;
        while (currPtr->next != NULL) {
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }
        item = currPtr->data;
        free(currPtr);
        currPtr = NULL;
        prevPtr->next = NULL;
    } 
    
    return item;
}

// removes an item with value 'key'
void delete(int key) {
    if (isEmpty()) {
        printf("%s", "List is empty");
        return;
    }
    
    // get to the position of key
    NodePtr prevPtr = NULL;
    NodePtr currPtr = head;
    while(currPtr != NULL && currPtr->data != key) {
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }
    
    if (currPtr == NULL) {
        printf("%s", "Key is not found in the list");
        return;
    }
    
    if (prevPtr == NULL) {
        // this is the first item
        head = head->next;
        free(currPtr);
        currPtr = NULL;
        return;
    }
    
    if (currPtr->next == NULL) {
        // this is the last item
        prevPtr->next = NULL;
        free(currPtr);
        currPtr = NULL;
    } else {
        // anywhere in between first and last
        NodePtr nextPtr = currPtr->next;
        prevPtr->next = nextPtr;
        free(currPtr);
        currPtr = NULL;
    }
}

// print the linked list 
void print() {
    NodePtr currPtr = head;
    while (currPtr != NULL) {
        printf("%d", currPtr->data);
        printf(" ");
        currPtr = currPtr->next;
    }
    printf("\n");
}

// check if key is in the list
int find(int key) {
    if (isEmpty()) {
        return 0;
    }

    NodePtr currPtr = head;
    while (currPtr != NULL && currPtr->data != key) {
        currPtr = currPtr->next;
    }

    if (currPtr == NULL) {
        return 0;
    }

    return 1;
}

int main() {
    insertAtFront(23);
    insertAtFront(24);    
    print();
    // operations
    return 0;
}