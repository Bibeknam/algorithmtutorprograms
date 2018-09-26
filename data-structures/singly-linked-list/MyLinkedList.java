// Java implementation of Singly linked list 

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class MyLinkedList {
    private Node head;

    public MyLinkedList() {
        head = null;
    }

    // Insert 'value' at the front of the list
    public void insertAtFront(int value) {
        Node node = new Node(value);
        if(isEmpty()) {
            head = node;
        } else {
            node.next = head;
            head = node;
        }
    }

    // insert value at the back of the linked list
    public void insertAtBack(int value) {
        Node node = new Node(value);
        if (isEmpty()) {
            head = node;
        } else {
            Node curr = head;
            while(null != curr.next) {
                curr = curr.next;
            }

            curr.next = node;
        }
    }

    // inserts value after key
    public void insertAfter(int key, int value) {
        Node node = new Node(value);

        // find the position of key
        Node curr = head;
        while(null != curr && curr.data != key) {
            curr = curr.next;
        }

        if (null == curr) {
            System.out.println("Key not found");
            return;
        }

        if(null == curr.next) {
            curr.next = node;
        } else {
            Node next = curr.next;
            curr.next = node;
            node.next = next;
        }
    }

    // returns the data at first node 
    public int topFront() {
        if (isEmpty()) {
            System.out.println("List is empty");
            return -999999;
        }

        return head.data;
    }  

    // returns the data at last node 
    public int topBack() { 
        if(isEmpty()) {
            System.out.println("List is empty");
            return -999999;
        }

        Node curr = head;
        while(curr.next != null) {
            curr = curr.next;
        }

        return curr.data;
    }

    // removes the item at front of the linked list and return 
    public int popFront() {
        if (isEmpty()) {
            System.out.println("List is empty");
            return -999999;
        }

        Node next = head.next;
        int item = head.data;
        head = next;
        return item;
    }

    // remove the item at the end of the list and return 
    public int popBack() {
        if (isEmpty()) {
            System.out.println("List is empty");
            return -999999;
        }

        // get to the last node
        Node curr = head;
        Node prev = null;
        while(curr.next != null) {
            prev = curr;
            curr = curr.next;
        }

        int item = curr.data;

        if (prev == null) {
            // the list has only one item
            head = null;
        } else {
            prev.next = null;
            curr = null;
        }

        return item;
    }

    // removes an item with value 'key'
    public void remove(int key) {
        if (isEmpty()) {
            System.out.println("List is empty");
            return;
        }

        // find the position of the key
        Node curr = head;
        Node prev = null;

        while(curr != null && curr.data != key) {
            prev = curr;
            curr = curr.next;
        }

        if(curr == null) {
            System.out.print("key not found");
            return;
        }

        // if curr is head, delete the head
        if (prev == null) {
            head = head.next;
            curr = null;
        } else if (curr.next == null) { // if curr is last item
            prev.next = null;
            curr = null;
        } else { //anywhere between first and last node
            Node next = curr.next;
            prev.next = next;
            curr = null;
        }   


    }

    // check if the key is in the list
    public boolean find(int key) {
        if (isEmpty()) {
            System.out.println("List is empty");
            return false;
        }

        Node curr = head;
        while(curr != null && curr.data != key) {
            curr = curr.next;
        }

        if (curr == null) {
            return false;
        }

        return true;
    }

    // check if the list is empty
    public boolean isEmpty() {
        return head == null;
    }

    // print all the items
    public void print() {
        if (isEmpty()) {
            System.out.println("Nothing to display");
        } else {
            Node curr = head;
            while (curr != null) {
                System.out.print(curr.data + " ");
                curr = curr.next;
            }
            System.out.println();
        }
    }

    public static void main(String [] args) {
        MyLinkedList list = new MyLinkedList();
    }
}