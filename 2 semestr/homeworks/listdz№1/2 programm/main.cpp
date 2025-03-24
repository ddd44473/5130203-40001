#include "lib.h" // ���������� ������������ ����

int main() {

    std::setlocale(LC_ALL, "Russian_Russia.1251");
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(2, 3, 4, 5);

    std::cout << "q1: ";
    q1.print();

    std::cout << "q2: ";
    q2.print();

    std::cout << "��������: ";
    (q1 + q2).print();

    std::cout << "���������: ";
    (q1 - q2).print();

    std::cout << "���������: ";
    (q1 * q2).print();

    std::cout << "�������: ";
    (q1 / q2).print();

    std::cout << "����� q1: " << q1.norm() << std::endl;

    std::cout << "���������� q1: ";
    q1.conjugate().print();

    std::cout << "������������ q1: ";
    q1.normalize().print();

    std::cout << "�������� q1: ";
    q1.inverse().print();

    std::cout << "��������� ����������: " << euclideanDistance(q1, q2) << std::endl;

    std::cout << "����� ��������: " << chebyshevNorm(q1, q2) << std::endl;

    return 0;
}