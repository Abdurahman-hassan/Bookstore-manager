#ifndef QUEUEUTILS_H
#define QUEUEUTILS_H

#include <iostream>
using namespace std;

template <typename T>
class QueueUtils {
private:
    T *queue;
    int front;
    int rear;
    int size;
    int count;

public:
    QueueUtils(int size = 128);
    ~QueueUtils();
    QueueUtils(const QueueUtils &q);

    void enqueue(T item);
    T dequeue();
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
    T getMax();
};

#include "QueueUtils.tpp" // Including implementation

#endif // QUEUEUTILS_H
