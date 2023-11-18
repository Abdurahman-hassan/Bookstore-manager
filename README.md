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
