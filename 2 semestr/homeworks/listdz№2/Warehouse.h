#pragma once
#include <vector>
#include <string>
#include "Product.h"
#include "Enums.h"

class Warehouse {
private:
    std::string id;
    WarehouseType type;
    double longitude;
    double latitude;
    int maxCapacity;
    int totalStock;
    std::vector<Product> products;

    static int nextCode;

public:
    Warehouse(WarehouseType warehouseType, double warehouseLongitude,
        double warehouseLatitude, int warehouseMaxCapacity);

    // Геттеры
    std::string getId() const;
    WarehouseType getType() const;
    double getLongitude() const;
    double getLatitude() const;
    int getMaxCapacity() const;
    int getTotalStock() const;
    const std::vector<Product>& getProducts() const;

    // Методы
    bool addProduct(const Product& product);
    void printInfo() const;
};