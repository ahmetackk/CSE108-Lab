#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "util.h"

/*-------------------------------- HELPER FUNCTIONS -------------------------------------------*/

void filter_text(char s[], char filter[], char filtered_text[]){

    int mode, mode_index;
    int filter_index = -1;

    for (int i = 0; i < strlen(filter); i++)
    {
        if (filter[i] == '*')
        {
            mode = 1;
            mode_index = i;
        }
        if (filter[i] == '?')
        {
            mode = 2;
            mode_index = i;
        }
    }
    

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == filter[0])
        {
            if (mode == 2)
            {
                for (int j = 0; j < strlen(filter); j++)
                {
                    if (j != mode_index)
                    {
                        if (s[i + j] == filter[j])
                        {
                            filter_index = i;
                        }
                        else filter_index = -1;
                    }
                    
                }
            }
            else{
                int k = 0;
                int fl, ll;
                while (s[i + k] == ' ')
                {
                    k++;
                }
                
                for (int l = 0; l < k; l++)
                {
                    if (s[i + l] == filter[0])
                    {
                        fl = l;
                    }
                    if (s[i + l] == filter[2])
                    {
                        ll = l;
                    }
                }
                if (fl < ll)
                {
                    filter_index = i;
                }
            }
        }
    }

    int filter_index_end = filter_index;
    while (s[filter_index_end] != ' ')
    {
        filter_index_end++;
    }

    // filter_index - i
    for (int i = 0; i < strlen(s); i++)
    {   
        if (i < filter_index)
        {
            filtered_text[i] = s[i];
        }
        else filtered_text[i] = s[i + (filter_index_end - filter_index)]; 
    }
    

}

void swap(int *a , int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void foo_min_max(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    printf("Min: %d, Max: %d", arr[0], arr[n - 1]);
}



/*--------------------------------- MAIN FUNCTIONS ---------------------------------------*/

void part1(){
    char letter_array[20];
    char letters[26];
    int letters_frequence[26];

    for (int i = 0; i < 26; i++)
    {
        letters_frequence[i] = 0;
    }
    

    printf("Please enter any lowercase letters: ");
    scanf("%s", &letter_array);

    int j = 1, n = 0;
    
    for (int i = 0; i < 20; i++)
    {   
        if(letter_array[i] != '\0')
        {
            for (int k = 0; k < j; k++)
            {
                if (letters[k] == letter_array[i])
                {
                    letters_frequence[k]++;
                    n = 1;
                }
                else n = 0;
            }
            if (n == 0)
            {
                letters[j - 1] = letter_array[i];
                letters_frequence[j - 1]++;
                j++;
            }
            
        }
        
    }

    printf("%c %d, %c %d",letters[0],letters_frequence[0],letters[1],letters_frequence[1]);
    
}

void part2(){
    char s[] = "As a noble person, I want to solve this novel problem on my own." ;
    char filtered_text[strlen(s)];

    char f1[] = "o*e";
    char f2[] = "no?el";

     
    filter_text(s, f1, filtered_text);  

    printf("%s", filtered_text);

    filter_text(s, f2, filtered_text);

    printf("%s", filtered_text);
}

void part3(){
    int arraysize;

    printf("Enter array size: ");
    scanf("%d", &arraysize);

    int array[arraysize];

    for (int i = 0; i < arraysize; i++)
    {
        printf("Enter %d. item: ", i + 1);
        scanf("%d", &array[i]);
    }
    
    foo_min_max(array, arraysize);


}
