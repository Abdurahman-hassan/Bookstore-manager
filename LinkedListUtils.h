#ifndef LINKEDLISTUTILS_H
#define LINKEDLISTUTILS_H

# include <iostream>
using namespace std;
using std::string;

template <class L>
class LinkedListUtils
{
public:

// =========== Constructor and Destructor ===========
    LinkedListUtils();
    ~LinkedListUtils();

// =========== checker functions ===========
    bool isEmpty() const;
    bool currsorIsEmpty() const;
    bool atFirst() const;
    bool atEnd() const;

// =========== Movement functions ===========
    void toFirst();
    void toEnd();
    void advance();

// =========== Retrieval functions ===========
    void retrieveData(L&) const;
    void retrieveData(L &, int &) const;
    void retrieveKey(int &) const;

// =========== Insertion functions ===========
    void insertFirst(const int &, const L &);
    void insertAfter(const int &, const L &);
    void insertBefore(const int &, const L &);
    void insertEnd(const int &, const L &);

// =========== Deletion functions ===========
    void deleteNode();
    void deleteFirst();
    void deleteEnd();
    void deleteNode(const int &key);
    void makeListEmpty();

// =========== Utils functions ===========
    bool search(const int &);
    void orderInsert(const int &, const L &);
    void traverse();
    int listSize() const;
    void updateData(const L &);

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

#include "LinkedListUtils.tpp"

#endif //LINKEDLISTUTILS_H
