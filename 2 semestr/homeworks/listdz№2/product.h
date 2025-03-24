// product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string barcode;
    std::string description;
    double price;
    int quantity;
    double latitude;
    double longitude;

    void generateBarcode();

public:
    Product();
    Product(std::string desc, double prc, int qty, double lat, double lon);
    Product(const Product& other);

    // Setters
    void setLatitude(double lat);
    void setLongitude(double lon);
    void setDescription(const std::string& desc);
    void setPrice(double prc);
    void setQuantity(int qty);

    // Getters
    std::string getBarcode() const;
    std::string getDescription() const;
    double getPrice() const;
    int getQuantity() const;
    double getLatitude() const;
    double getLongitude() const;

    void print() const;
};

#endif