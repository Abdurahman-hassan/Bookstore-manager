#ifndef BOOK_HEADER_H
#define BOOK_HEADER_H

#include <iostream>
#include "LinkedListUtils.h"
using namespace std;
using std::string;

class BookData {
public:
	string name;
	string category;
	float price;
	string author;
	bool isReserved;
	string reservedBy;
};

class Book
{
public:
	Book();
	Book(string&, string&);
	~Book();
	void initializeBookCollection();
	void insert(const string&, const string&, const float&, const string&);
	void update(const string&, const string&, const float&, const string&);
	void display();
	void displayAdmin();
	void adminSearchBook();
	void addBook();
	void displayUser();
	void userSearchBook();
	void displayDetailsAdmin(BookData&data, int key);
	void editBook(BookData &data, int key);
	void deleteBook(int key);
	void displayDetailsUser(BookData&);
	void reserveBook(int&);
	void reserveBook(BookData &data);
	bool serach(int&);
	bool serach(const string&);
	int size();
	void loadData();
	void printAll();
	void promptForBookAction();
	void myReservation();
	void printData(const BookData& data);
	void saveToCSV(const string& filename);
	void loadFromCSV(const string& filename);

private:
	LinkedListUtils<BookData> book_node;
	string username;
	string visitorName;
};

#endif //BOOK_HEADER_H