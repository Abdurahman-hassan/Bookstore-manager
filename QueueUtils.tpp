template <typename T>
QueueUtils<T>::QueueUtils(int size) {
    this->size = size;
    queue = new T[size];
    front = 0;
    rear = -1;
    count = 0;
}

template <typename T>
QueueUtils<T>::~QueueUtils() {
    delete[] queue;
}

template <typename T>
QueueUtils<T>::QueueUtils(const QueueUtils<T> &q) {
    size = q.size;
    queue = new T[size];
    front = q.front;
    rear = q.rear;
    count = q.count;
    for (int i = 0; i < size; i++) {
        queue[i] = q.queue[i];
    }
}

template <typename T>
void QueueUtils<T>::enqueue(T item) {
    if (isFull()) {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    rear = (rear + 1) % size;
    queue[rear] = item;
    count++;
}

template <typename T>
T QueueUtils<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return T(); // Return default value of T
    }
    T item = queue[front];
    front = (front + 1) % size;
    count--;
    return item;
}

template <typename T>
bool QueueUtils<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
bool QueueUtils<T>::isFull() const {
    return count == size;
}

template <typename T>
void QueueUtils<T>::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    std::cout << "Queue: ";
    for (int i = front; i != rear; i = (i + 1) % size) {
        std::cout << queue[i] << " ";
    }
    std::cout << queue[rear] << std::endl;
}
