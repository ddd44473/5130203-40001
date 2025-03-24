#include "lib.h"

// [2] Конструкторы
Quaternion::Quaternion() : a(1), b(0), c(0), d(0) {}

Quaternion::Quaternion(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

Quaternion::Quaternion(const Quaternion& other) : a(other.a), b(other.b), c(other.c), d(other.d) {}

// [3] Методы set и get
void Quaternion::setA(double a) { this->a = a; }
void Quaternion::setB(double b) { this->b = b; }
void Quaternion::setC(double c) { this->c = c; }
void Quaternion::setD(double d) { this->d = d; }

double Quaternion::getA() const { return a; }
double Quaternion::getB() const { return b; }
double Quaternion::getC() const { return c; }
double Quaternion::getD() const { return d; }

// [4] Печать кватерниона
void Quaternion::print() const {
    std::cout << a << " + " << b << "i + " << c << "j + " << d << "k" << std::endl;
}

// [5] Норма кватерниона
double Quaternion::norm() const {
    return std::sqrt(a * a + b * b + c * c + d * d);
}

// [6] Сопряжение кватерниона
Quaternion Quaternion::conjugate() const {
    return Quaternion(a, -b, -c, -d);
}

// [7] Нормализация кватерниона
Quaternion Quaternion::normalize() const {
    double n = norm();
    if (n == 0) {
        throw std::runtime_error("Нормализация невозможна: норма равна нулю.");
    }
    return Quaternion(a / n, b / n, c / n, d / n);
}

// [8] Инверсия кватерниона
Quaternion Quaternion::inverse() const {
    double n = norm();
    if (n == 0) {
        throw std::runtime_error("Инверсия невозможна: норма равна нулю.");
    }
    Quaternion conj = conjugate();
    return Quaternion(conj.a / (n * n), conj.b / (n * n), conj.c / (n * n), conj.d / (n * n));
}

// [9] Глобальные функции для операций между кватернионами
Quaternion operator+(const Quaternion& q1, const Quaternion& q2) {
    return Quaternion(q1.getA() + q2.getA(), q1.getB() + q2.getB(), q1.getC() + q2.getC(), q1.getD() + q2.getD());
}

Quaternion operator-(const Quaternion& q1, const Quaternion& q2) {
    return Quaternion(q1.getA() - q2.getA(), q1.getB() - q2.getB(), q1.getC() - q2.getC(), q1.getD() - q2.getD());
}

Quaternion operator*(const Quaternion& q1, const Quaternion& q2) {
    double a = q1.getA() * q2.getA() - q1.getB() * q2.getB() - q1.getC() * q2.getC() - q1.getD() * q2.getD();
    double b = q1.getA() * q2.getB() + q1.getB() * q2.getA() + q1.getC() * q2.getD() - q1.getD() * q2.getC();
    double c = q1.getA() * q2.getC() - q1.getB() * q2.getD() + q1.getC() * q2.getA() + q1.getD() * q2.getB();
    double d = q1.getA() * q2.getD() + q1.getB() * q2.getC() - q1.getC() * q2.getB() + q1.getD() * q2.getA();
    return Quaternion(a, b, c, d);
}

Quaternion operator/(const Quaternion& q1, const Quaternion& q2) {
    Quaternion invQ2 = q2.inverse();
    return q1 * invQ2;
}

double dotProduct(const Quaternion& q1, const Quaternion& q2) {
    return q1.getA() * q2.getA() + q1.getB() * q2.getB() + q1.getC() * q2.getC() + q1.getD() * q2.getD();
}

// [10] Евклидово расстояние между двумя кватернионами
double euclideanDistance(const Quaternion& q1, const Quaternion& q2) {
    double da = q1.getA() - q2.getA();
    double db = q1.getB() - q2.getB();
    double dc = q1.getC() - q2.getC();
    double dd = q1.getD() - q2.getD();
    return std::sqrt(da * da + db * db + dc * dc + dd * dd);
}

// [11] Норма Чебышева между двумя кватернионами
double chebyshevNorm(const Quaternion& q1, const Quaternion& q2) {
    return std::max({ std::abs(q1.getA() - q2.getA()),
                     std::abs(q1.getB() - q2.getB()),
                     std::abs(q1.getC() - q2.getC()),
                     std::abs(q1.getD() - q2.getD()) });
}