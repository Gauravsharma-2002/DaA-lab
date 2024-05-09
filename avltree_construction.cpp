#include <iostream>
using namespace std;
// Definition of a node in AVL tree
struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;
};
// Function to create a new node with given data
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->height = 1;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
// Function to get height of a node
int getHeight(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}
// Function to calculate balance factor of a node
int getBalanceFactor(Node *node)
{
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
// Function to right rotate subtree rooted with y
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    // Return new root
    return x;
}
// Function to left rotate subtree rooted with x
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    // Return new root
    return y;
}
// Function to insert a node into AVL tree
Node *insert(Node *root, int data)
{
    // Perform normal BST insertion
    if (root == nullptr)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else // Duplicate keys not allowed
        return root;
    // Update height of current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // Get balance factor of this node
    int balance = getBalanceFactor(root);
    // If node becomes unbalanced, there are 4 cases
    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);
    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);
    // Left Right Case
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // Return the (unchanged) root pointer
    return root;
}
// Function to print AVL tree in inorder traversal
void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " (Balance Factor: " << getBalanceFactor(root) << ")" << endl;
        inorderTraversal(root->right);
    }
}
int main()
{
    int elements[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90};
    Node *root = nullptr;
    // Construct AVL tree from the given set of elements
    for (int element : elements)
    {
        root = insert(root, element);
    }
    // Print AVL tree with balance factors
    cout << "AVL Tree with Balance Factors:" << endl;
    inorderTraversal(root);
    return 0;
}
