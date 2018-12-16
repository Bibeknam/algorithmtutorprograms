// Binary search tree implementation in C++
// Author: Algorithm Tutor

#include <iostream>

using namespace std;

// data structure that represents a node in the tree
struct Node {
	int data; // holds the key
	Node *parent; // pointer to the parent
	Node *left; // pointer to left child
	Node *right; // pointer to right child
};

typedef Node *NodePtr;

// class BST implements the operations in BST
class BST {
private:
	NodePtr root;

	// initializes the nodes with appropirate values
	// all the pointers are set to point to the null pointer
	void initializeNode(NodePtr node, int key) {
		node->data = key;
		node->parent = nullptr;
		node->left = nullptr;
		node->right = nullptr;
	}

	void preOrderHelper(NodePtr node) {
		if (node != nullptr) {
			cout<<node->data<<" ";
			preOrderHelper(node->left);
			preOrderHelper(node->right);
		} 
	}

	void inOrderHelper(NodePtr node) {
		if (node != nullptr) {
			inOrderHelper(node->left);
			cout<<node->data<<" ";
			inOrderHelper(node->right);
		} 
	}

	void postOrderHelper(NodePtr node) {
		if (node != nullptr) {
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			cout<<node->data<<" ";
		} 
	}

	NodePtr searchTreeHelper(NodePtr node, int key) {
		if (node == nullptr || key == node->data) {
			return node;
		}

		if (key < node->data) {
			return searchTreeHelper(node->left, key);
		} 
		return searchTreeHelper(node->right, key);
	}

	NodePtr deleteNodeHelper(NodePtr node, int key) {
		// search the key
		if (node == nullptr) return node;
		else if (key < node->data) node->left = deleteNodeHelper(node->left, key);
		else if (key > node->data) node->right = deleteNodeHelper(node->right, key);
		else {
			// the key has been found, now delete it

			// case 1: node is a leaf node
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				node = nullptr;
			}

			// case 2: node has only one child
			else if (node->left == nullptr) {
				NodePtr temp = node;
				node = node->right;
				delete temp;
			}

			else if (node->right == nullptr) {
				NodePtr temp = node;
				node = node->left;
				delete temp;
			}

			// case 3: has both children
			else {
				NodePtr temp = minimum(node->right);
				node->data = temp->data;
				node->right = deleteNodeHelper(node->right, temp->data);
			}

		} 
		return node;
	}

	void printHelper(NodePtr root, string indent, bool last) {
		// print the tree structure on the screen
	   	if (root != nullptr) {
		   cout<<indent;
		   if (last) {
		      cout<<"└────";
		      indent += "     ";
		   } else {
		      cout<<"├────";
		      indent += "|    ";
		   }

		   cout<<root->data<<endl;

		   printHelper(root->left, indent, false);
		   printHelper(root->right, indent, true);
		}
	}

public:
	BST() {
		root = nullptr;
	}

	void createSampleTree1() {
		NodePtr node50 = new Node;
		initializeNode(node50, 50);
		NodePtr node30 = new Node;
		initializeNode(node30, 30);
		NodePtr node70 = new Node;
		initializeNode(node70, 70);

		node30->parent = node50;
		node70->parent = node50;
		node50->left = node30;
		node50->right = node70;

		NodePtr node23 = new Node;
		initializeNode(node23, 23);
		NodePtr node35 = new Node;
		initializeNode(node35, 35);

		node23->parent = node30;
		node35->parent = node30;
		node30->left = node23;
		node30->right = node35;

		NodePtr node11 = new Node;
		initializeNode(node11, 11);
		NodePtr node25 = new Node;
		initializeNode(node25, 25);

		node11->parent = node23;
		node25->parent = node23;
		node23->left = node11;
		node23->right = node25;

		NodePtr node31 = new Node;
		initializeNode(node31, 31);
		NodePtr node42 = new Node;
		initializeNode(node42, 42);

		node31->parent = node35;
		node42->parent = node35;
		node35->left = node31;
		node35->right = node42;

		NodePtr node80 = new Node;
		initializeNode(node80, 80);

		node80->parent = node70;
		node70->right = node80;

		NodePtr node73 = new Node;
		initializeNode(node73, 73);
		NodePtr node85 = new Node;
		initializeNode(node85, 85);

		node73->parent = node80;
		node85->parent = node80;
		node80->left = node73;
		node80->right = node85;

		this->root = node50;
	}

	// Pre-Order traversal
	// Node->Left Subtree->Right Subtree
	void preorder() {
		preOrderHelper(this->root);
	}

	// In-Order traversal
	// Left Subtree -> Node -> Right Subtree
	void inorder() {
		inOrderHelper(this->root);
	}

	// Post-Order traversal
	// Left Subtree -> Right Subtree -> Node
	void postorder() {
		postOrderHelper(this->root);
	}

	// search the tree for the key k
	// and return the corresponding node
	NodePtr searchTree(int k) {
		return searchTreeHelper(this->root, k);
	}

	// find the node with the minimum key
	NodePtr minimum(NodePtr node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}

	// find the node with the maximum key
	NodePtr maximum(NodePtr node) {
		while (node->right != nullptr) {
			node = node->right;
		}
		return node;
	}

	// find the successor of a given node
	NodePtr successor(NodePtr x) {
		// if the right subtree is not null,
		// the successor is the leftmost node in the
		// right subtree
		if (x->right != nullptr) {
			return minimum(x->right);
		}

		// else it is the lowest ancestor of x whose
		// left child is also an ancestor of x.
		NodePtr y = x->parent;
		while (y != nullptr && x == y->right) {
			x = y;
			y = y->parent;
		}
		return y;
	}

	// find the predecessor of a given node
	NodePtr predecessor(NodePtr x) {
		// if the left subtree is not null,
		// the predecessor is the rightmost node in the 
		// left subtree
		if (x->left != nullptr) {
			return maximum(x->left);
		}

		NodePtr y = x->parent;
		while (y != nullptr && x == y->left) {
			x = y;
			y = y->parent;
		}

		return y;
	}

	// insert the key to the tree in its appropriate position
	void insert(int key) {
		NodePtr node = new Node;
		node->parent = nullptr;
		node->left = nullptr;
		node->right = nullptr;
		node->data = key;
		NodePtr y = nullptr;
		NodePtr x = this->root;

		while (x != nullptr) {
			y = x;
			if (node->data < x->data) {
				x = x->left;
			} else {
				x = x->right;
			}
		}

		// y is parent of x
		node->parent = y;
		if (y == nullptr) {
			root = node;
		} else if (node->data < y->data) {
			y->left = node;
		} else {
			y->right = node;
		}
	}

	NodePtr getRoot(){
		return this->root;
	}

	// delete the node from the tree
	NodePtr deleteNode(int data) {
		return deleteNodeHelper(this->root, data);
	}

	// print the tree structure on the screen
	void prettyPrint() {
		printHelper(this->root, "", true);
	}

};

int main() {
	BST bst;
	bst.createSampleTree1();
	bst.prettyPrint();
	return 0;
}