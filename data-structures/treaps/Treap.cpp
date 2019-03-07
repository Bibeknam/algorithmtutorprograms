// Treap data structure implementation in C++
// Author: Algorithm Tutor

#include <iostream>

using namespace std;

// data structure that represents a node in the tree
struct Node {
	int data; // holds the key
	float priority; // priority of the node
	Node *parent; // pointer to the parent
	Node *left; // pointer to left child
	Node *right; // pointer to right child
};

typedef Node *NodePtr;

// class Treap implements the operations in Treap Data Structure
class Treap {
private:
	NodePtr root;

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

		   cout<<root->data<<"("<<root->priority<<")"<<endl;

		   printHelper(root->left, indent, false);
		   printHelper(root->right, indent, true);
		}
	}

	// rotate left at node x
	void leftRotate(NodePtr x) {
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != nullptr) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	// rotate right at node x
	void rightRotate(NodePtr x) {
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != nullptr) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	// we move the node up until its priority is greater than
	// or equal the parent's priority
	void moveUp(NodePtr x) {
		if (x->parent == nullptr) {
			return;
		}
		if (x->parent != nullptr && x->priority >= x->parent->priority) {
			return;
		}

		if (x == x->parent->left) {
			rightRotate(x->parent);
		} else {
			leftRotate(x->parent);
		}

		// recursively move the x up
		moveUp(x);
	}

	// delete key k
	void deleteNodeHelper(NodePtr node, int k) {
		// find k
		NodePtr x = nullptr;
		while (node != nullptr) {
			if (node->data == k) {
				x = node;
				break;
			}

			if (node->data <= k) {
				node = node->right;
			} else {
				node = node->left;
			}
		}

		if (x == nullptr) {
			cout<<"couldn't find the "<<k<<" in the treap"<<endl;
			return;
		}

		// move down x
		moveDown(x);

		// in this point x is in the leaf node
		// delete x
		if (x == x->parent->left) {
			x->parent->left = nullptr;
		} else {
			x->parent->right = nullptr;
		}
		delete x;
		x = nullptr;
	}

	// move down x to the leaf of the tree
	void moveDown(NodePtr x) {
		if (x->left == nullptr && x->right == nullptr) {
			return;
		}

		if (x->left != nullptr && x->right != nullptr) {
			if (x->left->priority < x->right->priority) {
				rightRotate(x);
			} else {
				leftRotate(x);
			}
		} else if (x->left != nullptr) {
			rightRotate(x);
		} else {
			leftRotate(x);
		}

		moveDown(x);
	}

public:
	Treap() {
		root = nullptr;
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
	void insert(int key, float priority) {
		NodePtr node = new Node;
		node->parent = nullptr;
		node->left = nullptr;
		node->right = nullptr;
		node->data = key;
		node->priority = priority;
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

		// rotate the tree to fix the priorities.
		if (node->parent != nullptr) {
			moveUp(node);
		}
	}

	// split the tree into two trees
	void split(int x, Treap* t1, Treap* t2) {
		// insert a dummy node with lowest priority
		this->insert(x, -99);

		// this node is in the root node
		t1->root = this->root->left;
		t2->root = this->root->right;

		this->root->left = nullptr;
		this->root->right = nullptr;
		delete this->root;
		this->root = nullptr;
	}

	// merge trees t1 and t2
	void merge(Treap t1, Treap t2) {
		// find the largest node in t1
		NodePtr largest = t1.maximum(t1.root);
		// find the smallest node in t2
		NodePtr smallest = t2.minimum(t2.root);

		// create a dummy node
		NodePtr newRoot = new Node();
		newRoot->data = (largest->data + smallest->data) / 2;
		newRoot->left = t1.root;
		newRoot->right = t2.root;
		newRoot->parent = nullptr;
		newRoot->priority = 99;

		// move down the dummy node to the leaf node
		moveDown(newRoot);

		NodePtr currPtr = newRoot;
		while(currPtr->parent != nullptr) {
			currPtr = currPtr->parent;
		}

		this->root = currPtr;

		if (newRoot == newRoot->parent->left) {
			newRoot->parent->left = nullptr;
		} else {
			newRoot->parent->right = nullptr;
		}

		// delete the dummy node
		delete(newRoot);
		newRoot = nullptr;

	}

	NodePtr getRoot(){
		return this->root;
	}

	// delete the node from the tree
	void deleteNode(int data) {
		deleteNodeHelper(this->root, data);
	}

	// print the tree structure on the screen
	void prettyPrint() {
		printHelper(this->root, "", true);
	}

};

int main() {
	Treap bst;
	// test insert
	bst.insert(5, 0.30143);
	bst.insert(7, 0.47493);
	bst.insert(19, 0.54531);
	bst.insert(23, 0.46047);
	bst.insert(30, 0.73010);
	bst.insert(31, 0.28807);
	bst.insert(45, 0.99760);
	bst.insert(48, 0.51079);
	bst.insert(51, 0.98976);
	bst.insert(25, 0.22342);
	bst.prettyPrint();
	cout<<endl;
	bst.inorder();
	cout<<endl;

	// test delete
	bst.deleteNode(45);
	bst.prettyPrint();
	cout<<endl;
	bst.inorder();
	cout<<endl;

	// test split
	Treap t1, t2;
	bst.split(25, &t1, &t2);
	t1.prettyPrint();
	t2.prettyPrint();

	// test merge
	bst.merge(t1, t2);
	bst.prettyPrint();
	return 0;
}