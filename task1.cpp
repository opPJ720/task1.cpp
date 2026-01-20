#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile() {
    ofstream file("data.txt");
    string text;

    cout << "Enter text to write: ";
    cin.ignore();
    getline(cin, text);

    file << text;
    file.close();

    cout << "Data written successfully.\n";
}

void readFile() {
    ifstream file("data.txt");
    string line;

    if (!file) {
        cout << "File not found!\n";
        return;
    }

    cout << "\nFile Content:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void appendFile() {
    ofstream file("data.txt", ios::app);
    string text;

    cout << "Enter text to append: ";
    cin.ignore();
    getline(cin, text);

    file << "\n" << text;
    file.close();

    cout << "Data appended successfully.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- File Handling Menu ---\n";
        cout << "1. Write to File\n";
        cout << "2. Read from File\n";
        cout << "3. Append to File\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: writeFile(); break;
            case 2: readFile(); break;
            case 3: appendFile(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}