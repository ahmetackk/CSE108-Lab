#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"

/*-------------------------------- HELPER FUNCTIONS -------------------------------------------*/

void draw_space(int a, FILE *file){
    for (int i = 0; i < a; i++)
    {   
        fprintf(file ," ");
        printf(" ");
    }
}

void draw_star(int a, FILE *file){
    for (int i = 0; i < a; i++)
    {   
        fprintf(file ,"*");
        printf("*");
    }   
}

void skip_line(FILE *file){
    fprintf(file ,"\n");
    printf("\n");
}

void draw_line(int a, FILE *file){
    for (int i = 0; i < a; i++){
        printf("* ");
        fprintf(file ,"* ");
    }
    skip_line(file);
}

void reset_terminal(){
    printf("\033[2J");  
    printf("\033[0;0f");
}

/*--------------------------------- MAIN FUNCTIONS ---------------------------------------*/

void draw_triangle(int a, FILE *file){

    int base = (2 * a) - 1;

    draw_space(2 * (a - 1), file);
    draw_star(1, file);
    skip_line(file);

    for(int i = 0; i < a - 2; i++){
        draw_space(2 * ( a - (i + 2)), file);
        draw_star(1, file);
        draw_space(2 * ((2 * i) + 1) + 1, file);
        draw_star(1, file);
        draw_space(2 * ( a - (i + 2)), file);
        skip_line(file);
    }

    draw_line(base, file);
    skip_line(file);
   
}

void draw_square(int a, FILE *file){

    draw_line(a, file);

    for (int i = 0; i < a - 2; i++){
        draw_star(1, file);
        draw_space(2 * (a - 2) + 1, file);
        draw_star(1, file);
        skip_line(file);
    }
    
    draw_line(a, file);
}



