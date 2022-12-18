#include <iostream>

namespace T{  // задаем пространство имен
    struct Elem{; // задаем структуру дерева
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
    void center(Elem*& root); // центральный обход
    void straight(Elem*& root); // прямой обход
    void conc(Elem*& root); // концевой обход
}