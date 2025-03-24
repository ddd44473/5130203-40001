// globals.cpp
#include "globals.h"
#include "warehouse.h"

Warehouse* warehouses[3] = {
    new Warehouse(CENTER, 55.75, 37.61, 1000),
    new Warehouse(WEST, 59.93, 30.31, 800),
    new Warehouse(EAST, 43.11, 131.87, 1200)
};

// Реализация addProductToBestWarehouse и menu...