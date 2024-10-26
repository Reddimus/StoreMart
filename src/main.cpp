// main.cpp

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Product.h"
#include "Electronic.h"
#include "Clothing.h"
#include "Book.h"

int main() {
    std::cout << "Hi, welcome to SomeMart.\n";

    std::vector<std::shared_ptr<Product>> products = {
        std::make_shared<Electronic>("Washing Machine", 500.0, "It's OK at washing clothes.", 100.0),
        std::make_shared<Clothing>("T Shirt", 20.0, "The best outdoor wear.", Size::Medium, Material::Cotton),
        std::make_shared<Book>("I Spy", 10.0, "A classic amongst children.", "John Doe")
    };

    std::map<int, int> cart; // product index to quantity

    while (true) {
        std::cout << "Here is what we are currently selling:\n";
        for (size_t i = 0; i < products.size(); ++i) {
            std::cout << i + 1 << " - " << products[i]->toString() << "\n";
        }
        std::cout << "Enter the number of which one you want to buy, or enter 0 to exit.\n> ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > static_cast<int>(products.size())) {
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        int index = choice - 1;
        std::cout << "How many do you want to purchase?\n> ";
        int quantity;
        std::cin >> quantity;

        if (quantity <= 0) {
            std::cout << "Quantity must be at least 1. Please try again.\n";
            continue;
        }

        cart[index] += quantity;
        std::cout << "I've added " << quantity << " of \"" << products[index]->getName() << "\" to your cart.\n";
    }

    if (!cart.empty()) {
        double totalCost = 0.0;
        std::cout << "Okay, your total comes out to:\n";
        for (const auto& item : cart) {
            int index = item.first;
            int quantity = item.second;
            double cost = products[index]->calculateCost(quantity);
            totalCost += cost;
            std::cout << "- " << quantity << " of \"" << products[index]->getName() << "\": $" << cost << "\n";
        }
        std::cout << "Total: $" << totalCost << "\n";
    } else {
        std::cout << "You did not purchase anything.\n";
    }

    return 0;
}
