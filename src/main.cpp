// main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

// Base class: Product
class Product {
protected:
    std::string name;
    double price;
    std::string description;

public:
    Product(const std::string& name, double price, const std::string& description)
        : name(name), price(price), description(description) {}

    virtual ~Product() {}

    virtual double calculateCost(int quantity) const {
        return price * quantity;
    }

    virtual std::string toString() const {
        return name + "\n\t- " + description + "\n\t- Price: $" + std::to_string(price);
    }

    const std::string& getName() const {
        return name;
    }
};

// Derived class: Electronic
class Electronic : public Product {
private:
    double warrantyCost;

public:
    Electronic(const std::string& name, double price, const std::string& description, double warrantyCost)
        : Product(name, price, description), warrantyCost(warrantyCost) {}

    double calculateCost(int quantity) const override {
        double totalWarranty = warrantyCost * quantity * 0.5;
        return (price * quantity) + totalWarranty;
    }

    std::string toString() const override {
        return name + " (Electronic)\n\t- " + description +
               "\n\t- Price: $" + std::to_string(price) +
               "\n\t- Warranty: $" + std::to_string(warrantyCost);
    }
};

// Enums for Clothing
enum class Size { Small, Medium, Large };
enum class Material { Cotton, Leather, Linen };

// Derived class: Clothing
class Clothing : public Product {
private:
    Size size;
    Material material;

public:
    Clothing(const std::string& name, double price, const std::string& description, Size size, Material material)
        : Product(name, price, description), size(size), material(material) {}

    double calculateCost(int quantity) const override {
        double sizeMultiplier = 1.0;
        if (size == Size::Small)
            sizeMultiplier = 0.5;
        else if (size == Size::Large)
            sizeMultiplier = 1.5;

        double materialMultiplier = 1.0;
        if (material == Material::Cotton)
            materialMultiplier = 1.2;
        else if (material == Material::Leather)
            materialMultiplier = 1.4;
        else if (material == Material::Linen)
            materialMultiplier = 2.0;

        return price * quantity * sizeMultiplier * materialMultiplier;
    }

    std::string toString() const override {
        return name + " (Clothing)\n\t- " + description +
               "\n\t- Price: $" + std::to_string(price) +
               "\n\t- Size: " + sizeToString(size) +
               "\n\t- Material: " + materialToString(material);
    }

private:
    std::string sizeToString(Size s) const {
        switch (s) {
            case Size::Small: return "Small";
            case Size::Medium: return "Medium";
            case Size::Large: return "Large";
            default: return "Unknown";
        }
    }

    std::string materialToString(Material m) const {
        switch (m) {
            case Material::Cotton: return "Cotton";
            case Material::Leather: return "Leather";
            case Material::Linen: return "Linen";
            default: return "Unknown";
        }
    }
};

// Derived class: Book
class Book : public Product {
private:
    std::string author;

public:
    Book(const std::string& name, double price, const std::string& description, const std::string& author)
        : Product(name, price, description), author(author) {}

    std::string toString() const override {
        return name + " (Book)\n\t- " + description +
               "\n\t- Author: " + author +
               "\n\t- Price: $" + std::to_string(price);
    }
};

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
