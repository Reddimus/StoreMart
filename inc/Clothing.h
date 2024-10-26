// Clothing.h

#ifndef CLOTHING_H
#define CLOTHING_H

#include "Product.h"

enum class Size { Small, Medium, Large };
enum class Material { Cotton, Leather, Linen };

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

#endif
