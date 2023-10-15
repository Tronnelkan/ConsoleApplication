#pragma once
#include <string>
#include "LibraryCatalog.h"
#include "UserRecord.h"

class MainMenu {
public:
    int showMenu();
    int getYear();
    char getAuthorInitial();
    std::string getUserName();
    int getUserAge();
    std::string getUserPassword();
    std::string getRecipientName();
    std::string getBookTitle();
};
