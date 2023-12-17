#include <iostream>
//#include "GenericList.h"
#include "User.h"
using namespace std;
using std::string;


User::User()
{

}

User::~User()
{
	temp.makeListEmpty();
}


void User::display()
{
	string username, password;
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
				cout << "Not Found";

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
		}

	} while (chose > 2 || chose < 0);


}


void User::insert(const string& username, const string& password, const string& name)
{
	UserData data;
	data.name = name;
	data.username = username;
	int key = temp.listSize() + 1;
	//temp.orderInsert(key, data);
}


bool User::serach(const string& username)
{
	bool found = false; UserData data;
	temp.toFirst();
	while (!temp.currsorIsEmpty())
	{
		//temp.retrieveData(data);
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