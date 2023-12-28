#include "Book.h"
#include "CSVUtils.h"
#include "InputUtils.h"

using namespace std;

Book::Book() {
}

Book::Book(string&user, string&visitor) : username(user), visitorName(visitor) {
    initializeBookCollection();
}

Book::~Book() {
    saveToCSV("database/books_database.csv");
    book_node.makeListEmpty();
}

void Book::initializeBookCollection() {
    loadFromCSV("database/books_database.csv");
}

void Book::display() {
    char actionChoice = 'Y';
    while (toupper(actionChoice) == 'Y') {
        (username == "admin") ? displayAdmin() : displayUser();
        cout << "Would you like to take another action? (Y/ Anykey for exit)\n";
        cin >> actionChoice;
        if (toupper(actionChoice) != 'Y') {
            logout();
        }
    }
}


void Book::insert(const string&name, const string&category, const float&price, const string&author) {
    BookData data, curr;
    int key = 0;
    if (!book_node.currsorIsEmpty()) {
        book_node.toEnd();
        book_node.retrieveKey(key);
    }

    key++;
    data.name = name;
    data.category = category;
    data.price = price;
    data.author = author;
    book_node.insertEnd(key, data);
    saveToCSV("database/books_database.csv");
}

void Book::update(const string&name, const string&category, const float&price, const string&author) {
    BookData data;
    data.name = (name != "") ? name : data.name;
    data.category = (category != "") ? category : data.category;
    data.price = (price > 0) ? price : data.price;
    data.author = (author != "") ? author : data.author;
    book_node.updateData(data);
    saveToCSV("database/books_database.csv");
}

void Book::reserveBook(int&key) {
    bool found = false;
    found = serach(key);
    if (found) {
        BookData data;
        book_node.retrieveData(data);
        data.isReserved = true;
        data.reservedBy = username;
        book_node.updateData(data);
        cout << "The book has been updated" << endl;
    }
    else {
        cout << "Not Found\n";
    }
    saveToCSV("database/books_database.csv");
}

bool Book::serach(int&key) {
    bool found = false;
    BookData data;
    book_node.toFirst();
    found = book_node.search(key);
    if (found)
        book_node.retrieveData(data);
    return found;
}

bool Book::serach(const string&name) {
    bool found = false;
    BookData data;
    book_node.toFirst();

    while (!book_node.currsorIsEmpty()) {
        book_node.retrieveData(data);
        if (data.name == name)
            return true;

        book_node.advance();
    }
    return found;
}


int Book::size() {
    return book_node.listSize();
}

void Book::displayAdmin() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int choice = getValidNumber<int>("Select the action you would like to perform: \n"
                                 "1) Search\n"
                                 "2) Display All\n"
                                 "3) Add\n"
                                 "4) Logout\n");

    switch (choice) {
        case 1: adminSearchBook();
            break;
        case 2: printAll();
            break;
        case 3: addBook();
            break;
        case 4: logout();
            break;
        default: cout << "Invalid choice\n";
            break;
    }
}

void Book::adminSearchBook() {
    string name;
    cout << "Enter Book Name: ";
    cin >> name;
    if (serach(name)) {
        cout << "The book has been found successfully in our system\n";
        BookData data;
        book_node.retrieveData(data);

        int key;
        book_node.retrieveKey(key);
        displayDetailsAdmin(data, key);
    }
    else {
        cout << "Not Found\n";
    }
}

void Book::addBook() {
    string name, category, author;
    float price;
    cout << "Enter Book Name: ";
    cin >> name;
    cout << "Enter Category Name: ";
    cin >> category;
    cout << "Enter Author Name: ";
    cin >> author;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    price = getValidNumber<float>("Enter Price: ");

    insert(name, category, price, author);
    cout << "Book added successfully\n";
}

