#include <string>
#include <iostream>
#include <cmath>

#include "AML.h"

using namespace AML;

int main(int argc, char const *argv[])
{
    Vector3 v1(1.0, 2.0, 3.0);
    Vector3 v2(4.0, 5.0, 6.0);

    Vector3 v3 = v1 + v2;
    Vector3 v4 = v1 * v2;


    std::cout << "V3 = " << v3 << std::endl;
    std::cout << "V4 = " << v4 << std::endl;

    return 0;

}