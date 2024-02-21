/* Задача 5. Самое длинное слово 
В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать. 
Данные на входе: Строка из английских букв и пробелов. Не более 1000 символов. 
Данные на выходе: Одно слово из английских букв. 
Пример 
Данные на входе: Hello beautiful world 
Данные на выходе: beautiful
*/
#include <stdio.h>
#include <string.h>

#define SIZE 1000

int main(void)
{
    FILE *f_in, *f_out;

    char str[SIZE];
    char str_max[SIZE];

    f_in = fopen("in.txt", "r");

    int max = 0;

    while (fscanf(f_in, "%s", str) == 1)
    {
        if (strlen(str) > max)
        {
            max = strlen(str);
            strcpy(str_max, str);  
        }       
    }
           
    fclose(f_in);

    f_out = fopen("out.txt", "w");
    fputs(str_max, f_out);
    fclose(f_out); 

    return 0;
}

