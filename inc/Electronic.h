// Electronic.h

#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include "Product.h"

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

#endif
