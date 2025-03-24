// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include "warehouse.h"

extern Warehouse* warehouses[3];
void addProductToBestWarehouse(Product* p);
void menu();

#endif