#pragma once
#include <string>

class Product {
private:
    std::string name;
    int quantity;

public:
    Product(const std::string& productName, int productQuantity);

    // Геттеры
    std::string getName() const;
    int getQuantity() const;
};