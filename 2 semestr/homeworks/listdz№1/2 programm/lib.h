#ifndef lib_h
#define lib_h

#include <iostream>
#include <cmath>
#include <algorithm> 

class Quaternion {
private:
    double a; // �������������� ����� (������)
    double b, c, d; // ������������ ������ ������ (��������� �����)

public:
    // [2] ������������
    Quaternion(); // ����������� �� ���������
    Quaternion(double a, double b, double c, double d); // ����������� � �����������
    Quaternion(const Quaternion& other); // ����������� �����������

    // [3] ������ set � get
    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setD(double d);

    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    // [4] ������ �����������
    void print() const;

    // [5] ����� �����������
    double norm() const;

    // [6] ���������� �����������
    Quaternion conjugate() const;

    // [7] ������������ �����������
    Quaternion normalize() const;

    // [8] �������� �����������
    Quaternion inverse() const;
};

// [9] ���������� ������� ��� �������� ����� �������������
Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
Quaternion operator-(const Quaternion& q1, const Quaternion& q2);
Quaternion operator*(const Quaternion& q1, const Quaternion& q2);
Quaternion operator/(const Quaternion& q1, const Quaternion& q2);

// ��������� ������������
double dotProduct(const Quaternion& q1, const Quaternion& q2);

// [10] ��������� ���������� ����� ����� �������������
double euclideanDistance(const Quaternion& q1, const Quaternion& q2);

// [11] ����� �������� ����� ����� �������������
double chebyshevNorm(const Quaternion& q1, const Quaternion& q2);

#endif // QUATERNION_H