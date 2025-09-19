#ifndef _UTIL_H_
#define _UTIL_H_

typedef struct {
    char* customerName;
    int orderID;
    char* items;
    time_t orderTime;
    struct Order* next;
} Order;


#endif /* _UTIL_H_ */