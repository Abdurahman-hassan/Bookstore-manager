#ifndef BOOK_HEADER_H
#define BOOK_HEADER_H

#include <iostream>
#include "GenericList.h"
using namespace std;
using std::string;

class BookData {
public:
	string name;
	string category;
	bool isReserved;
	string reservedBy;
};

class Book
{
public:
	Book();
	Book(string&, string&);
	~Book();
	void insert(const string&, const string&);
	void update(const string&, const string&);
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
	void printData(BookData);
private:
	GenericList<BookData> temp;
	string username;
	string visitorName;
};

#endif //BOOK_HEADER_H