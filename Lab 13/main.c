#include <stdio.h>
#include "util.h"

void reset_terminal(){
    printf("\033[2J");
    printf("\033[0;0f");
}

/*----- MAIN ------*/

int main(){
    struct BST* bst = generateBST("input.txt");

    /*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */

    int choice, value;
    struct Node* foundNode;

    menu:
    reset_terminal();
    printf("----- Menu -----\n");
    printf("1. Add a node\n");
    printf("2. Remove a node\n");
    printf("3. Search for a node\n");
    printf("4. Print the BST (Pre-order traversal)\n");
    printf("5. Count nodes\n");
    printf("6. Find max depth\n");
    printf("7. Count leaf nodes\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the value to add: ");
            scanf("%d", &value);
            addNode(bst, value);
            printf("Node added successfully.\n");
            while(getchar() == ' ');
            getchar();
            goto menu;
            break;
        case 2:
            printf("Enter the value to remove: ");
            scanf("%d", &value);
            removeNodeWrapper(bst, value);
            printf("Node removed successfully.\n");
            while(getchar() == ' ');
            getchar();
            goto menu;
            break;
        case 3:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            foundNode = searchNodeWrapper(bst, value);
            if (foundNode != NULL) 
            {
                printf("Node found!\n");
            } 
            else 
            {
                printf("Node not found.\n");
            }
            while(getchar() == ' ');
            getchar();
            goto menu;
            break;
        case 4:
            printf("Pre-order traversal:\n");
            printPreorderTraversal(bst->root);
            while(getchar() == ' ');
            getchar();
            goto menu;
            break;
        case 5:
            value = getCountNodes(bst);
            printf("%d", value);
            while(getchar() == ' ');
            getchar();
            goto menu;
            break;
        case 6:
            value = getMaxTreeDepth(bst);
            printf("%d", value);
            while(getchar() == ' ');
            getchar();
            goto menu;
            break;
        case 7:
            value = getCountLeafNodes(bst);
            printf("%d", value);
            while(getchar() == ' ');
            getchar();
            goto menu;
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
    free(bst);
}