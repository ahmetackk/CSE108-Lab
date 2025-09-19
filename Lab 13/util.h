#ifndef _UTIL_H_
#define _UTIL_H_

struct Node {
    double value;
    struct Node* left;
    struct Node* right;
};

struct BST {
    struct Node* root;
};

void addNode(struct BST* bst, int value);

void removeNodeWrapper(struct BST* bst, int value);

struct Node* searchNodeWrapper(struct BST* bst, int value);

struct BST* generateBST(const char* filename);

void printPreorderTraversal(struct Node* node);

int getCountNodes(struct BST* bst);

int getMaxTreeDepth(struct BST* bst);

int getCountLeafNodes(struct BST* bst);

#endif /* _UTIL_H_ */