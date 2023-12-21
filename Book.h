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
	~Book();
	void insert(const string&, const string&);
	void reserveBook(int&, const string&);
	void display(string&, bool&);
	bool serach(int&);
	bool serach(const string&);
	int size();
	void loadData();
private:
	GenericList<BookData> temp;
};

#endif //BOOK_HEADER_H