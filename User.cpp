#include <iostream>
#include "User.h"
#include "CSVUtils.h"

using namespace std;
using std::string;


User::User() {
    loadFromCSV("users.csv");
}

User::~User() {
    saveToCSV("users.csv");
    user_node.makeListEmpty();
}


bool User::display(string&username, string&job_title) {
    string password;
    char ask = 'N';
    int choose = 0;
    bool found;
    do {
        cout << "Select Authentication: \n" << "1)Login \n" << "2)Register a new Account\n";
        cin >> choose;

        if (choose == 1) {
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            found = serach(username, password);
            if (!found) {
                cout << "User Not Found \n";
                cout << "Would you like to login again?(Y/N)" << endl;
                cin >> ask;
            }
            else {
                UserData data;
                user_node.retrieveData(data);
                cout << "\n'" << data.username << "' Welcome To Our Bookstore \n";
                break;
            }
        }

        else if (choose == 2) {
            cout << "Please Enter the username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            cout << "please Enter your job title: ";
            cin >> job_title;

            found = serach(username);
            if (found) {
                cout << "This User Already Exist \n" << endl;
                cout << "Would you like to Register again?(Y/N)" << endl;
                cin >> ask;
            }
            else {
                found = true;
                insert(username, password, job_title);
                cout << "\n'" << username << "' Welcome To Bookstore \n";
                saveToCSV("users.csv");
            }
        }
    }
    while (ask != 'N' && ask != 'n');

    return found;
}


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
    saveToCSV("users.csv");
}


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

int User::size() {
    return user_node.listSize();
}

void User::loadFromCSV(const string& filename) {
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
