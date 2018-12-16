// Binary search tree implementation in Java
// Author: AlgorithmTutor

// data structure that represents a node in the tree
class Node {
	int data; // holds the key
	Node parent; // pointer to the parent
	Node left; // pointer to left child
	Node right; // pointer to right child

	public Node(int data) {
		this.data = data;
		this.parent = null;
		this.left = null;
		this.right = null;
	}
}

public class BST {
	private Node root;

	public BST() {
		root = null;
	}

	public void createSampleTree1() {
		Node node50 = new Node(50);
		Node node30 = new Node(30);
		Node node70 = new Node(70);

		node30.parent = node50;
		node70.parent = node50;
		node50.left = node30;
		node50.right = node70;

		Node node23 = new Node(23);
		Node node35 = new Node(35);

		node23.parent = node30;
		node35.parent = node30;
		node30.left = node23;
		node30.right = node35;

		Node node11 = new Node(11);
		Node node25 = new Node(25);

		node11.parent = node23;
		node25.parent = node23;
		node23.left = node11;
		node23.right = node25;

		Node node31 = new Node(31);
		Node node42 = new Node(42);

		node31.parent = node35;
		node42.parent = node35;
		node35.left = node31;
		node35.right = node42;

		Node node80 = new Node(80);

		node80.parent = node70;
		node70.right = node80;

		Node node73 = new Node(73);
		Node node85 = new Node(85);

		node73.parent = node80;
		node85.parent = node80;
		node80.left = node73;
		node80.right = node85;

		this.root = node50;
	}

	private void printHelper(Node currPtr, String indent, boolean last) {
		// print the tree structure on the screen
	   	if (currPtr != null) {
		   System.out.print(indent);
		   if (last) {
		      System.out.print("R----");
		      indent += "     ";
		   } else {
		      System.out.print("L----");
		      indent += "|    ";
		   }

		   System.out.println(currPtr.data);

		   printHelper(currPtr.left, indent, false);
		   printHelper(currPtr.right, indent, true);
		}
	}

	private Node searchTreeHelper(Node node, int key) {
		if (node == null || key == node.data) {
			return node;
		}

		if (key < node.data) {
			return searchTreeHelper(node.left, key);
		} 
		return searchTreeHelper(node.right, key);
	}

	private Node deleteNodeHelper(Node node, int key) {
		// search the key
		if (node == null) return node;
		else if (key < node.data) node.left = deleteNodeHelper(node.left, key);
		else if (key > node.data) node.right = deleteNodeHelper(node.right, key);
		else {
			// the key has been found, now delete it

			// case 1: node is a leaf node
			if (node.left == null && node.right == null) {
				node = null;
			}

			// case 2: node has only one child
			else if (node.left == null) {
				Node temp = node;
				node = node.right;
			}

			else if (node.right == null) {
				Node temp = node;
				node = node.left;
			}

			// case 3: has both children
			else {
				Node temp = minimum(node.right);
				node.data = temp.data;
				node.right = deleteNodeHelper(node.right, temp.data);
			}

		} 
		return node;
	}

	private void preOrderHelper(Node node) {
		if (node != null) {
			System.out.print(node.data + " ");
			preOrderHelper(node.left);
			preOrderHelper(node.right);
		} 
	}

	private void inOrderHelper(Node node) {
		if (node != null) {
			inOrderHelper(node.left);
			System.out.print(node.data + " ");
			inOrderHelper(node.right);
		} 
	}

	private void postOrderHelper(Node node) {
		if (node != null) {
			postOrderHelper(node.left);
			postOrderHelper(node.right);
			System.out.print(node.data + " ");
		} 
	}

	// Pre-Order traversal
	// Node->Left Subtree->Right Subtree
	public void preorder() {
		preOrderHelper(this.root);
	}

	// In-Order traversal
	// Left Subtree -> Node -> Right Subtree
	public void inorder() {
		inOrderHelper(this.root);
	}

	// Post-Order traversal
	// Left Subtree -> Right Subtree -> Node
	public void postorder() {
		postOrderHelper(this.root);
	}

	// search the tree for the key k
	// and return the corresponding node
	public Node searchTree(int k) {
		return searchTreeHelper(this.root, k);
	}

	// find the node with the minimum key
	public Node minimum(Node node) {
		while (node.left != null) {
			node = node.left;
		}
		return node;
	}

	// find the node with the maximum key
	public Node maximum(Node node) {
		while (node.right != null) {
			node = node.right;
		}
		return node;
	}

	// find the successor of a given node
	public Node successor(Node x) {
		// if the right subtree is not null,
		// the successor is the leftmost node in the
		// right subtree
		if (x.right != null) {
			return minimum(x.right);
		}

		// else it is the lowest ancestor of x whose
		// left child is also an ancestor of x.
		Node y = x.parent;
		while (y != null && x == y.right) {
			x = y;
			y = y.parent;
		}
		return y;
	}

	// find the predecessor of a given node
	public Node predecessor(Node x) {
		// if the left subtree is not null,
		// the predecessor is the rightmost node in the 
		// left subtree
		if (x.left != null) {
			return maximum(x.left);
		}

		Node y = x.parent;
		while (y != null && x == y.left) {
			x = y;
			y = y.parent;
		}

		return y;
	}

	// insert the key to the tree in its appropriate position
	public void insert(int key) {
		Node node = new Node(key);
		Node y = null;
		Node x = this.root;

		while (x != null) {
			y = x;
			if (node.data < x.data) {
				x = x.left;
			} else {
				x = x.right;
			}
		}

		// y is parent of x
		node.parent = y;
		if (y == null) {
			root = node;
		} else if (node.data < y.data) {
			y.left = node;
		} else {
			y.right = node;
		}
	}

	// delete the node from the tree
	Node deleteNode(int data) {
		return deleteNodeHelper(this.root, data);
	}

	// print the tree structure on the screen
	public void prettyPrint() {
		printHelper(this.root, "", true);
	}

	public static void main(String [] args) {
		BST tree = new BST();
		tree.createSampleTree1();
		Node n = tree.deleteNode(35);
		tree.prettyPrint();
	}
}