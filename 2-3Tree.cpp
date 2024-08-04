// Name: Lawrence Menegus
// Date: 1/4/23 
// Course: Data Structures and Algorithms
// Description: This program will create a 2-3 Binary tree and add the various numbers to the 2-3 tree then search
// for a specific value in the search tree and print out the result of the tree. 

#include <iostream>

using namespace std;

// Struct for the 2-3 Binary Tree
struct Node {
    int small;
    int large;
    Node* left;
    Node* middle;
    Node* right;
};

// Function Phototypes
void inOrder(Node* tree);
Node* findItem(Node* tree, int target);
Node* insert(Node* tree, int value);

int main() {

    // Declareling then
    Node* root = nullptr;

    // Array of values 
    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160};

    // Inserts the array values into the 2-3 tree
    for (int i = 0; i < 16; i++) 
    {
        root = insert(root, numbers[i]);
    }

    // Prints out the inorder Traversal 
    cout << "Part 1: In-order traversal" << endl;
    inOrder(root);

    // Sets Values to search in 2-3 Tree
    cout << "\n\nPart 2: Find item" << endl;
    int target[] = { 50, 100, 75 }; 
    
   
    for (int i = 0; i < 3; i++)
    {
        // Finds the item in the 2-3 Binary Tree
        Node* newish = findItem(root, target[i]);

        cout << "\nSearch " << target[i] << endl;

        // If the node is found it prints out the following
        if (newish)
        {
            cout << "Item was found" << endl;
        }
        else
        {
            cout << "Item Not found." << endl;
        }

    }

    return 0;
}

// The Inorder Traverse Function
void inOrder(Node* tree)
{
    // If the tree is not empty
    if (tree)
    {
        // Traverse the left subtree first
        inOrder(tree->left);

        // Print the value in the "small" field of the current node
        cout << tree->small << " ";

        // If the "large" field is not -1, print its value as well
        if (tree->large != -1)
        {
            cout << tree->large << " ";
        }

        // Traverse the middle subtree
        inOrder(tree->middle);

        // Traverse the right subtree
        inOrder(tree->right);
    }
}

// Function to find an item with a specific target value in the tree
Node* findItem(Node* tree, int target)
{
    // If the tree is empty, return nullptr
    if (tree == nullptr)
    {
        return nullptr;
    }

    // If the "small" field of the current node matches the target, return the node
    if (tree->small == target)
    {
        return tree;
    }
    // If the "large" field is not -1 and matches the target, return the node
    else if (tree->large != -1 && tree->large == target)
    {
        return tree;
    }
    // If the target is less than the "small" value, search in the left subtree
    else if (target < tree->small)
    {
        return findItem(tree->left, target);
    }
    // If the "large" field is -1 or the target is less than the "large" value, search in the middle subtree
    else if (tree->large == -1 || target < tree->large)
    {
        return findItem(tree->middle, target);
    }
    // Otherwise, search in the right subtree
    else
    {
        return findItem(tree->right, target);
    }
}

// Function to create a new node with the given values
Node* createNode(int small, int large = -1)
{
    // Allocate memory for a new node and initialize its fields
    Node* newNode = new Node;
    newNode->small = small;
    newNode->large = large;
    newNode->left = newNode->middle = newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the tree
Node* insert(Node* tree, int value)
{
    // If the tree is empty, create a new node with the value
    if (tree == nullptr)
    {
        return createNode(value);
    }

    // If the "large" field is -1, handle the insertion logic for a two-value node
    if (tree->large == -1)
    {
        // If the value is smaller than the "small" value, update the "large" and "small" fields accordingly
        if (value < tree->small)
        {
            tree->large = tree->small;
            tree->small = value;
        }
        // If the value is larger than the "small" value, set it as the "large" value
        else if (value > tree->small)
        {
            tree->large = value;
        }
    }
    // If the "large" field is not -1, insert the value into the appropriate subtree
    else if (value < tree->small)
    {
        tree->left = insert(tree->left, value);
    }
    else if (tree->large == -1 || value < tree->large)
    {
        tree->middle = insert(tree->middle, value);
    }
    else
    {
        tree->right = insert(tree->right, value);
    }

    // Return the updated tree
    return tree;
}