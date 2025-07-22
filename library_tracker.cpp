#include <bits/stdc++.h>
using namespace std;

class Book {
private:
    string name;
    string author;
    bool isBorrowed;

public:
    Book(string name, string author) {
        this->name = name;
        this->author = author;
        isBorrowed = false;
    }

    string getBookName() {
        return this->name;
    }

    string getAuthorName() {
        return this->author;
    }

    bool BorrowedStatus() {
        return this->isBorrowed;
    }

    void setBookStatus(bool f) {
        this->isBorrowed = f;
    }
};

class Library {
private:
    vector<Book> list;

public:
    Library() {}

    void addBook(string name, string author) {
        Book b(name, author);
        list.push_back(b);
        cout << "Book added successfully!\n";
    }

    void returnBook(int ind) {
        if (ind <= 0 || ind > list.size()) {
            cout << "Invalid book index!\n";
            return;
        }
        if (!list[ind - 1].BorrowedStatus()) {
            cout << "This book wasn't borrowed.\n";
            return;
        }
        list[ind - 1].setBookStatus(false);
        cout << "Book returned successfully!\n";
    }

    void displayBooks() {
        if (list.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        for (int i = 0; i < list.size(); i++) {
            cout << (i + 1) << ". Book: \"" << list[i].getBookName()
                 << "\" by " << list[i].getAuthorName()
                 << (list[i].BorrowedStatus() ? " [Borrowed]" : " [Available]") << endl;
        }
    }

    void displayBorrowedBooks() {
        bool found = false;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].BorrowedStatus()) {
                found = true;
                cout << (i + 1) << ". Book: \"" << list[i].getBookName()
                     << "\" by " << list[i].getAuthorName() << endl;
            }
        }
        if (!found) {
            cout << "No books are currently borrowed.\n";
        }
    }

    void Borrow(int ind) {
        if (ind <= 0 || ind > list.size()) {
            cout << "Invalid book index!\n";
            return;
        }
        if (list[ind - 1].BorrowedStatus()) {
            cout << "Book is already borrowed!\n";
            return;
        }
        list[ind - 1].setBookStatus(true);
        cout << "Book borrowed successfully!\n";
    }
};

int main() {
    Library lb;
    while (true) {
        cout << "\n*** Library Menu ***\n";
        cout << "1. Add Book\n";
        cout << "2. Return Book\n";
        cout << "3. Borrow Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Display Borrowed Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int ch;
        cin >> ch;
        cin.ignore();  // flush newline

        switch (ch) {
        case 1: {
            string name, author;
            cout << "Enter book name: ";
            getline(cin, name);
            cout << "Enter author name: ";
            getline(cin, author);
            lb.addBook(name, author);
            break;
        }
        case 2: {
            lb.displayBorrowedBooks();
            int ind;
            cout << "Enter index of book to return: ";
            cin >> ind;
            lb.returnBook(ind);
            break;
        }
        case 3: {
            lb.displayBooks();
            int ind;
            cout << "Enter index of book to borrow: ";
            cin >> ind;
            lb.Borrow(ind);
            break;
        }
        case 4:
            lb.displayBooks();
            break;
        case 5:
            lb.displayBorrowedBooks();
            break;
        case 6:
            cout << "Exiting... Thank you!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
