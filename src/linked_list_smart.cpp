#include "linked_list_smart.hpp"

template <typename T>
smartLinkedList<T>::smartLinkedList() : _head(std::make_unique<T>(nullptr)), _size(0)

                                                                                 template <typename T>
                                                                                 smartLinkedList<T>::~smartLinkedList()
{
} // empty because the smart memory will automatically deconstruct nodes. As long as you keep the length below 10,000

template <typename T>
void smartLinkedList<T>::add_head(T &data)
{
    std::unique_ptr<Node<T>> new_node = std::make_unique<T>(std::move(data));

    if (_head->next == nullptr)
    {
        _head->next = std::move(new_node);
    }
    else
    {
        new_node->next = std::move(_head->next);
        _head->next = std::move(new_node);
    }
    _size++;
}

template <typename T>
void smartLinkedList<T>::add_tail(T &data)
{
    if (_size == 0)
    {
        add_head(data);
        _size++;
    }

    Node<T> *current_node = _head.get();
    int i = 0;
    while (i <= _size)
    {
        i++;
        current_node = current_node->next;
    }

    current_node->next = std::move(std::make_unique<T>(std::move(data)));
    _size++;
}

template <typename T>
void smartLinkedList<T>::add_index(int index, T &data)
{
    if (index > _size || index < 0)
    {
        throw std::out_of_range("Invalid operation: index out of bound\n");
    }
    else if (index == _size)
    {
        add_tail(data);
    }

    Node<T> *prev_node = _head.get();
    int i = 0;
    while (i < index && i <= _size)
    {
        prev_node = prev_node->next;
        i++;
    }

    prev_node->next = std::make_unique<Node<T>>(data, std::move(prev_node->next));
    _size++;
}

template <typename T>
T smartLinkedList<T>::get_head()
{
    return _head->next->data;
}

template <typename T>
T smartLinkedList<T>::get_tail()
{
    if (_head->next == nullptr)
    {
        throw std::out_of_range("Invalid operation: List empty\n");
    }

    if (_size == 1)
    {
        return get_head();
    }

    int i = 0;
    Node<T> *current_node = _head.get();
    while (i < _size)
    {
        current_node = current_node->next;
        i++;
    }

    return current_node->data;
}

template <typename T>
T smartLinkedList<T>::get_index(int index)
{
    if (index > _size || index < 0)
    {
        throw std::out_of_range("Invalid operation: index out of bound\n");
    }

    int i = 0;
    Node<T> *current_node = _head.get();
    while (i < index)
    {
        current_node = current_node->next;
        i++;
    }

    return current_node->data;
}

template <typename T>
void smartLinkedList<T>::remove_head()
{
    if (_size == 0)
    {
        throw std::out_of_range("Invalid operation: List empty\n");
        return;
    }
    else if (_size == 1)
    {
        _head = nullptr;
    }
    else
    {
        _head = std::move(_head->next->next);
    }
    _size--;
    return;
}

template <typename T>
void smartLinkedList<T>::remove_tail()
{
    if (_size == 0)
    {
        throw std::out_of_range("Invalid operation: list empty\n");
    }
    else if (_size == 1)
    {
        remove_head();
    }
    else
    {
        Node<T> *current_node = _head.get();
        int i = 0;
        while (i < _size--)
        {
            current_node = current_node->next;
            i++;
        }

        current_node->next = nullptr;
    }
    _size--;
}

template <typename T>
void smartLinkedList<T>::remove_index(int index)
{
    if (index > _size || index < 0)
    {
        throw std::out_of_range("Invalid operation: index out of bound\n");
    }
    else if (index == _size)
    {
        remove_tail();
    }
    else if (index == 1)
    {
        remove_head();
    }
    else
    {
        int i = index--;
        Node<T> *current_node = _head.get();

        for (i; i >= 0; i--;)
        {
            current_node = current_node->next;
        }

        current_node = std::move(current_node->next->next);
    }
    _size--;
}

template <typename T>
void smartLinkedList<T>::reverse()
{
    Node<T> *prev = nullptr,
            *curr = _head.get(),
            *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next.get();
        curr->nex = std::move(prev);
        prev = curr;
        curr = next;
    }

    _head = std::move(prev);
}

template<typename T>
void smartLinkedList<T>::clear() 
{
    _head->next = nullptr;
}