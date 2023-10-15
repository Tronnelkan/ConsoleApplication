#include "LibraryCatalog.h"
#include <iostream>


class LibraryCatalog {
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void listBooks() const {
        for (const Book& book : books) {
            std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Year: " << book.getYear() << std::endl;
        }
    }

    std::vector<Book> getBooks() const {
        return books;
    }

    std::vector<Book> findBooksByYear(int year) const {
        std::vector<Book> result;
        for (const Book& book : books) {
            if (book.getYear() == year) {
                result.push_back(book);
            }
        }
        return result;
    }

    std::vector<Book> findBooksByAuthorInitial(char initial) const {
        std::vector<Book> result;
        for (const Book& book : books) {
            if (!book.getAuthor().empty() && std::tolower(book.getAuthor()[0]) == std::tolower(initial)) {
                result.push_back(book);
            }
        }
        return result;
    }

    bool giftBook(const std::string& title, const std::string& recipientName) {
        auto it = std::remove_if(books.begin(), books.end(),
            [title](const Book& book) { return book.getTitle() == title; });
        if (it != books.end()) {
            books.erase(it, books.end());
            return true;
        }
        return false;
    }

private:
    std::vector<Book> books;
};