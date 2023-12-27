#include<iostream>
#include <string>
#include "User.h"
#include "Book.h"
using namespace std;

int main()
{
    User usr;
    
    string username, name;
    bool isLogin;
    isLogin = usr.display(username, name);
    
    Book bok(username, name);
    if(isLogin)
        bok.display();

	return 0;
}