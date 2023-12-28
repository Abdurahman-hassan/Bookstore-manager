QueueUtils::QueueUtils(int size) {
    this->size = size;
    queue = new int[size];
    front = 0;
    rear = -1;
    count = 0;
}

QueueUtils::~QueueUtils() {
    delete[] queue;
}

QueueUtils::QueueUtils(const QueueUtils &q) {
    size = q.size;
    queue = new int[size];
    front = q.front;
    rear = q.rear;
    count = q.count;
    for (int i = 0; i < size; i++) {
        queue[i] = q.queue[i];
    }
}

void QueueUtils::enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }
    rear = (rear + 1) % size;
    queue[rear] = item;
    count++;
}

int QueueUtils::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int item = queue[front];
    front = (front + 1) % size;
    count--;
    return item;
}

int QueueUtils::peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return queue[front];
}

bool QueueUtils::isEmpty() {
    return count == 0;
}

bool QueueUtils::isFull() {
    return count == size;
}

void QueueUtils::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i != rear; i = (i + 1) % size) {
        cout << queue[i] << " ";
    }
    cout << queue[rear] << endl;
}
