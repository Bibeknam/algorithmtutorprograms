// Java implementation of Doubly linked list 

class Node {
    int data;
    Node next;
    Node prev;

    public Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

public class MyLinkedList {
    private Node head;
    private Node tail;

    public MyLinkedList() {
        head = null;
        tail = null;
    }

    // Insert 'value' at the front of the list
    public void insertAtFront(int value) {
        Node node = new Node(value);
        if(isEmpty()) {
            head = node;
            tail = node;
        } else {
            node.next = head;
            head.prev = node;
            head = node;
        }
    }

    // insert value at the back of the linked list
    public void insertAtBack(int value) {
        Node node = new Node(value);
        if (isEmpty()) {
            head = node;
            tail = node;
        } else {
            tail.next = node;
            node.prev = tail;
            tail = node;
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
            node.prev = curr;
            tail = node;
        } else {
            Node next = curr.next;
            curr.next = node;
            node.prev = curr;
            node.next = next;
            next.prev = node;
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
        int item = head.data;
        Node next = head.next;
        if (next != null) {
            next.prev = null;
        }
        head = next;
        return item;
    }

    // remove the item at the end of the list and return 
    public int popBack() {
        if (isEmpty()) {
            System.out.println("List is empty");
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

    // removes an item with value 'key'
    public void remove(int key) {
        if (isEmpty()) {
            System.out.println("List is empty");
            return;
        }

        // find the position of the key
        Node curr = head;

        while(curr != null && curr.data != key) {
            curr = curr.next;
        }

        if(curr == null) {
            System.out.print("key not found");
            return;
        }

        // if curr is head, delete the head
        if (curr.prev == null) {
            popFront();

        } else if (curr.next == null) { // if curr is last item
            popBack();

        } else { //anywhere between first and last node
            Node next = curr.next;
            Node prev = curr.prev;

            prev.next = next;
            next.prev = prev;

            curr.prev = null;
            curr.next = null;
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
    
    // print all the items
    public void printReverse() {
        if (isEmpty()) {
            System.out.println("Nothing to display");
        } else {
            Node curr = tail;
            while (curr != null) {
                System.out.print(curr.data + " ");
                curr = curr.prev;
            }
            System.out.println();
        }
    }

    public static void main(String [] args) {
        MyLinkedList list = new MyLinkedList();
        list.insertAtFront(33);
        list.insertAtFront(55);
        list.insertAtBack(12);
        list.insertAtBack(3);
        list.printReverse();
        list.insertAfter(3, 44);
        list.insertAfter(12, 50);
        list.print();
        System.out.println(list.popFront());
        list.print();
        System.out.println(list.popBack());
        list.print();
        list.remove(12);
        list.printReverse();
    }
}