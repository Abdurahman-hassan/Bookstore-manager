# Bookstore-manager
CS505 Bookstore Manager Project  Data Structures &amp; Algorithms project from the Dept. of Computer Science, College of Graduate Studies for Statistical Research, Cairo University. A C++ console app to manage a virtual bookstore. Created by Cairo University students.


# Book Store Manger

### 1- System Design Overview with Data Structures
   - User Registration: Users can register with a username and password.

   - JSON File Storage: Store user and admin credentials in a JSON file.

   - Admin Check: Avoid storing admin credentials.

   - User Interface:

       > **important information**
       >
       > - Regular Users: Options to buy, search, display books.
       > - Admin Users: Options to add, delete, update book records.

   - Book Addition Format: Admin adds book details.

   - Book Display Format: Display as "(book_number) (book_name) (rate)".

### 2. Key Components and Data Structures
   - ### Classes:
        - User: Attributes include username, password, role.
        - Book: Attributes include name, price, category, author, description, rate.
        - Bookstore: Manages books and user interactions.
        - StorageManager: Handles JSON file I/O.
        - UserInterface: Manages UI for different user types.
   - ### Data Structures:

        - Dynamic Array: Store user data or book data for flexible size management.
        - Static Array: Use for fixed-size data storage where appropriate.
        - Linked List: Ideal for managing book lists where frequent insertions and deletions occur.
        - Stack: Use for undo operations in admin interface or for history tracking.
        - Queue: Handle user requests or book purchases in an orderly fashion.
        - Tree (Binary Search Tree or AVL Tree): Manage book records efficiently, facilitating faster searches.

