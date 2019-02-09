#ifndef BINTREE_H_
#define BINTREE_H_
#include <cstddef>

/**
    Simple binary tree data structure.

    Author: Marcus Östling

*/
template <class K, class V>
class Bintree {
    private:
        class Leaf {
            public:
                K key;
                V val;
                Leaf* left;
                Leaf* right;
                Leaf(K k, V v) : key(k), val(v), left(nullptr), right(nullptr) {}
        };

        size_t m_size;
        Leaf* m_root;

    public:
        Bintree() : m_size(0), m_root(nullptr) {}

        /* Return the number of elements in the tree */
        size_t const size();

        /* Check if the tree is empty */
        bool const empty();

        /* Add an element to the tree */
        void push(K key, V val);

        V& get(K key);

};

template <class K, class V>
size_t const Bintree<K, V>::size() {
    return m_size;
}

template <class K, class V>
bool const Bintree<K, V>::empty() {
    return this->size() == 0;
}

template <class K, class V>
void Bintree<K, V>::push(K key, V val) {
    Leaf* newLeaf = new Leaf(key, val);
    Leaf* current = m_root;

    if(m_root == nullptr) {
        m_root = newLeaf;
        m_size++;
    }

    while(current != nullptr) {
        if(key == current->key) {
            current = nullptr;
        }
        else if(key < current->key) {
            if(current->left == nullptr) {
                current->left = newLeaf;
                current = nullptr;
                m_size++;
            } else {
                current = current->left;
            }
        } 
        else {
            if(current->right == nullptr) {
                current->right = newLeaf;
                current = nullptr;
                m_size++;
            } else {
                current = current->right;
            }
        }
    }

}

template <class K, class V>
V& Bintree<K, V>::get(K key) {
    Leaf* current = m_root;

    if(m_root == nullptr) {
        m_root = newLeaf;
        m_size++;
    }

    while(current != nullptr) {
        if(key == current->key) {
            return current->val;
        }
        else if(key < current->key) {
            if(current->left == nullptr) {
                return current->val;
            } else {
                current = current->left;
            }
        } 
        else {
            if(current->right == nullptr) {
                return current->val;
            } else {
                current = current->right;
            }
        }
    }

}
#endif //BINTREE_H_
