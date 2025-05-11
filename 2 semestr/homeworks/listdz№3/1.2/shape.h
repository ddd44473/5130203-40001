/*
    Template of class Shape
*/

#pragma once

enum COLOR { RED, GREEN, BLUE };

class Shape {

public:
    COLOR color;

public:
    Shape();
    Shape(enum COLOR c);
    Shape(const Shape& s);
    virtual ~Shape();
    virtual double calculate_perimeter() { return 0.0; };
    virtual double calculate_area() { return 0.0; };
    virtual void describe() const;
    virtual void inflate(int d) {};
};