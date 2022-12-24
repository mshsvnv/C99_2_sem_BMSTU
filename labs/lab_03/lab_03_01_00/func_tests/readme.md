# Тесты для лабораторной работы №02

## Входные данные

Натуральные числа: кол-во строк _rows_ и столбцов _columns_

## Выходные данные

Массив из натуральных чисел

## Позитивные тесты

- 01 - 1 <= _rows_, _columns_ <= 10, натуральные элементы матрицы; 
- 02 - 1 <= _rows_, _columns_ <= 10, целые отрицательные элементы матрицы; 
- 03 - 1 <= _rows_, _columns_ <= 10, в каждом столбце выполняется условие; 
- 04 - 1 <= _rows_, _columns_ <= 10, ни в одном столбце не выполняется условие; 
- 05 - 1 <= _rows_, _columns_ <= 10, матрица из одной строки;
## Негативные тесты

- 01 - _rows_ и _columns_ не числа, неверный тип данных; <br />
__Выходные данные__ : "ERROR: неверный тип входных данных", код завершения 1

- 02 - _rows_ и _columns_ > 10, неверный диапазон значений; <br />
__Выходные данные__ : "ERROR: неверный диапазон входных данных", код завершения 2

- 03 - элементы матрицы - не числа, неверный тип данных; <br /> 
__Выходные данные__ : "ERROR: неверный тип данных матрицы", код завершения 3

- 04 - _rows_ == 1, _columns_ >= 1 неверный диапазон значений; <br /> 
__Выходные данные__ : "ERROR: неверный диапазон входных данных", код завершения 2
