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

template <typename L>
bool List<L>::atFirst() const {
    return cursor == head;
}

template <typename L>
void List<L>::advance() {
    prev = cursor;
    cursor = cursor->next;
}

template <typename L>
void List<L>::toEnd() {
    toFirst();
    if (!isEmpty()) {
        while (cursor->next != NULL)
            advance();
    }
}

template <typename L>
bool List<L>::atEnd() const {
    if (isEmpty())
        return true;
    else if (currsorIsEmpty())
        return false;
    else
        return cursor->next == NULL;
}

template <typename L>
void List<L>::retrieveData(L &d, int &k) const {
    if (!currsorIsEmpty()) {
        d = cursor->data;
        k = cursor->key;
    }
}