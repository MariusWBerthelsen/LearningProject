#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class LoginHandler {
public:
	void loginWindow();
	bool isLoggedIn() const;
private:
	bool login(const string& username, const string& password);
	bool loggedIn = false; // Add this line
};
