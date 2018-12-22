#ifndef EVYATAR_GENERIC_TREE_TREE_H
#define EVYATAR_GENERIC_TREE_TREE_H

#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>
class Tree {
public:
    Tree();
    void insert(T data);
    void print();

    Node<T> *search(T value);
    Node<T> *min();
    Node<T> *max();
    void remove(T* data);
    void clear();
    virtual ~Tree();
    int numOfNodes();

private:
    Node<T> * insert(T data, Node<T> *cur);
    void print(Node<T> *cur);
    Node<T> *search(T value, Node<T> *cur);
    Node<T> *min(Node<T> *cur);
    Node<T> *max(Node<T> *cur);
    Node<T> * remove(T data, Node<T> *root);
    Node<T> *getFather(Node<T> *son, Node<T> *cur);
    void clear(Node<T> *cur);
    int numOfNodes(Node<T> *cur);

protected:
    Node<T> *root;
};

template<typename T>
void Tree<T>::insert(T data) {
    root = insert(data, root);
}

template<typename T>
Node<T>* Tree<T>::insert(T data, Node<T> *cur) {
    if (!cur) {
        return new Node<T>(data);
    }
    if (*data > *(cur->getData())) {
        cur->setRight(insert(data, cur->getRight()));
    } else if (*data < *(cur->getData())) {
        cur->setLeft(insert(data, cur->getLeft()));
    } else {
        delete cur->getData();
        cur->setData(data);
    }
    return cur;

}

template<typename T>
Tree<T>::Tree(): root(NULL) {}

template<typename T>
void Tree<T>::print() {
    print(root);
}

template<typename T>
void Tree<T>::print(Node<T> *cur) {
    if (!cur) {
        return;
    }
    print(cur->getLeft());
    cout << *(cur->getData()) << endl;
    print(cur->getRight());
}

template<typename T>
Node<T> *Tree<T>::min() {
    return min(root);
}

template<typename T>
Node<T> *Tree<T>::search(T value) {
    return search(value, root);
}

template<typename T>
Node<T> *Tree<T>::search(T value, Node<T> *cur) {
    if (!cur) {
        return NULL;
    }
    if (*(cur->getData()) == value) {
        return cur;
    }
    if (value > *(cur->getData())) {
        return search(value, cur->getRight());
    } else {
        return search(value, cur->getLeft());
    }
}

template<typename T>
Node<T> *Tree<T>::min(Node<T> *cur) {
    if (cur->getLeft() == NULL) {
        return cur;
    }
    return cur->getLeft();
}

template<typename T>
Node<T> *Tree<T>::max() {
    return max(root);
}

template<typename T>
Node<T> *Tree<T>::max(Node<T> *cur) {
    if (cur->getRight() == NULL) {
        return cur;
    }
    return cur->getRight();
}

template<typename T>
void Tree<T>::remove(T* data) {
    root = remove(data, root);
}

template<typename T>
Node<T>* Tree<T>::remove(T data, Node<T> *root) {
    Node<T>* toRemove = search(*data, root);

    if (toRemove == NULL) {
        return root;
    }

    if (toRemove->isLeaf()) {
        Node<T>* father = getFather(toRemove, root);
        if (father == NULL) {
            delete toRemove;
            return NULL;
        }
        if (father->getRight() == toRemove) {
            father->setRight(NULL);
        } else {
            father->setLeft(NULL);
        }
        delete toRemove;
        return root;
    }
    if (toRemove->numOfKids() == 1) {
        Node<T>* father = getFather(toRemove, root);
        if (father == NULL) {
            Node<T> *newSon = toRemove->getOnlySon();
            delete toRemove;
            return newSon;
        }
        father->getRight() == toRemove ? father->setRight(toRemove->getOnlySon()) : father->setLeft(toRemove->getOnlySon());
        return root;
    }

    Node<T>* successor = min(toRemove->getRight());
    T *temp = toRemove->getData();
    toRemove->setData(successor->getData());
    successor->setData(temp);
    toRemove->setRight(remove(data, toRemove->getRight()));
    return root;
}

template<typename T>
Node<T> *Tree<T>::getFather(Node<T> *son, Node<T> *cur) {
    if (!cur || cur->isLeaf()) {
        return NULL;
    }
    if (cur->getLeft() == son || cur->getRight() == son) {
        return cur;
    }
    if (*(son->getData()) > *(cur->getData())) {
        return getFather(son, cur->getRight());
    } else {
        return getFather(son, cur->getLeft());
    }
}

template<typename T>
void Tree<T>::clear() {
    clear(root);
    root = NULL;
}

template<typename T>
Tree<T>::~Tree() {
    clear();
}

template<typename T>
void Tree<T>::clear(Node<T> *cur) {
    if (!cur) {
        return;
    }
    if (cur->isLeaf()) {
        delete cur;
        return;
    }
    clear(cur->getRight());
    clear(cur->getLeft());
    delete cur;
}

template<typename T>
int Tree<T>::numOfNodes() {
    return numOfNodes(root);
}

template<typename T>
int Tree<T>::numOfNodes(Node<T> *cur) {
    if (!cur) {
        return 0;
    }
    return 1 + numOfNodes(cur->getRight()) + numOfNodes(cur->getLeft());
}

#endif //EVYATAR_GENERIC_TREE_TREE_H