[//]: # (Hash Table: Store and retrieve user credentials rapidly, ensuring quick login and registration processes.)
    
### 3. Functional Documentation of Project Components

 - Comprehensive Documentation of Utilized Functions.
 - This section provides an exhaustive breakdown of all functions integrated into the project. Each function is meticulously documented, encompassing its defined purpose, detailed inputs, expected outputs, and precise implementation specifics.


[//]: # (Linked List Functions)

<details>
  <summary><h3><b>Linked List Functions</b></h3></summary>
   
  <details>
    <summary><i>Constructor</i></summary>
    
   ### LinkedListUtils<L>::LinkedListUtils() 
   - Purpose: Constructor initializing the linked list.
   - Inputs: None.
   - Outputs: None.
   - Initializes pointers head, cursor, and prev to nullptr.

   ### Implementation
   ```C++
   template <class L>
   LinkedListUtils<L>::LinkedListUtils() {
        head = nullptr;
        cursor = nullptr;
        prev = nullptr;
   }
   ```
  </details>
  
  <details>
    <summary><i>isEmpty</i></summary>
    
   ### bool LinkedListUtils<L>::isEmpty() const 
   - Purpose: Checks if the linked list is empty.
   - Inputs: None.
   - Outputs: Boolean indicating whether the list is empty or not.

   ### Implementation
   ```C++
    template <typename L>
    bool LinkedListUtils<L>::isEmpty() const {
       return head == nullptr;
    }
   ```
  </details> 

  <details>
    <summary><i>cursorIsEmpty</i></summary>
    
   ### bool LinkedListUtils<L>::currsorIsEmpty() const 
   - Purpose: Checks if the cursor is empty.
   - Inputs: None.
   - Outputs: Boolean indicating whether the cursor is empty or not.

   ### Implementation
   ```C++
    template <typename L>
    bool LinkedListUtils<L>::currsorIsEmpty() const {
       return cursor == nullptr;
    }
   ```
  </details> 

  <details>
    <summary><i>toFirst</i></summary>
     
   ### void LinkedListUtils<L>::toFirst()
   - Purpose: Moves the cursor to the beginning of the list.
   - Inputs: None.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::toFirst() {
       cursor = head;
       prev = nullptr;
    }
   ```
  </details>

  <details>
    <summary><i>atFirst</i></summary>
     
   ### bool LinkedListUtils<L>::atFirst() const
   - Purpose: Checks if the cursor is at the beginning of the list.
   - Inputs: None.
   - Outputs: Boolean indicating if the cursor is at the beginning.
       
   ### Implementation
   ```C++
    template <typename L>
    bool LinkedListUtils<L>::atFirst() const {
        return cursor == head;
    }
   ```
  </details>

  <details>
    <summary><i>advance</i></summary>
     
   ### void LinkedListUtils<L>::advance()
   - Purpose: Moves the cursor to the next node in the list.
   - Inputs: None.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::advance() {
       prev = cursor;
       cursor = cursor->next;
    }
   ```
  </details>

  <details>
    <summary><i>toEnd</i></summary>
     
   ### void LinkedListUtils<L>::toEnd()
   - Purpose: Moves the cursor to the end of the list.
   - Inputs: None.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::toEnd() {
       toFirst();
       if (!isEmpty()) {
           while (cursor->next != nullptr)
               advance();
       }
   }
   ```
  </details>

  <details>
    <summary><i>atEnd</i></summary>
     
   ### bool LinkedListUtils<L>::atEnd() const
   - Purpose: Checks if the cursor is at the end of the list.
   - Inputs: None.
   - Outputs: Boolean indicating if the cursor is at the end.
       
   ### Implementation
   ```C++
    template <typename L>
    bool LinkedListUtils<L>::atEnd() const {
    if (isEmpty())
        return true;
    else if (currsorIsEmpty())
        return false;
    else
        return cursor->next == nullptr;
    }
   ```
  </details>

  <details>
    <summary><i>retrieveData</i></summary>
     
   ### void LinkedListUtils<L>::retrieveData(L& d) const
   - Purpose: Retrieves data from the current node.
   - Inputs: Reference to store retrieved data.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::retrieveData(L& d) const {
        d = cursor->data;
    }
   ```
  </details>

  <details>
    <summary><i>retrieveData</i></summary>
     
   ### void LinkedListUtils<L>::retrieveData(L &d, int &k) const
   - Purpose: Retrieves data and key from the current node.
   - Inputs: References to store retrieved data and key.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::retrieveData(L &d, int &k) const {
       d = cursor->data;
       k = cursor->key;
    }
   ```
  </details>

  <details>
    <summary><i>retrieveKey</i></summary>
     
   ### void LinkedListUtils<L>::retrieveKey(int &k) const
   - Purpose: Retrieves key from the current node.
   - Inputs: Reference to store retrieved key.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::retrieveKey(int &k) const {
       k = cursor->key;
    }
   ```
  </details>

   <details>
    <summary><i>updateData</i></summary>
     
   ### void LinkedListUtils<L>::updateData(const L &d)
   - Purpose: Updates the data of the current node.
   - Inputs: New data to update.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::updateData(const L &d) {
       cursor->data = d;
    }
   ```
  </details>

   <details>
    <summary><i>listSize</i></summary>
     
   ### int LinkedListUtils<L>::listSize() const
   - Purpose: Computes the size of the linked list.
   - Inputs: None.
   - Outputs: Integer representing the size of the list.
       
   ### Implementation
   ```C++
    template <typename L>
    int LinkedListUtils<L>::listSize() const {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
   ```
  </details>

   <details>
    <summary><i>insertFirst</i></summary>
     
   ### void LinkedListUtils<L>::insertFirst(const int &k, const L &d)
   - Purpose: Inserts a new node at the beginning of the list.
   - Inputs: Key and data for the new node.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::insertFirst(const int &k, const L &d) {
        Node* temp = new Node;
        temp->key = k;
        temp->data = d;

        temp->next = head;

        head = temp;
        cursor = head;
        prev = nullptr;
    }
   ```
  </details>

   <details>
    <summary><i>insertAfter</i></summary>
     
   ### void LinkedListUtils<L>::insertAfter(const int &k, const L &d)
   - Purpose: Inserts a new node after the current node.
   - Inputs: Key and data for the new node.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::insertAfter(const int &k, const L &d) {
        Node* temp = new Node;
        temp->key = k;
        temp->data = d;

        temp->next = cursor->next;
        cursor->next = temp;

        prev = cursor;
        cursor = temp;
    }
   ```
  </details>

  <details>
    <summary><i>insertBefore</i></summary>
     
   ### void LinkedListUtils<L>::insertBefore(const int &k, const L &d)
   - Purpose: Inserts a new node before the current node.
   - Inputs: Key and data for the new node.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    template <typename L>
    void LinkedListUtils<L>::insertBefore(const int &k, const L &d) {
        Node* temp = new Node;
        temp->key = k;
        temp->data = d;

        temp->next = cursor;
        prev->next = temp;

        cursor = temp;
    }
   ```
  </details>

  <details>
    <summary><i>insertEnd</i></summary>
     
   ### void LinkedListUtils<L>::insertEnd(const int &k, const L &d)
   - Purpose: Inserts a new node at the end of the list.
   - Inputs: Key and data for the new node.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::insertEnd(const int &k, const L &d) {
        if (isEmpty())
            insertFirst(k, d);
        else {
            toEnd();
            insertAfter(k, d);
        }
    }
   ```
  </details>

  <details>
    <summary><i>deleteNode</i></summary>
     
   ### void LinkedListUtils<L>::deleteNode(const int &key)
   - Purpose: Deletes a node with a specified key from the list.
   - Inputs: Key of the node to be deleted.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::deleteNode(const int &key) {
       // Node* temp = head;
       // Node* prev = nullptr;
       toFirst();
       // Case: List is empty
       if (cursor == nullptr) return;
   
       // Case: Node to delete is head
       if (cursor != nullptr && cursor->key == key) {
           head = cursor->next;   // Changed head
           delete cursor;         // free old head
           return;
       }
   
       // Search for the key to be deleted
       while (cursor != nullptr && cursor->key != key) {
           prev = cursor;
           cursor = cursor->next;
       }
   
       // If key was not present in linked list
       if (cursor == nullptr) return;
   
       // Unlink the node from linked list
       prev->next = cursor->next;
       delete cursor;
    }
   ```
  </details>

   <details>
    <summary><i>deleteNode</i></summary>
     
   ### void LinkedListUtils<L>::deleteNode()
   - Purpose: Deletes the current node.
   - Inputs: None.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::deleteNode() {
      Node* temp;
      
      if (!currsorIsEmpty()){
          if (atFirst()) {
              temp = cursor;
              cursor = cursor->next;
              head = cursor;
              delete temp;
          } else {
              temp = cursor;
              cursor = cursor->next;
              prev->next = cursor;
              delete temp;
          }
      }
    }
   ```
  </details>

  <details>
    <summary><i>deleteFirst</i></summary>
     
   ### void LinkedListUtils<L>::deleteFirst()
   - Purpose: Deletes the first node in the list.
   - Inputs: None.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::deleteFirst() {
      if (!isEmpty()) {
          toFirst();
          deleteNode();
      }
    }
   ```
  </details>

  <details>
    <summary><i>deleteEnd</i></summary>
     
   ### void LinkedListUtils<L>::deleteEnd()
   - Purpose: Deletes the last node in the list.
   - Inputs: None.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::deleteEnd() {
      if (!isEmpty()) {
          toEnd();
          deleteNode();
      }
    }
   ```
  </details>

   <details>
    <summary><i>makeListEmpty</i></summary>
     
   ### void LinkedListUtils<L>::makeListEmpty()
   - Purpose: Empties the entire linked list.
   - Inputs: None.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
   void LinkedListUtils<L>::makeListEmpty() {
      toFirst();
      while (!isEmpty())
          deleteNode();
   }
   ```
  </details>

<details>
    <summary><i>search</i></summary>
     
   ### bool LinkedListUtils<L>::search(const int &k)
   - Purpose: Searches for a node with a specified key in the list.
   - Inputs: Key to search for.
   - Outputs: Boolean indicating if the key was found.
       
   ### Implementation
   ```C++
    template <typename L>
   bool LinkedListUtils<L>::search(const int &k) {
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
   ```
  </details>

  <details>
    <summary><i>orderInsert</i></summary>
     
   ### void LinkedListUtils<L>::orderInsert(const int &k, const L &d)
   - Purpose: Inserts a node in ascending order based on the key.
   - Inputs:  Key and data for the new node.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::orderInsert(const int &k, const L &d) {
      toFirst();
      while (cursor != nullptr && cursor->key < k)
          advance();
      if (prev == nullptr)
          insertFirst(k, d);
      else
          insertBefore(k, d);
    }
   ```
  </details>

   <details>
    <summary><i>traverse</i></summary>
     
   ### void LinkedListUtils<L>::traverse()
   - Purpose: Traverses the list and prints the keys of all nodes.
   - Inputs:  None.
   - Outputs: None.
       
   ### Implementation
   ```C++
    template <typename L>
    void LinkedListUtils<L>::traverse() {
      toFirst();
      while (!currsorIsEmpty()) {
          cout << cursor->key; //<< " " << cursor->data << endl;
          advance();
      }
    }
   ```
  </details>

  <details>
       <summary><i>Destructor</i></summary>
        
   ### LinkedListUtils<L>::~LinkedListUtils()
   - Purpose: Destructor to free memory by making the list empty.
   - Inputs:  None.
   - Outputs: None.
          
   ### Implementation
   ```C++
      template <typename L>
      LinkedListUtils<L>::~LinkedListUtils() {
         makeListEmpty();
      }
   ```
   </details>
 
</details>

[//]: # (Stack Functions)

<details>
  <summary><h3><b>Stack Functions</b></h3></summary>
   
  <details>
    <summary><i>Constructor</i></summary>
    
   ### StackUtils<T>::StackUtils(int size) 
   - Purpose: Constructor for the Stack class with an argument specifying the size of the stack.
   - Inputs: Size of the stack.
   - Outputs: None.

   ### Implementation
   ```C++
   template <typename T>
   StackUtils<T>::StackUtils(int size) {
       stack_size = size;
       top = -1; /* top is -1 at the beginning */
       count = 0;
       stack = new T[stack_size];
   }
   ```
  </details>

  <details>
    <summary><i>Copy Constructor</i></summary>
    
   ### StackUtils<T>::StackUtils(const StackUtils<T> &original)
   - Purpose: Copy constructor to copy the original stack to a new one without changing the original stack.
   - Inputs: The original stack to be copied.
   - Outputs: None.

   ### Implementation
   ```C++
   template <typename T>
   StackUtils<T>::StackUtils(const StackUtils<T> &original) {
       stack_size = original.stack_size;
       top = original.top;
       count = original.count;
       stack = new T[stack_size]; /* allocate memory for the new stack */
       for (int i = 0; i <= stack_size; i++)
           stack[i] = original.stack[i];
   }
   ```
  </details>

  <details>
    <summary><i>push</i></summary>
    
   ### void StackUtils<T>::push(T data)
   - Purpose: Pushes a new element onto the stack.
   - Inputs: The new element to be pushed.
   - Outputs: None.

   ### Implementation
   ```C++
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
   ```
  </details>

  <details>
    <summary><i>pop</i></summary>
    
   ### void StackUtils<T>::pop(T &data)
   - Purpose: Pops an element from the stack.
   - Inputs: Reference to store the popped element.
   - Outputs: None.

   ### Implementation
   ```C++
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
   ```
  </details>

  <details>
    <summary><i>stackTop</i></summary>
    
   ### void StackUtils<T>::stackTop(T &data) const
   - Purpose: Retrieves the top element of the stack without removing it.
   - Inputs: Reference to store the top element.
   - Outputs: None.

   ### Implementation
   ```C++
   template <typename T>
   void StackUtils<T>::stackTop(T &data) const {
       if (stackIsEmpty())
           cout << "Stack Underflow";
       else
           data = stack[top];
   }
   ```
  </details>

   <details>
    <summary><i>stackIsEmpty</i></summary>
    
   ### bool StackUtils<T>::stackIsEmpty() const
   - Purpose: Checks if the stack is empty.
   - Inputs:  None.
   - Outputs: Boolean indicating if the stack is empty.

   ### Implementation
   ```C++
   template <typename T>
   bool StackUtils<T>::stackIsEmpty() const {
       return top < 0; // or return (top == -1);
   }
   ```
  </details>

   <details>
    <summary><i>stackIsFull</i></summary>
    
   ### bool StackUtils<T>::stackIsFull() const
   - Purpose: Checks if the stack is full.
   - Inputs:  None.
   - Outputs: Boolean indicating if the stack is full.

   ### Implementation
   ```C++
   template <typename T>
   bool StackUtils<T>::stackIsFull() const {
       return (top >= (stack_size - 1)); // or return (top == stack_size - 1);
   }
   ```
  </details>

   <details>
    <summary><i>stackSize</i></summary>
    
   ### int StackUtils<T>::stackSize()
   - Purpose: Retrieves the size of the stack (number of elements).
   - Inputs:  None.
   - Outputs: Integer representing the size of the stack.

   ### Implementation
   ```C++
   template <typename T>
   int StackUtils<T>::stackSize() {
       return count;
   }
   ```
  </details>

  <details>
    <summary><i>Destructor</i></summary>
    
   ### StackUtils<T>::~StackUtils()
   - Purpose: Destructor to delete the stack from memory after program execution.
   - Inputs:  None.
   - Outputs: None.

   ### Implementation
   ```C++
   template <typename T>
   StackUtils<T>::~StackUtils() {
       delete [] stack;
   }
   ```
  </details>

  <details>
    <summary><i>sorting_stack</i></summary>
    
   ### void StackUtils<T>::sorting_stack(StackUtils<T> &s)
   - Purpose: Sorts the elements of the provided stack in descending order.
   - Inputs: Reference to a stack to be sorted.
   - Outputs: None.

   ### Implementation
   ```C++
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
   
        // Sorting using a Bubble Sort algorithm
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
   ```
  </details>


  <details>
    <summary><i>sorting_stack</i></summary>
    
   ### void StackUtils<T>::sorting_stack()
   - Purpose: Sorts the elements of the stack in ascending order using a Bubble Sort algorithm.
   - Inputs: None.
   - Outputs: None.

   ### Implementation
   ```C++
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
   ```
  </details>

   <details>
    <summary><i>printStack</i></summary>
    
   ### void StackUtils<T>::printStack(StackUtils<T>& stack, const string& message)
   - Purpose: Prints the elements of the provided stack along with a message.
   - Inputs:  
      - stack: Reference to the stack whose elements need to be printed.
      - message: Message to be displayed before printing the elements. 
   - Outputs: None.

   ### Implementation
   ```C++
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
   ```
  </details>

  <details>
    <summary><i>getMin</i></summary>
    
   ### T StackUtils<T>::getMin()
   - Purpose: Retrieves the minimum element in the stack.
   - Inputs: None.
   - Outputs: The minimum element in the stack.

   ### Implementation
   ```C++
    template <typename T>
    T StackUtils<T>::getMin() {
        if (stackIsEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
   
        T minElement = stack[top];
        for (int i = 0; i <= top; i++) {
            if (stack[i] < minElement) {
                minElement = stack[i];
            }
        }
   
        return minElement;
    }
   ```
  </details>
  
   
</details>


[//]: # (Book Functions)



[//]: # (Queue Functions)


<details>
  <summary><h3><b>Queue Functions</b></h3></summary>
   
  <details>
    <summary><i>Constructor</i></summary>
    
   ### QueueUtils<T>::QueueUtils(int size) 
   - Purpose: Constructor for QueueUtils class.
   - Inputs: Size of the queue.
   - Outputs: None.

   ### Implementation
   ```C++
    template <typename T>
    QueueUtils<T>::QueueUtils(int size) {
        this->size = size;
        queue = new T[size];
        front = 0;
        rear = -1;
        count = 0;
    }
   ```
  </details>

   <details>
    <summary><i>Destructor</i></summary>
    
   ### QueueUtils<T>::~QueueUtils()
   - Purpose: Destructor for QueueUtils class.
   - Inputs: None.
   - Outputs: None.

   ### Implementation
   ```C++
     template <typename T>
     QueueUtils<T>::~QueueUtils() {
         delete[] queue;
     }
   ```
  </details>

   <details>
    <summary><i>Copy constructor</i></summary>
    
   ### QueueUtils<T>::QueueUtils(const QueueUtils<T> &q)
   - Purpose: Copy constructor for QueueUtils class.
   - Inputs: Another QueueUtils object.
   - Outputs: None.

   ### Implementation
   ```C++
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
   ```
  </details>

  <details>
    <summary><i>enqueue</i></summary>
    
   ### void QueueUtils<T>::enqueue(T item)
   - Purpose: Adds an element to the queue.
   - Inputs: Element to be added.
   - Outputs: None.

   ### Implementation
   ```C++
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
   ```
  </details>

  <details>
    <summary><i>dequeue</i></summary>
    
   ### T QueueUtils<T>::dequeue()
   - Purpose: Removes and returns the element from the front of the queue.
   - Inputs: None.
   - Outputs: Element removed from the queue (default value if empty).

   ### Implementation
   ```C++
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
   ```
  </details>

   <details>
    <summary><i>isEmpty</i></summary>
    
   ### bool QueueUtils<T>::isEmpty() const
   - Purpose: Checks if the queue is empty.
   - Inputs: None.
   - Outputs: Boolean indicating if the queue is empty.

   ### Implementation
   ```C++
          template <typename T>
          bool QueueUtils<T>::isEmpty() const {
              return count == 0;
          }
   ```
  </details>

   <details>
    <summary><i>isFull</i></summary>
    
   ### bool QueueUtils<T>::isFull() const
   - Purpose: Checks if the queue is full.
   - Inputs: None.
   - Outputs: Boolean indicating if the queue is full.

   ### Implementation
   ```C++
       template <typename T>
       bool QueueUtils<T>::isFull() const {
           return count == size;
       }
   ```
  </details>

  <details>
    <summary><i>display</i></summary>
    
   ### void QueueUtils<T>::display() const
   - Purpose: Displays the elements in the queue.
   - Inputs: None.
   - Outputs: None (prints queue elements if not empty).

   ### Implementation
   ```C++
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
   ```
  </details>


 <details>
    <summary><i>getMax</i></summary>
    
   ### T QueueUtils<T>::getMax()
   - Purpose: Retrieves the maximum element in the queue.
   - Inputs: None.
   - Outputs: The maximum element in the queue.

   ### Implementation
   ```C++
       template <typename T>
       T QueueUtils<T>::getMax() {
           if (isEmpty()) {
               throw std::runtime_error("Queue is empty");
           }
      
           T maxElement = queue[front];
           for (int i = front; i != rear; i = (i + 1) % size) {
               if (queue[i] > maxElement) {
                   maxElement = queue[i];
               }
           }
      
           // Check the rear element
           if (queue[rear] > maxElement) {
               maxElement = queue[rear];
           }
      
           return maxElement;
       }
   ```
  </details>


</details>



[//]: # (User Functions)


<details>
  <summary><h3><b>User Functions</b></h3></summary>
   
  <details>
    <summary><i>Constructor</i></summary>
    
   ### User::User() 
   - Purpose: Constructor that loads user data from a CSV file.
   - Inputs: None.
   - Outputs: None.

   ### Implementation
   ```C++
    User::User() {
       loadFromCSV("database/users.csv");
     }
   ```
  </details>

   <details>
    <summary><i>Destructor</i></summary>
    
   ### User::~User()
   - Purpose: Destructor that saves user data to a CSV file and empties the user_node.
   - Inputs: None.
   - Outputs: None.

   ### Implementation
   ```C++
     User::~User() {
          saveToCSV("database/users.csv");
          user_node.makeListEmpty();
     }
   ```
  </details>

   <details>
    <summary><i>display</i></summary>
    
   ### bool User::display(string& username, string& job_title)
   - Purpose: Displays login or registration options for users.
   - Inputs: References to store username and job_title.
   - Outputs: Boolean indicating if the user was authenticated or registered.

   ### Implementation
   ```C++
   bool User::display(string& username, string& job_title) {
       string input, password;
       char ask = 'N';
       int choose = 0;
       bool found;
   
       do {
           choose = getValidNumber<int>("Select Authentication: \n1)Login \n2)Register a new Account\n");
           if (choose == 1) {
               cout << "Enter Username: ";
               getline(cin, username);
               cout << "Enter Password: ";
               getline(cin, password);
   
               found = serach(username, password);
               if (!found) {
                   if (serach(username)) {
                       // User exists, but password is incorrect
                       cout << "Incorrect password for existing user. Would you like to login again? (Y/N)" << endl;
                   } else {
                       // User does not exist
                       cout << "User Not Found. Would you like to login again? (Y/N)" << endl;
                   }
                   getline(cin, input);
                   ask = !input.empty() ? input[0] : 'N';
               } else {
                   UserData data;
                   user_node.retrieveData(data);
                   cout << "\n'" << data.username << "' Welcome To Our Bookstore \n";
                   return true;
               }
           } else if (choose == 2) {
               cout << "Please Enter the username: ";
               getline(cin, username);
               cout << "Enter Password: ";
               getline(cin, password);
               cout << "Please Enter your job title: ";
               getline(cin, job_title);
   
               if (username.empty() || password.empty() || job_title.empty()) {
                   cout << "Username or password cannot be empty. Would you like to try again? (Y/N)" << endl;
                   getline(cin, input);
                   ask = !input.empty() ? input[0] : 'N';
                   continue;
               }
   
               found = serach(username);
               if (found) {
                   cout << "This User Already Exists. Would you like to try logging in? (Y/N)" << endl;
                   getline(cin, input);
                   ask = !input.empty() ? input[0] : 'N';
                   if (ask == 'Y' || ask == 'y') {
                       continue; // Redirect to login
                   }
               } else {
                   insert(username, password, job_title);
                   cout << "\n'" << username << "' Welcome To Bookstore \n";
                   saveToCSV("database/users.csv");
                   return true;
               }
           }
       } while (ask == 'Y' || ask == 'y');
   
       return false;
   }
   ```
  </details>

  <details>
    <summary><i>insert</i></summary>
    
   ### void User::insert(const string& username, const string& password, const string& job_title)
   - Purpose: Inserts a new user into the user_node.
   - Inputs: Username, password, and job title of the new user.
   - Outputs: None.

   ### Implementation
   ```C++
   void User::insert(const string&username, const string&password, const string&job_title) {
       UserData data;
       int key = 0;
       if (!user_node.currsorIsEmpty()) {
           user_node.toEnd();
           user_node.retrieveKey(key);
       }
   
       key++;
       data.job_title = job_title;
       data.username = username;
       data.password = password;
       user_node.insertEnd(key, data);
       saveToCSV("database/users.csv");
   }
   ```
  </details>

  <details>
    <summary><i>search</i></summary>
    
   ### bool User::search(const string& username)
   - Purpose: Searches for a specific username in the user_node.
   - Inputs: Username to search.
   - Outputs: Boolean indicating if the username exists.

   ### Implementation
   ```C++
   bool User::serach(const string&username) {
       bool found = false;
       UserData data;
       user_node.toFirst();
       while (!user_node.currsorIsEmpty()) {
           user_node.retrieveData(data);
           if (data.username == username)
               return true;
   
           user_node.advance();
       }
       return found;
   }
   ```
  </details>

   <details>
    <summary><i>search</i></summary>
    
   ### bool User::search(const string& username, const string& password)
   - Purpose: Searches for a specific username and password combination in the user_node.
   - Inputs: Username and password to search.
   - Outputs: Boolean indicating if the username and password match.

   ### Implementation
   ```C++
   bool User::serach(const string&username, const string&password) {
       bool found = false;
       UserData data;
       user_node.toFirst();
       while (!user_node.currsorIsEmpty()) {
           user_node.retrieveData(data);
           if (data.username == username && data.password == password)
               return true;
   
           user_node.advance();
       }
       return found;
   }
   ```
  </details>

   <details>
    <summary><i>size</i></summary>
    
   ### int User::size()
   - Purpose: Retrieves the number of users in the user_node.
   - Inputs: None.
   - Outputs: Integer representing the number of users.

   ### Implementation
   ```C++
      int User::size() {
          return user_node.listSize();
      }
   ```
  </details>

  <details>
    <summary><i>loadFromCSV</i></summary>
    
   ### void User::loadFromCSV(const string& filename)
   - Purpose: Loads user data from a CSV file into the user_node.
   - Inputs: Filename of the CSV file.
   - Outputs: None.
   - 
   ### Implementation
   ```C++
     void User::loadFromCSV(const string& filename) {
      
          // skip the first line
          locale::global(locale("C"));
      
          std::string data[MAX_ROWS][USER_MAX_COLS];
          int rowCount, colCount;
      
          try {
              readCSV<USER_MAX_COLS>(filename, data, rowCount, colCount); // Template argument added
              for (int i = 0; i < rowCount; ++i) {
                  string username = data[i][0];
                  string password = data[i][1];
                  string job_title = data[i][2];
      
                  // Basic validation example
                  if (!username.empty() && !password.empty() && !job_title.empty()) {
                      insert(username, password, job_title);
                  }
              }
          } catch (const std::exception& e) {
              cerr << "Error reading file: " << e.what() << endl;
          }
      }
   ```
  </details>


 <details>
    <summary><i>saveToCSV</i></summary>
    
   ### void User::saveToCSV(const string& filename)
   - Purpose: Saves user data from the user_node to a CSV file.
   - Inputs: Filename of the CSV file.
   - Outputs: None.

   ### Implementation
   ```C++
       void User::saveToCSV(const string& filename) {
          std::string data[MAX_ROWS][USER_MAX_COLS];
          int rowCount = 0;
      
          user_node.toFirst();
          UserData userData;
          while (!user_node.currsorIsEmpty() && rowCount < MAX_ROWS) {
              user_node.retrieveData(userData);
              data[rowCount][0] = userData.username;
              data[rowCount][1] = userData.password;
              data[rowCount][2] = userData.job_title;
              rowCount++;
              user_node.advance();
          }
      
          writeCSV<USER_MAX_COLS>(filename, data, rowCount, USER_MAX_COLS); // Template argument added
      }
   ```
  </details>


</details>


[//]: # (Input Utilities Functions)


<details>
  <summary><h3><b>Input Utilities Functions</b></h3></summary>
   
  <details>
    <summary><i>getValidNumber</i></summary>
    
   ### T getValidNumber(const string& prompt)
   - Purpose: Prompts the user for input until a valid number of type T is entered.
   - Inputs: A prompt message to display to the user.
   - Outputs: The valid number of type T entered by the user.

   ### Implementation
   ```C++
   template <typename T>
   T getValidNumber(const string& prompt) {
       T number;
       string input;
       bool isValid = false;
   
       while (!isValid) {
           cout << prompt;
           getline(cin, input);
           stringstream ss(input);
   
           if (ss >> number && !(ss >> input)) { // Check if input is a number and nothing follows
               isValid = true;
           } else {
               cout << "Invalid input. Please enter a valid number.\n";
           }
       }
       return number;
   }
   ```
  </details>

   
</details>


[//]: # (CSV Utilities Functions)


<details>
  <summary><h3><b>CSV Utilities Functions</b></h3></summary>
   
  <details>
    <summary><i>writeCSV</i></summary>
    
   ### void writeCSV(const std::string& filename, const std::string data[][MAX_COLS], int rowCount, int colCount)
   - Purpose: Writes data in CSV format to the specified file.
   - Inputs:
     - filename: Name of the file to write data to.
     - data: Two-dimensional array containing the data to write.
     - rowCount: Number of rows in the data.
     - colCount: Number of columns in the data.
   - Outputs: None.

   ### Implementation
   ```C++
   template <size_t MAX_COLS>
   void writeCSV(const std::string& filename, const std::string data[][MAX_COLS], int rowCount, int colCount) {
       std::ofstream fileOut(filename);
       if (!fileOut.is_open()) {
           throw std::runtime_error("Error opening file for writing");
       }
   
       for (int i = 0; i < rowCount; ++i) {
           for (int j = 0; j < colCount; ++j) {
               fileOut << data[i][j];
               if (j < colCount - 1) fileOut << ",";
           }
           fileOut << "\n";
       }
   
       fileOut.close();
   }
   ```
  </details>

  <details>
    <summary><i>readCSV</i></summary>
    
   ### void readCSV(const std::string& filename, std::string data[][MAX_COLS], int& rowCount, int& colCount)
   - Purpose: Reads data in CSV format from the specified file.
   - Inputs:
     - filename: Name of the file to read data from.
     - data: Two-dimensional array to store the read data.
     - rowCount: Reference to store the number of rows read.
     - colCount: Reference to store the number of columns read.
   - Outputs: None.

   ### Implementation
   ```C++
   template <size_t MAX_COLS>
   void readCSV(const std::string& filename, std::string data[][MAX_COLS], int& rowCount, int& colCount) {
       std::ifstream fileIn(filename);
       if (!fileIn.is_open()) {
           throw std::runtime_error("Error opening file for reading");
       }
   
       std::string line;
       rowCount = 0;
   
       while (std::getline(fileIn, line) && rowCount < 100) { // Assuming max 100 rows
           std::istringstream ss(line);
           std::string cell;
           int col = 0;
   
           while (std::getline(ss, cell, ',') && col < MAX_COLS) {
               data[rowCount][col++] = cell;
           }
   
           if (col > 0) { // Ensure we have at least one column
               rowCount++;
           }
       }
   
       colCount = (rowCount > 0) ? MAX_COLS : 0; // Set colCount to MAX_COLS if we have at least one row
       fileIn.close();
   }
   ```
  </details>

   
</details>








