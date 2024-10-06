#include <stdio.h>
#include <stdlib.h>

// Define the structure for the nodes in the BST
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) 
        return createNode(data);

    // Otherwise, recursively insert the data
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// Function to perform in-order traversal of the BST
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int nodes[] = {50, 30, 20, 40, 70, 60, 80, 35, 55, 75};  // 10 node values

    // Insert nodes into the BST
    for (int i = 0; i < 10; i++) {
        root = insert(root, nodes[i]);
    }

    // Print in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inOrder(root);
    printf("\n");
    getch();
    return 0;
}
