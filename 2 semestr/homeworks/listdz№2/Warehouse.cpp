#include "Warehouse.h"
#include <iomanip>
#include <iostream>

// Инициализация статической переменной
int Warehouse::nextCode = 0;

// Конструктор
Warehouse::Warehouse(WarehouseType warehouseType, double warehouseLongitude,
    double warehouseLatitude, int warehouseMaxCapacity)
    : type(warehouseType), longitude(warehouseLongitude),
    latitude(warehouseLatitude), maxCapacity(warehouseMaxCapacity),
    totalStock(0) {
    id = "W" + std::to_string(100 + nextCode++);
    if (id.length() > 4) id = id.substr(0, 4);
}

// Реализации геттеров
std::string Warehouse::getId() const { return id; }
WarehouseType Warehouse::getType() const { return type; }
double Warehouse::getLongitude() const { return longitude; }
double Warehouse::getLatitude() const { return latitude; }
int Warehouse::getMaxCapacity() const { return maxCapacity; }
int Warehouse::getTotalStock() const { return totalStock; }
const std::vector<Product>& Warehouse::getProducts() const { return products; }

// Добавление продукта
bool Warehouse::addProduct(const Product& product) {
    if (totalStock + product.getQuantity() <= maxCapacity) {
        products.push_back(product);
        totalStock += product.getQuantity();
        return true;
    }
    return false;
}

// Вывод информации
void Warehouse::printInfo() const {
    std::cout << "=== Информация о складе ===\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Тип: " << warehouseTypeToString(type) << "\n";
    std::cout << "Координаты: (" << std::fixed << std::setprecision(6)
        << latitude << ", " << longitude << ")\n";
    std::cout << "Заполненность: " << totalStock << "/" << maxCapacity << "\n";
    std::cout << "Продукты (" << products.size() << "):\n";

    for (const auto& product : products) {
        std::cout << "  - " << product.getName() << ": "
            << product.getQuantity() << " ед.\n";
    }
}