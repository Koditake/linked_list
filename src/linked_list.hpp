#pragma once

#include <cstddef>

struct node
{
    node *next;
    int data;

    /********************************
     * Implementation of node methods
     ********************************/

    node() : next(nullptr), data(0) {}

    node(int node_data) : next(nullptr), data(node_data) {}

    ~node() {}
};

node::node(/* args */)
{
}

node::~node()
{
}


class linked_list
{
private:
    std::size_t _size;    
    node *_head;
public:
    linked_list(/* args */);

    ~linked_list();

    int get (std::size_t index);

    void add_head(int data);

    void add_tail(int data);

    void add_indx(int data);

    void reverse();

    node *reverseHead(node *&head);

    void del_indx(std::size_t index);
};

linked_list::linked_list(/* args */)
{
}

linked_list::~linked_list()
{
}
