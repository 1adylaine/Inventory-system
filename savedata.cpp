#include "savedata.h"
#include "product.h"
#include <fstream>
#include <sstream>
#include <iostream>

void saveToFile(const std::vector<Product>& list){
    std::ofstream outFile("database.txt"); //creates or open textfile
    //ofstream is to create the file if it does not exist.
    if(outFile.is_open()){
            for(const auto& p : list){  //write one like per index infos with delimeter | or any that separates the file
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

    list.clear(); //clear first for less bug

    std::string line;
    while(std::getline(inFile, line)) { //reads the file one line at a time to the string line
        if(line.empty()) continue;

        std::stringstream ss(line); //huh
        Product p;
        std::string priceStr; //because getline is for string dzuh
        std::string quantityStr;

        std::getline(ss, p.code, '|');
        std::getline(ss, p.name, '|');
        std::getline(ss, p.brand, '|');
        std::getline(ss, p.item, '|');
        std::getline(ss, quantityStr, '|');
        std::getline(ss, priceStr, '\n');

        try {
            p.price = std::stod(priceStr); //stod string to double
            p.quantity = std::stoi(quantityStr); //idkbro :) string to int
        } catch (...) {
            p.price = 0.0;
            p.quantity = 0;
        }

        list.push_back(p);
        
    }
    inFile.close();
}