// Book.h

#ifndef BOOK_H
#define BOOK_H

#include "Product.h"

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

#endif
