#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class LoginHandler {
public:
	string loginWindow();
private:
	void login(const string& username, const string& password);
};
