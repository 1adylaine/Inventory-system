#include "validator.h"
#include <iostream>

int getInt(const std::string& prompt){
    int num;
    while(true){
        std::cout << prompt;
        if(std::cin >> num){
            std::cin.ignore();
            return num;
        }
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid! Try again.\n";
    }
}

double getDouble(const std::string& prompt){
    double num;
    while(true){
        std::cout << prompt;
        if(std::cin >> num){
            std::cin.ignore();
            return num;
        }
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid! Try again.\n";
    }
}