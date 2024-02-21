/* Задача 6. Заканчивается на a 
В файле .txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. Ответ записать в файл .txt. 
Данные на входе: Строка из английских букв и пробелов не более 1000 символов. 
Данные на выходе: Одно целое число 
Пример 
Данные на входе: Mama mila ramu 
Данные на выходе: 2
*/
#include <stdio.h>
#include <string.h>

#define SIZE 1000

int main(void)
{
    FILE *f_in, *f_out;

    char str[SIZE];
    int index = 0, count = 0;

    f_in = fopen("in.txt", "r");

    int max = 0;

    while (fscanf(f_in, "%s", str) == 1)
    {
        index++;
        int len = strlen(str);
        if (str[len - 1] == 'a')
            count++;    
    }
           
    fclose(f_in);

    f_out = fopen("out.txt", "w");
    fprintf(f_out, "%d", count);
    fclose(f_out);

    return 0;
}