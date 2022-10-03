#include <iostream>
#include <fstream>

void buyProducts(){
    std::vector<double> cart;
    int check = 0;
    double total = 0;
    std::string userChoice;
    std::string product;
    double price;
    std::ifstream getProducts;
    getProducts.open("products.txt");

    while (!getProducts.eof()){
        getProducts >> product >> price;
        std::cout << std::endl;
        std::cout << product << ' ' << price << " laris" << std::endl;
    }
    getProducts.close();


    do {
        std::cout << std::endl;
        std::cout << "Enter your choice(type 'exit' to exit): ";
        std::cin >> userChoice;

        getProducts.open("products.txt");
        while (!getProducts.eof()){
            getProducts >> product >> price;
            if(userChoice == product){
                check = 1;
                cart.push_back(price);
            }
        }
        if (userChoice == "exit"){
            std::cout << std::endl;
        }
        else if (check != 1){
            std::cout << "There are no products with this name!" << std::endl;
        }

        getProducts.close();
    } while (userChoice != "exit");

    for (int i = 0; i < cart.size(); i++){
        total += cart[i];
    }
    std::cout << "Total: " << total << std::endl;

}

void addProduct(std::string &pwd){

    std::string product;
    double price;
    int userInput;

    do {
        std::string userPwd;
        std::cout << "1. Add product" << std::endl;
        std::cout << "2. Change password" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> userInput;
        switch (userInput) {

            case 1:{
                std::fstream openFile;
                openFile.open("products.txt",std::ios::app);
                std::cout << "Enter product that you want to add: ";
                std::cin.ignore();
                getline(std::cin, product);
                std::cout << "Enter price for it: ";
                std::cin >> price;

                openFile << std::endl << product << " " << price;

                break;
            }

            case 2:{
                std::cout << "Enter current password: ";
                std::cin >> userPwd;
                if (userPwd == pwd) {
                    std::string userNewPwd;
                    std::string confirmNewPwd;
                    std::cout << "Enter new password: ";
                    std::cin >> userNewPwd;
                    std::cout << "Repeat new password: ";
                    std::cin >> confirmNewPwd;
                    if (confirmNewPwd != userNewPwd){
                        std::cout << "Confirmed password is incorrect!" << std::endl;
                        break;
                    }
                    else{
                        pwd = userNewPwd;
                        break;
                    }
                }
                else {
                    std::cout << "Incorrect password!" << std::endl;
                    break;
                }
            }

            case 3:{
                break;
            }
        }

    }while(userInput != 3);

}