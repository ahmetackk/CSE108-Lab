#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"

/*-------------------------------- HELPER FUNCTIONS -------------------------------------------*/

// Read numbers from user for part 1
void read_numbers(int array[]){
    // Variables
    int num;
    int i = 0;

    // First of all empty array
    for (int j = 0; j < 20; j++)
    {
        array[j] = 0;
    }
    
    // Take first number
    scanf("%d", &num);

    // While number is not -100 keep taking numbers
    while (num != -100)
    {   
        array[i] = num;
        i++;
        scanf("%d", &num);
    }
    
}

// Find numbers are even or odd for part 1
void odd_even(int array[], char array2[]){

    // Look every index of integer array
    for (int i = 0; i < 20; i++)
    {   
        // If arrays index is not empty
        if (array[i] != 0)
        {
            // If 2 mod is equal to 0 then number is even
            if (array[i] % 2 == 0)
            {
                array2[i] = 'e';
            }
            // If 2 mod is equal to 1 then number is odd
            else if (array[i] % 2 == 1)
            {
                array2[i] = 'o';
            }
        }
        // If arrays index is empty then just blank
        else
        {
            array2[i] = ' ';
        }
    }

}

// Printing array for part 1
void print_array(int array[], char array2[]){

    // For every index of integer array
    for (int i = 0; i < 20; i++)
    {   
        // If arrays index is not empty print it
        if (array[i] != 0)
        {
            printf("%d  ", array[i]);
            printf("%c\n", array2[i]);
        }
    }
    
}


/*--------------------------------- MAIN FUNCTIONS ---------------------------------------*/

// Part 1
void part_1(){

    // Variables
    int arr1[20]; 
    char arr2[20] = " ";
    int i = 0;

    // Call in order of read, find even or odd, print
    read_numbers(arr1);
    odd_even(arr1, arr2);
    
    printf("\n");

    print_array(arr1, arr2);

}

void part_2(){
    // Variables
    char selectedteam, readteam, occupation;
    int tablerows, age, salary_number = 0;
    float salary, avarage_salary;

    // File variable
    FILE *table;
    table = fopen("table.txt", "r");

    //If file cant opened exit
    if (table == NULL) {
        printf("File cannot opened!\n");
        exit(0);
    }

    // Take team from user
    printf("Please select a team: ");
    scanf(" %c", &selectedteam);

    // First of all read table row
    fscanf(table, " %d", &tablerows);

    // For table row times read data
    for (int i = 0; i < tablerows; i++)
    {
        fscanf(table, "%d %c %f %c", &age, &occupation, &salary, &readteam);
        // If read team is selected team then add its salary to avarage
        if (readteam == selectedteam)
        {
            salary_number++;
            avarage_salary = ((avarage_salary * (salary_number - 1)) + salary) / salary_number;
        }
    }

    // If there is not salary 
    if (salary_number == 0)
    {
        printf("There are no fans of %c in the database!", selectedteam);
    }
    // If there is salary
    else
    {
        printf("Average salaries of fans of f: %.1f", avarage_salary);
    }
    // Close file
    fclose(table);
}

