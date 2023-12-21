#include <iostream>
#include "User.h"
using namespace std;
using std::string;


User::User()
{
	insert("admin", "admin", "General Manager");
}

User::~User()
{
	temp.makeListEmpty();
}


void User::display(string& username, bool& found)
{
	string password;
	char ask = 'N';
	int chose = 0;
	do {

		if (chose == 0)
		{
			cout << "Select Authentication: \n" << "1)Login \n" << "2)Register a new Account\n";
			cin >> chose;
		}

		if (chose == 1)
		{
			cout << "Enter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> password;
			
			bool found = serach(username, password);
			if (!found)
			{
				cout << "Not Found \n";
			    cout <<"Would you like to login again?(Y/N)"<< endl;
				cin >> ask;
			}
			else
				cout << "Welcome To Bookstore";

		}

		else if (chose == 2)
		{
			string name;
			cout << "Enter Name: ";
			cin >> name;
			cout << "Enter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> password;
			bool found = serach(username);
			if (found) {
				cout << "This User Already Exist \n" << endl;
				cout << "Would you like to login again?(Y/N)" << endl;
				cin >> ask;
			}
			else {
				found = true;
				insert(username, password, name);
				cout << "Welcome To Bookstore";
			}
		}
		

	} while (ask != 'N' && ask != 'n');


}


void User::insert(const string& username, const string& password, const string& name)
{
	UserData data;
	data.name = name;
	data.username = username;
	data.password = password;
	int key = temp.listSize() + 1;
	temp.insertEnd(key, data);
}


bool User::serach(const string& username)
{
	bool found = false; UserData data;
	temp.toFirst();
	while (!temp.currsorIsEmpty())
	{
		temp.retrieveData(data);
		if (data.username == username)
			return true;

		temp.advance();
	}
	return found;
}

bool User::serach(const string& username, const string& password)
{
	if (username == "admin" && password == "admin")
	{
		return true;
	}

	bool found = false; UserData data;
	temp.toFirst();
	while (!temp.currsorIsEmpty())
	{
		//temp.retrieveData(data);
		if (data.username == username && data.username == password)
			return true;

		temp.advance();
	}
	return found;
}

int User::size()
{
	return temp.listSize();
}


void User::loadData()
{

}

template class GenericList<UserData>;