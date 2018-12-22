//
// Created by amichai on 22/12/18.
//

#ifndef EVYATAR_GENERIC_TREE_PLAYERTREE_H
#define EVYATAR_GENERIC_TREE_PLAYERTREE_H

#include "Tree.h"
#include "Player.h"

template <typename T>
class PlayerTree : public Tree<T> {
public:
    T getPlayerById(int id);
private:
    T getPlayerById(int id, Node<T> *cur);
};

template<typename T>
T PlayerTree<T>::getPlayerById(int id) {
    return getPlayerById(id, Tree<T>::root);
}

template<typename T>
T PlayerTree<T>::getPlayerById(int id, Node<T> *cur) {
    if (cur == NULL) {
        return NULL;
    }
    if (static_cast<Player*>(cur->getData())->getId() == id) {
        return cur->getData();
    }
    if (id > static_cast<Player*>((cur->getData()))->getId()) {
        return getPlayerById(id, cur->getRight());
    } else {
        return getPlayerById(id, cur->getLeft());
    }
}

#endif //EVYATAR_GENERIC_TREE_PLAYERTREE_H
