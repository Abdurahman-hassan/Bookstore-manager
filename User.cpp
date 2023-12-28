#include <iostream>
#include "User.h"
#include "CSVUtils.h"
#include "InputUtils.h"

using namespace std;
using std::string;


User::User() {
    loadFromCSV("database/users.csv");
}

User::~User() {
    saveToCSV("database/users.csv");
    user_node.makeListEmpty();
}


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
