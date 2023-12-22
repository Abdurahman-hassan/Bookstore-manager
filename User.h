#ifndef USER_HEADER_H
#define USER_HEADER_H

#include <iostream>
#include "GenericList.h"
using namespace std;
using std::string;

class UserData {
public:
	string username;
	string name;
	string password;
};

class User
{
public:
	User();
	~User();
	void insert(const string&, const string&, const string&);
	bool display(string&, string&);
	bool serach(const string&);
	bool serach(const string&, const string&);
	int size();
	void loadData();
private:
	GenericList<UserData> temp;
};

#endif //USER_HEADER_H