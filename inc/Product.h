// Product.h

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

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

#endif
