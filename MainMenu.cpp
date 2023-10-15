#include <iostream>
#include <string>

class MainMenu {
public:
    int showMenu() {
        int choice;
        std::cout << "Main Menu:" << std::endl;
        std::cout << "1. Add a Book" << std::endl;
        std::cout << "2. List Books" << std::endl;
        std::cout << "3. Search Books by Year" << std::endl;
        std::cout << "4. Search Author by Initial" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "6. Register" << std::endl;
        std::cout << "7. Gift a Book" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        return choice;
    }

    int getYear() {
        int year;
        std::cout << "Enter Year: ";
        std::cin >> year;
        return year;
    }

    char getAuthorInitial() {
        char initial;
        std::cout << "Введите начальную букву автора: ";
        std::cin >> initial;
        // Очистим буфер ввода, чтобы избежать зацикливания
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return std::tolower(initial);
    }

    std::string getUserName() {
        std::string name;
        std::cout << "Enter your name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        return name;
    }

    int getUserAge() {
        int age;
        std::cout << "Enter your age: ";
        std::cin >> age;
        return age;
    }

    std::string getUserPassword() {
        std::string password;
        std::cout << "Enter your password: ";
        std::cin.ignore();
        std::getline(std::cin, password);
        return password;
    }

    std::string getRecipientName() {
        std::string name;
        std::cout << "Enter the recipient's name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        return name;
    }

    std::string getBookTitle() {
        std::string title;
        std::cout << "Enter the name of book: ";
        std::getline(std::cin, title);
        return title;
    }
};