#include <iostream>
#include <clocale>
#include <windows.h>
#include "Warehouse.h"
#include "Product.h"
#include "Enums.h"

std::string warehouseTypeToString(WarehouseType type) {
    switch (type) {
    case WarehouseType::CENTER: return "центр";
    case WarehouseType::WEST: return "запад";
    case WarehouseType::EAST: return "восток";
    default: return "неизвестно";
    }
}

int main() {
    // Настройка консоли для русского языка
    system("chcp 1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    // Создание складов
    Warehouse center(WarehouseType::CENTER, 37.6176, 55.7558, 1000);
    Warehouse west(WarehouseType::WEST, 30.3159, 59.9391, 500);
    Warehouse east(WarehouseType::EAST, 131.8856, 43.1155, 800);

    // Создание и добавление продуктов
    Product laptops("Ноутбуки", 50);
    Product phones("Телефоны", 20);
    Product tablets("Планшеты", 15);

    center.addProduct(laptops);
    west.addProduct(phones);
    east.addProduct(tablets);

    // Вывод информации
    center.printInfo();
    std::cout << "\n";
    west.printInfo();
    std::cout << "\n";
    east.printInfo();

    // Ожидание ввода перед закрытием
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.get();

    return 0;
}