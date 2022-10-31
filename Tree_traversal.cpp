 #include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left, *right;
};


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


void Preorder(struct Node *node)
{
    if (node == NULL)
        return;


    cout << node->data << " ";  
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct Node* node)
{
    if (node == NULL)
        return;

    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << " ";
}
void Inorder(struct Node* node)
{
    if (node == NULL)
        return;

    Inorder(node->left); 
    cout << node->data << " ";
    Inorder(node->right);
}
int main()
{
    struct Node *root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    cout << "\nPreorder traversal of binary tree is \n";
    Preorder(root);

    return 0;
}