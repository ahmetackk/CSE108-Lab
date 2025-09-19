#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR_LENGTH 100
#define MAX_ARRAY_LENGTH 100

typedef struct{
    struct Customer *prev;
    char name[MAX_CHAR_LENGTH];
    int age;
    int priority;
    char priority_group_name[MAX_CHAR_LENGTH];
    struct Customer *next;
}Customer;

void reset_terminal(){
    printf("\033[2J");
    printf("\033[0;0f");
}

Customer* readCustomersFromFile(Customer *customers) {
    FILE *file = fopen("customers.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char name[MAX_CHAR_LENGTH];
    int age;
    int priority;
    char priority_group_name[MAX_CHAR_LENGTH];

    while (fscanf(file, "%s %d %s %d", &name, &age, &priority_group_name ,&priority) == 4){
        Customer* new_customer = (Customer*)malloc(sizeof(Customer));
        strcpy(new_customer->name, name);
        strcpy(new_customer->priority_group_name, priority_group_name);
        new_customer->priority = priority;
        new_customer->age = age;
        new_customer->next = NULL;

        if (customers == NULL)
        {   
            new_customer->prev = NULL;
            customers = new_customer;
        } 
        else 
        {
            Customer* temp = customers;
            while (temp->next != NULL) temp = temp->next;
            new_customer->prev = temp;
            temp->next = new_customer;
        }
        customers = customers->next;
    }

    fclose(file);

    return customers;
}

void writeCustomersToFile(Customer *customers) {
    FILE *file = fopen("customers.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (customers != NULL)
    {
        fprintf(file, "%s %d %s %d", customers->name, customers->age, customers->priority_group_name ,customers->priority);
        customers = customers->next;
    }

    fclose(file);
}

Customer* insertCustomer(Customer *customers, char *name, int age, int priority){
    Customer* new_customer = (Customer*)malloc(sizeof(Customer));
    strcpy(new_customer->name, name);
    new_customer->priority = priority;
    new_customer->age = age;
    new_customer->next = NULL;
    switch (priority)
    {
    case 1:
        strcpy(new_customer->priority_group_name, "NORMAL");
        break;
    case 2:
        strcpy(new_customer->priority_group_name, "VETERAN");
        break;
    case 3:
        strcpy(new_customer->priority_group_name, "OD");
        break;
    case 4:
        strcpy(new_customer->priority_group_name, "VIP");
        break;
    default:
        break;
    }

    if (customers == NULL)
    {   
        new_customer->prev = NULL;
        customers = new_customer;
    } 
    else 
    {
        Customer* temp = customers;
        while (temp->next != NULL) temp = temp->next;
        new_customer->prev = temp;
        temp->next = new_customer;
    }
    return customers;
}

Customer* removeCustomer(Customer *customers, char *name){
    
    int found = 0;
    while (customers != NULL)
    {
        if (strcmp(customers->name, name) == 0)
        {   
            Customer* temp = customers;
            found = 1;
            customers = customers->prev;
            customers->next = temp->next;
            customers = customers->next;
            customers = customers->next;
            customers->prev = temp->prev;
        }
        customers = customers->next;
    }

    if(found) printf("Customer '%s' removed from the queue.\n", name);
    else printf("Customer '%s' not found in the queue.\n", name);

    return customers;
}

void displayCustomers(Customer* customers){
    printf("Customers in order of priorities:\n");
    int i = 1;
    while (customers != NULL)
    {
        printf("%d. %s -Age:%d -Priority Group: %s -Priority Level:%d\n", 
                    i, customers->name, customers->age, 
                        customers->priority_group_name, customers->priority);
        customers = customers->next;
        i++;
    }

}

void searchCustomer(Customer* customers, char *name){
    if (strcmp(customers->name, name) == 0) {
        printf("Found: %s -Age:%d -Priority Group: %s -Priority Level:%d\n", 
                    customers->name, customers->age, customers->priority_group_name, customers->priority);
        return;
    }
    return searchCustomer(customers->next, name);
}

void changePriority(Customer* customers, char *name, int newPriority){
    int found = 0;
    while (customers != NULL)
    {
       if (strcmp(customers->name, name) == 0){
            found = 1;
            customers->priority = newPriority;
            switch (newPriority)
            {
            case 1:
                strcpy(customers->priority_group_name, "NORMAL");
                break;
            case 2:
                strcpy(customers->priority_group_name, "VETERAN");
                break;
            case 3:
                strcpy(customers->priority_group_name, "OD");
                break;
            case 4:
                strcpy(customers->priority_group_name, "VIP");
                break;
            default:
                break;
            }
            break;
        }
        customers = customers->next;
    }
    if (found) {
        printf("Priority of customer '%s' changed to %d.\n", name, newPriority);
    } else {
        printf("Customer '%s' not found in the queue.\n", name);
    }
}

/*----- MAIN ------*/

int main(){
    Customer* customers = NULL;
    // customers = readCustomersFromFile(customers);

    int choice;
    char name[MAX_CHAR_LENGTH];
    int age;
    int priority;
    char priority_group_name[MAX_CHAR_LENGTH];
    menu:
    reset_terminal();
    printf("1. Insert new customer\n");
    printf("2. Remove customer\n");
    printf("3. Display customers in order\n");
    printf("4. Search for a customer\n");
    printf("5. Change customer priority\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("---\n");
    switch (choice){
        case 1:
            printf("Enter customers name: ");
            scanf("%s", name);
            printf("Enter customers age: ");
            scanf("%d", &age);
            printf("Enter customer priority: ");
            scanf("%d", &priority);

            customers = insertCustomer(customers, name, age, priority);
            writeCustomersToFile(customers);
            while(getchar() == ' ');
            getchar();
            goto menu;
        case 2:
            printf("Enter customer name to remove: ");
            scanf("%s", name);
            customers = removeCustomer(customers, name);
            writeCustomersToFile(customers);
            while(getchar() == ' ');
            getchar();
            goto menu;
        case 3:
            displayCustomers(customers);
            while(getchar() == ' ');
            getchar();
            goto menu;
        case 4:
            printf("Enter customer name to search: ");
            scanf("%s", name);
            searchCustomer(customers, name);
            while(getchar() == ' ');
            getchar();
            goto menu;
        case 5:
            printf("Enter customer name to change priority: ");
            scanf("%s", name);
            printf("Enter new priority: ");
            scanf("%d", &priority);
            changePriority(customers, name, priority);
            writeCustomersToFile(customers);
            while(getchar() == ' ');
            getchar();
            goto menu;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    free(customers);

    return 0;
}