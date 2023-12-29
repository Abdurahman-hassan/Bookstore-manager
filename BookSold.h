#ifndef BOOKSOLD_HEADER_H
#define BOOKSOLD_HEADER_H

#include <iostream>
#include "LinkedListUtils.h"
using namespace std;
using std::string;

const string File_Name = "database/sold_books_database.csv";

class BookSoldData {
public:
	string bookName;
	string soldBy;
	float price;
	int qty;
	string author;
};

class BookSold
{
public:
	BookSold();
	BookSold(string&, string&);
	~BookSold();
	void initializeBookCollection();
	void loadList(const string& bookName, const string& soldBy, const float& price, const string& author);
	void insert(const string& bookName, const string& soldBy, const float& price, const string& author);
	void update(const string& bookName, const string& soldBy, const float& price, const string& author, int& qty);
	void updateCount();
	void display();
	void displayAdmin();
	void displayUser();
	bool checkIsExist(const string& bookName, const string& soldBy, const float& price);
	bool checkHasSold(const string& soldBy);
	void saveToCSV();
	void loadFromCSV();
	void reloadBookCollection();
	void mySold(const string& soldBy);
	bool search(const string& bookName, const float& price, const string& author);
	void retrieveData(BookSoldData& data);

private:
	LinkedListUtils<BookSoldData> sold_node;
	string username;
	string visitorName;
};

#endif //BOOK_SOLD_HEADER_H#pragma once
