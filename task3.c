/* Задача 3. Числа в массив 
В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
Вывести массив по возрастанию в файл .txt. 

Данные на входе: Строка из английских букв, цифр и знаков препинания 
Данные на выходе: Последовательность целых чисел, отсортированная по возрастанию 
Пример 
Данные на входе: data 48 call 9 read13 blank0a 
Данные на выходе: 0 9 13 48
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(void)
{

    FILE *f_in, *f_out;

    char str[SIZE];
    int nums[SIZE];
    int index = 0;


    f_in = fopen("in.txt", "r");

   char c;
   int flag = 0, num = 0, order = 1;

    while ((c = fgetc(f_in)) != EOF)
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == ' ')
        {
            if (flag)
            {
                nums[index] = num;
                index++;
                flag = 0;
                num = 0;
                order = 1;
            }
        } 
        else if (c >= '0' && c <= '9')
        {
            num = num * order + (c - '0');
            order = 10;
            flag = 1;
        }
       
    }
    if (flag)
        nums[index] = num;

    fclose(f_in);
    
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if (nums[j] < nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    f_out = fopen("out.txt", "w");
    for (int i = 0; i < index; i++)
        fprintf(f_out, "%d ", nums[i]);
    
    fclose(f_out);
    return 0;
}
