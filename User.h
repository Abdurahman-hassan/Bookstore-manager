#ifndef USER_HEADER_H
#define USER_HEADER_H

#include <iostream>
#include <string>
#include <fstream>

#include "LinkedListUtils.h"
using namespace std;
using std::string;

class UserData {
public:
	string username;
	string job_title;
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
	void saveToCSV(const string& filename);
	void loadFromCSV(const string& filename);
private:
	LinkedListUtils<UserData> user_node;
};

#endif //USER_HEADER_H