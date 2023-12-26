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
	void insert(const string&, const string&, const float&, const string&);
	void update(const string&, const string&, const float&, const string&);
	void reserveBook(int&);
	void display();
	void displayAdmin();
	void displayUser();
	void displayDetailsAdmin(BookData&);
	void displayDetailsUser(BookData&);
	bool serach(int&);
	bool serach(const string&);
	int size();
	void loadData();
	void printAll();
	void myReservation();
	void printData(BookData);
private:
	LinkedListUtils<BookData> temp;
	string username;
	string visitorName;
};

#endif //BOOK_HEADER_H