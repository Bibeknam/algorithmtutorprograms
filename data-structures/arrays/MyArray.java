// array declaration and operations

public class MyArray {
    private int [] a;
    private int n;
    
    public MyArray() {
        a = new int[12];
        n = 0;
    }
    
    public void initialize() {
        for (int i = 0; i < 10; i++) {
            a[i] = i+1;
        }
        n = 10;
    }
    
    // print the array
    public void print() {
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
    
    public int get(int i) {
        return a[i];
    }
    
    public void set(int position, int value) {
        a[position] = value;
    }
    
    public void insert(int position, int value) {
        for (int i = n; i >= position; i--) {
            a[i + 1] = a[i];
        }
        a[position] = value;
        n = n + 1;
    }
    
    public void delete(int position) {
        for(int i = 0; i < n; i++) {
            a[i] = a[i + 1];
        }
        n = n - 1;
    }
    
    public static void main(String [] args) {
        MyArray arr = new MyArray();
        
        // initialize the array (takes O(n) time)
        arr.initialize();
        
        // print to verify 
        arr.print(); // prints 1 2 3 4 5 6 7 8 9 10 
        
        // read the item in 5th position (position starts from 0)
        System.out.println(arr.get(5)); // prints 6
        
        // write 12 in first position
        arr.set(0, 12); // prints 12 2 3 4 5 6 7 8 9 10 
        
        // print to verify
        arr.print(); // 12 2 3 4 5 6 7 8 9 10 
        
        // insert 100 in first position
        arr.insert(0, 100); // 100 12 2 3 4 5 6 7 8 9 10
        
        // print to verify 
        arr.print(); 
        
        // remove item in first position
        arr.delete(0); // 12 2 3 4 5 6 7 8 9 10
        
        // print to verify
        arr.print();
    }
}