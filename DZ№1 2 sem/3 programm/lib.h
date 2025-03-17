#pragma once
#include <iostream>


using namespace std;
class Rectangle {
	public:
		int p_left, p_right, p_bottom, p_top;


    public:
        Rectangle(int left = 0, int right = 0, int bottom = 0, int top = 0);
        Rectangle(const Rectangle& r);
        ~Rectangle();
        void normalize_axis(int& x1, int& x2);
        void normalize_all();
        void print();
        double calculate_perimeter();
        double calculate_area();
        void inflate_axis(int x, int y);
        void inflate_all(int left, int right, int bottom, int top);
        void set_all(int left, int right, int bottom, int top);
        void get_all(int& left, int& right, int& bottom, int& top);
};

Rectangle build_rectangle(Rectangle r1, Rectangle r2);



Rectangle::Rectangle(int left, int right, int bottom, int top) {
    p_left = left;
    p_right = right;
    p_bottom = bottom;
    p_top = top;

    normalize_all();
}


Rectangle::Rectangle(const Rectangle& r) {
    p_left = r.p_left;
    p_right = r.p_right;
    p_bottom = r.p_bottom;
    p_top = r.p_top;

    normalize_all();
}


Rectangle::~Rectangle() {}


void Rectangle::normalize_axis(int& x1, int& x2) {
    int aux;

    if (x1 > x2) {
        aux = x1;
        x1 = x2;
        x2 = aux;
    }
}


void Rectangle::normalize_all() {
    normalize_axis(p_left, p_right);
    normalize_axis(p_bottom, p_top);
}


void Rectangle::print() {
    cout << "Left: " << p_left << endl;
    cout << "Right: " << p_right << endl;
    cout << "Bottom: " << p_bottom << endl;
    cout << "Top: " << p_top << endl;
}


double Rectangle::calculate_perimeter() {
    return 2 * (p_right - p_left) + 2 * (p_top - p_bottom);
}


double Rectangle::calculate_area() {
    return (p_right - p_left) * (p_top - p_bottom);
}


void Rectangle::inflate_axis(int x, int y) {
    inflate_all(x, x, y, y);
}



void Rectangle::inflate_all(int left, int right, int bottom, int top) {
    p_left -= left;
    p_right += right;
    p_bottom -= bottom;
    p_top += top;
}


void Rectangle::set_all(int left, int right, int bottom, int top) {
    p_left = left;
    p_right = right;
    p_bottom = bottom;
    p_top = top;
}


void Rectangle::get_all(int& left, int& right, int& bottom, int& top) {
    left = p_left;
    right = p_right;
    bottom = p_bottom;
    top = p_top;
}


Rectangle build_rectangle(Rectangle r1, Rectangle r2) {
    int x1, x2, y1, y2;

    x1 = min(r1.p_left, r2.p_left);
    x2 = max(r1.p_right, r2.p_right);
    y1 = min(r1.p_bottom, r2.p_bottom);
    y2 = max(r1.p_top, r2.p_top);

    return Rectangle(x1, x2, y1, y2);
}


