// main.cpp
#include "globals.h"
#include <ctime>

int main() {
    srand(time(nullptr));
    menu();

    // Очистка памяти
    for (auto wh : warehouses) delete wh;
    return 0;
}