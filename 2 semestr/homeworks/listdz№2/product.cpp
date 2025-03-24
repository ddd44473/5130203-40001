// product.cpp
#include "product.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// ... (остальные методы)

void Product::setDescription(const std::string& desc) {
    description = desc.substr(0, 50);
}

void Product::setPrice(double prc) {
    price = prc > 0 ? prc : 0;
}

void Product::setQuantity(int qty) {
    quantity = qty > 0 ? qty : 0;
}

void Product::print() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Barcode: " << barcode << "\nDescription: " << description
        << "\nPrice: " << price << " RUB\nQuantity: " << quantity
        << "\nCoordinates: (" << latitude << ", " << longitude << ")\n\n";
}