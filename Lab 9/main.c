#include <stdio.h>
#include <string.h>

/* ------------------ Helper Funcs ---------------------------- */

// Furniture Struct
struct Furniture {
    char name[50];
    char color[20];
    float price;
    int serial_number;
    int quantity;
};

// Reset terminal for cleaning
void reset_terminal(){
    printf("\033[2J");
    printf("\033[0;0f");
}

// Reads database and returns number of index
int read_database(struct Furniture* furniture_list) {
    // Open file 
    FILE* file;
    file = fopen("furniture_database.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    // While read is succeed keep going 
    int i = 0;
    while (fscanf(file, "%s %s %f %d %d", furniture_list[i].name, furniture_list[i].color, 
    &furniture_list[i].price, &furniture_list[i].serial_number, &furniture_list[i].quantity) == 5)     i++;
    
    fclose(file);
    return i;
}

void add_furniture(struct Furniture* furniture_list, int num_items) {
    // Open file
    FILE *file ;
    file = fopen("furniture_database.txt", "a");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    struct Furniture new_item;

    // Take new item from user
    printf("Enter the name of the new furniture item:\n");
    scanf("%s", &new_item.name);
    printf("Enter the color:\n");
    scanf("%s", &new_item.color);
    printf("Enter the price:\n");
    scanf("%f", &new_item.price);
    printf("Enter the serial number (6 digits):\n");
    scanf("%d", &new_item.serial_number);
    printf("Enter the quantity:\n");
    scanf("%d", &new_item.quantity);

    // Print and add new item
    fprintf(file, "\n%s %s %f %d %d", new_item.name, new_item.color, new_item.price, new_item.serial_number, new_item.quantity);
    furniture_list[num_items] = new_item;
    num_items++;
    printf("New item added successfully\n");

    fclose(file);
}

// Deletes database which u want
void delete_furniture(int delete){
    // Open files
    FILE *file ;
    file = fopen("furniture_database.txt", "r+");
    FILE *tempfile;
    tempfile = fopen("temp.txt", "w+");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    // Variables
    char name[50], color[20];
    int serial_number, quantity;
    float price;
    // Delete vaiables
    char del_name[50], del_color[20];
    int del_serial_number, del_quantity;
    float del_price;

    // Read and write to temp file until delete index
    for (int i = 0; i < delete - 1; i++)
    {
        fscanf(file, "%s %s %f %d %d", &name, &color, &price, &serial_number, &quantity);
        fprintf(tempfile, "%s %s %f %d %d\n", name, color, price, serial_number, quantity);
    }
    // In delete index just read dont write to temp file
    fscanf(file, "%s %s %f %d %d", &del_name, &del_color, &del_price, &del_serial_number, &del_quantity);
    // After keep going read and writing
    while (fscanf(file, "%s %s %f %d %d", &name, &color, &price, &serial_number, &quantity) == 5)
    {
        fprintf(tempfile, "%s %s %f %d %d\n", name, color, price, serial_number, quantity);
    }

    fclose(tempfile);
    tempfile = fopen("temp.txt", "r+");

    // Clear last empty line from new file for prevent any error
    FILE *tempdatabase;
    tempdatabase = fopen("tempdatabase.txt", "w+");

    fscanf(tempfile, "%s %s %f %d %d", &name, &color, &price, &serial_number, &quantity);
    fprintf(tempdatabase, "%s %s %f %d %d", name, color, price, serial_number, quantity);
    while (fscanf(tempfile, "%s %s %f %d %d", &name, &color, &price, &serial_number, &quantity) == 5)
    {   
        fprintf(tempdatabase, "\n%s %s %f %d %d", name, color, price, serial_number, quantity);
    }

    fclose(file);
    fclose(tempfile);
    fclose(tempdatabase);

    // Rename new file as products.txt and delete old one
    remove("furniture_database.txt");
    remove("temp.txt");
    rename("tempdatabase.txt", "furniture_database.txt");

    // Show to user that removed database
    printf("Following furniture is removed from the database:\n");
    printf("Name: %s\n", del_name);
    printf("Color: %s\n", del_color);
    printf("Price: %.2f\n", del_price);
    printf("Serial number: %d\n", del_serial_number);
    printf("Quantity: %d\n", del_quantity);

}

// Search database by name
void search_database_name(char find_name[]) {
    // Open file
    FILE* file;
    file = fopen("furniture_database.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char name[50], color[20];
    int serial_number, quantity;
    float price;

    // Read database
    while (fscanf(file, "%s %s %f %d %d", &name, &color, &price, &serial_number, &quantity) == 5){
        // If name and find name is same print to user
        if (strcmp(name, find_name) == 0)
        {
            printf("Name: %s\n", name);
            printf("Color: %s\n", color);
            printf("Price: %.2f\n", price);
            printf("Serial number: %d\n", serial_number);
            printf("Quantity: %d\n\n", quantity);
        }
        
    }
    
    fclose(file);
}

// Search database by color
void search_database_color(char find_color[]) {
    // Open file
    FILE* file;
    file = fopen("furniture_database.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char name[50], color[20];
    int serial_number, quantity;
    float price;

    // Read database
    while (fscanf(file, "%s %s %f %d %d", &name, &color, &price, &serial_number, &quantity) == 5){
        // If colors are same print to user
        if (strcmp(color, find_color) == 0)
        {
            printf("Name: %s\n", name);
            printf("Color: %s\n", color);
            printf("Price: %.2f\n", price);
            printf("Serial number: %d\n", serial_number);
            printf("Quantity: %d\n\n", quantity);
        }
        
    }
    
    fclose(file);
}

/*----- MAIN ------*/

int main(){
    // Variables
    int operation, search_operation;
    struct Furniture furniture_list[100];
    int furniture_number, delete;
    char color[20], name[50];

    // Main menu
    menu:
    reset_terminal();
    printf("Welcome to database of furniture shop\n");
    printf("1-See all furnitures\n2-Add a new furniture\n3-Remove furniture\n4-Search furniture\n5-Exit\n");
    scanf("%d", &operation);

    switch (operation)
    {
    case 1:
        reset_terminal();
        // Read database and print read furniture list
        furniture_number = read_database(furniture_list);
        for (int i = 0; i < furniture_number; i++) 
        {
        printf("Name: %s\nColor: %s\nPrice: %.2f\nSerial number: %d\nQuantity: %d\n\n",furniture_list[i].name, furniture_list[i].color, 
            furniture_list[i].price, furniture_list[i].serial_number, furniture_list[i].quantity);
        }
        while(getchar() == ' ');
        getchar();
        goto menu;
        break;
    case 2:
        // First read database to find item number then add furniture
        reset_terminal();
        furniture_number = read_database(furniture_list);
        add_furniture(furniture_list, furniture_number);
        while(getchar() == ' ');
        getchar();
        goto menu;
        break;
    case 3:
        // Take delete index from user and call delete function
        reset_terminal();
        printf("Enter the index of product you want remove: ");
        scanf("%d", &delete);
        delete_furniture(delete);
        while(getchar() == ' ');
        getchar();
        goto menu;
        break;
    case 4:
        // Take search filter from user and search
        search_menu:
        reset_terminal();
        printf("Select property to make search:\n1-Name\n2-Color\n");
        scanf("%d", &search_operation);

        switch (search_operation)
        {
        case 1:
            printf("Enter the name of product: ");
            scanf("%s", &name);
            search_database_name(name);
            break;
        case 2:
            printf("Enter the color of product: ");
            scanf("%s", &color);
            search_database_color(color);
            break;
        default:
            printf("Please enter valid operation!");
            while(getchar() == ' ');
            getchar();
            goto search_menu;
            break;
        }
        while(getchar() == ' ');
        getchar();
        goto menu;
        break;
    case 5:
        // Shut down
        return 0;
    default:
        // Give an error
        printf("Please enter valid operation!");
        while(getchar() == ' ');
        getchar();
        goto menu;
        break;
    }
}