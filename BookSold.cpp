#include "BookSold.h"
#include "CSVUtils.h"
#include "InputUtils.h"
#include "StackUtils.h"

using namespace std;

BookSold::BookSold() {
    initializeBookCollection();
}

BookSold::BookSold(string& user, string& visitor) : username(user), visitorName(visitor) {
    initializeBookCollection();
}

BookSold::~BookSold() {
    saveToCSV();
    sold_node.makeListEmpty();
}

void BookSold::initializeBookCollection() {
    loadFromCSV();
}


void BookSold::display() {
    char actionChoice = 'Y';
    (username == "admin") ? displayAdmin() : displayUser();
}


void BookSold::displayAdmin() {
    reloadBookCollection(); // Reload data from CSV

    if (sold_node.isEmpty()) {
        cout << "There are no books sold" << endl;
        return;
    }

    sold_node.toFirst();
    BookSoldData data;
    int key;
    int bookNumber = 1;
    while (!sold_node.currsorIsEmpty()) {
        sold_node.retrieveKey(key);
        sold_node.retrieveData(data);
        cout << "Book Name: " << data.bookName << endl;
        cout << "Sold By: " << data.soldBy << endl;
        cout << "Price: " << data.price << endl;
        cout << "Quantity: " << data.qty << endl;
        cout << "Quantity: " << data.qty << endl;
        cout << "Total: " << (data.qty * data.price) << endl;
        sold_node.advance();
        bookNumber++;
    }
}


void BookSold::displayUser() {
    reloadBookCollection(); // Reload data from CSV

    if (sold_node.isEmpty()) {
        cout << "There are no books sold" << endl;
        return;
    }

    sold_node.toFirst();
    BookSoldData data;
    int key;
    int bookNumber = 1;
    while (!sold_node.currsorIsEmpty()) {
        sold_node.retrieveKey(key);
        sold_node.retrieveData(data);
        if (data.soldBy == username) {
            cout <<"Book Name: " << data.bookName<<endl;
            cout <<"Price: " << data.price<<endl;
            cout <<"Quantity: " << data.qty<<endl;
            cout <<"Quantity: " << data.qty<<endl;
            cout <<"Total: " << (data.qty * data.price)<<endl;
        }
        sold_node.advance();
        bookNumber++;
    }
}

void BookSold::loadList(const string& bookName, const string& soldBy, const float& price, const string& author, int& qty) {
    BookSoldData data, curr;
    int key = 0;
    key++;
    data.bookName = bookName;
    data.soldBy = soldBy;
    data.price = price;
    data.author = author;
    data.qty = qty;
    sold_node.insertEnd(key, data);
}

void BookSold::insert(const string& bookName, const string& soldBy, const float& price, const string& author) {
    BookSoldData data;
    int key = 0;
   /* if (!sold_node.currsorIsEmpty()) {
        sold_node.toEnd();
        sold_node.retrieveKey(key);
    }*/

   // Check if the book has been sold to the user. If true update the quantity (increment by 1)
    if (checkIsExist(bookName, soldBy, price)) { 
        updateCount();
    }

    else {
        key++;
        data.bookName = bookName;
        data.soldBy = soldBy;
        data.price = price;
        data.author = author;
        data.qty = 1;
        sold_node.insertEnd(key, data);
        saveToCSV();
    }
    
}

void BookSold::update(const string& bookName, const string& soldBy, const float& price, const string& author, int& qty) {
    BookSoldData data;
    data.bookName = (bookName != "") ? bookName : data.bookName;
    data.soldBy = (soldBy != "") ? soldBy : data.soldBy;
    data.price = (price > 0) ? price : data.price;
    data.author = (author != "") ? author : data.author;
    data.qty = (qty > 0) ? qty: data.qty;
    
    sold_node.updateData(data);
    saveToCSV();
}


void BookSold::updateCount() {
    BookSoldData data;
    sold_node.retrieveData(data);
    data.qty++;
    update(data.bookName, data.soldBy, data.price, data.author, data.qty);
}


bool BookSold::checkIsExist(const string& bookName, const string& soldBy, const float& price) {
    bool found = false;
    BookSoldData data; int key;
    sold_node.toFirst();
    while (!sold_node.currsorIsEmpty())
    {
        sold_node.retrieveData(data);
        if (data.bookName == bookName && data.soldBy == soldBy && data.price == price) {
            return true;
        }
        sold_node.advance();
    }

    return found;
}

void BookSold::mySold(const string& soldBy) {
    bool found = false;
    BookSoldData data;
    sold_node.toFirst();
    while (!sold_node.currsorIsEmpty())
    {
        sold_node.retrieveData(data);
        if (data.soldBy == soldBy) {
            cout << "\nBook Name: " << data.bookName << endl
                 << "Author: " << data.author << endl
                 << "Price: " << data.price << endl
                 << "Qty: " << data.qty << endl
                 << "Total: " << (data.qty * data.price) << endl;

            cout << "-----------------------------------------\n";
        }

        sold_node.advance();
    }
}

bool BookSold::search(const string& bookName, const float& price, const string& author) {
    bool found = false;
    BookSoldData data;
    sold_node.toFirst();
    while (!sold_node.currsorIsEmpty())
    {
        sold_node.retrieveData(data);
        if (data.bookName == bookName && data.price == price && data.author == author) {
            return true;
        }

        sold_node.advance();
    }

    return found;
}

