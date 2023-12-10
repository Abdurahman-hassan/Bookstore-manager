#include "linkedlist_header.h"
using namespace std;
// using std::string;

int main() {
    // Create a List of integers
    List<int> myList;

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
    } else {
        cout << "Key not found: " << keyToSearch << endl;
    }

    // Delete an element
    myList.deleteNode(); // Delete the current node

    // Traverse and print the list after deletion
    cout << "Traversing the list after deletion:" << endl;
    myList.traverse();

    return 0;
}
