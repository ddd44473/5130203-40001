/*
    Template of class Circle
*/

#pragma once
#include "shape.h"
#include "rect.h"

class Circle : public Shape {

public:
    double centerX, centerY, radius;

public:
    Circle();
    Circle(double centerX, double centerY, double radius, COLOR color);
    Circle(const Circle& c);
    Circle(Rectangle& r);
    ~Circle();
    // polymorfirsm to virtual methods
    double calculate_perimeter();
    double calculate_area();
    void describe() const;
    void inflate(int d);
};