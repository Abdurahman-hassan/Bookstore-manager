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


void Book::insert(const string&name, const string&category,
                  const float&price, const string&author, bool isReserved,
                  const string&reservedBy, const string&reviews, float rating, int ratingCount) {
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
    data.isReserved = isReserved;
    data.reservedBy = reservedBy;
    data.reviews = reviews;
    data.ratings = rating;
    data.ratingCount = ratingCount;
    book_node.insertEnd(key, data);
    saveToCSV("database/books_database.csv");
}

void Book::update(const string&name, const string&category, const float&price,
                  const string&author, bool isReserved, const string&reservedBy,
                  const string&reviews, float rating, int ratingCount) {
    BookData data;
    data.name = (name != "") ? name : data.name;
    data.category = (category != "") ? category : data.category;
    data.price = (price > 0) ? price : data.price;
    data.author = (author != "") ? author : data.author;
    data.isReserved = isReserved;
    data.reservedBy = reservedBy;
    data.reviews = reviews;
    data.ratings = rating;
    data.ratingCount = ratingCount;
    book_node.updateData(data);
    saveToCSV("database/books_database.csv");
}

void Book::reserveBook(int key) {
    if (!book_node.search(key)) {
        cout << "Book not found." << endl;
        return;
    }

    BookData data;
    book_node.retrieveData(data);

    if (data.isReserved && data.reservedBy == username) {
        cout << "You have already reserved this book." << endl;
    } else if (data.isReserved) {
        cout << "This book is already reserved by another user." << endl;
    } else {
        data.isReserved = true;
        data.reservedBy = username;
        book_node.updateData(data);
        cout << "The book has been reserved successfully." << endl;
        saveToCSV("database/books_database.csv");
    }
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
        "4) Advanced Search\n"
        "5) Generate Reports\n"
        "6) Logout\n");

    switch (choice) {
        case 1: adminSearchBook();
            break;
        case 2: printAll();
            break;
        case 3: addBook();
            break;
        case 4: advancedSearch();
            break;
        case 5: generateReports();
            break;
        case 6: logout();
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

    insert(name, category, price, author, false, "", "", 0.0f, 0);
    cout << "Book added successfully\n";
}

void Book::displayUser() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int choice = getValidNumber<int>("Select the action you would like to perform: \n"
        "1) Book Search\n"
        "2) Display All Books\n"
        "3) Advanced Search\n"
        "4) My Reservation\n"
        // "5) Rate and Review Books\n"
        "6) Logout\n");

    switch (choice) {
        case 1: userSearchBook();
            break;
        case 2: printAll();
            break;
        case 3: advancedSearch();
            break;
        case 4:
            myReservation();
            break;
        // case 5: rateAndReviewBooks();
        //     break;
        case 5: logout();
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

void Book::displayDetailsAdmin(BookData&data, int key) {
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

    update(name, category, price, author, data.isReserved, data.reservedBy, data.reviews, data.ratings,
           data.ratingCount);
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
    }
    else {
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
        case 1:
            reserveBook(data);
            break;
        case 2:
            break; // Return to previous menu
        default: cout << "Invalid choice\n";
            break;
    }
}


void Book::reserveBook(BookData& data) {
    if (data.isReserved && data.reservedBy == username) {
        cout << "You have already reserved this book." << endl;
        return;
    } else if (data.isReserved) {
        cout << "This book is already reserved by another user." << endl;
        return;
    }

    data.isReserved = true;
    data.reservedBy = username;
    int key;
    book_node.retrieveKey(key); // Retrieve the key of the current book
    book_node.updateData(data); // Update the data in the linked list
    cout << "The book has been reserved successfully." << endl;
    saveToCSV("database/books_database.csv"); // Save changes to CSV
}


