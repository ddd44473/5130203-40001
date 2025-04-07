#include "Product.h"

Product::Product(const std::string& productName, int productQuantity)
    : name(productName), quantity(productQuantity) {
}

std::string Product::getName() const {
    return name;
}

int Product::getQuantity() const {
    return quantity;
}