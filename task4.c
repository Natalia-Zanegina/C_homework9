/* Задача 4. Удалить повторяющиеся символы 
В файле .txt строка из маленьких и больших английских букв, знаков препинания и пробелов.
Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл .txt. 
Данные на входе: Строка из маленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 символов. 
Данные на выходе: Строка из маленьких и больших английских букв. 
Пример 
Данные на входе: abc cde def 
Данные на выходе: abcdef
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000

int main(void)
{
    
    FILE *f_in, *f_out;
    char c, i = 0;
    char letters[SIZE];

    f_in = fopen("in.txt", "r");

    while ((c = fgetc(f_in)) != EOF)
    { 
        if (c != ' ' && strchr(letters, c) == 0)
        {
            letters[i] = c; 
            i++;
        }
    }
    fclose(f_in);

    f_out = fopen("out.txt", "w");
    fputs(letters, f_out);
    fclose(f_out);
}