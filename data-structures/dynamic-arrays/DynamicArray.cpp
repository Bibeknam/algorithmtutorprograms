// C++ implementation of Dynamic Array
#include <iostream>
using namespace std;

template <class T>
class DynamicArray {
private:
	T *list;
	int max_size;
	int length;
public:
	DynamicArray() {
		// initially allocate a single memory block
		max_size = 1;
		list = new T[max_size];
		length = 0;
	}

	// insert new item to the end of the list
	void add(T item) {
		if (isFull()) {
			// create temporary list with double size
			max_size = 2 * max_size;
			T *temp_list = new T[2* max_size];

			// move all the elements to the temporary list
			for (int i = 0; i < length; i++) {
				temp_list[i] = list[i];
			}

			// delete the old list
			delete [] list;

			// rename temp list
			list = temp_list;
		}
		
		// add the new item at the end of the list
		list[length] = item;
		length++;
	}

	void printList() {
		for (int i = 0; i < length; i++) {
			cout<<list[i]<<' ';
		}
		cout<<endl;
	}

	// check if the list is full
	bool isFull() {
		return length == max_size;
	}

	~DynamicArray() {
		delete [] list;
	}


};

int main() {
	DynamicArray<char> list;
	list.add('1');
	list.add('2');
	list.add('3');
	list.add('4');
	list.add('5');
	list.add('6');
	list.add('7');
	list.add('8');
	list.add('9');
	list.printList();
	return 0;
}