#include <iostream>
#include "Book.h"
using namespace std;
using std::string;


Book::Book()
{
	
}

Book::~Book()
{
	temp.makeListEmpty();
}


void Book::display(string& username)
{
	char ask = 'N';
	int chose = 0;
	string name, category;
	bool found = false;

	do {
		cout << endl;
		if (username == "admin") 
		{
			displayAdmin(username);
			cout << "Would you like to take another action?(Y/N)\n" << endl;
			cin >> ask;
		}

		else 
		{
			displayUser(username);
			cout << "Would you like to take another action?(Y/N)\n" << endl;
			cin >> ask;
		}

	} while (ask != 'N' && ask != 'n');

}


void Book::insert(const string& name, const string& category)
{
	BookData data;
	data.name = name;
	data.category = category;
	int key = temp.listSize() + 1;
	temp.insertEnd(key, data);
}

void Book::update(const string& name, const string& category)
{
	BookData data;
	data.name = name;
	data.category = category;
	int key = temp.listSize() + 1;
	temp.updateData(data);
}

void Book::reserveBook(int& key, const string& username)
{
	bool found = false;
	found = serach(key);
	if (found) {
		BookData data;
		temp.retrieveData(data);
		data.isReserved = true;
		data.reservedBy = username;
		temp.updateData(data);
		cout << "The book has been updated successfully";
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
		//temp.retrieveData(data);
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


void Book::displayAdmin(string& username)
{
	int chose = 0;
	string name, category;
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

	else if (chose == 3)
	{
		cout << "Enter Book Name: ";
		cin >> name;
		cout << "Enter Category Name: ";
		cin >> category;

		insert(name, category);
		cout << "The book has been added successfully\n";

	}
	
}

void Book::displayUser(string& username) 
{
	string name;
	int chose = 0;
	bool found = false;
	BookData data;

	if (chose == 0)
	{
		cout << "Select Please choose the action you would like to perform: \n"
			<< "1) Search \n" << "2) Display All \n" << "3) My Reserves \n";

		cin >> chose;
	}

	if (chose == 1)
	{
		cout << "Enter Book Name: ";
		cin >> name;
		found = serach(name);
		if (found) {
			temp.retrieveData(data);
			displayDetailsUser(data, username);
		}
		else {
			cout << "Not Found \n";
		}
	}

	else if (chose == 3)
	{
		/*cout << "Enter Book Name: ";
		cin >> name;
		cout << "Enter Category Name: ";
		cin >> category;

		insert(name, category);
		cout << "The book has been added successfully";
		*/

	}
}

void Book::displayDetailsAdmin(BookData& data, string username)
{
	int chose = 0;
	string name, category;
	if (chose == 0)
	{
		cout << "Select Please choose the action you would like to perform: \n"
			<< "1) Edit \n" << "2) Delete \n" << "3) Back To Home \n";

		cin >> chose;
	}

	if (chose == 1)
	{
		cout << "Enter Book Name: ";
		cin >> name;
		cout << "Enter Category Name: ";
		cin >> category;

		update(name, category);
		cout << "The book has been added successfully\n";
	}

	else if (chose == 3)
	{
		display(username);
	}
}

void Book::displayDetailsUser(BookData& data, string username)
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
		cout << "Enter Book Name: ";
		cin >> name;
		cout << "Enter Category Name: ";
		cin >> category;

		update(name, category);
		cout << "The book has been added successfully\n";
	}

	else if (chose == 2)
	{
		display(username);
	}
}

template class GenericList<BookData>;