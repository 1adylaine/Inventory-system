#include "product.h"
#include "validator.h"
#include <iostream>
#include <iomanip>

std::vector<Product> products;

int productIndex(const std::string& searchCode){
    for(int i = 0; i < products.size(); i++){
        if(products[i].code == searchCode){
            return i;
        }
    }
    return -1;
}
std::string toUpper(const std::string& s){
    std::string result = "";
    for(int i = 0; i < s.size(); i++){
        result += toupper(s[i]);
    }
    return result;
}
void displaySpecificProduct(int i){
    std::cout << "Code: " << products[i].code << std::endl;
    std::cout << "Name: " << products[i].name << std::endl;
    std::cout << "Brand: " << products[i].brand << std::endl;
    std::cout << "Item: " << products[i].item << std::endl;
    std::cout << "Quantity: " << products[i].quantity << std::endl;
    std::cout << "Price: " << products[i].price << "\n\n";
}
void displayMenu(){
    std::cout << "INVENTORY SYSTEM\n";
    std::cout << "[1] Add Product\n";
    std::cout << "[2] Edit Product\n";
    std::cout << "[3] Display All Products\n"; 
    std::cout << "[4] Search Product\n";
    std::cout << "[5] Remove Product\n";
    std::cout << "[6] Close System\n";
}

std::string generateCode(const std::string& name, const std::string& brand, int position){
    std::string code = "";

    code += toupper(brand[0]);
    code += toupper(brand[1]);
    code += '-';

    code += toupper(name[0]);
    code += toupper(name[1]);
    code += toupper(name[2]);
    code += '-';
    
    std::string binary = "";
    int num = position + 1;
    while(num > 0){
        binary = (char)('0' + num % 2) + binary; 
        num /= 2;
    }

    code += binary;
    return code;

}
void addProduct(){
    Product p; 
    std::cout<< "Add Product Detail\n";
    std::cout<< "Name: "; std::getline(std::cin, p.name);
    if(p.name.size() < 3){
        std::cout<< "Invalid input!\n\n";
        return;
    }

    std::cout << "Brand: "; std::getline(std::cin, p.brand);
    if(p.brand.size() < 2){
        std::cout<< "Invalid input!\n\n";
        return;
    }

    std::cout << "Item: "; std::getline(std::cin, p.item);
    if(p.item.size() == 0){
        std::cout<<"Invalid input!\n\n";
        return;
    }

    p.quantity = getInt("Quantity: ");
    if(p.quantity < 0){
        std::cout <<"Invalid input!\n\n";
        return;
    }

    p.price = getDouble("Price: ");
    if(p.price < 0){
        std::cout <<"Invalid input!\n\n";
        return;
    }
    
    p.code = generateCode(p.name, p.brand, products.size());
    std::cout<< "Code: " << p.code << "\n";
    products.push_back(p);
    std::cout<< "Succesfully added!\n\n";
}

void editProduct(){
    if(products.size() == 0){
        std::cout<<"INVENTORY IS EMPTY\n\n";
        return;
    }

    std::string code;
    std::cout<<"EDIT PRODUCT\n" << "Enter product code to edit: ";
    std::getline(std::cin, code);

    code = toUpper(code);

    int index = productIndex(code);

    if(index == -1){
        std::cout<< "Product not found.\n\n";
        return;
    }

    std::cout <<"Current Product Details\n";
    displaySpecificProduct(index);

    std::cout<<"\nWhat do you want to edit? \n" 
        << "[1] Name      [2] Brand     [3] Item\n"
        << "[4] Quantity  [5] Price     [6] Edit All\n";
        int choice = getInt("Enter your choice: ");

    std::string modifiedDetail;
    switch (choice)
    {
        case 1:
            std::cout << "Enter new name: ";
            std::getline(std::cin, modifiedDetail);
            if(modifiedDetail.size() < 3){
                std::cout << "Invalid input!\n\n";
                return;
            }
            products[index].name = modifiedDetail;
            break;
        case 2:
            std::cout << "Enter new brand: ";
            std::getline(std::cin, modifiedDetail);
            if(modifiedDetail.size() < 3){
                std::cout << "Invalid input!\n\n";
                return;
            }
            products[index].brand = modifiedDetail;
            break;
        case 3:
            std::cout << "Enter new item: ";
            std::getline(std::cin, modifiedDetail);
            if(modifiedDetail.size() < 3){
                std::cout << "Invalid input!\n\n";
                return;
            }
            products[index].item = modifiedDetail;
            break;
        case 4:{
            int newQty = getInt("Enter new quantity: ");
            products[index].quantity = newQty;
            break;
        }
        case 5: {
            double newPrice = getDouble("Enter new price: ");
            products[index].price = newPrice;
            break;
        }
        case 6: 
            std::cout << "too lazy for this hehez";
            break;
        default:
            break;
    }
}

void displayProducts(){
    if(products.empty()){
        std::cout<<"No products found\n\n";
        return;
    }

    const int nameWidth = 15;
    const int numWidth = 8;
    const int lineWidth = 64;

    std::vector<std::string> displayedItems;
    for(int i = 0; i < products.size(); i++){       
        bool alreadyDisplayed = false;
        for(int j = 0; j < displayedItems.size(); j++){
            if(displayedItems[j] == products[i].item){
                alreadyDisplayed = true;
                break;
            }
        }

        if(!alreadyDisplayed){
            std::cout << std::right
                    << std::setw(lineWidth / 2 + products[i].item.size() / 2)
                    << products[i].item << std::endl;
                    std::cout << std::left
                        << std::setw(nameWidth) << "CODE" << "| "
                        << std::setw(nameWidth) << "NAME" << "| "
                        << std::setw(nameWidth) << "BRAND" << "| "
                        << std::setw(numWidth) << "QUANTITY" << "| "
                        << std::setw(numWidth) << "PRICE" << "\n";
            for(int k = 0; k < products.size(); k++){
                if(products[k].item == products[i].item){
                    std::cout << std::left
                        << std::setw(nameWidth) << products[k].code << "| "
                        << std::setw(nameWidth) << products[k].name << "| "
                        << std::setw(nameWidth) << products[k].brand << "| "
                        << std::setw(numWidth) << products[k].quantity << "| "
                        << std::setw(numWidth) << products[k].price << "\n";
                }
            }
            displayedItems.push_back(products[i].item);
            std::cout << std::endl;
        }
    }

}

void searchProduct(){
    std::string searchProduct;
    std::cout << "Product code to search: ";
    std::getline(std::cin, searchProduct);

    searchProduct = toUpper(searchProduct);

    int index = productIndex(searchProduct);

    if(index == -1){
        std::cout << "Product not found.\n\n";
        return;
    }

    std::cout <<"Product found\n";
    displaySpecificProduct(index);

}

void removeProduct(){
    std::string remove;
    std::cout << "Code of product to remove: ";
    std::getline(std::cin, remove);

    remove = toUpper(remove);

    int index = productIndex(remove);

    if(index == -1){
        std::cout << "Product not found.\n\n";
        return;
    }

    std::cout<<"Product to delete\n";
    displaySpecificProduct(index);
    char confirm;
    std::cout << "Are you sure you want to delete this product? [Y | N]: ";
    std::cin >> confirm;
    if(confirm == 'Y' || confirm == 'y'){
        products.erase(products.begin() + index);
        std::cout <<"Product deleted.\n\n";
    } else {
        std::cout << "Deletion cancelled.\n\n";
        return;
    }
}