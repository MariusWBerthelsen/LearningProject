#include <iostream>
#include "LoginHandler.h"

using namespace std;

int main() {
    LoginHandler login;
    string username = login.loginWindow();
    cout << "Logged in as: " << username << endl;
    return 0;
}