#include <iostream>
#include <clocale>
#include <windows.h>
#include "Warehouse.h"
#include "Product.h"
#include "Enums.h"

std::string warehouseTypeToString(WarehouseType type) {
    switch (type) {
    case WarehouseType::CENTER: return "�����";
    case WarehouseType::WEST: return "�����";
    case WarehouseType::EAST: return "������";
    default: return "����������";
    }
}

int main() {
    // ��������� ������� ��� �������� �����
    system("chcp 1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    // �������� �������
    Warehouse center(WarehouseType::CENTER, 37.6176, 55.7558, 1000);
    Warehouse west(WarehouseType::WEST, 30.3159, 59.9391, 500);
    Warehouse east(WarehouseType::EAST, 131.8856, 43.1155, 800);

    // �������� � ���������� ���������
    Product laptops("��������", 50);
    Product phones("��������", 20);
    Product tablets("��������", 15);

    center.addProduct(laptops);
    west.addProduct(phones);
    east.addProduct(tablets);

    // ����� ����������
    center.printInfo();
    std::cout << "\n";
    west.printInfo();
    std::cout << "\n";
    east.printInfo();

    // �������� ����� ����� ���������
    std::cout << "\n������� Enter ��� ������...";
    std::cin.get();

    return 0;
}