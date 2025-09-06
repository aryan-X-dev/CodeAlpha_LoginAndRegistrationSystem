#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

// Function for checking if username already exists
bool userExists(const string &username) {
    ifstream infile("users.txt");
    string u, p;
    while (infile >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

// Function for registering a new user
void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    // Check duplicate username
    if (userExists(username)) {
        cout << "❌ Username already exists❌ . Try a different one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    cout << "✅ Registration successful!\n";
}

// Function for login as an existing user
void loginUser() {
    string username, password, u, p;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    bool success = false;

    while (infile >> u >> p) {
        if (u == username && p == password) {
            success = true;
            break;
        }
    }

    if (success) {
        cout << "✅ Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "❌ Invalid username or password.❌\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n==== LOGIN & REGISTRATION SYSTEM ====\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "❌ Invalid choice.❌ Try again.\n";
        }
    }
}