void Book::displayUser() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int choice = getValidNumber<int>("Select the action you would like to perform: \n"
                                 "1) Search\n"
                                 "2) Display All\n"
                                 "3) My Reservation\n"
                                 "4) Logout\n");

    switch (choice) {
        case 1: userSearchBook();
            break;
        case 2: printAll();
            break;
        case 3: myReservation();
            break;
        case 4: logout();
            break;
        default: cout << "Invalid choice\n";
            break;
    }
}

void Book::userSearchBook() {
    string name;
    cout << "Enter Book Name: ";
    cin >> name;
    if (serach(name)) {
        BookData data;
        book_node.retrieveData(data);
        displayDetailsUser(data);
    }
    else {
        cout << "Not Found\n";
    }
}

void Book::displayDetailsAdmin(BookData& data, int key) {
    printData(data);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int choice = getValidNumber<int>("Select the action you would like to perform: \n"
                                 "1) Edit\n"
                                 "2) Delete\n"
                                 "3) Back To Home\n");

    switch (choice) {
        case 1:
            editBook(data, key);
        break;
        case 2:
            deleteBook(key);
        break;
        case 3:
                break;
        default:
            cout << "Invalid choice\n";
        break;
    }
}

void Book::editBook(BookData&data, int key) {
    string name, category, author;
    float price;
    cout << "Enter the new Book Name: ";
    cin >> name;
    cout << "Enter the new Category Name: ";
    cin >> category;
    cout << "Enter the new Author Name: ";
    cin >> author;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    price = getValidNumber<float>("Enter Price: ");

    update(name, category, price, author);
    cout << "The book has been updated successfully\n";
}

void Book::deleteBook(int bookNumber) {
    int currentNumber = 1;
    book_node.toFirst();
    while (!book_node.currsorIsEmpty() && currentNumber != bookNumber) {
        book_node.advance();
        currentNumber++;
    }

    if (currentNumber == bookNumber) {
        book_node.deleteNode();
        cout << "The book has been deleted successfully\n";
    } else {
        cout << "Book not found for deletion." << endl;
    }
    saveToCSV("database/books_database.csv");
}


void Book::displayDetailsUser(BookData&data) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int choice = getValidNumber<int>("Select the action you would like to perform: \n"
                                 "1) Reserve\n"
                                 "2) Back To Home\n");

    switch (choice) {
        case 1: reserveBook(data);
            break;
        case 2: break; // Return to previous menu
        default: cout << "Invalid choice\n";
            break;
    }
}

void Book::reserveBook(BookData&data) {
    int key;
    book_node.retrieveKey(key);
    reserveBook(key);
    cout << "The book has been reserved successfully\n";
}

void Book::printAll() {
    if (book_node.isEmpty()) {
        cout << "There are no books available" << endl;
        return;
    }

    book_node.toFirst();
    BookData data;
    int key;
    int bookNumber = 1;
    while (!book_node.currsorIsEmpty()) {
        book_node.retrieveKey(key);
        book_node.retrieveData(data);
        cout << bookNumber << ") Book Name: " << data.name;
        if (username == "admin" && data.isReserved) {
            cout << " (Reserved)";
        }
        cout << endl;
        book_node.advance();
        bookNumber++;
    }
    promptForBookAction();
}

// void Book::promptForBookAction() {
//     int selectedNumber;
//     cout << "Please select the book number on which you would like to perform the action: \n";
//     cin >> selectedNumber;
//
//     // Convert selected number to corresponding key
//     book_node.toFirst();
//     int currentNumber = 1; // Start from the first book
//     int key;
//     bool bookFound = false;
//
//     while (!book_node.currsorIsEmpty()) {
//         book_node.retrieveKey(key);
//         if (currentNumber == selectedNumber) {
//             bookFound = true;
//             break;
//         }
//         book_node.advance();
//         currentNumber++;
//     }
//
//     if (!bookFound) {
//         cout << "Book not found." << endl;
//         return;
//     }
//
//     if (bookFound) {
//         BookData data;
//         book_node.search(key);  // Search for the book with the corresponding key
//         book_node.retrieveData(data);
//
//         if (username == "admin") {
//             displayDetailsAdmin(data, key);  // Pass the key to the admin display function
//         } else {
//             displayDetailsUser(data);
//         }
//     } else {
//         cout << "Book not found." << endl;
//     }
// }

