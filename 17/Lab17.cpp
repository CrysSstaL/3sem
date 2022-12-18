//В качестве входной информации для следующих лабораторных работ  вводится символьная строка (бинарное дерево) с помощью линейно-скобочной записи. Например 8 (3 (1, 6 (4,7)), 10 (, 14(13,)))
//Что соответствует
//Структура бинарного дерева создается с помощь динамических переменных.
//Лаба №17 “Операции над БНП: поиск, добавление, удаление”
//Дерево вводится в программу в формате линейно-скобочной записи.
//Затем появляется меню, в котором доступна операция добавления, удаления и поиска вершины БДП.
//После выполнения операции программа должна возвращаться снова в меню.
//При выходе их него до завершения программы на экран должно быть выведено
//БДН любым способом (в виде линейно-скобочной записи или в графической форме).
#include <iostream>
#include "17.hpp" // делим по принципу ООП программу на 3 файла для удобства работы

int main(){
    std::string str = "8 (3 (1, 6 (4,7)), 10 (, 14(13,)))";
    T::Tree t1;  // дерево
    t1 = t1.parse(str); // записываем элементы строки
    T::Tree t2 = t1; // с помощью кнструктора копирования записываем 1 дерево во 2
    t2.remove(10); // удаление
    t2.write();
    return 0;
}