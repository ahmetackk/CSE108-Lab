#ifndef _UTIL_H_
#define _UTIL_H_

typedef struct Order {
    int orderID;
    char customername[100];
    char items[100];
    char ordertime[100];
    struct Order* next;
} Order;

typedef struct ExamPaper {
    char *studentName;
    int studentNumber;
    int score;
    struct ExamPaper *next;
} ExamPaper;

Order* enqueue(Order* queue, char* customername, int orderID, char* items, char* ordertime);

Order* dequeue(Order* queue);

void display(Order* queue);

void updateOrder(Order* queue, int orderID, char* newItems);

ExamPaper* push(ExamPaper* stack, char *studentName, int studentNumber, int score);

ExamPaper* pop(ExamPaper* stack);

int isEmpty(ExamPaper* stack);

void display2(ExamPaper* stack);

#endif /* _UTIL_H_ */