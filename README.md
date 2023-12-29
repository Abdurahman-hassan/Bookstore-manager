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
        - Hash Table: Store and retrieve user credentials rapidly, ensuring quick login and registration processes.
    
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
   
</details>
















