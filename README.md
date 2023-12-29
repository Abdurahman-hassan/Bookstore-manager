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



  

  
</details>

















