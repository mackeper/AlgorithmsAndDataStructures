#ifndef QUEUE_H_
#define QUEUE_H_
#include <cstddef>

/**
    Simple FIFO Queue data structure.

    Note: Segfault if using front/back on an empty queue.

    Author: Marcus Östling

*/
template <class T>
class Queue {
    private:
        class Item {
            public:
                T val;
                Item* next;
                Item(T v) : val(v) {}
        };

        size_t m_size;
        Item* m_first;
        Item* m_last;

    public:
        Queue() : m_size(0), m_first(nullptr), m_last(nullptr) {}

        /* Return the number of elements in the queue */
        size_t const size();

        /* Check if the queue is empty */
        bool const empty();

        /* Add an element to the end of the queue */
        void push(T val);

        /* Remove the first element in the que */
        void pop();

        /* Return the first element in the queue */
        T& front();

        /* Return the last element in the queue */
        T& back();
};

template <class T>
size_t const Queue<T>::size() {
    return this->m_size;
}

template <class T>
bool const Queue<T>::empty() {
    return this->size() == 0;
}

template <class T>
void Queue<T>::push(T val) {
    Item* newItem = new Item(val);

    if(m_last == nullptr) {
        m_first = newItem;
        m_last = newItem;
    }
    else {
        m_last->next = newItem;
        m_last = newItem;
    }

    m_size++;
}

template <class T>
void Queue<T>::pop() {
    if(m_first != nullptr) {
        Item* tmp = m_first->next;
        delete m_first;
        m_first = tmp;
        if(m_first == nullptr) {
            m_last = nullptr;
        }
        m_size--;
    }
}

template <class T>
T& Queue<T>::front() {
    return m_first->val;
}

template <class T>
T& Queue<T>::back() {
    return m_last->val;
}
#endif //QUEUE_H_
