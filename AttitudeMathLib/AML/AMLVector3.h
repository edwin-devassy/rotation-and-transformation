#ifndef AML_VECTOR3_H
#define AML_VECTOR3_H

#include <iostream>

namespace AML
{
    class Vector3
    {
    private:
        /* data */
    public:
        union 
        {
            /* data */
            double data[3];
            struct
            {
                double x;
                double y;
                double z;
            };
        };
        
        Vector3(/* args */);
        Vector3(double val);
        Vector3(double x, double y, double z);
        Vector3(const double data[3]);

        // Operator assignment(Vector) 

        // Vector3&: This indicates that the function returns a reference to a Vector3 object. This allows for chain assignments like a += b += c;.
        // operator+=: This is the function name. In C++, operators like += can be overloaded by defining a function named operator+=.
        // (const Vector3& rhs): This is the parameter list. The function takes one argument, which is a constant reference to a Vector3 object
        Vector3& operator+=(const Vector3& rhs);
        Vector3& operator-=(const Vector3& rhs);
        Vector3& operator*=(const Vector3& rhs);
        Vector3& operator/=(const Vector3& rhs);

        // Operator assignment(Scalar) 

        Vector3& operator+=(double scalar_value);
        Vector3& operator-=(double scalar_value);
        Vector3& operator*=(double scalar_value);
        Vector3& operator/=(double scalar_value);

        // Special Object Creation
        static const Vector3 xAxis();
        static const Vector3 yAxis();
        static const Vector3 zAxis();
    };

    // Vector vector element wise operations
    Vector3 operator-(const Vector3& rhs);
    Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
    Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
    Vector3 operator*(const Vector3& lhs, const Vector3& rhs);
    Vector3 operator/(const Vector3& lhs, const Vector3& rhs);

    // Vector scalar operations
    Vector3 operator+(const Vector3& lhs, double scalar_value);
    Vector3 operator-(const Vector3& lhs, double scalar_value);
    Vector3 operator*(const Vector3& lhs, double scalar_value);
    Vector3 operator/(const Vector3& lhs, double scalar_value);
    
    // Scalar vector operations
    Vector3 operator+(double scalar_value, const Vector3& rhs);
    Vector3 operator-(double scalar_value, const Vector3& rhs);
    Vector3 operator*(double scalar_value, const Vector3& rhs);
    Vector3 operator/(double scalar_value, const Vector3& rhs);

    // Vector operations
    double norm(const Vector3& v);
    void normalize(Vector3& v);
    Vector3 unit(const Vector3& v);
    Vector3 cross(const Vector3& lhs, const Vector3& rhs);
    double dot(const Vector3& lhs, const Vector3& rhs);

    // Stream Functions
    std::ostream& operator<<(std::ostream& os, const Vector3& v);    
}

#endif // AML_VECTOR3_H