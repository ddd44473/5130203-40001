#include <iostream>
#include "lib.h"
#include <cmath>

int main() {
    try {
        // Создание объекта эллипса
        Ellipse ellipse(0, 0, 5, 3, true);

        // Печать уравнения эллипса
        ellipse.printEquation();

        // Вершины и фокусы
        auto vertices = ellipse.getVertices();
        auto foci = ellipse.getFoci();

        std::cout << "Vertices: (" << vertices.first.first << ", " << vertices.first.second << ") and ("
            << vertices.second.first << ", " << vertices.second.second << ")\n";

        std::cout << "Foci: (" << foci.first.first << ", " << foci.first.second << ") and ("
            << foci.second.first << ", " << foci.second.second << ")\n";

        // Характеристики эллипса
        std::cout << "Focal chord length: " << ellipse.focalChordLength() << "\n";
        std::cout << "Eccentricity: " << ellipse.eccentricity() << "\n";
        std::cout << "Approximate perimeter: " << ellipse.approximatePerimeter() << "\n";
        std::cout << "Area: " << ellipse.area() << "\n";

        // Проверка положения точки
        double x = 2, y = 2;
        std::cout << "Point (" << x << ", " << y << ") is " << ellipse.checkPointPosition(x, y) << " the ellipse.\n";

        // Вычисление второй координаты
        auto secondCoord = ellipse.calculateSecondCoordinate(true, 4);
        std::cout << "For x = 4, possible y values are: " << secondCoord.first << " and " << secondCoord.second << "\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}