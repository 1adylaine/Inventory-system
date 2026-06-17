#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <vector>

struct Product {
    std::string name;
    std::string brand;
    std::string item;
    std::string code;
    int quantity;
    double price;
};

extern std::vector<Product> products;  // extern shared across files

int productIndex(const std::string& searchCode);
std::string toUpper(const std::string& s);
std::string generateCode(const std::string& name, const std::string& brand, int position);
void displaySpecificProduct(int i);
void addProduct();
void editProduct();
void displayProducts();
void searchProduct();
void removeProduct();
void displayMenu();

#endif