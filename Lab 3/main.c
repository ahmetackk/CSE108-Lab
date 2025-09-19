#include <stdio.h>

/*-------------------------------------HELPER FUNCTIONS------------------------------------------*/

void swap(int *a, int *b)
{   
    /* Swap numbers for use in find_median()*/
    int temp = *a;
    *a = *b;
    *b = temp;    
}

const char* letter_grade(int a)
{   
    /* Return letter grades by scores for use grading_system()*/
    /*  90-100%: A+
        80-89%: A
        70-79%: B+
        60-69%: B
        50-59%: C
        40-49%: D
        Below 40%: F */
    if (a <= 100 && a >= 90)
    {
        return "A+";
    }
    else if (a <= 89 && a >= 80)
    {
        return "A";
    }
    else if (a <= 79 && a >= 70)
    {
        return "B+";
    }
    else if (a <= 69 && a >= 60)
    {
        return "B";
    }
    else if (a <= 59 && a >= 50)
    {
        return "C";
    }
    else if (a <= 49 && a >= 40)
    {
        return "D";
    }
    else
    {
        return "F";
    }
}

/*--------------------------------------MAIN FUNCTIONS-----------------------------------------*/

void find_median()
{   
    /* Variables */
    int num1, num2, num3;
    /* Take numbers from user */
    printf("Enter 3 integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    /* Sort numbers by magnitude */
    if(num1 > num2)
    {
        if (num1 > num3)
        {
            swap(&num1, &num3);
            if (num1 > num2)
            {
                swap(&num1, &num2);
            }
            
        }
        else
        {
            swap(&num1, &num2);
        }
    }
    else
    {
        if(num2 > num3)
        {
            swap(&num2, &num3);
            if(num1 > num2)
            {
                swap(&num1, &num2);
            }
        }
    }
    /* Print median number */
    printf("Median number is %d", num2);
}

void grading_system()
{
    /* Variables*/
    int score1, score2, score3;
    /* Take scores from user */
    printf("Enter your scores: ");
    scanf("%d %d %d", &score1, &score2, &score3);

    /* Average score calculate */
    float average = (float)(score1 + score2 + score3) / 3;
    /* Print result */
    // For find letter grades of scores used letter_grade() funtion from HELPER FUNCTIONS
    printf("Your letter grades are %s, %s and %s with %.1f average", letter_grade(score1), letter_grade(score2), letter_grade(score3), average);

}

void arithmetic_test()
{   
    /* Variables */
    char operate;
    int number1, number2;
    float result, answer;
    /* Take operate */
    printf("Enter an arithmetic operation (+, -, *, /): ");
    scanf("%c", &operate);
    /* Take numbers from user */
    printf("Enter two numbers: ");
    scanf("%d %d", &number1, &number2);
    /* Switch operate for correct calculate */
    switch (operate)
    {
    case '+':
        result = number1 + number2;
        break;
    case '-':
        result = number1 - number2;
        break;
    case '*':
        result = number1 * number2;
        break;
    case '/':
        result = (float)(number1 / number2);
        break;
    default:
        printf("Wrong operate");
        break;
    }

    /* Take answer for result from user*/
    printf("\nResult: ");
    scanf("%f", &answer);
    /* Check answer */
    if (answer == result)
    {   // If answer is correct
        printf("\nBravo, correct answer!");
    }
    else
    {   // If answer is wrong
        printf("\nWrong answer, try again.");
    }

}

int main()
{
    find_median();
    grading_system();
    arithmetic_test();
}