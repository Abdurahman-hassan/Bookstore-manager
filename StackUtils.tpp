/**
 * Stack - Constructor with argument, size is nelements, default is 128
 * @size: size of the stack
 */
template <typename T>
StackUtils<T>::StackUtils(int size) {
    stack_size = size;
    top = -1; /* top is -1 at the beginning */
    count = 0;
    stack = new T[stack_size];
}

/**
 * Stack - Copy Constructor to copy the original stack to the new one
 * without changing the original stack
 * @original: the original stack
 */
template <typename T>
StackUtils<T>::StackUtils(const StackUtils<T> &original) {
    stack_size = original.stack_size;
    top = original.top;
    count = original.count;
    stack = new T[stack_size]; /* allocate memory for the new stack */
    for (int i = 0; i <= stack_size; i++)
        stack[i] = original.stack[i];
}

/**
 * push - Push a new element to the stack
 * @data: the new element
 */
template <typename T>
void StackUtils<T>::push(T data) {
    if (stackIsFull()) {
        cout << "Stack is full\n";
    }
    else {
        /* we must ++ before assigning because top is -1 at the beginning */
        stack[++top] = data;
        count++;
    }
}

/**
 * pop - pop a new element to the stack
 * @data: the new element of generic type
 */
template <typename T>
void StackUtils<T>::pop(T &data) {
    if (stackIsEmpty()) {
        cout << "Stack is empty\n";
    }
    else {
        data = stack[top--];
        count--;
    }
}

/**
 * stackTop - Retrieve stack top without removing it
 * @data: the top element
 */
template <typename T>
void StackUtils<T>::stackTop(T &data) const {
    if (stackIsEmpty())
        cout << "Stack Underflow";
    else
        data = stack[top];
}

/**
 * stackIsEmpty - Check if the stack is empty or not
 * @return: true if the stack is empty, false otherwise
 */
template <typename T>
bool StackUtils<T>::stackIsEmpty() const {
    return top < 0; // or return (top == -1);
}

/**
 * stackIsFull - Check if the stack is full or not
 * @return: true if the stack is full, false otherwise
 */
template <typename T>
bool StackUtils<T>::stackIsFull() const {
    return (top >= (stack_size - 1)); // or return (top == stack_size - 1);
}

/**
 * stackSize - size of the stack (number of elements)
 * return: the size of the stack
 */
template <typename T>
int StackUtils<T>::stackSize() {
    return count;
}

/**
 * ~Stack - Destructor to delete the stack
 * from the memory after finishing the program
 */
template <typename T>
StackUtils<T>::~StackUtils() {
    delete [] stack;
}

template <typename T>
void StackUtils<T>::sorting_stack(StackUtils<T> &s) {
    int size = s.stackSize();
    T *array = new T[size]; // Array to hold stack elements
    int arraySize = 0;

    // Transfer elements from stack 's' to array
    while (!s.stackIsEmpty()) {
        T temp;
        s.pop(temp);
        array[arraySize++] = temp;
    }

    // sorting using a Bubble Sort algorithm
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                // Swap array[j] and array[j + 1]
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Push sorted elements back to stack 's'
    for (int i = 0; i < arraySize; i++) {
        s.push(array[i]);
    }

    delete[] array; // Clean up the dynamically allocated array
}


template <typename T>
void StackUtils<T>::sorting_stack() {
    T *array = new T[count]; // Array to hold stack elements
    int arraySize = 0;

    // Transfer elements from stack to array
    while (!stackIsEmpty()) {
        pop(array[arraySize++]);
    }

    // Bubble Sort algorithm
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Push sorted elements back to stack
    for (int i = 0; i < arraySize; i++) {
        push(array[i]);
    }

    delete[] array; // Clean up the dynamically allocated array
}


// Function to print the elements of a stack
template <typename T>
void StackUtils<T>::printStack(StackUtils<T>& stack, const string& message) {
    cout << message << endl;
    StackUtils<T> tempStack(stack);

    while (!tempStack.stackIsEmpty()) {
        T element;
        tempStack.pop(element);
        cout << element << "  ";
    }
    cout << endl;
}


// template <typename T>
// void StackUtils<T>::sorting_stack(StackUtils<T> &s) {
//     StackUtils<T> temp_stack;
//     T temp;
//     while (!s.stackIsEmpty()) {
//         s.pop(temp);
//         while (!temp_stack.stackIsEmpty() && temp_stack.stackTop(temp) > temp) {
//             s.push(temp_stack.top);
//             temp_stack.pop(temp);
//         }
//         temp_stack.push(temp);
//     }
//     while (!temp_stack.stackIsEmpty()) {
//         temp_stack.pop(temp);
//         s.push(temp);
//     }
// }
