#include <catch2/catch_test_macros.hpp>
#include "AML.h"

using namespace AML;

TEST_CASE("Vector3Test", "[Vector3Test]")
{
    Vector3 v;
    REQUIRE(v.x == 0.0);
    Vector3 v1(1.0, 2.0, 3.0);
    Vector3 v2(4.0, 5.0, 6.0);

    Vector3 v3 = v1 + v2;
    Vector3 v4 = v1 * v2;

    REQUIRE(v3.x == 5.0);
    REQUIRE(v3.y == 7.0);
    REQUIRE(v3.z == 9.0);

    REQUIRE(v4.x == 4.0);
    REQUIRE(v4.y == 10.0);
    REQUIRE(v4.z == 18.0);
}