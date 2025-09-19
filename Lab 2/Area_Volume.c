#include <stdio.h>
#include <math.h>
#define Pi 3.14   /* Pi constant */

void area_volume_calc(){

    /* User input variables */
    float cube_edgelen, rect_sidelen, rect_sidewidth, rect_sideheight, sphere_radius, cone_radius, cone_height;

    /* Take cube edge length */
    printf("Enter the edge length for cube: ");
    scanf("%f", &cube_edgelen);

    /* Calculate for cube */
    double cube_surfarea = 6 * pow(cube_edgelen, 2);    // A = 6 * a^2
    double cube_vol = pow(cube_edgelen, 3);             // V = a^3
    printf("\nSurface Area = %.2f, Volume = %.2f\n", cube_surfarea, cube_vol);

    /* Take rectangles edges lengths*/
    printf("\nEnter side length for rectangular prism: ");
    scanf("%f", &rect_sidelen);

    printf("\nEnter side width: ");
    scanf("%f", &rect_sidewidth);

    printf("\nEnter side height: ");
    scanf("%f", &rect_sideheight);

    /* Calculate for rectangle */
    // A = 2 * ( a.b + b.c + a.c )
    double rect_surfarea = 2 * ((rect_sidelen * rect_sidewidth) + (rect_sidewidth * rect_sideheight) + (rect_sidelen * rect_sideheight));
    double rect_vol = rect_sidelen * rect_sidewidth * rect_sideheight;    // V = a.b.c
    printf("\nSurface Area = %.2f, Volume = %.2f\n", rect_surfarea, rect_vol);

    /* Take sphere radius */
    printf("\nEnter the radius for sphere: ");
    scanf("%f", &sphere_radius);

    /* Calculate for sphere */
    double sphere_surfarea = 4 * Pi * pow(sphere_radius, 2);    // A = 4πr²
    double sphere_vol = (4 * Pi * pow(sphere_radius, 3)) / 3;   // V = (4/3)πr³
    printf("\nSurface Area = %.2f, Volume = %.2f\n", sphere_surfarea, sphere_vol);

    /* Take cone radius and height */
    printf("\nEnter the radius for cone: ");
    scanf("%f", &cone_radius);

    printf("\nEnter the height: ");
    scanf("%f", &cone_height);

    /* Calculate for cone */
    // A = πr (b + r) [b = √(r^2 + h^2)]
    double cone_sufarea = Pi * cone_radius * (sqrt(pow(cone_radius, 2) + pow(cone_height, 2)) + cone_radius);
    double cone_vol =  (Pi * pow(cone_radius, 2) * cone_height) / 3;    // V = (1/3)πr^2h
    printf("\nSurface Area = %.2f, Volume = %.2f\n", cone_sufarea, cone_vol);

}

void body_mass_index(){
    /* Variables */
    float height, bmi;
    int weight;

    printf("Welcome to the BMI Calculator\n");

    /* Take weight */
    printf("Please enter your weight in kg: ");
    scanf("%d", &weight);

    /* Take height */
    printf("\nPlease enter your height in m: ");
    scanf("%f", &height);

    /* Calculate IBM */
    bmi = weight / pow(height, 2);
    printf("\nYour BMI: %.1f\n", bmi);

    /*
    •BMI less than 18.5:underweight
    •BMI between 18.5 and 24.9: average weight
    •BMI between 25 and 29.9: overweight
    •BMI of 30 or greater: obese
    */
    if(bmi >= 30){
        printf("You are obese.");
    }
    else if(bmi < 18.5){
        printf("You have underweight.");
    }
    else if (bmi < 25){
        printf("You have average weight.");
    }
    else{
        printf("You have overweight.");
    }
    
}

int main(){
    area_volume_calc();
    body_mass_index();
}