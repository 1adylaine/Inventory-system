#include "savedata.h"
#include "product.h"
#include <fstream>
#include <sstream>
#include <iostream>

void saveToFile(const std::vector<Product>& list){
    std::ofstream outFile("database.txt"); //creates or open textfile

    if(outFile.is_open()){
            for(const auto& p : list){
                outFile << p.code << "|"
                        << p.name << "|"
                        << p.brand << "|"
                        << p.item << "|"
                        << p.quantity << "|"
                        << p.price << "\n";
            }
        outFile.close();
    } else {
        std::cout << "Error\n";
    }

    
}

void loadFromFile(std::vector<Product>& list){
    std::ifstream inFile("database.txt");

    if(!inFile){
        return;
    }

    list.clear();

    std::string line;
    while(std::getline(inFile, line)) {
        if(line.empty()) continue;

        std::stringstream ss(line);
        Product p;
        std::string priceStr;
        std::string quantityStr;

        std::getline(ss, p.code, '|');
        std::getline(ss, p.name, '|');
        std::getline(ss, p.brand, '|');
        std::getline(ss, p.item, '|');
        std::getline(ss, quantityStr, '|');
        std::getline(ss, priceStr, '\n');

        try {
            p.price = std::stod(priceStr);
            p.quantity = std::stoi(quantityStr); //idkbro
        } catch (...) {
            p.price = 0.0;
            p.quantity = 0;
        }

        list.push_back(p);
        
    }
    inFile.close();
}