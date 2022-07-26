#include "datamodel.h"

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(3, "mango", 16),
    Product(2, "guava", 36),
    Product(4, "strwaberry", 29),
    Product(5, "grapes", 29),
    Product(6, "pineapple", 78),
};

Product *chooseProduct() {

    // display the list of products
    string productList;
    cout << "Available Products" << endl;

    for (auto product : allProducts) {
        productList.append(product.getDisplayName());
    }
    cout << productList << endl;
    cout << "----------------------------" << endl;
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++) {
        if (allProducts[i].getShortName() == choice) {
            return &allProducts[i];
        }
    }
    cout << "Product not found!" << endl;
    return NULL;
}

bool checkOut(Cart &cart) {
    if (cart.isEmpty()) {
        return "Cart is empty";
    }
    int total = cart.getTotal();
    cout << "Pay " << total << endl;

    int paid;
    cin >> paid;
    if (paid >= total) {
        cout << "Change " << paid - total << endl;
        cout << "Thank You for shopping!";
        return true;
    } else {
        cout << "Due Amount " << total - paid << endl;
        return false;
    }
}

int main() {
    char action;
    Cart cart;

    while (true) {
        cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;
        if (action == 'a') {
            // Todo: add to cart
            // view all products + choose product + add to the cart
            Product *product = chooseProduct();
            if (product != NULL) {
                cout << "Added to the Cart " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        } else if (action == 'v') {
            // view the cart

            cout << "-----------------------------" << endl;
            cout << cart.viewCart();
            cout << "-----------------------------" << endl;
        } else {
            // checkout
            cart.viewCart();
            if (checkOut(cart)) {
                break;
            }
        }
    }
}