#include "product.h"
#include "validator.h"

int main(){
    do {
        displayMenu();
        int choice = getInt("Enter your choice: ");

        switch(choice){
            case 1: addProduct(); break;
            case 2: editProduct(); break;
            case 3: displayProducts(); break;
            case 4: searchProduct(); break;
            case 5: removeProduct(); break;
            case 6: return 0;
        }
    } while(true);
}