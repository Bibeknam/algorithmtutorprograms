// C implementation of doubly linked list
#include <stdio.h>
#include <stdlib.h>



// data structure for Node
// data -> the actual value
// next -> address of the next node
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node *NodePtr;

// global variables head and tail
NodePtr head = NULL;
NodePtr tail = NULL;

// check if the list is empty
int isEmpty() {
    return head == NULL;
}

// Insert 'value' at the front of the list
void insertAtFront(int value) {
    NodePtr node = malloc(sizeof(NodePtr));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    
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
    NodePtr node = malloc(sizeof(NodePtr));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    
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
NodePtr insertAfter(int key, int value) {
    NodePtr node = malloc(sizeof(NodePtr));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;

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
        item = head->data;
        if (head->next != NULL) {
            head->next->prev = NULL;
        }
        NodePtr next = head->next;
        free(head);
        head = next;
    }
    
    return item;
}

// remove the item at the list of the linked list and return 
int popBack() {
    int item;
    if (isEmpty()) {
        printf("%s", "List is empty");
        return -99999;
    } else {
        item = tail->data;
        if (tail->prev != NULL) {
            tail->prev->next = NULL;
        }
        NodePtr prev = tail->prev;
        tail->prev = NULL;
        free(tail);
        tail = prev;

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
    NodePtr currPtr = head;
    while(currPtr != NULL && currPtr->data != key) {
        currPtr = currPtr->next;
    }
    
    if (currPtr == NULL) {
        printf("%s", "Key is not found in the list");
        return;
    }
    
    if (currPtr->prev == NULL) {
        // this is the first item
        popFront();

    } else if (currPtr->next == NULL) {
        // this is the last item
        popBack();

    } else {
        // anywhere in between first and last
        NodePtr nextPtr = currPtr->next;
        NodePtr prevPtr = currPtr->prev;
        nextPtr->prev = prevPtr;
        prevPtr->next = nextPtr;
        currPtr->next = NULL;
        currPtr->prev = NULL;
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

// print the linked list 
void printReverse() {
    NodePtr currPtr = tail;
    while (currPtr != NULL) {
        printf("%d", currPtr->data);
        printf(" ");
        currPtr = currPtr->prev;
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
    insertAtBack(25);
    insertAtBack(44);
    insertAfter(25, 39);
    insertAfter(25, 233);
    insertAfter(44, 45);
    print();
    int item = popFront();
    printf("%d\n", item);
    print();
    item = popBack();
    printf("%d\n", item);
    print();
    delete(233);
    print();
    // operations
    return 0;
}