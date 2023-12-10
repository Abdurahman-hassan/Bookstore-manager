#ifndef LINKEDLIST_HEADER_H
#define LINKEDLIST_HEADER_H

# include <iostream>
using namespace std;
using std::string;

template <class L>
class List
{
public:
    List();
    bool isEmpty() const;

private:
    class Node
    {
    public:
        int key;
        L data;
        Node *next;
    };
    Node *head, *cursor, *prev;
};

#endif //LINKEDLIST_HEADER_H
