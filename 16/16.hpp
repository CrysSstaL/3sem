#include <iostream>
#include <stack>

namespace T{ // задаем пространство имен
    struct Elem{;  // создаем структуру дерева
        int data;
        Elem* left;
        Elem* right;
        Elem* parent;
    };
    Elem* make(int data, Elem* p);
    void add(int data, Elem*& root);
    void write(Elem* v);
    Elem* search(int data, Elem* v);
    void deletee(int data, Elem*& root);
    void clear(Elem*& v);
    void straight_no_rec(Elem*& root); // Не рекурсивный прямой обход(стек)
}