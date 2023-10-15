#pragma once
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author, int year);

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;

private:
    std::string title;
    std::string author;
    int year;
};