void Book::promptForBookAction() {
    int bookNumber = getValidNumber<int>("Enter the book number to view details: ");

    book_node.toFirst();
    int currentNumber = 1; // Start from the first book
    BookData data;
    bool bookFound = false;

    while (!book_node.currsorIsEmpty()) {
        if (currentNumber == selectedNumber) {
            book_node.retrieveData(data); // Retrieve the data of the currently pointed book
            bookFound = true;
            break;
        }
        book_node.advance();
        currentNumber++;
    }

    if (!bookFound) {
        cout << "Book not found." << endl;
        return;
    }

    if (bookFound) {
        if (username == "admin") {
            displayDetailsAdmin(data, selectedNumber); // For admin, display book details for potential editing or deleting
        } else {
            displayDetailsUser(data);
        }
    }
}



void Book::myReservation() {
    if (book_node.isEmpty()) {
        cout << "There are no books available" << endl;
        return;
    }

    book_node.toFirst();
    BookData data;
    bool hasReservation = false;
    while (!book_node.currsorIsEmpty()) {
        book_node.retrieveData(data);
        if (data.reservedBy == username) {
            printData(data);
            hasReservation = true;
        }
        book_node.advance();
    }

    if (!hasReservation) {
        cout << "You don't have any reservations" << endl;
    }
}

void Book::printData(const BookData&data) {
    cout << "Book Name: " << data.name << endl
            << "Category Name: " << data.category << endl
            << "Price: " << data.price << endl
            << "Author: " << data.author << endl;

    if (username == "admin") {
        cout << "Is Reserved: " << (data.isReserved ? "Yes" : "No") << endl;
        cout << "Reserved By: " << (data.isReserved ? data.reservedBy : "N/A") << endl;
    }
}


void Book::loadFromCSV(const string& filename) {
    const int MAX_ROWS = 100;
    const int MAX_COLS = 6;
    std::string data[MAX_ROWS][MAX_COLS];
    int rowCount, colCount;

    try {
        readCSV<MAX_COLS>(filename, data, rowCount, colCount);
        for (int i = 0; i < rowCount; ++i) {
            string name = data[i][0];
            string category = data[i][1];
            string priceStr = data[i][2];
            string author = data[i][3];
            float price = 0.0f;

            try {
                price = stof(priceStr);
            } catch(const exception& e) {
                cerr << "Error converting price for book '" << name << "' with price string '" << priceStr << "': " << e.what() << endl;
                continue; // Skip this entry and continue with the next
            }

            if (!name.empty()) {
                insert(name, category, price, author);
            }
        }
    } catch (const std::exception& e) {
        cerr << "Error reading file: " << filename << " - " << e.what() << endl;
    }
}

void Book::saveToCSV(const string& filename) {
    std::string data[MAX_ROWS][BOOK_MAX_COLS];
    int rowCount = 0;

    book_node.toFirst();
    BookData bookData;
    while (!book_node.currsorIsEmpty() && rowCount < MAX_ROWS) {
        book_node.retrieveData(bookData);
        data[rowCount][0] = bookData.name;
        data[rowCount][1] = bookData.category;
        data[rowCount][2] = to_string(bookData.price);
        data[rowCount][3] = bookData.author;

        rowCount++;
        book_node.advance();
    }

    writeCSV<BOOK_MAX_COLS>(filename, data, rowCount, BOOK_MAX_COLS);
}

void Book::logout() {
    cout << "Thank you for using our system\n";
    exit(0);
}

void Book::reloadBookCollection() {
    book_node.makeListEmpty();
    loadFromCSV("database/books_database.csv"); // Reload data from CSV
}

