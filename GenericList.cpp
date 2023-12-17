#include "GenericList.h"
#include "User.h"

template <class L>
GenericList<L>::GenericList() {
    head = nullptr;
    cursor = nullptr;
    prev = nullptr;
}

template <typename L>
bool GenericList<L>::isEmpty() const {
    return head == nullptr;
}

template <typename L>
bool GenericList<L>::currsorIsEmpty() const {
    return cursor == nullptr;
}

template <typename L>
void GenericList<L>::toFirst() {
    cursor = head;
    prev = nullptr;
}

template <typename L>
bool GenericList<L>::atFirst() const {
    return cursor == head;
}

template <typename L>
void GenericList<L>::advance() {
    prev = cursor;
    cursor = cursor->next;
}

template <typename L>
void GenericList<L>::toEnd() {
    toFirst();
    if (!isEmpty()) {
        while (cursor->next != nullptr)
            advance();
    }
}

template <typename L>
bool GenericList<L>::atEnd() const {
    if (isEmpty())
        return true;
    else if (currsorIsEmpty())
        return false;
    else
        return cursor->next == nullptr;
}

template <typename L>
void GenericList<L>::retrieveData(L& d) const {
    d = cursor->data;
}

template <typename L>
void GenericList<L>::retrieveData(L& d, int& k) const {
    d = cursor->data;
    k = cursor->key;
}

template <typename L>
void GenericList<L>::retrieveKey(int& k) const {
    k = cursor->key;
}

template <typename L>
void GenericList<L>::updateData(const L& d) {
    cursor->data = d;
}

template <typename L>
int GenericList<L>::listSize() const {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename L>
void GenericList<L>::insertFirst(const int& k, const L& d) {
    Node* temp = new Node;
    temp->key = k;
    temp->data = d;

    temp->next = head;

    head = temp;
    cursor = head;
    prev = nullptr;
}

template <typename L>
void GenericList<L>::insertAfter(const int& k, const L& d) {
    Node* temp = new Node;
    temp->key = k;
    temp->data = d;

    temp->next = cursor->next;
    cursor->next = temp;

    prev = cursor;
    cursor = temp;
}

template <typename L>
void GenericList<L>::insertBefore(const int& k, const L& d) {
    Node* temp = new Node;
    temp->key = k;
    temp->data = d;

    temp->next = cursor;
    prev->next = temp;

    cursor = temp;
}

template <typename L>
void GenericList<L>::insertEnd(const int& k, const L& d) {
    if (isEmpty())
        insertFirst(k, d);
    else {
        toEnd();
        insertAfter(k, d);
    }
}

template <typename L>
void GenericList<L>::deleteNode() {
    Node* temp;

    if (!currsorIsEmpty()) {
        if (atFirst()) {
            temp = cursor;
            cursor = cursor->next;
            head = cursor;
            delete temp;
        }
        else {
            temp = cursor;
            cursor = cursor->next;
            prev->next = cursor;
            delete temp;
        }
    }
}

template <typename L>
void GenericList<L>::deleteFirst() {
    if (!isEmpty()) {
        toFirst();
        deleteNode();
    }
}

template <typename L>
void GenericList<L>::deleteEnd() {
    if (!isEmpty()) {
        toEnd();
        deleteNode();
    }
}

template <typename L>
void GenericList<L>::makeListEmpty() {
    toFirst();
    while (!isEmpty())
        deleteNode();
}

template <typename L>
bool GenericList<L>::search(const int& k) {
    bool found = false;
    toFirst();
    while (!found && cursor != nullptr) {
        if (cursor->key == k)
            found = true;
        else
            advance();
    }
    return found;
}

template <typename L>
void GenericList<L>::orderInsert(const int& k, const L& d) {
    toFirst();
    while (cursor != nullptr && cursor->key < k)
        advance();
    if (prev == nullptr)
        insertFirst(k, d);
    else
        insertBefore(k, d);
}

template <typename L>
void GenericList<L>::traverse() {
    toFirst();
    while (!currsorIsEmpty()) {
        cout << cursor->key << " " << cursor->data << endl;
        advance();
    }
}

template <typename L>
GenericList<L>::~GenericList() {
    makeListEmpty();
}

template class GenericList<int>;