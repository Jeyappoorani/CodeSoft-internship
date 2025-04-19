#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

const int MAX_DAYS = 14;
const float FINE_PER_DAY = 1.5;  

struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable; 
};

struct BorrowRecord {
    string isbn;
    string borrowerName;
    time_t checkoutDate;
};

class LibrarySystem {
private:
    vector<Book> books;
    vector<BorrowRecord> records;

public:
    void addBook() {
        Book book;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, book.title);
        cout << "Enter author: ";
        getline(cin, book.author);
        cout << "Enter ISBN: ";
        getline(cin, book.isbn);
        book.isAvailable = true;
        books.push_back(book);
        cout << "Book added successfully!\n";
    }

    void searchBook() {
        int choice;
        string query;
        cout << "\nSearch by:\n1. Title\n2. Author\n3. ISBN\nChoice: ";
        cin >> choice;
        cin.ignore();
        cout << "Enter your search query: ";
        getline(cin, query);

        bool found = false;
        for (size_t i = 0; i < books.size(); ++i) {
            Book book = books[i];
            if ((choice == 1 && book.title == query) ||
                (choice == 2 && book.author == query) ||
                (choice == 3 && book.isbn == query)) {
                cout << "\n--- Book Found ---\n";
                cout << "Title: " << book.title << "\nAuthor: " << book.author
                     << "\nISBN: " << book.isbn
                     << "\nStatus: " << (book.isAvailable ? "Available" : "Checked out") << endl;
                found = true;
            }
        }

        if (!found) cout << "No matching book found.\n";
    }

    void checkoutBook() {
        string isbn, borrower;
        cout << "Enter ISBN of the book to checkout: ";
        cin.ignore();
        getline(cin, isbn);

        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isbn == isbn) {
                if (!books[i].isAvailable) {
                    cout << "Book is currently checked out.\n";
                    return;
                }

                cout << "Enter borrower's name: ";
                getline(cin, borrower);

                BorrowRecord record;
                record.isbn = isbn;
                record.borrowerName = borrower;
                record.checkoutDate = time(NULL);
                records.push_back(record);

                books[i].isAvailable = false;
                cout << "Book checked out successfully!\n";
                return;
            }
        }

        cout << "Book not found.\n";
    }

    void returnBook() {
        string isbn;
        cout << "Enter ISBN of the book to return: ";
        cin.ignore();
        getline(cin, isbn);

        for (size_t i = 0; i < records.size(); ++i) {
            if (records[i].isbn == isbn) {
                time_t now = time(NULL);
                double seconds = difftime(now, records[i].checkoutDate);
                int daysBorrowed = static_cast<int>(seconds / (60 * 60 * 24));
                float fine = 0;

                if (daysBorrowed > MAX_DAYS) {
                    fine = (daysBorrowed - MAX_DAYS) * FINE_PER_DAY;
                    cout << "Overdue! You owe a fine of $" << fixed << setprecision(2) << fine << ".\n";
                } else {
                    cout << "Book returned on time. No fine.\n";
                }

                for (size_t j = 0; j < books.size(); ++j) {
                    if (books[j].isbn == isbn) {
                        books[j].isAvailable = true;
                        break;
                    }
                }

                records.erase(records.begin() + i);
                cout << "Book return recorded successfully.\n";
                return;
            }
        }

        cout << "No borrow record found for this ISBN.\n";
    }

    void menu() {
        int choice;
        do {
            cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======\n";
            cout << "1. Add Book\n2. Search Book\n3. Checkout Book\n4. Return Book\n5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addBook(); break;
                case 2: searchBook(); break;
                case 3: checkoutBook(); break;
                case 4: returnBook(); break;
                case 5: cout << "Exiting system. Goodbye!\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    LibrarySystem lib;
    lib.menu();
    return 0;
}

