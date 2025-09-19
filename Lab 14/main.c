#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Order {
    char* customerName;
    int orderID;
    char* items;
    time_t orderTime;
    struct Order* next;
} Order;

void enqueue(Order** list, char* customerName, int orderID, char* items, time_t orderTime){
    Order* newNode = (Order*)malloc(sizeof(Order));
    strcpy(newNode->customerName, customerName);
    newNode->orderID = orderID;
    strcpy(newNode->items, items);
    newNode->orderTime = orderTime;
    newNode->next = NULL;

    if (*list == NULL)
    {
        *list = newNode;
    } 
    else
    {
        Order* current = *list;
        while (current->next != NULL) current = current->next;
        current->next = newNode;
    }
}

Order* dequeue(Order** list, time_t thresholdTime){

    if (*list == NULL) return NULL;

    Order* oldestOrder = *list;
    Order* previous = NULL;
    Order* current = *list;

    while (current != NULL && current->orderTime <= thresholdTime)
    {
        if (current->orderTime < oldestOrder->orderTime) oldestOrder = current;

        previous = current;
        current = current->next;
        free(previous->customerName);
        free(previous->items);
        free(previous);
    }

    if (oldestOrder == *list)
    {
        *list = current;
    } 
    else
    {
        previous->next = current;
    }

    return oldestOrder;
}

void freeOrders(Order* list){
    Order* current = list;
    while (current != NULL)
    {
        Order* temp = current;
        current = current->next;
        free(temp->customerName);
        free(temp->items);
        free(temp);
    }
}

/*----- MAIN ------*/

int main(){
     Order* orderList = NULL;

    // Adding orders
    enqueue(&orderList, "John Doe", 1001, "Shirt, Pants", time(NULL) - 10000);
    enqueue(&orderList, "Jane Smith", 1002, "Dress, Shoes", time(NULL) - 5000);
    enqueue(&orderList, "Bob Johnson", 1003, "Hat, Socks", time(NULL));

    // Displaying orders
    displayOrders(orderList);

    // Dequeue orders older than the threshold time
    time_t thresholdTime = time(NULL) - 7000;
    Order* oldestOrder = dequeue(&orderList, thresholdTime);
    printf("Oldest Order:\n");
    if (oldestOrder != NULL) {
        printf("Customer Name: %s\n", oldestOrder->customerName);
        printf("Order ID: %d\n", oldestOrder->orderID);
        printf("Items: %s\n", oldestOrder->items);
        printf("Order Time: %s", ctime(&oldestOrder->orderTime));
        freeOrderNode(oldestOrder);
    } else {
        printf("No orders older than the threshold.\n");
    }

    // Displaying updated orders
    displayOrders(orderList);

    // Freeing memory
    freeOrders(orderList);

    return 0;

}