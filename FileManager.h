#pragma once
#include <string>
#include <map>
#include "LibraryCatalog.h"
#include "UserRecord.h"
#include "ConsoleApplication3.cpp"

class FileManager {
public:
    void saveBooks(const LibraryCatalog& catalog, const std::string& filename);
    void loadBooks(LibraryCatalog& catalog, const std::string& filename);
    void saveUserRecords(const std::map<std::string, UserRecord>& users, const std::string& filename);
    void loadUserRecords(std::map<std::string, UserRecord>& users, const std::string& filename);
private:
    bool parseBookInfo(const std::string& line, std::string& title, std::string& author, int& year);
    bool parseUserRecordInfo(const std::string& line, std::string& name, int& age, std::string& password);
};
