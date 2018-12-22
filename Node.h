//
// Created by amichai on 21/12/18.
//

#ifndef EVYATAR_GENERIC_TREE_NODE_H
#define EVYATAR_GENERIC_TREE_NODE_H

template <typename T>
class Node {
public:
    T getData() const {
        return data;
    }

    virtual ~Node() {
        delete data;
    }

    void setData(T data) {
        Node::data = data;
    }

    Node<T> *getLeft() const {
        return left;
    }

    void setLeft(Node<T> *left) {
        Node::left = left;
    }

    Node<T> *getRight() const {
        return right;
    }

    void setRight(Node<T> *right) {
        Node::right = right;
    }

    Node(T data) : data(data), left(NULL), right(NULL) {}

    bool isLeaf() {
        return !left && !right;
    }

    int numOfKids() {
        return !!left + !!right;
    }

    Node<T> *getOnlySon() {
        return left ? left : right;
    }

private:
    T data;
    Node<T> *left;
    Node<T> *right;
};


#endif //EVYATAR_GENERIC_TREE_NODE_H
