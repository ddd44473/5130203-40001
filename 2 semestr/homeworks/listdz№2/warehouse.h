// warehouse.h
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "product.h"
#include <vector>

enum WarehouseType { CENTER, WEST, EAST };

class Warehouse {
private:
    std::string id;
    WarehouseType type;
    double latitude;
    double longitude;
    int maxCapacity;
    int totalStock;
    std::vector<Product*> products;

    static int nextId;

public:
    Warehouse(WarehouseType t, double lat, double lon, int maxCap);
    Warehouse(const Warehouse& other);
    ~Warehouse();

    int calculateDistance(double lat, double lon) const;
    bool addProduct(Product* product);
    bool removeProduct(std::string barcode);
    void listProducts() const;
    Product* searchProduct(std::string description) const;

    std::string getTypeString() const;
    std::string getId() const;
    int getMaxCapacity() const;
};

#endif