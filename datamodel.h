#include <bits/stdc++.h>
using namespace std;

// we need product, item and cart...

class Product {
    int id;
    string name;
    int price;

public:
    Product() {
    }
    Product(int id, string name, int price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    string getDisplayName() {
        return name + " : Rs " + to_string(price) + "\n";
    }

    string getShortName() {
        return name.substr(0, 1);
    }

    friend class Item;
    friend class Cart;
};

class Item {
    Product product;
    int quantity;

public:
    Item() {
    }
    Item(Product p, int q) : product(p), quantity(q){};

    int getItemPrice() {
        return quantity * product.price;
    }

    string getItemInfo() {
        return to_string(quantity) + " x " + product.name + " Rs. " + to_string(quantity + product.price);
    }
    friend class Cart;
};

class Cart {
    unordered_map<int, Item> items;

public:
    void addProduct(Product product) {
        if (items.count(product.id) == 0) {
            Item newItem(product, 1);
            items[product.id] = newItem;
        } else {
            items[product.id].quantity += 1;
        }
    }
    int getTotal() {
        int total = 0;
        for (auto itemPair : items) {
            auto item = itemPair.second;
            total += item.getItemPrice();
        }
        return total;
    }

    string viewCart() {
        if (!items.size()) {
            return "Cart is empty";
        }
        string itemList;
        int cartTotal = getTotal();

        for (auto itemPair : items) {
            auto item = itemPair.second;
            itemList.append(item.getItemInfo());
            itemList += "\n";
        }
        return itemList + "\nTotal Amout : Rs. " + to_string(cartTotal) + '\n';
    }

    bool isEmpty() {
        return items.empty();
    }
};