#include <string>
#include <iostream>
#include <cmath>

#include "AML.h"

using namespace AML;

int main(int argc, char const *argv[])
{
    // Vector related operations
    Vector3 v1(1.0, 2.0, 3.0);
    Vector3 v2(4.0, 5.0, 6.0);

    Vector3 v3 = v1 + v2;
    Vector3 v4 = v1 * v2;

    std::cout << "V3 = " << v3 << std::endl;
    std::cout << "V4 = " << v4 << std::endl;

    // Matrix related operations
    double data[9] = {1.2, 3.2, 0.5, 0.1, 1.0, 6.0, -4.1, 6.0, 8.0};
    Matrix33 m1 = Matrix33(data);

    Vector3 v5 = Vector3(1.0, 0.0, 0.0);
    Vector3 v6 = m1 * v5;

    std::cout << "V6 = " << v6 << std::endl;



    return 0;

}