#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Vector {
	public:

		double xi, yj, zk;

	public:

		Vector(double x = 0, double y = 0, double z = 0);
		Vector(const Vector& v);
		~Vector();


		static void input_vector(Vector& v);

		void print();

		double calculate_module();

		Vector unit_vector();
};

Vector::Vector(double x, double y, double z) {
	xi = x;
	yj = y;
	zk = z;
}

Vector::Vector(const Vector& v) {
	xi = v.xi;
	yj = v.yj;
	zk = v.zk;
}

Vector::~Vector() {};

void Vector::input_vector(Vector& v) {

	double x, y, z;

	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	cout << "Z: ";
	cin >> z;

	v = Vector(x, y, z);

}

void Vector::print() {
	cout << xi << "i + " << yj << "j + " << zk << "k" << endl;
}

double Vector::calculate_module() {
	return sqrt(xi * xi + yj * yj + zk * zk);
}

Vector Vector::unit_vector() {
	double mod = calculate_module();
	return Vector(xi / mod, yj / mod, zk / mod);
}





double scalar_product(Vector v1, Vector v2) {
	return v1.xi * v2.xi + v1.yj * v2.yj + v1.zk * v2.zk;
}

Vector vector_product(Vector v1, Vector v2) {
	double x, y, z;
	x = v1.yj * v2.zk - v1.zk * v2.yj;
	y = v1.zk * v2.xi - v1.xi * v2.zk;
	z = v1.xi * v2.yj - v1.yj * v2.xi;

	return Vector(x, y, z);
}

double angle(Vector v1, Vector v2) {
	double sp, mod1, mod2;

	sp = scalar_product(v1, v2);
	mod1 = v1.calculate_module();
	mod2 = v2.calculate_module();

	return acos(sp / (mod1 * mod2));
}

double euclidean_dist(Vector v1, Vector v2) {
	return sqrt(pow(v1.xi - v2.xi, 2) + pow(v1.yj - v2.yj, 2) + pow(v1.zk - v2.zk, 2));
}

double manhattan_dist(Vector v1, Vector v2) {
	return abs(v1.xi - v2.xi) + abs(v1.yj - v2.yj) + abs(v1.zk - v2.zk);
}




