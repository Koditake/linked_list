#include "linked_list.hpp"

linked_list::linked_list(): _head(new node()) {}

linked_list::~linked_list() 
{
    /*
        Default destructor only delete _HEAD node 
        So we need to kill chain nodes manually
    */

   node *h = _head;

   while (_head->next)
   {
        //move head to next
        _head = _head->next;
        //delete old "head"
        delete h;
        //move h to next "head"
        h = _head;
   }

   delete h;
}

int linked_list::get(std::size_t index)
{
    if (index < 0 || index > this->_size) 
    {
        return -1;
    }

    node *p = _head;
    while (index > 0)
    {
        p = p->next;
        index--;
    }

    return p->data;
}

void linked_list::add_head(int data)
{
    // make a new node with data
    node *nhead = new node(data);

    node *nnode = _head->next;
    // Point from head to new Node
    _head->next = nhead;
    // Point from new Node to old Node 2
    nhead->next = nnode;
    // increase size
    this->_size++;
}

void linked_list::add_tail(int data) {
    // mark reference to head
    node *p = _head;
    // traverse list until the end
    while (p->next != nullptr)
    {
        p = p->next;
    }
    // make new node with given data
    node *n = new node(data);
    //point last node to new tail
    p->next = n;
    //increase length
    this->_size++;
}

void linked_list::add_index(std::size_t index, int data)
{
    //traverse node until at index--
    if (index < 0 || index > this->_size)
    {
        return;
    }

    int i = index;
    node *p = _head;
    while (i > 1)
    {
        p = p->next;
        i--;
    }

    //make new node
    node *n = new node(data);
    //point pointer of new node to index
    n->next = p->next;
    //point pointer of node index-- to new node
    p->next = n;

    this->_size++;
}

void linked_list::reverse()
{
    node    *prev(_head),
            *cur (_head->next),
            *next (_head->next->next);

    std::size_t n = this->_size;

    while (n > 0) 
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        n--;
    }
}

node* linked_list::reverse_head(node *&_head)
{
    if (_head == nullptr || _head->next == nullptr)
    {
        return _head;
    }

    node *rest = reverse_head(_head->next);
    _head->next->next = _head;

    _head->next = nullptr;

    return rest;
}

void linked_list::delete_index(std::size_t index)
{
    // traverse the node until index - 1
    if (index < 0 || index > this->_size)
    {
        return;
    }
    // traver to node index + 1
    int i = index - 1;
    node *p1 = _head;
    while (i > 0)
    {
        p1 = p1->next;
        i--;
    }
    node *p2 = p1->next,
         *p3 = p1->next->next;
    // p1(i - 1) -> p2(i) -> p3(i + 1)
    // change pointer of index - 1 to point to index + 1
    p1->next = p3;
    // delete old node
    delete p2;
    _size--;
}