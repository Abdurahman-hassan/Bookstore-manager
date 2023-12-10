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
    void retrieveData(L &, int &) const;
    void retrieveKey(int &) const;
    void updateData(const L &);
    int listSize() const;

// =========== Insertion functions ===========
    void insertFirst(const int &, const L &);
    void insertAfter(const int &, const L &);
    void insertBefore(const int &, const L &);
    void insertEnd(const int &, const L &);

// =========== Deletion functions ===========
    void deleteNode();
    void deleteFirst();
    void deleteEnd();
    void makeListEmpty();

// =========== Utils functions ===========
    bool search(const int &);
    void orderInsert(const int &, const L &);
    void traverse();




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
