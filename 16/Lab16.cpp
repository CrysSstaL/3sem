//В качестве входной информации для следующих лабораторных работ  вводится символьная строка (бинарное дерево) с помощью линейно-скобочной записи. Например 8 (3 (1, 6 (4,7)), 10 (, 14(13,)))
//Что соответствует
//Структура бинарного дерева создается с помощь динамических переменных.
//Лаба №16 “Не рекурсивный прямой обход” (реализуется с помощью стека).
//В качестве выходных данных формируется строка обхода. Например:
//Бинарное дерево поиска
#include <iostream>
#include "16.hpp" // делим по принципу ООП программу на 3 файла для удобства работы

int main()
{
    T::Elem* root = nullptr; // создаём нулевое дерево
    int N = 10; // количество чисел в дереве
    int mas[] = {1, 5, 23, 4, 6, 9, 1, 17, 7, 31};
    for (int i = 0; i < N; i++)
    {
        T::add(mas[i], root); // добавляем каждый элемент в дерево
    }
    T::write(root);
    T::straight_no_rec(root); //Не рекурсивный обход, через стэк
    T::clear(root); // чистим память
    return 0;
}