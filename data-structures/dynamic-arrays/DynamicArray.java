// Java implementation of Dynamic Array
class DynamicArray {
	private int [] list;
	private int max_size;
	private int length;

	public DynamicArray() {
		// initially allocate a single memory block
		max_size = 1;
		list = new int[max_size];
		length = 0;
	}

	// insert new item to the end of the list
	public void add(int item) {
		if (isFull()) {
			// create temporary list with double size
			max_size = 2 * max_size;
			int [] temp_list = new int[2* max_size];

			// move all the elements to the temporary list
			for (int i = 0; i < length; i++) {
				temp_list[i] = list[i];
			}

			// rename temp list
			list = temp_list;
		}
		
		// add the new item at the end of the list
		list[length] = item;
		length++;
	}

	public void printList() {
		for (int i = 0; i < length; i++) {
			System.out.print(list[i] + " ");
		}
		System.out.println();
	}

	// check if the list is full
	boolean isFull() {
		return length == max_size;
	}

	public static void main(String [] args) {
		DynamicArray list = new DynamicArray();
		list.add(1);
		list.add(2);
		list.add(3);
		list.add(4);
		list.add(5);
		list.add(6);
		list.add(7);
		list.add(8);
		list.add(9);
		list.printList();
	}
}
