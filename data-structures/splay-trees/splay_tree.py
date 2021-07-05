class Node:
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None


class SplayTree:
    def __init__(self):
        self.root = None

    def __print_helper(self, current, indent, last):
        # print the tree structure on the screen
        if current is not None:
            print(indent, end="")
            if last:
                print("R----", end="")
                indent += "     "
            else:
                print("L----", end="")
                indent += "|    "

            print(current.data)

            self.__print_helper(current.left, indent, False)
            self.__print_helper(current.right, indent, True)

    def __search_tree_helper(self, node, key):
        if node is None or key == node.data:
            return node

        if key < node.data:
            return self.__search_tree_helper(node.left, key)
        return self.__search_tree_helper(node.right, key)

    def __delete_node_helper(self, node, key):
        x = None
        while node is not None:
            if node.data == key:
                x = node

            if node.data <= key:
                node = node.right
            else:
                node = node.left

        if x is None:
            return

        # split operation
        self.__splay(x)
        if x.right is not None:
            t = x.right
            t.parent = None
        else:
            t = None

        s = x
        s.right = None

        # join operation
        if s.left is not None:
            s.left.parent = None

        self.root = self.__join(s.left, t)

    # rotate left at node x
    def __left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left is not None:
            y.left.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    # rotate right at node x
    def __right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right is not None:
            y.right.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y

        y.right = x
        x.parent = y

    # Splaying operation. It moves x to the root of the tree
    def __splay(self, x):
        while x.parent is not None:
            if x.parent.parent is None:
                if x == x.parent.left:
                    # zig rotation
                    self.__right_rotate(x.parent)
                else:
                    # zag rotation
                    self.__left_rotate(x.parent)
            elif x == x.parent.left and x.parent == x.parent.parent.left:
                # zig-zig rotation
                self.__right_rotate(x.parent.parent)
                self.__right_rotate(x.parent)
            elif x == x.parent.right and x.parent == x.parent.parent.right:
                # zag-zag rotation
                self.__left_rotate(x.parent.parent)
                self.__left_rotate(x.parent)
            elif x == x.parent.right and x.parent == x.parent.parent.left:
                # zig-zag rotation
                self.__left_rotate(x.parent)
                self.__right_rotate(x.parent)
            else:
                # zag-zig rotation
                self.__right_rotate(x.parent)
                self.__left_rotate(x.parent)

    # joins two trees s and t
    def __join(self, s, t):
        if s is None:
            return t

        if t is None:
            return s

        x = self.maximum(s)
        self.__splay(x)
        x.right = t
        t.parent = x
        return x

    def __pre_order_helper(self, node):
        if node is not None:
            print(node.data + " ")
            self.__pre_order_helper(node.left)
            self.__pre_order_helper(node.right)

    def __in_order_helper(self, node):
        if node is not None:
            self.__in_order_helper(node.left)
            print(node.data + " ")
            self.__in_order_helper(node.right)

    def __post_order_helper(self, node):
        if node is not None:
            self.__post_order_helper(node.left)
            self.__post_order_helper(node.right)
            print(node.data + " ")

    # Pre-Order traversal
    # Node->Left Subtree->Right Subtree
    def preorder(self):
        self.__pre_order_helper(self.root)

    # In-Order traversal
    # Left Subtree -> Node -> Right Subtree
    def inorder(self):
        self.__in_order_helper(self.root)

    # Post-Order traversal
    # Left Subtree -> Right Subtree -> Node
    def postorder(self):
        self.__post_order_helper(self.root)

    # search the tree for the key k
    # and return the corresponding node
    def search_tree(self, k):
        x = self.__search_tree_helper(self.root, k)
        if x is not None:
            self.__splay(x)

    # find the node with the minimum key
    def minimum(self, node):
        while node.left is not None:
            node = node.left
        return node

    # find the node with the maximum key
    def maximum(self, node):
        while node.right is not None:
            node = node.right
        return node

    # find the successor of a given node
    def successor(self, x):
        # if the right subtree is not null,
        # the successor is the leftmost node in the
        # right subtree
        if x.right is not None:
            return self.minimum(x.right)

        # else it is the lowest ancestor of x whose
        # left child is also an ancestor of x.
        y = x.parent
        while y is not None and x == y.right:
            x = y
            y = y.parent
        return y

    # find the predecessor of a given node
    def predecessor(self, x):
        # if the left subtree is not null,
        # the predecessor is the rightmost node in the
        # left subtree
        if x.left is not None:
            return self.maximum(x.left)

        y = x.parent
        while y is not None and x == y.left:
            x = y
            y = y.parent
        return y

    # insert the key to the tree in its appropriate position
    def insert(self, key):
        node = Node(key)
        y = None
        x = self.root

        while x is not None:
            y = x
            if node.data < x.data:
                x = x.left
            else:
                x = x.right

        # y is parent of x
        node.parent = y
        if y is None:
            self.root = node
        elif node.data < y.data:
            y.left = node
        else:
            y.right = node
        # splay the node
        self.__splay(node)

    # delete the node from the tree
    def delete_node(self, data):
        self.__delete_node_helper(self.root, data)

    # print the tree structure on the screen
    def pretty_print(self):
        self.__print_helper(self.root, "", True)


if __name__ == '__main__':
    tree = SplayTree()
    tree.insert(33)
    tree.insert(44)
    tree.insert(67)
    tree.insert(5)
    tree.insert(89)
    tree.insert(41)
    tree.insert(98)
    tree.insert(1)
    tree.pretty_print()
    tree.search_tree(33)
    tree.search_tree(44)
    tree.pretty_print()
    tree.delete_node(89)
    tree.delete_node(67)
    tree.delete_node(41)
    tree.delete_node(5)
    tree.pretty_print()
