#include "LoginHandler.h"

void LoginHandler::login(const string& username, const string& password) {
    ifstream registeredUser(username + ".txt");
    if (registeredUser.is_open()) {
        string line;
        while (getline(registeredUser, line)) {
            size_t pos = line.find("pass=");
            if (pos != string::npos) { // ?
                string storedPassword = line.substr(pos + 5);
                if (storedPassword == password) {
                    cout << "Login successful." << endl;
                    registeredUser.close();
                    return;
                }
                else {
                    cout << "Incorrect password." << endl;
                    registeredUser.close();
                    return;
                }
            }
        }
        cout << "Error: File format is incorrect." << endl;
        registeredUser.close();
    }
    else {
        ofstream registerUser(username + ".txt");
        if (registerUser.is_open()) {
            registerUser << "user=" << username << "\n"
                << "pass=" << password << "\n";
            cout << "User registered successfully." << endl;
            registerUser.close();
        }
        else {
            cout << "Error: Unable to create user file." << endl;
        }
    }
}

string LoginHandler::loginWindow() {
    string username;
    string password;

    cout << "Enter username: ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    login(username, password);
    return username;
}