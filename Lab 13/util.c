#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"

// ----------------------------- Part 1 -----------------

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct Node* node, int value){
    if (value < node->value) 
    {
        if (node->left == NULL) 
        {
            node->left = createNode(value);
        } 
        else 
        {
            insertNode(node->left, value);
        }
    } 
    else if (value > node->value) 
    {
        if (node->right == NULL) 
        {
            node->right = createNode(value);
        } 
        else 
        {
            insertNode(node->right, value);
        }
    }
}

struct BST* generateBST(const char* filename) 
{
    struct BST* bst = (struct BST*)malloc(sizeof(struct BST));
    bst->root = NULL;

    FILE* file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return bst;
    }

    double value;
    fscanf(file, "%lf", &value);
    bst->root = createNode(value);

    while (fscanf(file, "%lf", &value) == 1) 
    {
        insertNode(bst->root, value);
    }

    fclose(file);
    return bst;
}

// ---------------------------- Part 2 ----------------------------

void addNode(struct BST* bst, int value) {
    if (bst->root == NULL) 
    {
        bst->root = createNode(value);
    } 
    else 
    {
        insertNode(bst->root, value);
    }
}

struct Node* findMinvalueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct Node* removeNode(struct Node* root, int value) {
    if (root == NULL) 
    {
        return root;
    }

    if (value < root->value) 
    {
        root->left = removeNode(root->left, value);
    } 
    else if (value > root->value) 
    {
        root->right = removeNode(root->right, value);
    } 
    else 
    {
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* minNode = findMinvalueNode(root->right);
        root->value = minNode->value;
        root->right = removeNode(root->right, minNode->value);
    }
    return root;
}

void removeNodeWrapper(struct BST* bst, int value) 
{
    bst->root = removeNode(bst->root, value);
}

struct Node* searchNode(struct Node* node, int value) 
{
    if (node == NULL || node->value == value) {
        return node;
    }

    if (value < node->value) {
        return searchNode(node->left, value);
    } else {
        return searchNode(node->right, value);
    }
}

struct Node* searchNodeWrapper(struct BST* bst, int value) 
{
    return searchNode(bst->root, value);
}



// ------------------------- Part 3 -----------------------------------

int countNodes(struct Node* node) {
    if (node == NULL) 
    {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int getCountNodes(struct BST* bst) 
{
    return countNodes(bst->root);
}

int getMaxDepth(struct Node* node) 
{
    if (node == NULL) 
    {
        return 0;
    }
    int leftDepth = getMaxDepth(node->left);
    int rightDepth = getMaxDepth(node->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int getMaxTreeDepth(struct BST* bst) 
{
    return getMaxDepth(bst->root);
}

int countLeafNodes(struct Node* node) 
{
    if (node == NULL) 
    {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) 
    {
        return 1;
    }
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int getCountLeafNodes(struct BST* bst) 
{
    return countLeafNodes(bst->root);
}

void printPreorderTraversal(struct Node* node) {
    if (node != NULL) 
    {
        printf("%.1f ", node->value);
        printPreorderTraversal(node->left);
        printPreorderTraversal(node->right);
    }
}

