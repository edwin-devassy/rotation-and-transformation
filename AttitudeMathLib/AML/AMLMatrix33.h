#ifndef AML_MATRIX33_H
#define AML_MATRIX33_H

#include "AMLVector3.h"

namespace AML
{
    class Matrix33
    {
    private:
        /* data */
    public:

        union 
        {
            /* data */
            double data[3][3];
            struct
            {
                double m11;
                double m12;
                double m13;
                double m21;
                double m22;
                double m23;
                double m31;
                double m32;
                double m33;
            };
        };
        // Constructors
        Matrix33();
        explicit Matrix33(double val);
        explicit Matrix33(const double data[9]);
        explicit Matrix33(const double data[3][3]);
        explicit Matrix33(const Vector3& col1, const Vector3& col2, const Vector3& col3);

        // Operator assignments
        Matrix33& operator+=(const Matrix33& rhs);
        Matrix33& operator-=(const Matrix33& rhs);
        Matrix33& operator*=(const Matrix33& rhs);
        Matrix33& operator/=(const Matrix33& rhs);

        // Operator assignments using scalars
        Matrix33& operator+=(const double scalar);
        Matrix33& operator-=(const double scalar);
        Matrix33& operator*=(const double scalar);
        Matrix33& operator/=(const double scalar);

        // Special object creation
        static const Matrix33 identity();

        //~Matrix33();
    };
    
    // Matrix matrix operations
    Vector3 operator*(const Matrix33& lhs, const Vector3& vector);

    Matrix33 operator+(const Matrix33& lhs, const Matrix33& rhs);
    Matrix33 operator-(const Matrix33& lhs, const Matrix33& rhs);
    Matrix33 operator*(const Matrix33& lhs, const Matrix33& rhs);
    Matrix33 operator/(const Matrix33& lhs, const Matrix33& rhs);

    // Matrix vector operations
    Vector3 operator+(const Matrix33& rhs, const Vector3& vector);

    // Matrix scalar operations
    Matrix33 operator+(const Matrix33& rhs, const double scalar);
    Matrix33 operator-(const Matrix33& rhs, const double scalar);
    Matrix33 operator*(const Matrix33& rhs, const double scalar);
    Matrix33 operator/(const Matrix33& rhs, const double scalar);
    Matrix33 operator/(const double scalar, const Matrix33& rhs);
    Matrix33 operator*(const double scalar, const Matrix33& rhs);
    Matrix33 operator-(const double scalar, const Matrix33& rhs);
    Matrix33 operator+(const double scalar, const Matrix33& rhs);

    // Matrix special operations
    Vector3 diag(const Matrix33& rhs); // Diagonal vector from a matrix
    Matrix33 diag(const Vector3& vector); // Diagonal matrix from a vector
    Matrix33 transpose(const Matrix33& rhs); // Transpose of a matrix
    double determinant(const Matrix33& rhs); // Determinant of a matrix
    Matrix33 inverse(const Matrix33& rhs); // Inverse of a matrix

    //Overloaded stream operators
    std::ostream& operator<<(std::ostream& os, const Matrix33& rhs);



}


#endif  // AML_MATRIX33_H