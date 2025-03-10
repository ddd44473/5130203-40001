#include <iostream>
#include <cmath>
#include "clss.h"
using namespace std;

int main()
{
    Vector x, y;

    Vector::input_vector(x);
    Vector::input_vector(y);

    cout << "Vector x:" << endl;
    x.print();
    cout << "Vector y: " << endl;
    y.print();

    cout << "Module x = " << x.calculate_module() << endl;
    cout << "Module y = " << y.calculate_module() << endl;

    cout << "Unit vector vx: " << endl;
    x.unit_vector().print();
    cout << "Unit vector vy: " << endl;
    y.unit_vector().print();

    cout << "Scalar product x and y = " << scalar_product(x, y) << endl;

    vector_product(x, y).print();

    cout << "Angle: " << angle(x, y) << endl;

    cout << "Euclidean distance: " << euclidean_dist(x, y) << endl;

    cout << "Manhattan distance: " << manhattan_dist(x, y) << endl;
}


