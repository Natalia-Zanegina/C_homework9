/* Задача 1. По одному разу 
В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
Найдите только те символы слов, которые встречаются в обоих словах только один раз.
Напечатайте их через пробел в файл .txt в лексикографическом порядке. 
Данные на входе: Два слова из маленьких английских букв через пробел. Длина каждого слова не больше 100 символов. 
Данные на выходе: Маленькие английские буквы через пробел. 
Пример № 1 
Данные на входе: hello world 
Данные на выходе: o 
Данные на входе: aabcd bcef 
Данные на выходе: b c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100
#define COUNT 2

int main(void)
{
    
    FILE *f_in, *f_out;

    f_in = fopen("in.txt", "r");
    
    char words[COUNT][SIZE];

    for (int i = 0; i < COUNT; i++)
        fscanf(f_in, "%s", words[i]);
           
    fclose(f_in);

    int len1 = strlen(words[0]), len2 = strlen(words[1]);

    char res[SIZE];
    int index = 0;
    for (int i = 0; i < len1; i++)
    {
        int count = 0;
        for (int j = 0; j < len2; j++)
        {
            if (words[0][i] == words[1][j])
                count++;
        }
    
        if (count == 1)
        {
            res[index] = words[0][i];
            index++;    
        }
          
    }

    size_t res_len = sizeof(res); 

    for (size_t i = 0; i < res_len - 1; i++)
    {
        int count = 0;
        for (size_t j = i+1; j < res_len - 1; j++)
        {
            if (res[i] == res[j])
            {
                count++;
                res[j] = NULL;
            }
        }
        if (count)
            res[i] = NULL;
    }

    for (size_t i = 0; i < res_len - 1; i++)
    {
        
        for (size_t j = i + 1; j < res_len; j++)
        {
            if (res[j] < res[i])
            {
                char temp = res[i];
                res[i] = res[j];
                res[j] = temp;
            }
        }  
    }

    f_out = fopen("out.txt", "w");
    for (int i = 0; i < res_len; i++)
    {
        if (res[i] != NULL)
            fprintf(f_out, "%c ", res[i]);
    }
    fclose(f_out);   
}