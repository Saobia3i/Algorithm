#include<bits/stdc++.h>
using namespace std;

class Library {
private:
    struct Book {
        string title;
        bool isIssued;
        int searchCount;
    };

    unordered_map<string, Book> books;
    int bookCounter = 100;

    string generateBookID() {
        return "ISBN" + to_string(bookCounter++);
    }

public:
    void addBook() {
        string title;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        string bookID = generateBookID();
        books[bookID] = {title, false, 0};
        cout << "Book added with ID: " << bookID << endl;
    }

    void issueBook() {
        string bookID;
        cout << "Enter book ID to issue: ";
        cin >> bookID;
        if (books.find(bookID) != books.end()) {
            if (books[bookID].isIssued) {
                cout << "Error: Book is already issued.\n";
            } else {
                books[bookID].isIssued = true;
                cout << "Book issued.\n";
            }
        } else {
            cout << "Error: Not issued\n";
        }
    }

    void searchBook() {
        string bookID;
        cout << "Enter book ID: ";
        cin >> bookID;
        if (books.find(bookID) != books.end()) {
            books[bookID].searchCount++;
            cout << "Title: " << books[bookID].title << "Available" << endl;
        } else {
            cout << "Error: Book not found!\n";
        }
    }

    void displaySearchCounts() {
        string bookID;
        cout << "Enter book ID: ";
        cin >> bookID;
        if (books.find(bookID) != books.end()) {
            cout << "Book '" << books[bookID].title << "' has been searched "
                 << books[bookID].searchCount << " times.\n";
        } else {
            cout << "Error: Book not found!\n";
        }
    }



    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "\nBooks in Library:\n";
        for (const auto& pair : books) {
            cout << "ID: " << pair.first << ", Title: " << pair.second.title
                 << ", Status: " << (pair.second.isIssued ? "Issued" : "Available") << endl;
        }
    }



    void returnBook() {
        string bookID;
        cout << "Enter book ID to return: ";
        cin >> bookID;
        if (books.find(bookID) != books.end()) {
            if (!books[bookID].isIssued) {
                cout << "Error: This book was not issued.\n";
            } else {
                books[bookID].isIssued = false;
                cout << "Book has returned.\n";
            }
        } else {
            cout << "Error: Book not found\n";
        }
    }

};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\n Library Management System (STL)\n";
        cout << "1. Add a Book\n";
        cout << "2. Search for a Book\n";
        cout << "3. Display Search Counts\n";
        cout<<"4.  Issue a Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Return a Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.searchBook(); break;
            case 3:library.displaySearchCounts();break;
            case 4: library.issueBook();break;
            case 5: library.displayAllBooks(); break;
            case 6: library.returnBook(); break;
            case 7: cout << "Exiting program"; return 0;
            default: cout << "Invalid choice! Please try again.\n";
        }
    }
}
