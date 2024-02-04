#include "AML.h"
#include <catch2/catch_test_macros.hpp>

using namespace AML;

TEST_CASE("Matrix33Test", "[Matrix33Test]")
{
    double data[9] = {1.2, 3.2, 0.5, 0.1, 1.0, 6.0, -4.1, 6.0, 8.0};
    Matrix33 m1 = Matrix33(data);

    Vector3 v5 = Vector3(1.0, 0.0, 0.0);
    Vector3 v6 = m1 * v5;

    REQUIRE(v6.x == 1.2);
    REQUIRE(v6.y == 0.1);
    REQUIRE(v6.z == -4.1);
}