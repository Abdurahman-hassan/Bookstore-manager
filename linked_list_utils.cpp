# include "linkedlist_header.h"

template <class L>
List<L>::List() {
    head = NULL;
    cursor = NULL;
    prev = NULL;
}

template <typename L>
bool List<L>::isEmpty() const {
    return head == NULL;
}

template <typename L>
bool List<L>::currsorIsEmpty() const {
    return cursor == NULL;
}

template <typename L>
void List<L>::toFirst() {
    cursor = head;
    prev = NULL;
}