void Book::printAll() {
    reloadBookCollection(); // Reload data from CSV

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

void Book::promptForBookAction() {
    int bookNumber = getValidNumber<int>("Enter the book number to view details: ");

    int currentNumber = 1;
    bool bookFound = false;
    BookData data;

    book_node.toFirst();
    while (!book_node.currsorIsEmpty()) {
        if (currentNumber == bookNumber) {
            book_node.retrieveData(data); // Retrieve the data of the selected book
            bookFound = true;
            break;
        }
        book_node.advance();
        currentNumber++;
    }

    if (bookFound) {
        if (username == "admin") {
            displayDetailsAdmin(data, currentNumber);
        }
        else {
            displayDetailsUser(data);
        }
    }
    else {
        cout << "Book not found." << endl;
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
    cout << "\nBook Name: " << data.name << endl
            << "Category Name: " << data.category << endl
            << "Price: " << data.price << endl
            << "Author: " << data.author << endl;

    if (data.isReserved) {
        cout << "Reviews: " << data.reviews << endl
                << "Rating: " << data.ratings << "/5" << endl;
    }

    // Reserved details if admin
    if (username == "admin") {
        cout << "Is Reserved: " << (data.isReserved ? "Yes" : "No") << endl
                << "Reserved By: " << (data.isReserved ? data.reservedBy : "N/A") << endl;
    }
    cout << endl;
}


void Book::loadFromCSV(const string&filename) {
    // Set the locale to C to avoid issues with reading floats
    // skips the first row of the CSV file
    locale::global(locale("C"));

    const int MAX_ROWS = 100;
    const int MAX_COLS = 9;
    std::string data[MAX_ROWS][MAX_COLS];
    int rowCount, colCount;

    try {
        readCSV<MAX_COLS>(filename, data, rowCount, colCount);
        for (int i = 0; i < rowCount; ++i) {
            string name = data[i][0];
            string category = data[i][1];
            string priceStr = data[i][2];
            string author = data[i][3];
            string isReservedStr = data[i][4];
            string reservedBy = data[i][5];
            string reviews = data[i][6];
            string ratingsStr = data[i][7];
            string ratingCountStr = data[i][8];
            float price = 0.0f;
            float ratings = 0.0f;
            int ratingCount = 0;

            try {
                price = stof(priceStr);
                ratings = stof(ratingsStr);
                ratingCount = stoi(ratingCountStr);
            }
            catch (const exception&e) {
                cerr << "Error converting price for book " << name << "with price string" << priceStr << ": " << e.
                        what() << endl;
                continue; // Skip this entry and continue with the next
            }

            bool isReserved = (isReservedStr == "Yes");

            if (!name.empty()) {
                insert(name, category, price, author, isReserved, reservedBy, reviews, ratings, ratingCount);
            }
        }
    }
    catch (const std::exception&e) {
        cerr << "Error reading file: " << filename << " - " << e.what() << endl;
    }
}

void Book::saveToCSV(const string&filename) {
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
        data[rowCount][4] = bookData.isReserved ? "Yes" : "No";
        data[rowCount][5] = bookData.reservedBy;
        data[rowCount][6] = bookData.reviews;
        data[rowCount][7] = to_string(bookData.ratings);
        data[rowCount][8] = to_string(bookData.ratingCount);

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

void Book::advancedSearch() {
    int choice = getValidNumber<int>(
        "Advanced Search Options:\n1. By Author\n2. By Category\n3. By Price Range\nEnter your choice: ");

    switch (choice) {
        case 1: searchByAuthor();
            break;
        case 2: searchByCategory();
            break;
        case 3: searchByPriceRange();
            break;
        default: cout << "Invalid choice\n";
            break;
    }
}

void Book::searchByAuthor() {
    string author;
    cout << "Enter author's name: ";
    getline(cin, author);
    book_node.toFirst();
    bool found = false;
    while (!book_node.currsorIsEmpty()) {
        BookData data;
        book_node.retrieveData(data);
        if (data.author == author) {
            printData(data);
            found = true;
        }
        book_node.advance();
    }
    if (!found) {
        cout << "No books found by this author.\n";
    }
}

void Book::searchByCategory() {
    string category;
    cout << "Enter category: ";
    getline(cin, category);
    book_node.toFirst();
    bool found = false;
    while (!book_node.currsorIsEmpty()) {
        BookData data;
        book_node.retrieveData(data);
        if (data.category == category) {
            printData(data);
            found = true;
        }
        book_node.advance();
    }
    if (!found) {
        cout << "No books found in this category.\n";
    }
}

void Book::searchByPriceRange() {
    float minPrice, maxPrice;
    cout << "Enter minimum price: ";
    minPrice = getValidNumber<float>("");
    cout << "Enter maximum price: ";
    maxPrice = getValidNumber<float>("");

    book_node.toFirst();
    bool found = false;
    while (!book_node.currsorIsEmpty()) {
        BookData data;
        book_node.retrieveData(data);
        if (data.price >= minPrice && data.price <= maxPrice) {
            printData(data);
            found = true;
        }
        book_node.advance();
    }
    if (!found) {
        cout << "No books found in this price range.\n";
    }
}

// Generate Reports function
void Book::generateReports() {
    int choice = getValidNumber<int>(
        "Report Options:\n1. Total number of books\n2. Books by Category\n3. Reserved Books\nEnter your choice: ");

    switch (choice) {
        case 1: reportTotalBooks();
            break;
        case 2: reportBooksByCategory();
            break;
        case 3: reportReservedBooks();
            break;
        default: cout << "Invalid choice\n";
            break;
    }
}

// Report Total Number of Books
void Book::reportTotalBooks() {
    cout << "Total number of books: " << book_node.listSize() << endl;
}

// Function to generate a report of books by category
void Book::reportBooksByCategory() {
    string categories[MAX_CATEGORIES];
    int counts[MAX_CATEGORIES] = {0};
    int numCategories = 0;

    book_node.toFirst();
    while (!book_node.currsorIsEmpty()) {
        BookData data;
        book_node.retrieveData(data);

        // Check if the category is already recorded
        bool categoryFound = false;
        for (int i = 0; i < numCategories; ++i) {
            if (categories[i] == data.category) {
                counts[i]++;
                categoryFound = true;
                break;
            }
        }

        // If category not found, add it to the array
        if (!categoryFound && numCategories < MAX_CATEGORIES) {
            categories[numCategories] = data.category;
            counts[numCategories] = 1;
            numCategories++;
        }

        book_node.advance();
    }

    // Display the results
    cout << "Books by Category:\n";
    for (int i = 0; i < numCategories; ++i) {
        cout << categories[i] << ": " << counts[i] << endl;
    }
}


void Book::reportReservedBooks() {
    int reservedCount = 0;
    book_node.toFirst();
    while (!book_node.currsorIsEmpty()) {
        BookData data;
        book_node.retrieveData(data);
        if (data.isReserved) {
            reservedCount++;
        }
        book_node.advance();
    }

    cout << "Total reserved books: " << reservedCount << endl;
}

//
// void Book::rateAndReviewBooks() {
//     int bookNumber = getValidNumber<int>("Enter the book number to view details: ");
//
//     int currentNumber = 1;
//     bool bookFound = false;
//     BookData data;
//
//     book_node.toFirst();
//     while (!book_node.currsorIsEmpty()) {
//         if (currentNumber == bookNumber) {
//             book_node.retrieveData(data); // Retrieve the data of the selected book
//             bookFound = true;
//             break;
//         }
//         book_node.advance();
//         currentNumber++;
//     }
//
//     if (bookFound) {
//         displayBookRatingAndReviews(currentNumber);
//         int choice = getValidNumber<int>("Select the action you would like to perform: \n"
//             "1) Add Review\n"
//             "2) Add Rating\n"
//             "3) Display Reviews\n"
//             "4) Display Ratings\n"
//             "5) Back To Home\n");
//
//         switch (choice) {
//             case 1: addReview(currentNumber);
//                 break;
//             case 2: addRating(currentNumber);
//                 break;
//             case 3: displayReviews(currentNumber);
//                 break;
//             case 4: displayRatings(currentNumber);
//                 break;
//             case 5: break; // Return to previous menu
//             default: cout << "Invalid choice\n";
//                 break;
//         }
//     }
//     else {
//         cout << "Book not found." << endl;
//     }
// }
//
//
// void Book::displayBookRatingAndReviews(int bookKey) {
//     if (!book_node.search(bookKey)) {
//         cout << "Book not found." << endl;
//         return;
//     }
//
//     BookData data;
//     book_node.retrieveData(data);
//     cout << "Ratings for " << data.name << ": " << (data.ratingCount > 0 ? data.ratings / data.ratingCount : 0) << "/5"
//             << endl;
//     cout << "Reviews: \n" << data.reviews << endl;
// }
//
// void Book::addReview(int bookKey) {
//     if (!book_node.search(bookKey)) {
//         cout << "Book not found." << endl;
//         return;
//     }
//
//     BookData data;
//     book_node.retrieveData(data);
//
//     // Clear input buffer before reading the review
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//     cout << "Enter your review: ";
//     string review;
//     getline(cin, review);
//
//     // Append new review with proper formatting
//     if (!data.reviews.empty()) {
//         data.reviews += "\n"; // Add a new line if there are already existing reviews
//     }
//     data.reviews += username + ": " + review; // Append the new review
//     book_node.updateData(data);
//     saveToCSV("database/books_database.csv");
// }
//
//
// void Book::addRating(int bookKey) {
//     if (!book_node.search(bookKey)) {
//         cout << "Book not found." << endl;
//         return;
//     }
//
//     BookData data;
//     book_node.retrieveData(data);
//
//     cout << "Enter your rating (0-5): ";
//     float rating;
//     cin >> rating;
//
//     data.ratings += rating;
//     data.ratingCount++;
//     book_node.updateData(data);
//     saveToCSV("database/books_database.csv");
// }
//
// void Book::displayReviews(int bookKey) {
//     if (!book_node.search(bookKey)) {
//         cout << "Book not found." << endl;
//         return;
//     }
//
//     BookData data;
//     book_node.retrieveData(data);
//     cout << "Reviews for " << data.name << ":\n" << data.reviews << endl;
// }
//
// void Book::displayRatings(int bookKey) {
//     if (!book_node.search(bookKey)) {
//         cout << "Book not found." << endl;
//         return;
//     }
//
//     BookData data;
//     book_node.retrieveData(data);
//     cout << "Average rating for " << data.name << ": "
//             << (data.ratingCount > 0 ? data.ratings / data.ratingCount : 0) << "/5" << endl;
// }
