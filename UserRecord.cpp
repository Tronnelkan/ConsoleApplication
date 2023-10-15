#pragma once
#include <string>

class UserRecord {
public:
    UserRecord();
    UserRecord(const std::string& name, int age, const std::string& password);

    std::string getName() const;
    int getAge() const;
    std::string getPassword() const;

private:
    std::string name;
    int age;
    std::string password;
};
