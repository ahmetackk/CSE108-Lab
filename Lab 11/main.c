#include <stdio.h>
#include "util.h"

/*----- MAIN ------*/

int main(){

    /* ------------------------------ Part 1 --------------------------------------- */
    printf("--- Part 1 ---\n");

    Order* queue = NULL;

    queue = enqueue(queue, "Baris Ozcan", 101, "Burger, Fries, Coke", "10:30");

    display(queue);

    queue = enqueue(queue, "Zehra Bilici", 102, "Pizza, Salad, Ice Cream", "11:15");

    display(queue);

    queue = enqueue(queue, "Mehmet Burak Koca", 103, "Steak, Mashed Potatoes, Salad", "12:00");

    display(queue);

    printf("Dequeque Operation: \n");
    queue = dequeue(queue);

    display(queue);

    updateOrder(queue, 102, "Pizza, Salad, Coke");

    display(queue);

    queue = dequeue(queue);

    display(queue);

    /* ------------------------------ Part 2 --------------------------------------- */
    printf("--- Part 2 ---\n");

    ExamPaper* stack = NULL; 

    stack = push(stack, "Zehra Bilici", 1, 90);

    display2(stack);

    stack = push(stack, "Baris Ozcan", 2, 85);

    display2(stack);

    stack = push(stack, "Mehmet Burak Koca", 3, 95);

    display2(stack);

    ExamPaper* popped = pop(stack);
    printf("Stack is popped.\n");
    printf("Student Name: %s, Student Number: %d, Score: %d\n\n", popped->studentName, popped->studentNumber, popped->score);
    
    display2(stack);

    isEmpty(stack);

    display2(stack);

    free(stack);
    free(queue);
}