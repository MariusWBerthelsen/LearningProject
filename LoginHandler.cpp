#include "LoginHandler.h"
#include <imgui.h>

bool LoginHandler::isLoggedIn() const {
    return loggedIn;
}

bool LoginHandler::login(const std::string& username, const std::string& password) {
    ifstream registeredUser("data/accounts/" + username + ".txt");
    if (registeredUser.is_open()) {
        string line;
        while (getline(registeredUser, line)) {
            size_t pos = line.find("pass=");
            if (pos != string::npos) {
                string storedPassword = line.substr(pos + 5);
                registeredUser.close();
                if (storedPassword == password) {
                    cout << "Login successful." << endl;
                    return true;
                } else {
                    cout << "Incorrect password." << endl;
                    return false;
                }
            }
        }
        cout << "Error: File format is incorrect." << endl;
        registeredUser.close();
        return false;
    } else {
        ofstream registerUser("data/accounts/" + username + ".txt");
        if (registerUser.is_open()) {
            registerUser << "user=" << username << "\n"
                << "pass=" << password << "\n";
            cout << "User registered successfully." << endl;
            registerUser.close();
            return true;
        } else {
            cout << "Error: Unable to create user file." << endl;
            return false;
        }
    }
}

void LoginHandler::loginWindow() {
    static char username[100] = "";
    static char password[100] = "";
    static bool loginAttempted = false;
    static bool loginSuccess = false;

    ImGui::Begin("Login");
    ImGui::InputText("Username", username, 100);
    ImGui::InputText("Password", password, 100, ImGuiInputTextFlags_Password);
    if (ImGui::Button("Login")) {
        loginSuccess = login(std::string(username), std::string(password));
        loggedIn = login(std::string(username), std::string(password));
        loginAttempted = true;
    }
    if (loginAttempted) {
        if (loginSuccess)
            ImGui::Text("Login successful!");
        else
            ImGui::Text("Invalid username/password!");
    }
    ImGui::End();
}
