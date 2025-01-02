#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void signup();
void forgot();

int main() {
    int choice;
    while (true) {
        cout << "\t\t\t___________________________\n\n\n";
        cout << "\t\t\t   WELCOME TO LOGIN PAGE    \n\n\n";
        cout << "\t\t\t___________MENU_____________\n\n\n";
        cout << "\n\t Press 1 to Login        " << endl;
        cout << "\t Press 2 to SignUp       " << endl;
        cout << "\t Press 3 to Forgot Password" << endl;
        cout << "\t Press 4 to EXIT         " << endl;
        cout << "\n\t\t\t Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                signup();
                break;
            case 3:
                forgot();
                break;
            case 4:
                cout << "\t\t\t THANK YOU \n\n";
                return 0;
            default:
                cout << "\t\t\t Invalid choice! Please try again.\n" << endl;
        }
    }
}

void login() {
    int count = 0;
    string userId, password, Id, pass;
    cout << "\t\t\t Enter Username and Password:\n";
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");
    if (!input.is_open()) {
        cout << "ERROR: Unable to open file.\n";
        return;
    }

    while (input >> Id >> pass) {
        if (Id == userId && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1) {
        cout << "\n" << userId << " LOGIN SUCCESSFUL!\n";
    } else {
        cout << "\nERROR: Please check your username and password\n";
    }
}

void signup() {
    string suserId, spassword;
    cout << "\t\t\t Enter the username: ";
    cin >> suserId;
    cout << "\t\t\t Enter the password: ";
    cin >> spassword;

    ofstream f1("records.txt", ios::app);
    if (!f1.is_open()) {
        cout << "ERROR: Unable to open file for writing.\n";
        return;
    }

    f1 << suserId << " " << spassword << endl;
    f1.close();
    cout << "\n\t\t\t Registration done!" << endl;
}

void forgot() {
    int option;
    cout << "\t\t\t Forgot password?\n";
    cout << "1. Search ID\n";
    cout << "2. Main menu\n";
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string fuserId, fId, fpass;
            cout << "\n\t\t\t Enter known username: ";
            cin >> fuserId;

            ifstream f2("records.txt");
            if (!f2.is_open()) {
                cout << "ERROR: Unable to open file.\n";
                return;
            }

            while (f2 >> fId >> fpass) {
                if (fId == fuserId) {
                    count = 1;
                    break;
                }
            }
            f2.close();

            if (count == 1) {
                cout << "\n\n Account found!\n";
                cout << "\n\n Your Password: " << fpass << endl;
            } else {
                cout << "\n\t Account not found!" << endl;
            }
            break;
        }
        case 2:
            break;
        default:
            cout << "\t\t\t Wrong choice! Please try again.\n";
            forgot();
            break;
    }
}
