#include <iostream>
#include "User.h"
using namespace std;
using std::string;


User::User()
{
	insert("admin", "admin", "General Manager");
	insert("ahmed", "123", "Ahmed");
}

User::~User()
{
	temp.makeListEmpty();
}


bool User::display(string& username, string& name)
{
	string password;
	char ask = 'N';
	int chose = 0;
	bool found;
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
			
			found = serach(username, password);
			if (!found)
			{
				cout << "Not Found \n";  
				chose = 0;
			    cout <<"Would you like to login again?(Y/N)"<< endl;
				cin >> ask;
			}
			else
			{
				UserData data;
				temp.retrieveData(data);
				cout <<"\n'" << data.name << "' Welcome To Bookstore \n";
			}
		}

		else if (chose == 2)
		{
			cout << "Enter Name: ";
			cin >> name;
			cout << "Enter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> password;
			found = serach(username);
			if (found) {
				cout << "This User Already Exist \n" << endl;
				cout << "Would you like to Register again?(Y/N)" << endl;
				cin >> ask;
			}
			else {
				found = true;
				insert(username, password, name);
				cout << "\n'" << name << "' Welcome To Bookstore \n";
			}
		}
		

	} while (ask != 'N' && ask != 'n');

	return found;
}


void User::insert(const string& username, const string& password, const string& name)
{
	UserData data;
	int key = 0;
	if (!temp.currsorIsEmpty()) {
		temp.toEnd();
		temp.retrieveKey(key);
	}

	key++;
	data.name = name;
	data.username = username;
	data.password = password;
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
	bool found = false; UserData data;
	temp.toFirst();
	while (!temp.currsorIsEmpty())
	{
		temp.retrieveData(data);
		if (data.username == username && data.password == password)
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