#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

/*-------------------------------- Part 1 -------------------------------------------*/

Order* enqueue(Order* queue, char* customername, int orderID, char* items, char* ordertime){

    Order* new_order = (Order*)malloc(sizeof(Order));
    strcpy(new_order->customername, customername);
    new_order->orderID = orderID;
    strcpy(new_order->items, items);
    strcpy(new_order->ordertime, ordertime);
    new_order->next = NULL;

    if (queue == NULL)
    {
        queue = new_order;
    } 
    else 
    {
        Order* temp = queue;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new_order;
    }

    printf("Enqueued:  Order ID: %d, Customer Name: %s, Items: %s\n\n", orderID, customername, items);

    return queue;
}


Order* dequeue(Order* queue){

    if (queue == NULL) return NULL;
    Order* temp = queue;

    queue = queue->next;

    free(temp);

    return queue;
}

void display(Order* queue){

    if (queue == NULL)
    {
        printf("Queue is empty.\n\n");
    } 
    else 
    {
        printf("Display Orders:\n");
        Order* temp = queue;

        while (temp != NULL)
        {
            printf("- Order ID: %d, Customer Name: %s, Items: %s\n", temp->orderID, temp->customername, temp->items);
            temp = temp->next;
        }
        printf("\n");
    }
}

void updateOrder(Order* queue, int orderID, char* newItems){
    Order* temp = queue;

    while (temp != NULL)
    {
        if (temp->orderID == orderID)
        {
            strcpy(temp->items, newItems);
            printf("Updated Order: Order ID: %d, Customer Name: %s, Items: %s\n\n", temp->orderID, temp->customername, temp->items);
            return;
        }
        temp = temp->next;
    }
}

/*--------------------------------- Part 2 ---------------------------------------*/

ExamPaper* push(ExamPaper* stack, char *studentName, int studentNumber, int score){
    
    ExamPaper* newExamPaper = (ExamPaper*)malloc(sizeof(ExamPaper));
    newExamPaper->studentName = studentName;
    newExamPaper->studentNumber = studentNumber;
    newExamPaper->score = score;
    newExamPaper->next = NULL;

    printf("Exam Paper Added: Student Name: %s, Student Number: %d, Score: %d\n\n", studentName, studentNumber, score);

    if (stack == NULL)
    {
        return newExamPaper;
    } 
    else
    {
        newExamPaper->next = stack;
        return newExamPaper;
    }
}

ExamPaper* pop(ExamPaper* stack){
    if (stack == NULL)
    {
        printf("Stack is empty.\n");
        return NULL;
    } 
    else
    {   
        ExamPaper* paper = stack;
        ExamPaper* temp = stack;
        ExamPaper* prev;
        while (stack->next != NULL)
        {   
            temp = temp->next;
            if (temp->next == NULL)
            {
                stack->next = NULL;
            }
            else
            {
                stack = stack->next;
            }
        }
        
        return paper;
    }
}

int isEmpty(ExamPaper* stack) {
    if (stack == NULL)
    {
        printf("Stack is empty.\n\n");
        return 1;
    }
    else
    {
        printf("Stack is not empty.\n\n");
        return 0;
    }
}

void display2(ExamPaper* stack) {
    if (stack == NULL)
    {
        printf("Stack is empty.\n");
    } 
    else
    {
        ExamPaper* current = stack;
        printf("Exam Papers in Stack:\n");
        while (current != NULL)
        {
            printf("Student Name: %s, Student Number: %d, Score: %d\n", current->studentName, current->studentNumber, current->score);
            current = current->next;
        }
        printf("\n");
    }
}

void freeStack(ExamPaper* stack){
    ExamPaper* current = stack;
    while (current != NULL)
    {
        ExamPaper* temp = current;
        current = current->next;
        free(temp);
    }
}