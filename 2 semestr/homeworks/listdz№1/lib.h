#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <cmath>
#include <stdexcept>

const double PI = 3.14159265358979323846;

class Ellipse {
private:
    double h, k; // ���������� ������
    double a, b; // ������� � ����� �������
    bool isXAxisMajor; // true, ���� ������� ��� �� ��� X, ����� false

public:
    // ����������� �� ���������
    Ellipse() : h(0), k(0), a(1), b(0.5), isXAxisMajor(true) {}

    // ����������� � �����������
    Ellipse(double h, double k, double a, double b, bool isXAxisMajor = true)
        : h(h), k(k), isXAxisMajor(isXAxisMajor) {
        setAxes(a, b);
    }

    // ����������� �����������
    Ellipse(const Ellipse& other)
        : h(other.h), k(other.k), a(other.a), b(other.b), isXAxisMajor(other.isXAxisMajor) {
    }

    // ������ ��������� ��������
    void setCenter(double h, double k) {
        this->h = h;
        this->k = k;
    }

    void setAxes(double a, double b) {
        if (a > b) {
            this->a = a;
            this->b = b;
        }
        else {
            throw std::invalid_argument("Major axis (a) must be greater than minor axis (b).");
        }
    }

    // ������ ��������� ��������
    double getH() const { return h; }
    double getK() const { return k; }
    double getA() const { return a; }
    double getB() const { return b; }
    bool isMajorAxisX() const { return isXAxisMajor; }

    // ���������� �������������� c
    double calculateC() const {
        return std::sqrt(a * a - b * b);
    }

    // ������� �������
    std::pair<std::pair<double, double>, std::pair<double, double>> getVertices() const {
        if (isXAxisMajor) {
            return { {h - a, k}, {h + a, k} };
        }
        else {
            return { {h, k - a}, {h, k + a} };
        }
    }

    // ������ �������
    std::pair<std::pair<double, double>, std::pair<double, double>> getFoci() const {
        double c = calculateC();
        if (isXAxisMajor) {
            return { {h - c, k}, {h + c, k} };
        }
        else {
            return { {h, k - c}, {h, k + c} };
        }
    }

    // ����� ��������� �����
    double focalChordLength() const {
        return (2 * b * b) / a;
    }

    // ��������������
    double eccentricity() const {
        return calculateC() / a;
    }

    // �������� ��������� ����� P(x, y)
    std::string checkPointPosition(double x, double y) const {
        double value = ((x - h) * (x - h)) / (a * a) + ((y - k) * (y - k)) / (b * b);
        if (value < 1) return "Inside";
        if (value == 1) return "On";
        return "Outside";
    }

    // ��������������� �������� �������
    double approximatePerimeter() const {
        return PI * (3 * (a + b) - std::sqrt((3 * a + b) * (a + 3 * b)));
    }

    // ������� �������
    double area() const {
        return PI * a * b;
    }

    // ���������� ������ ���������� �� ����� ����������
    std::pair<double, double> calculateSecondCoordinate(bool isXGiven, double coord) const {
        if (isXGiven) {
            double ySquared = b * b * (1 - ((coord - h) * (coord - h)) / (a * a));
            if (ySquared < 0) throw std::invalid_argument("Invalid coordinate for ellipse.");
            return { k + std::sqrt(ySquared), k - std::sqrt(ySquared) };
        }
        else {
            double xSquared = a * a * (1 - ((coord - k) * (coord - k)) / (b * b));
            if (xSquared < 0) throw std::invalid_argument("Invalid coordinate for ellipse.");
            return { h + std::sqrt(xSquared), h - std::sqrt(xSquared) };
        }
    }

    // ������ ��������� �������
    void printEquation() const {
        std::cout << "Ellipse equation: ";
        if (isXAxisMajor) {
            std::cout << "(x - " << h << ")^2 / " << a << "^2 + (y - " << k << ")^2 / " << b << "^2 = 1\n";
        }
        else {
            std::cout << "(x - " << h << ")^2 / " << b << "^2 + (y - " << k << ")^2 / " << a << "^2 = 1\n";
        }
    }
};

#endif // LIB_H
