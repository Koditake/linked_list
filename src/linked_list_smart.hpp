#pragma once

#include <memory>

template <typename D>
struct Node {
    std::unique_ptr<Node<D>> next;
    D data;

    Node() = delete;

    Node(D &data);
    ~Node();
};

template<typename T>
class smartLinkedList {
public:
    smartLinkedList();
    ~smartLinkedList();

    void add_head(T &data);
    void add_tail(T &data);
    void add_index(int index, T &data);

    void remove_head();
    void remove_tail();
    void remove_index(int index);

    T get_head();
    T get_tail();
    T get_index(int index);

    void reverse();
    void clear();
private: 
    std::unique_ptr<Node<T>> _head;
    std::size_t _size;
};