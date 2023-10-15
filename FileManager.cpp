#include "FileManager.h"
#include <fstream>

void FileManager::saveBooks(const LibraryCatalog& catalog, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Book& book : catalog.getBooks()) {
            file << book.getTitle() << "," << book.getAuthor() << "," << book.getYear() << "\n";
        }
        file.close();
    }
}

void FileManager::loadBooks(LibraryCatalog& catalog, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string title, author;
            int year;
            if (parseBookInfo(line, title, author, year)) {
                catalog.addBook(Book(title, author, year));
            }
        }
        file.close();
    }
}

void FileManager::saveUserRecords(const std::map<std::string, UserRecord>& users, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.second.getName() << "," << user.second.getAge() << "," << user.second.getPassword() << "\n";
        }
        file.close();
    }
}

void FileManager::loadUserRecords(std::map<std::string, UserRecord>& users, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string name, password;
            int age;
            if (parseUserRecordInfo(line, name, age, password)) {
                users[name] = UserRecord(name, age, password);
            }
        }
        file.close();
    }
}

bool FileManager::parseBookInfo(const std::string& line, std::string& title, std::string& author, int& year) {
    size_t pos1 = line.find(",");
    if (pos1 == std::string::npos) {
        return false;
    }
    size_t pos2 = line.find(",", pos1 + 1);
    if (pos2 == std::string::npos) {
        return false;
    }
    try {
        title = line.substr(0, pos1);
        author = line.substr(pos1 + 1, pos2 - pos1 - 1);
        year = std::stoi(line.substr(pos2 + 1));
        return true;
    }
    catch (...) {
        return false;
    }
}

bool FileManager::parseUserRecordInfo(const std::string& line, std::string& name, int& age, std::string& password) {
    size_t pos1 = line.find(",");
    if (pos1 == std::string::npos) {
        return false;
    }
    size_t pos2 = line.find(",", pos1 + 1);
    if (pos2 == std::string::npos) {
        return false;
    }
    try {
        name = line.substr(0, pos1);
        age = std::stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        password = line.substr(pos2 + 1);
        return true;
    }
    catch (...) {
        return false;
    }
}
