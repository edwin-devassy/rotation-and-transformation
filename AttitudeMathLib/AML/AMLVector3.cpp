#include "AMLVector3.h"
#include <cmath>

namespace AML
{
    Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}
    Vector3::Vector3(double val) : x(val), y(val), z(val) {}
    Vector3::Vector3(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}
    Vector3::Vector3(const double data[3]) : x(data[0]), y(data[1]), z(data[2]) {}

    // Operator assignment(Vector)
    Vector3 &Vector3::operator+=(const Vector3 &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    Vector3 &Vector3::operator-=(const Vector3 &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    Vector3 &Vector3::operator*=(const Vector3 &rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }

    Vector3 &Vector3::operator/=(const Vector3 &rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        return *this;
    }

    // Operator assignment(Scalar)
    Vector3 &Vector3::operator+=(double scalar_value)
    {
        x += scalar_value;
        y += scalar_value;
        z += scalar_value;
        return *this;
    }
    Vector3 &Vector3::operator-=(double scalar_value)
    {
        x -= scalar_value;
        y -= scalar_value;
        z -= scalar_value;
        return *this;
    }
    Vector3 &Vector3::operator*=(double scalar_value)
    {
        x *= scalar_value;
        y *= scalar_value;
        z *= scalar_value;
        return *this;
    }
    Vector3 &Vector3::operator/=(double scalar_value)
    {
        x /= scalar_value;
        y /= scalar_value;
        z /= scalar_value;
        return *this;
    }

    // Special Object Creation
    const Vector3 Vector3::xAxis() { return Vector3(1.0, 0.0, 0.0); }
    const Vector3 Vector3::yAxis() { return Vector3(0.0, 1.0, 0.0); }
    const Vector3 Vector3::zAxis() { return Vector3(0.0, 0.0, 1.0); }

    // Vector vector element wise operations
    Vector3 operator-(const Vector3 &rhs) { return Vector3(-rhs.x, -rhs.y, -rhs.z); }
    /**
     *
     * The Vector3 class provides operations for performing vector addition, subtraction, and other mathematical operations.
     * It also supports operator overloading for convenient usage. Canonical usage is as follows:
     */
    Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs) { return (Vector3(lhs) += rhs); }
    Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs) { return (Vector3(lhs) -= rhs); }
    Vector3 operator*(const Vector3 &lhs, const Vector3 &rhs) { return (Vector3(lhs) *= rhs); }
    Vector3 operator/(const Vector3 &lhs, const Vector3 &rhs) { return (Vector3(lhs) /= rhs); }

    // Vector scalar operations
    Vector3 operator+(const Vector3 &lhs, double scalar_value) { return (Vector3(lhs) += scalar_value); }
    Vector3 operator-(const Vector3 &lhs, double scalar_value) { return (Vector3(lhs) -= scalar_value); }
    Vector3 operator*(const Vector3 &lhs, double scalar_value) { return (Vector3(lhs) *= scalar_value); }
    Vector3 operator/(const Vector3 &lhs, double scalar_value) { return (Vector3(lhs) /= scalar_value); }

    // Scalar vector operations
    Vector3 operator+(double scalar_value, const Vector3 &rhs) { return (Vector3(rhs) += scalar_value); }
    Vector3 operator-(double scalar_value, const Vector3 &rhs) { return (Vector3(rhs) -= scalar_value); }
    Vector3 operator*(double scalar_value, const Vector3 &rhs) { return (Vector3(rhs) *= scalar_value); }
    Vector3 operator/(double scalar_value, const Vector3 &rhs) { return (Vector3(rhs) /= scalar_value); }

    // Vector operations
    double norm(const Vector3 &v) { return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
    void normalize(Vector3 &v)
    {
        double mag = norm(v);
        if (mag > 0.0)
        {
            v.x /= mag;
            v.y /= mag;
            v.z /= mag;
        }
    }
    Vector3 unit(const Vector3 &v)
    {
        double mag = norm(v);
        if (mag > 0.0)
        {
            return Vector3(v.x / mag, v.y / mag, v.z / mag);
        }
        else
        {
            return Vector3();
        }
    }
    Vector3 cross(const Vector3 &lhs, const Vector3 &rhs)
    {
        return Vector3(lhs.y * rhs.z - lhs.z * rhs.y,
                       lhs.z * rhs.x - lhs.x * rhs.z,
                       lhs.x * rhs.y - lhs.y * rhs.x);
    }
    double dot(const Vector3 &lhs, const Vector3 &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    // Stream Functions
    std::ostream& operator<<(std::ostream& os, const Vector3& obj)
    {
        os << "[" << obj.x << ", " << obj.y << ", " << obj.z << "]";
        return os;
    }


} // namespace AML