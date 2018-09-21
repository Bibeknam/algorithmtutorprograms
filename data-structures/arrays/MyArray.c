// array declaration and operations
#include <stdio.h>

// prints the array
void print(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int i;
    // declares initializes 1d array of 12 integers
    int a[12];
    
    // keeps track of current number of items in the array
    int n = 0;
    
    // initialize first 10 items (takes O(n) time) 
    for (i = 0; i < 10; i++) {
        a[i] = i + 1;
        n = n + 1;
    }
    
    // print and see if it has all 10 items
    print(a, n); // prints 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    
    // read the item in 5th position (position starts from 0)
    printf("%d\n", a[5]); // prints 6
    
    // write 12 in first position
    a[0] = 12; 
    
    // print to see the change
    print(a, n); // prints 12, 2, 3, 4, 5, 6, 7, 8, 9, 10
    
    // insert 100 to first position
    for (i = n; i >= 0; i--) {
        a[i + 1] = a[i]; // move one step to right
    }
    
    a[0] = 100; // write 100 in first position
    n = n + 1;
    
    // print to verify
    print(a, n); // prints 100 12 2 3 4 5 6 7 8 9 10 
    
    // remove the item in the first position
    for(i = 0; i < n; i++) {
        a[i] = a[i + 1];
    }
    
    n = n - 1;
    
    // print to verify
    print(a, n); // prints 12 2 3 4 5 6 7 8 9 10 
    
	return 0;
}