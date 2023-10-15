#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "Book.h"
#include "UserRecord.h"
#include "LibraryCatalog.h"
#include "FileManager.h"
#include "MainMenu.h"
#include "UserRecord.cpp"

int main() {
    LibraryCatalog catalog;
    FileManager fileManager;
    fileManager.loadBooks(catalog, "books.txt");

    std::map<std::string, UserRecord> userRecords;
    fileManager.loadUserRecords(userRecords, "users.txt");

    int choice;
    std::string currentUser;

    MainMenu menu;
    do {
        choice = menu.showMenu();
        switch (choice) {
        case 1: {
            if (!currentUser.empty()) {
                std::string title, author;
                int year;
                std::cout << "Enter Book Title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter Author: ";
                std::getline(std::cin, author);
                year = menu.getYear();
                catalog.addBook(Book(title, author, year));
                fileManager.saveBooks(catalog, "books.txt");
            }
            else {
                std::cout << "You need to be registered to add a book." << std::endl;
            }
            break;
        }
        case 2: {
            catalog.listBooks();
            break;
        }
        case 3: {
            int yearToSearch = menu.getYear();
            std::vector<Book> foundBooks = catalog.findBooksByYear(yearToSearch);

            if (!foundBooks.empty()) {
                for (const Book& book : foundBooks) {
                    std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Year: " << book.getYear() << std::endl;
                }
            }
            else {
                std::cout << "No books found with the year " << yearToSearch << std::endl;
            }
            break;
        }
        case 4: {
            char initial = menu.getAuthorInitial();
            std::vector<Book> foundBooks = catalog.findBooksByAuthorInitial(initial);

            if (!foundBooks.empty()) {
                for (const Book& book : foundBooks) {
                    std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Year: " << book.getYear() << std::endl;
                }
            }
            else {
                std::cout << "No authors found with the initial '" << initial << "'" << std::endl;
            }
            break; // Добавим break для выхода из switch-case блока
        }
        case 5: {
            fileManager.saveBooks(catalog, "books.txt");
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        case 6: {
            if (!currentUser.empty()) {
                std::cout << "You are already registered as " << currentUser << "." << std::endl;
            }
            else {
                std::string name = menu.getUserName();
                int age = menu.getUserAge();
                std::string password = menu.getUserPassword();
                userRecords[name] = UserRecord(name, age, password);
                fileManager.saveUserRecords(userRecords, "users.txt");
                currentUser = name;
                std::cout << "Welcome, " << currentUser << "! You are now registered." << std::endl;
            }
            break;
        }
        case 7: {
            if (currentUser.empty()) {
                std::cout << "You need to be registered to gift a book." << std::endl;
            }
            else {
                std::string senderName = currentUser;
                int senderAge;
                std::cout << "Enter your age to confirm your identity: ";
                std::cin >> senderAge;
                std::string recipientName = menu.getRecipientName();
                if (userRecords.find(recipientName) != userRecords.end()) {
                    std::string bookTitle = menu.getBookTitle();  // Corrected input
                    bool bookFound = catalog.giftBook(bookTitle, recipientName); // Corrected search
                    if (bookFound) {
                        std::cout << "You have successfully gifted the book '" << bookTitle << "' to " << recipientName << "." << std::endl;
                        fileManager.saveBooks(catalog, "books.txt");
                    }
                    else {
                        std::cout << "The book '" << bookTitle << "' is not available." << std::endl;
                    }
                }
                else {
                    std::cout << "User '" << recipientName << "' not found." << std::endl;
                }
            }
            break;
        }
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
