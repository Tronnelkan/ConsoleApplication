#pragma once
#include <vector>
#include "Book.h"

class LibraryCatalog {
public:
    void addBook(const Book& book);
    void listBooks() const;
    std::vector<Book> getBooks() const;
    std::vector<Book> findBooksByYear(int year) const;
    std::vector<Book> findBooksByAuthorInitial(char initial) const;
    bool giftBook(const std::string& title, const std::string& recipientName);

private:
    std::vector<Book> books;
};
