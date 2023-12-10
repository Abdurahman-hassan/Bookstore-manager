# include "linkedlist_header.h"

template <class L>
List<L>::List() {
    head = nullptr;
    cursor = nullptr;
    prev = nullptr;
}

template <typename L>
bool List<L>::isEmpty() const {
    return head == nullptr;
}

template <typename L>
bool List<L>::currsorIsEmpty() const {
    return cursor == nullptr;
}

template <typename L>
void List<L>::toFirst() {
    cursor = head;
    prev = nullptr;
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
        while (cursor->next != nullptr)
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
        return cursor->next == nullptr;
}

template <typename L>
void List<L>::retrieveData(L &d, int &k) const {
        d = cursor->data;
        k = cursor->key;
}

template <typename L>
void List<L>::retrieveKey(int &k) const {
     k = cursor->key;
}

template <typename L>
void List<L>::updateData(const L &d) {
     cursor->data = d;
}

template <typename L>
int List<L>::listSize() const {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename L>
void List<L>::insertFirst(const int &k, const L &d) {
    Node* temp = new Node;
    temp->key = k;
    temp->data = d;
    temp->next = head;
    head = temp;
    cursor = head;
    prev = nullptr;
}
