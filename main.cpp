#include<iostream>
#include <string>
#include <fstream>
#include "User.h"
using namespace std;

int main()
{
    User usr;
    usr.display();


    // Create a List of integers
    GenericList<int> myList;

    // Check if the list is empty
    if (myList.isEmpty()) {
        cout << "The list is currently empty." << endl;
    }

    // Insert elements
    myList.insertFirst(1, 100); // Insert at the beginning
    myList.insertEnd(2, 200);   // Insert at the end
    myList.insertAfter(3, 300); // Insert after the current position

    // Traverse and print the list
    cout << "Traversing the list:" << endl;
    myList.traverse();

    // Search for an element
    int keyToSearch = 2;
    if (myList.search(keyToSearch)) {
        cout << "Found key: " << keyToSearch << endl;
    }
    else {
        cout << "Key not found: " << keyToSearch << endl;
    }

    // Delete an element
    myList.deleteNode(); // Delete the current node

    // Traverse and print the list after deletion
    cout << "Traversing the list after deletion:" << endl;
    myList.traverse();

	return 0;
}

void readFile() 
{

    ifstream ip("user.csv");

    if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string firstname;
    string lastname;
    string age;
    string weight;

    while (ip.good()) {

        getline(ip, firstname, ',');
        getline(ip, lastname, ',');
        getline(ip, age, ',');
        getline(ip, weight, '\n');

        std::cout << "Name: " << firstname << " " << lastname << '\n';
        std::cout << "Age: " << age << '\n';
        std::cout << "Weight: " << weight << '\n';
        std::cout << "-------------------" << '\n';
    }

    ip.close();
}