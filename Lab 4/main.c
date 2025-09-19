#include <stdio.h>
#include "util.h"

int main(){
    int choice, fileflag = 0;
    FILE *shape;
    char ch;

    menu_start:
    reset_terminal();

    printf("Welcome to Shape Reader! Please make your choice to continue: \n");
    printf("1-) Generate a shape file\n");
    printf("2-) Read and draw a shape file\n");
    printf("3-) Terminate the program\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        shape = fopen("shape.txt", "w+");
        fileflag = 1;
        printf("File opened plase push any key.");
        scanf(" %c",&ch);
        getchar();
        goto menu_start;
        break;
    case 2:
        if(fileflag){
            int size;
            char shape_type;

            type_menu:
            printf("Please enter shape type (square: 's', tiangle: 't') and integer size (between 3 - 10) with seperated by commas: ");
            scanf(" %c,%d", &shape_type, &size);

            if (shape_type == 's'){
                draw_square(size, shape);
                scanf(" %c",&ch);
                getchar();
                reset_terminal();
                goto menu_start;
            }
            else if (shape_type == 't'){
                draw_triangle(size, shape);
                scanf(" %c",&ch);
                getchar();
                reset_terminal();
                goto menu_start;
            }
            else if (shape_type == 'e'){
                scanf(" %c",&ch);
                getchar();
                reset_terminal();
                goto menu_start;
            }
            else{
                printf("Wrong type!");
                scanf(" %c",&ch);
                getchar();
                reset_terminal();
                goto type_menu;
            }
            
        }
        else{
            printf("Plese open a file first!");
            scanf("%c",&ch);
            getchar();
            reset_terminal();
            goto menu_start;
        }
        break;
    case 3:
        return 0;
        break;
    default:
        break;
    }
}