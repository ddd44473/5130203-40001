#ifndef lib_h
#define lib_h

#include <iostream>
#include <cmath>
#include <algorithm> 

class Quaternion {
private:
    double a; // Действительная часть (скаляр)
    double b, c, d; // Коэффициенты мнимых частей (векторная часть)

public:
    // [2] Конструкторы
    Quaternion(); // Конструктор по умолчанию
    Quaternion(double a, double b, double c, double d); // Конструктор с параметрами
    Quaternion(const Quaternion& other); // Конструктор копирования

    // [3] Методы set и get
    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setD(double d);

    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    // [4] Печать кватерниона
    void print() const;

    // [5] Норма кватерниона
    double norm() const;

    // [6] Сопряжение кватерниона
    Quaternion conjugate() const;

    // [7] Нормализация кватерниона
    Quaternion normalize() const;

    // [8] Инверсия кватерниона
    Quaternion inverse() const;
};

// [9] Глобальные функции для операций между кватернионами
Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
Quaternion operator-(const Quaternion& q1, const Quaternion& q2);
Quaternion operator*(const Quaternion& q1, const Quaternion& q2);
Quaternion operator/(const Quaternion& q1, const Quaternion& q2);

// Скалярное произведение
double dotProduct(const Quaternion& q1, const Quaternion& q2);

// [10] Евклидово расстояние между двумя кватернионами
double euclideanDistance(const Quaternion& q1, const Quaternion& q2);

// [11] Норма Чебышева между двумя кватернионами
double chebyshevNorm(const Quaternion& q1, const Quaternion& q2);

#endif // QUATERNION_H