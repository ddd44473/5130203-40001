#pragma once
#include <string>

enum class WarehouseType {
    CENTER,
    WEST,
    EAST
};

std::string warehouseTypeToString(WarehouseType type);