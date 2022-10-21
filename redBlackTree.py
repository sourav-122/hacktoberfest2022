


class Color:
    RED = 1
    BLACK = 2

class Node:

    def __init__(self, data, parent=None, color=Color.RED) -> None:
        self.data = data
        self.left_node =None
        self.right_node = None
        self.parent = parent
        self.color = color

class RedBlackTree:

    def __init__(self) -> None:
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self.insert_node(data, self.root)

    def insert_node(self, data, node):
        if data < node.data:
            if node.left_node:
                self.insert_node(data, node.left_node)
            else:
                node.left_node = Node(data, node)
                self.settle_violation(node.left_node)
        else:
            if node.right_node:
                self.insert_node(data, node.right_node)
            else:
                node.right_node = Node(data, node)
                self.settle_violation(node.right_node)

    def traverse(self):

        if self.root:
            self.in_order_traversal(self.root)

    def in_order_traversal(self, node):

        if node.left:
            self.in_order_traversal(node.left)

        print(node.data)

        if node.right:
            self.in_order_traversal(node.right)

    
    def rotate_right(self, node):

        temp_left_node = node.left_node
        t = temp_left_node.right_node

        node.left_node = t
        temp_left_node.right_node = node

        if t is not None:
            t.parent = node
        
        temp_parent = node.parent
        node.parent = temp_left_node
        temp_left_node.parent = temp_parent

        if temp_left_node.parent is not None and temp_left_node.parent.left_node == node:
            temp_left_node.parent.left_node = temp_left_node

        if temp_left_node.parent is not None and temp_left_node.parent.right_node == node:
            temp_left_node.parent.right_node = temp_left_node


        if node == self.root:
            self.root = temp_left_node

    def rotate_left(self, node):

        temp_right_node = node.right_node
        t = temp_right_node.left_node

        node.right_node = t
        temp_right_node.left_node = node

        if t is not None:
            t.parent = node
        
        temp_parent = node.parent
        node.parent = temp_right_node
        temp_right_node.parent = temp_parent

        if temp_right_node.parent is not None and temp_right_node.parent.left_node == node:
            temp_right_node.parent.left_node = temp_right_node

        if temp_right_node.parent is not None and temp_right_node.parent.right_node == node:
            temp_right_node.parent.right_node = temp_right_node


        if node == self.root:
            self.root = temp_right_node


    def settle_violation(self,node):
        pass

    def is_red(self, node):

        if node is None:
            return False

        else:
            return node.color == Color.RED

