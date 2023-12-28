#ifndef QUEUEUTILS_H
#define QUEUEUTILS_H

#include <iostream>
using namespace std;

class QueueUtils {
private:
    int front;
    int rear;
    int size;
    int count;

public:
    QueueUtils(int size = 128);
    ~QueueUtils();
    QueueUtils(const QueueUtils &q);

    void enqueue(int item);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

#include "Queue.tpp"

#endif // QUEUEUTILS_H
