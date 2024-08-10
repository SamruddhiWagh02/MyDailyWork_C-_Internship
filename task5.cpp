#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    string isbn;
    bool is_available;
};

struct Borrower {
    int id;
    string name;
};

struct Transaction {
    int book_id;
    int borrower_id;
    time_t borrow_date;
    time_t due_date;
    bool is_returned;
};

vector<Book> books;
vector<Borrower> borrowers;
vector<Transaction> transactions;

void loadBooks() {
    ifstream infile("books.txt");
    if (infile.is_open()) {
        Book book;
        while (infile >> book.id >> book.title >> book.author >> book.isbn >> book.is_available) {
            books.push_back(book);
        }
        infile.close();
    }
}

void saveBooks() {
    ofstream outfile("books.txt");
    for (const auto& book : books) {
        outfile << book.id << " " << book.title << " " << book.author << " " << book.isbn << " " << book.is_available << endl;
    }
    outfile.close();
}

void addBook() {
    Book book;
    cout << "Enter book ID: ";
    cin >> book.id;
    cout << "Enter title: ";
    cin >> book.title;
    cout << "Enter author: ";
    cin >> book.author;
    cout << "Enter ISBN: ";
    cin >> book.isbn;
    book.is_available = true;
    books.push_back(book);
    saveBooks();
}

void searchBooks() {
    string keyword;
    cout << "Enter title, author, or ISBN to search: ";
    cin >> keyword;
    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos || book.isbn.find(keyword) != string::npos) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << ", Available: " << (book.is_available ? "Yes" : "No") << endl;
        }
    }
}

void checkoutBook() {
    int book_id, borrower_id;
    cout << "Enter book ID: ";
    cin >> book_id;
    cout << "Enter borrower ID: ";
    cin >> borrower_id;

    for (auto& book : books) {
        if (book.id == book_id && book.is_available) {
            book.is_available = false;
            Transaction transaction = {book_id, borrower_id, time(0), time(0) + 7 * 24 * 60 * 60, false};
            transactions.push_back(transaction);
            saveBooks();
            cout << "Book checked out successfully." << endl;
            return;
        }
    }
    cout << "Book is not available or does not exist." << endl;
}

void returnBook() {
    int book_id;
    cout << "Enter book ID: ";
    cin >> book_id;

    for (auto& book : books) {
        if (book.id == book_id && !book.is_available) {
            book.is_available = true;
            for (auto& transaction : transactions) {
                if (transaction.book_id == book_id && !transaction.is_returned) {
                    transaction.is_returned = true;
                    time_t now = time(0);
                    if (now > transaction.due_date) {
                        double days_overdue = difftime(now, transaction.due_date) / (60 * 60 * 24);
                        cout << "Book is overdue by " << days_overdue << " days. Fine: $" << days_overdue * 1.0 << endl;  // Assuming $1 fine per day
                    } else {
                        cout << "Book returned on time." << endl;
                    }
                }
            }
            saveBooks();
            return;
        }
    }
    cout << "Book is already available or does not exist." << endl;
}

int main() {
    loadBooks();
    int choice;
    do {
        cout << "Library Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Books\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBooks();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

