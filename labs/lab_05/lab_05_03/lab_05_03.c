/*
Целочисленный тип : int;

Алгоритм сортировки : сортировка выбором;

Особенности реализации : на каждой итерации с помощью функции get_number_by_pos
получаем значение первого элемента в неотсортированной части файла. Затем проходим по 
оставшейся части файла и находим минимальное число, при этом запоминаем его индекс, 
чтобы в дальнейшем поменять числа местами c помощью функции put_number_by_pos. 
Упорядочивание чисел идет по возрастанию;

get_number_by_pos : в качестве пареметров передается файловая переменная и конкретная 
позиция в файле. Считывает и возвращает число, расположенное на указанной позиции;

put_number_by_pos : в качестве пареметров передается файловая переменная, конкретная 
позиция в файле и число, которое необходимо записать на указанную позициюю. Записывает
переданное число на указанную позицию; 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "essential_funcs.h"
#include "specific_funcs.h"

int main(int argc, char **argv)
{
    int rc;

    if (argc > 4 || argc < 3)
    {
        return ARGS_AMOUNT_ERROR;
    }
    
    if (argc == 4)
    {
        if (strcmp(argv[1], "c") == 0)
        {
            if (correct_number(argv[2]) == SUCCESS)
            {
                rc = create_file(atoi(argv[2]), argv[3]);
            }
            else if (correct_number(argv[3]) == SUCCESS)
            {
                rc = create_file(atoi(argv[3]), argv[2]);
            }
            else
            {
                return INCORRECT_ARGS_ERROR;
            }
        }
        else if (strcmp(argv[2], "c") == 0)
        {
            if (correct_number(argv[1]) == SUCCESS)
            {
                rc = create_file(atoi(argv[1]), argv[3]);
            }
            else if (correct_number(argv[3]) == SUCCESS)
            {
                rc = create_file(atoi(argv[3]), argv[1]);
            }
            else
            {
                return INCORRECT_ARGS_ERROR;
            }  
        }
        else if (strcmp(argv[3], "c") == 0)
        {
            if (correct_number(argv[1]) == SUCCESS)
            {
                rc = create_file(atoi(argv[1]), argv[2]);
            }
            else if (correct_number(argv[2]) == SUCCESS)
            {
                rc = create_file(atoi(argv[2]), argv[1]);
            }
            else
            {
                return INCORRECT_ARGS_ERROR;
            }
        }
        else
        {
            return INCORRECT_ARGS_ERROR;
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "p") == 0)
        {
            rc = print_file(argv[2]);
        }
        else if (strcmp(argv[1], "s") == 0)
        {
            rc = sort_file(argv[2]);
        }
        else
        {
            return INCORRECT_ARGS_ERROR;
        }
    }

    return rc;
}

