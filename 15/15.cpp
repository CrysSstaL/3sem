#include "15.hpp"
namespace T{
    Elem* make(int data, Elem* p){ // дерево
        Elem* q = new Elem;
        q->data = data;
        q->left = nullptr;    // расписываем дерево
        q->right = nullptr;
        q->parent = p;
        return q;
    }

    void add(int data, Elem*& root){ // Добавить элемент в дерево
        if (root == nullptr){ // проверка на пустоту
            root = make(data, nullptr);
            return;
        }
        Elem* v = root;
        while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
            if (data < v->data){
                v = v->left;
            }
            else
                v = v->right;
        if (data == v->data)
            return;
        Elem* u = make(data, v);
        if (data < v->data){
            v->left = u;
        }
        else
            v->right = u;
    }

    void write(Elem* v){ // Вывести дерево
        if (v == nullptr) // проверка на пустоту
            return;
        write(v->left);
        std::cout << v->data << std::endl;
        write(v->right);
    }

    void center(Elem*& root){ // центральный обход
        if (root != nullptr){ //проверка на пустоту
            if (root->left != nullptr){ // проверка на пустоту
                center(root->left); // рекурскивный обход по дереву
            }
            std::cout << root->data << " ";
            if (root->right != nullptr){ // проверка на пустоту
                center(root->right); // рекурскивный обход по дереву
            }
        }
    }

    void straight(Elem*& root){ // прямой обход
        if (root == nullptr){  // проверка на пустоту
            return;
        }
        std::cout << root->data << " ";
        straight(root->left);    // рекурскивный обход по дереву
        straight(root->right);   // рекурскивный обход по дереву
    }

    void conc(Elem*& root){ // концевой обход
        if (root != nullptr){ //проверка на пустоту
            if (root->left != nullptr){ // проверка на пустоту
                conc(root->left); // рекурскивный обход по дереву
            }
            if (root->right != nullptr){ // проверка на пустоту
                conc(root->right);  // рекурскивный обход по дереву
            }
            std::cout << root->data << " ";
        }
    }


    Elem* search(int data, Elem* v){  // поиск элемента в дереве
        if (v == nullptr)
            return v;
        if (v->data == data)
            return v;
        if (data < v->data)
            return search(data, v->left); // рекурсия по дереву
        else
            return search(data, v->right); // рекурсия по дереву
    }


    void deletee(int data, Elem*& root){ // удалить элемент в дереве
        Elem* u = search(data, root);
        if (u == nullptr)
            return;

        if (u->left == nullptr && u->right == nullptr && u == root){ // если оба пустые
            delete root;
            root = nullptr;
            return;
        }

        if (u->left == nullptr && u->right != nullptr && u == root){ // левый пустой
            Elem* t = u->right;
            while (t->left != nullptr){
                t = t->left;
            }
            u->data = t->data;
            u = t;
        }

        if (u->left != nullptr && u->right == nullptr && u == root){ // правый пустой
            Elem* t = u->left;
            while (t->right != nullptr){
                t = t->right;
            }
            u->data = t->data;
            u = t;
        }

        if (u->left != nullptr && u->right != nullptr){  // оба не пустые
            Elem* t = u->right;
            while (t->left != nullptr){
                t = t->left;
            }
            u->data = t->data;
            u = t;
        }
        Elem* t;
        if (u->left == nullptr){
            t = u->right;
        }
        else
            t = u->left;
        if (u->parent->left == u){
            u->parent->left = t;
        }
        else
            u->parent->right = t;
        if (t != nullptr){
            t->parent = u->parent;
        }
        delete u;
    }

    void clear(Elem*& v) // очистить дерево
    {
        if (v == nullptr)
            return;
        clear(v->left);
        clear(v->right);
        delete v;
        v = nullptr;
    }

}