bool BookSold::checkHasSold(const string& soldBy) {
    bool found = false;
    BookSoldData data;
    sold_node.toFirst();
    while (!sold_node.currsorIsEmpty())
    {
        sold_node.retrieveData(data);
        if (data.soldBy == soldBy) {
            return true;
        }
        sold_node.advance();
    }

    return found;
}


void BookSold::retrieveData(BookSoldData& data) {
    sold_node.retrieveData(data);
}


void BookSold::displayDescending(const string& soldBy) {
    reloadBookCollection(); // Reload data from CSV
    StackUtils<BookSoldData> stack;
    sortDescending(soldBy, stack);

    BookSoldData data;
    while (!stack.stackIsEmpty())
    {
        stack.pop(data);
        cout << "\nBook Name: " << data.bookName << endl
            << "Author: " << data.author << endl
            << "Price: " << data.price << endl
            << "Qty: " << data.qty << endl
            << "Total: " << (data.qty * data.price) << endl;

        cout << "-----------------------------------------\n";
    }
}

void BookSold::displayAscending(const string& soldBy) {
    reloadBookCollection(); // Reload data from CSV
    QueueUtils<BookSoldData> queue;
    sortAscending(soldBy, queue);
    BookSoldData data;
    while (!queue.isEmpty())
    {
        data = queue.dequeue();
        cout << "\nBook Name: " << data.bookName << endl
            << "Author: " << data.author << endl
            << "Price: " << data.price << endl
            << "Qty: " << data.qty << endl
            << "Total: " << (data.qty * data.price) << endl;

        cout << "-----------------------------------------\n";
    }

}


void BookSold::sortDescending(const string& soldBy, StackUtils<BookSoldData>& stack) {
    LinkedListUtils<BookSoldData> nodeList;
    BookSoldData data;
    sold_node.toFirst();
    while (!sold_node.currsorIsEmpty())
    {
        sold_node.retrieveData(data);
        if (data.soldBy == soldBy) {
            nodeList.orderInsert(data.qty, data);
       }
        sold_node.advance();
    }
    
    nodeList.toFirst();
    while (!nodeList.currsorIsEmpty())
    {
        nodeList.retrieveData(data);
        stack.push(data);
        nodeList.advance();
    }

    nodeList.makeListEmpty();

}


void BookSold::sortAscending(const string& soldBy, QueueUtils<BookSoldData>& queue) {
    LinkedListUtils<BookSoldData> nodeList;
    BookSoldData data;
    sold_node.toFirst();
    while (!sold_node.currsorIsEmpty())
    {
        sold_node.retrieveData(data);
        if (data.soldBy == soldBy) {
            nodeList.orderInsert(data.qty, data);
        }
        sold_node.advance();
    }

    nodeList.toFirst();
    while (!nodeList.currsorIsEmpty())
    {
        nodeList.retrieveData(data);
        queue.enqueue(data);
        nodeList.advance();
    }

    nodeList.makeListEmpty();
}


void BookSold::reloadBookCollection() {
    sold_node.makeListEmpty();
    loadFromCSV(); // Reload data from CSV
}

void BookSold::loadFromCSV() {
    // Set the locale to C to avoid issues with reading floats
    // skips the first row of the CSV file
    locale::global(locale("C"));

    const int MAX_ROWS = 100;
    const int MAX_COLS = 5;
    std::string data[MAX_ROWS][MAX_COLS];
    int rowCount, colCount;

    try {
        readCSV<MAX_COLS>(File_Name, data, rowCount, colCount);
        for (int i = 0; i < rowCount; ++i) {
            string name = data[i][0];
            string soldBy = data[i][1];
            string priceStr = data[i][2];
            string qtyStr = data[i][3];
            string author = data[i][4];
            float price = 0.0f;
            int qty;
            try {
                //price = stof(priceStr);
                char* ending;
                price = strtof(priceStr.c_str(), &ending);//stof(priceStr);
                qty = strtof(qtyStr.c_str(), &ending);//stof(priceStr);
            }
            catch (const exception& e) {
                cerr << "Error converting price for book " << name << "with price string" << priceStr << ": " << e.
                    what() << endl;
                continue; // Skip this entry and continue with the next
            }

            if (!name.empty()) {
                loadList(name, soldBy, price, author, qty);
            }
        }
    }
    catch (const std::exception& e) {
        cerr << "Error reading file: " << File_Name << " - " << e.what() << endl;
    }
}

void BookSold::saveToCSV() {
    std::string data[MAX_ROWS][SOLD_MAX_COLS];
    int rowCount = 0;

    sold_node.toFirst();
    BookSoldData bookData;
    while (!sold_node.currsorIsEmpty() && rowCount < MAX_ROWS) {
        sold_node.retrieveData(bookData);
        data[rowCount][0] = bookData.bookName;
        data[rowCount][1] = bookData.soldBy;
        data[rowCount][2] = to_string(bookData.price);
        data[rowCount][3] = to_string(bookData.qty);
        data[rowCount][4] = bookData.author;
        rowCount++;
        sold_node.advance();
    }

    writeCSV<SOLD_MAX_COLS>(File_Name, data, rowCount, SOLD_MAX_COLS);
}