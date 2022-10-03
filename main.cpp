#include <iostream>
#include <vector>
#include "Supermarket.h"

void addProduct(std::string &pwd);
void buyProducts();

int main() {
    std::string password = "supermarket123";
    int userInput;
    std::cout << "=====================================" << std::endl;
    std::cout << "=============SUPERMARKET=============" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "1. For costumers" << std::endl;
    std::cout << "2. For employees" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Your Choice: ";
    std::cin >> userInput;

    switch (userInput) {

        case 1:{
            buyProducts();
            break;
        }
        case 2:{
            std::string userPwd;
            std::cout << "Enter password: ";
            std::cin >> userPwd;
            if (userPwd == password){
                addProduct(password);
                main();
            }
            else {
                std::cout << "Incorrect password!" << std::endl;
                main();
            }
        }
        case 3:{
            return 0;
        }

    }

    return 0;
}
