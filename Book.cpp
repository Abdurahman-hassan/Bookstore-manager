#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;
using std::string;


Book::Book()
{
	
}

Book::Book(string& user, string& visitor) {
	visitorName = visitor;
	username = user;

	insert("c++","CS", 300, "Sams");
	insert("math","MS",300,"Abdel Hady");
	insert("asp","CS",250,"Sams");
	insert("php","CS",200,"Sams");
	insert("pmp","OR",350,"Hamdy Attia");
}

Book::~Book()
{
	temp.makeListEmpty();
}


void Book::display()
{
	char ask = 'N';
	int chose = 0;
	string name, category;
	bool found = false;

	do {
		cout << endl;
		if (username == "admin") 
		{
			displayAdmin();
			cout << "Would you like to take another action?(Y/N)\n" << endl;
			cin >> ask;
		}

		else 
		{
			displayUser();
			cout << "Would you like to take another action?(Y/N)\n" << endl;
			cin >> ask;
		}

	} while (ask != 'N' && ask != 'n');

}


void Book::insert(const string& name, const string& category, const float& price, const string& author)
{
	BookData data, curr;
	int key = 0;
	if (!temp.currsorIsEmpty()) {
		temp.toEnd();
		temp.retrieveKey(key);
	}
	
	key++;
	data.name = name;
	data.category = category;
	data.price = price;
	data.author = author;
	temp.insertEnd(key, data);
}

void Book::update(const string& name, const string& category, const float& price, const string& author)
{
	BookData data;
	data.name = (name !="")? name : data.name;
	data.category = (category !="")? category : data.category;
	data.price = (price >0)? price : data.price;
	data.author = (author !="") ? author : data.author;
	temp.updateData(data);
}

void Book::reserveBook(int& key)
{
	bool found = false;
	found = serach(key);
	if (found) {
		BookData data;
		temp.retrieveData(data);
		data.isReserved = true;
		data.reservedBy = username;
		temp.updateData(data);
		cout << "The book has been updated successfully"<<endl;
	}
	else {
		cout << "Not Found\n";
	}

}

bool Book::serach(int& key)
{
	bool found = false;  BookData data;
	temp.toFirst();
	found = temp.search(key);
	if (found)
		temp.retrieveData(data);

	return found;
}

bool Book::serach(const string& name)
{
	bool found = false; BookData data;
	temp.toFirst();

	while (!temp.currsorIsEmpty())
	{
		temp.retrieveData(data);
		if (data.name == name)
			return true;

		temp.advance();
	}
	return found;
}


int Book::size()
{
	return temp.listSize();
}


void Book::loadData()
{

}


void Book::displayAdmin()
{
	int chose = 0;
	float price;
	string name, category, author;
	bool found = false;

	if (chose == 0)
	{
		cout << "Select Please choose the action you would like to perform: \n"
			<< "1) Search \n" << "2) Display All \n" << "3) Add \n";

		cin >> chose;
	}

	if (chose == 1)
	{
		cout << "Enter Book Name: ";
		cin >> name;
		found = serach(name);
		if (found) {

		}
		else {
			cout << "Not Found \n";
		}
	}

	else if (chose == 2) 
	{
		printAll();
	}

	else if (chose == 3)
	{
		cout << "Enter Book Name: ";       cin >> name;
		cout << "Enter Category Name: ";   cin >> category;
		cout << "Enter Author Name: ";     cin >> author;
		cout << "Enter Price: ";		   cin >> price;

		insert(name, category, price, author);
		cout << "The book has been added successfully\n";

	}
	
}

void Book::displayUser() 
{
	string name;
	int chose = 0;
	bool found = false;
	BookData data;

	if (chose == 0)
	{
		cout << "Select Please choose the action you would like to perform: \n"
			<< "1) Search \n" << "2) Display All \n" << "3) My Reservation \n";

		cin >> chose;
	}

	if (chose == 1)
	{
		cout << "Enter Book Name: ";
		cin >> name;
		found = serach(name);
		if (found) {
			temp.retrieveData(data);
			displayDetailsUser(data);
		}
		else {
			cout << "Not Found \n";
		}
	}
	else if (chose == 2) {
		printAll();
	}
	else if (chose == 3)
	{
		myReservation();
	}
}

void Book::displayDetailsAdmin(BookData& data)
{
	int chose = 0;
	float price;
	string name, category, author;
	if (chose == 0)
	{
		cout << "Select Please choose the action you would like to perform: \n"
			<< "1) Edit \n" << "2) Delete \n" << "3) Back To Home \n";

		cin >> chose;
	}

	if (chose == 1)
	{
		cout << "Enter Book Name: ";       cin >> name;
		cout << "Enter Category Name: ";   cin >> category;
		cout << "Enter Author Name: ";     cin >> author;
		cout << "Enter Price: ";		   cin >> price;

		update(name, category, price, author);
		cout << "The book has been added successfully\n";
	}
	else if (chose == 2) {
		temp.deleteNode();
		cout << "The book has been deleted successfully\n";
		display();
	}

	else if (chose == 3)
	{
		display();
	}
}

void Book::displayDetailsUser(BookData& data)
{
	int chose = 0;
	string name, category;
	if (chose == 0)
	{
		cout << "Select Please choose the action you would like to perform: \n"
			<< "1) Reserve \n" << "2) Back To Home \n";

		cin >> chose;
	}

	if (chose == 1)
	{
		int key;
		temp.retrieveKey(key);
		reserveBook(key);
	}

	else if (chose == 2)
	{
		display();
	}
}


void Book::printAll() 
{
	if (!temp.isEmpty()) {
		temp.toFirst();
		BookData data;
		int key;
		while (!temp.currsorIsEmpty())
		{
			temp.retrieveKey(key);
			temp.retrieveData(data);
			temp.advance();
			if (username != "admin" && !data.isReserved) {
				cout << key <<") Book Name: " << data.name << endl;
			}
			else {
				cout << key << ") Book Name: " << data.name << endl;
			}

		}
		cout << "Please select the book on which you would like to perform the action: \n";
		cin >> key;

		temp.search(key);
		temp.retrieveData(data);
		
		if (username == "admin") {
			temp.search(key);
			displayDetailsAdmin(data);
		}
		else {
			displayDetailsUser(data);
		}
	}
	else {
		cout << "There are no books available" << endl;
	}
}

void Book::myReservation() 
{
	if (!temp.isEmpty()) {
		temp.toFirst();
		BookData data;
		int key;
		bool chk = false;
		while (!temp.currsorIsEmpty())
		{
			temp.retrieveData(data);
			temp.advance();
			if (data.reservedBy == username) {
				printData(data);
				chk = true;
			}
		}

		if(!chk)
			cout << "You don't have a reservation" << endl;
	}
	else {
		cout << "There are no books available" << endl;
	}
}

void Book:: printData(BookData data)
{
	cout << "Book Name: " << data.name<<endl;
	cout << "Category Name: " << data.category<<endl;
	cout << "Price: " << data.price<<endl;
	cout << "Author: " << data.author<<endl;
	
	if (username == "admin") {
		cout << "Is Reserved: " << data.isReserved << endl;
		cout << "Reserved By: " << data.reservedBy << endl;
	}
}
