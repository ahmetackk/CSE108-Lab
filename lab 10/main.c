#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

typedef struct {
    int ID;
    int age;
    float gpa;
} Student;

int findmin(int* array, int size) {
    int min = array[0];

    for (int i = 1; i < size; i++){
        if (array[i] < min){
            min = array[i];
        }
    }

    return min;
}

int* createarr(int size){
    int* array = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    return array;
}

float calculateaverageGPA(Student* students, int size) {
    float totalGPA = 0.0;

    for (int i = 0; i < size; i++){
        totalGPA += students[i].gpa;
    }

    return totalGPA / size;
}

float createstudentarray(){
    Student* students = (Student*)malloc(sizeof(Student) * ARRAY_SIZE);

    for (int j = 0; j < ARRAY_SIZE; j++){
        students[j].ID = j + 1;
        students[j].age = rand() % 25 + 18;  
        students[j].gpa = (float)(rand() % 40 + 1) / 10.0 ;
    }   

    float totalGPA = 0.0;

    for (int i = 0; i < ARRAY_SIZE; i++){
        totalGPA += students[i].gpa;
    }

    float averageGPA = totalGPA / ARRAY_SIZE;
    
    free(students);

    return averageGPA;
}
/*----- MAIN ------*/

int main(){
    /* ----------------------------------- Part 1 ----------------------------------*/
    int size1;
    printf("---Part1---\nEnter the size of the array: ");
    scanf("%d", &size1);

    int* array1 = createarr(size1);

    int min = findmin(array1, size1);
    printf("Minimum value: %d\n", min);

    /* ----------------------------------- Part 2 ----------------------------------*/
    int size2;
    printf("---Part2---\nEnter the size of the array: ");
    scanf("%d", &size2);
    
    int* array2 = createarr(size2);
    int* cumulativearray = (int*)calloc(size2, sizeof(int));

    cumulativearray[0] = array2[0];  

    for (int i = 1; i < size2; i++){
        cumulativearray[i] = cumulativearray[i - 1] + array2[i];  
    }

    printf("First array: ");
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\nSecond array (cumulative sum): ");
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", cumulativearray[i]);
    }

    /* ----------------------------------- Part 3 ----------------------------------*/
    float totalaverageGPA = 0.0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        srand(time(NULL));
        totalaverageGPA += createstudentarray();
    }

    float allaverageGPA = totalaverageGPA / ARRAY_SIZE;
    printf("\n---Part3---\nAverage GPA of 10.000 x 10.0000 students: %.1f\n", allaverageGPA);
}