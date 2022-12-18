#include "17.hpp"
namespace T
{
    Tree::Tree(const int v, Tree* p){ //конструктор класса дерева
        value = v;
        parent = p;
    }
    Tree::Tree() {} //переопределение конструктора
    Tree::Tree(std::string str){ // для переприсовения строки
        string = str;
    }

    void Tree::add(const int v){ // добавить элемент в дерево
        if (v >= value){
            if (right == nullptr){
                right = new Tree(v, this);
            }
            else{
                right->add(v);
            }
        }
        else{
            if (left == nullptr){
                left = new Tree(v, this);
            }
            else{
                left->add(v);
            }
        }
    }

    Tree* Tree::Search(int v){
        return search(this, v);
    }

    Tree* Tree::search(Tree* item, int v){ // поиск поддерева по элементу
        if (item == nullptr || item->value == v){
            return item;
        }
        if (item != nullptr && item->value > v){
            return search(item->left, v);
        }
        if (item != nullptr && item->value < v){
            return search(item->right, v);
        }
    }

    void Tree::remove(int value){
        Tree* item = this->Search(value);
        if (item == nullptr) return;
        Tree* cTree = nullptr;
        // удаляем корень
        if (this == item){
            if (item->right != nullptr){
                cTree = item->right;
                while (cTree->left != nullptr){
                    cTree = cTree->left;
                }
            }
            else if (item->left != nullptr){
                cTree = item->left;
                while (cTree->right != nullptr){
                    cTree = cTree->right;
                }
            }
            int val = cTree->value;
            remove(val);
            item->value = val;
        }
            // удаление листьев
        else if (item->left == nullptr && item->right == nullptr && item->parent != nullptr){
            if (item->parent->right == item){
                item->parent->right = nullptr;
            }
            else{
                item->parent->left = nullptr;
            }
        }
            // удаление всех возможных вариантных исходов
            // те 1)левый 2)правый 3)левый и правый
            // удаление узла, который имеет левого потомка
        else if (item->left != nullptr && item->right == nullptr && item->parent != nullptr){
            item->left->parent = item->parent;
            if (item == item->parent->left){
                *item->parent->left = *item->left;
            }
            else if (item == item->parent->right){
                *item->parent->right = *item->left;
            }
        }
            // удаление узла, который имеет правого потомка
        else if (item->left == nullptr && item->right != nullptr && item->parent != nullptr){
            item->right->parent = item->parent;
            if (item == item->parent->left){
                *item->parent->left = *item->right;
            }
            else if (item == item->parent->right){
                *item->parent->right = *item->right;
            }
        }
            // удаление узла, который имеет оба потомка
        else if (item->left != nullptr && item->right != nullptr && item->parent != nullptr){
            cTree = item->right;
            if (cTree->left != nullptr){
                while (cTree->left != nullptr){
                    cTree = cTree->left;
                }
                if (cTree->right != nullptr){
                    cTree->right->parent = cTree->parent;
                    cTree->parent->left = cTree->right;
                }
                else{
                    cTree->parent->left = nullptr;
                }
                item->left->parent = cTree;
                cTree->left = item->left;
                if (item->parent->right == item){
                    cTree->parent = item->parent->right;
                    item->parent->right = cTree;
                }
                else{
                    cTree->parent = item->parent->left;
                    item->parent->left = cTree;
                }
                cTree->right = item->right;
                item->right->parent = cTree;
            }
            else{
                item->left->parent = cTree;
                cTree->left = item->left;
                cTree->parent = item->parent;
                if (item->parent->left == item){
                    item->parent->left = cTree;
                }
                else{
                    item->parent->right = cTree;
                }
            }
        }
    }
    std::string  Tree::toString(int value){ // переводит число в строку
        std::string result;
        if (value > 9){
            result += char(value / 10 + 48);
            result += char(value % 10 + 48);
        }
        else{
            result += char(value + 48);
        }
        return result;
    }
    void  Tree::print(Tree* tree){ // разворачиваем дерево в строчную запись
        string += toString(tree->value);
        if (tree->left != nullptr || tree->right != nullptr){
            string += '(';
            if (tree->left != nullptr){
                print(tree->left);
            }
            string += ',';
            if (tree->right != nullptr){
                print(tree->right);
            }
            string += ')';
        }
    }

    void  Tree::write(){ // вывод всех элементов
        print(this);
        for (const auto& elem : string){
            std::cout << elem;
        }
    }

    bool Tree::isdig(const char elem) { // проверка на число
        if (elem >= '0' && elem <= '9'){
        return true;
        }
        else{
            return false;
        }
    }

    Tree  Tree::parse(std::string str){ // берем за основу 2 лабораторную работу
        Tree result;                    // для разбиения строки и проверки на числа и скобки
        int index;
        if (isdig(str[0]) && isdig(str[1])){
            int val = (str[0] - 48) * 10 + str[1] - 48;
            result.value = val;
            index = 2;
        }
        else if (isdig(str[0]) && !isdig(str[1])){
            int val = str[0] - 48;
            result.value = val;
            index = 1;
        }
        for (int i = index; i < str.size() - 1;){
            if (isdig(str[i]) && isdig(str[i + 1])){
                int value = (str[i] - 48) * 10 + str[i + 1] - 48;
                result.add(value);
                i += 2;
            }
            else if (isdig(str[i]) && !isdig(str[i + 1])){
                int value = str[i] - 48;
                result.add(value);
                i++;
            }
            else{
                i++;
            }
        }
        return result;
    }
}