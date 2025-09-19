#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "util.h"

/*-------------------------------- HELPER FUNCTIONS -------------------------------------------*/

float fahrenheit_to_celsius(float temperature){
    return  ((float)(5/9) * (temperature - 32.0));
}

float celsius_to_fahrenheit(float temperature){ 
    return ((temperature * (float)(9/5)) + 32.0);
}

// Clear terminal
void reset_terminal(){
    printf("\033[2J");  
    printf("\033[0;0f");
}

int reverse(int number){
    int remainder;
    int reversenumber = 0;

    while(number != 0)
    {
      remainder = number % 10;
      reversenumber = (reversenumber * 10) + remainder;
      number = number / 10;
   }

   return reversenumber;
}

// int convert_binary(int number){
//     int binary;
//     int i = 1;

//     while(number > 0)
//     {
//         binary = binary + ((number % 2) * i);
//         number =  number / 2;
//         i = i * 10;
//     }

//     return binary;
// }

int convert_binary(int number){
    int remainder, binary;
    int i = 1;

    while(number >= 1)
    {
        remainder = number % 2;
        number = (int)((int)(number - remainder) / 2);
        binary =  binary + (int)(remainder * i);
        i *= 10;
    }

    return binary;
}

int convert_octal(int number){
    int octal;
    int i = 1;
    
    while(number != 0)
    {
        octal = octal + (number % 8) * i;
        number = number / 8;
        i = i * 10;
    }

    return octal;
}


/*--------------------------------- MAIN FUNCTIONS ---------------------------------------*/

void temperature_converter(){
    int choice;
    float temp;

    menu_start:
    reset_terminal();
    printf("Temperature Conversion Menu\n\n");
    printf("1. Convert Celsius to Fahrenheit\n\n");
    printf("2. Conver Fahrenheit to Celsius\n\n");
    printf("3. Quit\n\n");
    printf("Enter your choice (1-3): ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter temperature value to convert: ");
        scanf("%f", &temp);
        printf("\n%.2f Celsius = %.2f Fahrenheit", temp, celsius_to_fahrenheit(temp));
        while (getchar() != '\n');
        getchar();
        goto menu_start;
        break;
    case 2:
        printf("Enter temperature value to convert: ");
        scanf("%f", &temp);
        printf("\n%.2f Celsius = %.2f Fahrenheit", temp, fahrenheit_to_celsius(temp));
        while (getchar() != '\n');
        getchar();
        goto menu_start;
        break;
    case 3:
        return 0;
        break;
    default:
        printf("Wrong choice!");
        while (getchar() != '\n');
        getchar();
        goto menu_start;
        break;
    }
}

void number_reverse(){
    int number;
    printf("Enter a number (3, 4 or 5): ");
    scanf("%d", &number);

    printf("Reversed number: %d", reverse(number));
}

void number_converter(){
    int choice, number;

    menu_start:
    reset_terminal();
    printf("Menu\n\n");
    printf("1. Convert a number to decimal, binary, octal, and hexadecimal\n\n");
    printf("2. Quit\n\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nEnter a number: ");
        scanf("%d", &number);
        printf("Decimal equivalent: %d", number);
        printf("\nBinary equivalent: %d", convert_binary(number));
        printf("\nOctal equivalent: %d", convert_octal(number));
        printf("\nHexadecimal equivalent: %X", number);
        while(getchar() != '\n');
        getchar();
        goto menu_start;
        break;
    case 2:
        return 0;
        break;
    default:
        printf("Wrong choice!");
        while (getchar() != '\n');
        getchar();
        goto menu_start;
        break;
    }
}