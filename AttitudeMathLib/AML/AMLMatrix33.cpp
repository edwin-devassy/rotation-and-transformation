#include "AMLMatrix33.h"
#include "AMLVector3.h"
#include <cmath>

namespace AML
{
  // Constructors
  Matrix33::Matrix33()
      : m11(0.0), m12(0.0), m13(0.0),
        m21(0.0), m22(0.0), m23(0.0),
        m31(0.0), m32(0.0), m33(0.0) {}

  Matrix33::Matrix33(double val)
      : m11(val), m12(val), m13(val),
        m21(val), m22(val), m23(val),
        m31(val), m32(val), m33(val) {}

  Matrix33::Matrix33(const double data[9])
      : m11(data[0]), m12(data[1]), m13(data[2]),
        m21(data[3]), m22(data[4]), m23(data[5]),
        m31(data[6]), m32(data[7]), m33(data[8]) {}

  Matrix33::Matrix33(const double data[3][3])
      : m11(data[0][0]), m12(data[0][1]), m13(data[0][2]),
        m21(data[1][0]), m22(data[1][1]), m23(data[1][2]),
        m31(data[2][0]), m32(data[2][1]), m33(data[2][2]) {}
  Matrix33::Matrix33(const Vector3 &col1, const Vector3 &col2, const Vector3 &col3)
      : m11(col1.x), m12(col1.x), m13(col3.x),
        m21(col2.y), m22(col2.y), m23(col3.y),
        m31(col3.z), m32(col3.z), m33(col3.z) {}

  // Operator assignments
  Matrix33 &Matrix33::operator+=(const Matrix33 &rhs)
  {
    m11 += rhs.m11;
    m12 += rhs.m12;
    m13 += rhs.m13;
    m21 += rhs.m21;
    m22 += rhs.m22;
    m23 += rhs.m23;
    m31 += rhs.m31;
    m32 += rhs.m32;
    m33 += rhs.m33;
    return *this;
  }
  Matrix33 &Matrix33::operator-=(const Matrix33 &rhs)
  {
    m11 -= rhs.m11;
    m12 -= rhs.m12;
    m13 -= rhs.m13;
    m21 -= rhs.m21;
    m22 -= rhs.m22;
    m23 -= rhs.m23;
    m31 -= rhs.m31;
    m32 -= rhs.m32;
    m33 -= rhs.m33;
    return *this;
  }
  Matrix33 &Matrix33::operator*=(const Matrix33 &rhs)
  {
    double m11_temp = m11 * rhs.m11 + m12 * rhs.m21 + m13 * rhs.m31;
    double m12_temp = m11 * rhs.m12 + m12 * rhs.m22 + m13 * rhs.m32;
    double m13_temp = m11 * rhs.m13 + m12 * rhs.m23 + m13 * rhs.m33;
    double m21_temp = m21 * rhs.m11 + m22 * rhs.m21 + m23 * rhs.m31;
    double m22_temp = m21 * rhs.m12 + m22 * rhs.m22 + m23 * rhs.m32;
    double m23_temp = m21 * rhs.m13 + m22 * rhs.m23 + m23 * rhs.m33;
    double m31_temp = m31 * rhs.m11 + m32 * rhs.m21 + m33 * rhs.m31;
    double m32_temp = m31 * rhs.m12 + m32 * rhs.m22 + m33 * rhs.m32;
    double m33_temp = m31 * rhs.m13 + m32 * rhs.m23 + m33 * rhs.m33;

    m11 = m11_temp;
    m12 = m12_temp;
    m13 = m13_temp;
    m21 = m21_temp;
    m22 = m22_temp;
    m23 = m23_temp;
    m31 = m31_temp;
    m32 = m32_temp;
    m33 = m33_temp;

    return *this;
  }
  Matrix33 &Matrix33::operator/=(const Matrix33 &rhs)
  {
    (*this) = (*this) * inverse(rhs);
    return *this;
  }

  // Operator assignments using scalars
  Matrix33 &Matrix33::operator+=(const double scalar)
  {
    m11 += scalar;
    m12 += scalar;
    m13 += scalar;
    m21 += scalar;
    m22 += scalar;
    m23 += scalar;
    m31 += scalar;
    m32 += scalar;
    m33 += scalar;
    return *this;
  }
  Matrix33 &Matrix33::operator-=(const double scalar)
  {
    m11 -= scalar;
    m12 -= scalar;
    m13 -= scalar;
    m21 -= scalar;
    m22 -= scalar;
    m23 -= scalar;
    m31 -= scalar;
    m32 -= scalar;
    m33 -= scalar;
    return *this;
  }
  Matrix33 &Matrix33::operator*=(const double scalar)
  {
    m11 *= scalar;
    m12 *= scalar;
    m13 *= scalar;
    m21 *= scalar;
    m22 *= scalar;
    m23 *= scalar;
    m31 *= scalar;
    m32 *= scalar;
    m33 *= scalar;
    return *this;
  }
  Matrix33 &Matrix33::operator/=(const double scalar)
  {
    m11 /= scalar;
    m12 /= scalar;
    m13 /= scalar;
    m21 /= scalar;
    m22 /= scalar;
    m23 /= scalar;
    m31 /= scalar;
    m32 /= scalar;
    m33 /= scalar;
    return *this;
  }

  // Special object creation
  const Matrix33 Matrix33::identity()
  {
    double data[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    return Matrix33(data);
  }

  // Matrix matrix operations
  Matrix33 operator-(const Matrix33 &lhs)
  {
    double data[3][3] = {{-lhs.m11, -lhs.m12, -lhs.m13},
                         {-lhs.m21, -lhs.m22, -lhs.m23},
                         {-lhs.m31, -lhs.m32, -lhs.m33}};
    return Matrix33(data);
  }
  Matrix33 operator+(const Matrix33 &lhs, const Matrix33 &rhs) { return (Matrix33(lhs) += rhs); }
  Matrix33 operator-(const Matrix33 &lhs, const Matrix33 &rhs) { return (Matrix33(lhs) -= rhs); }
  Matrix33 operator*(const Matrix33 &lhs, const Matrix33 &rhs) { return (Matrix33(lhs) *= rhs); }
  Matrix33 operator/(const Matrix33 &lhs, const Matrix33 &rhs) { return (Matrix33(lhs) /= rhs); }

  // Matrix vector operations
  Vector3 operator*(const Matrix33& lhs, const Vector3& vector)
  {
    return Vector3(lhs.m11 * vector.x + lhs.m12 * vector.y + lhs.m13 * vector.z,
                   lhs.m21 * vector.x + lhs.m22 * vector.y + lhs.m23 * vector.z,
                   lhs.m31 * vector.x + lhs.m32 * vector.y + lhs.m33 * vector.z);
  }
  // Matrix scalar operations
  Matrix33 operator+(const Matrix33 &rhs, const double scalar) { return (Matrix33(rhs) += scalar); }
  Matrix33 operator-(const Matrix33 &rhs, const double scalar) { return (Matrix33(rhs) -= scalar); }
  Matrix33 operator*(const Matrix33 &rhs, const double scalar) { return (Matrix33(rhs) *= scalar); }
  Matrix33 operator/(const Matrix33 &rhs, const double scalar) { return (Matrix33(rhs) /= scalar); }
  Matrix33 operator*(const double scalar, const Matrix33 &rhs) { return (Matrix33(rhs) *= scalar); }
  Matrix33 operator-(const double scalar, const Matrix33 &rhs) { return (Matrix33(scalar) -= rhs); }
  Matrix33 operator+(const double scalar, const Matrix33 &rhs) { return (Matrix33(scalar) += rhs); }
  Matrix33 operator/(const double scalar, const Matrix33 &rhs)
  {
    double data[3][3] = {{scalar / rhs.m11, scalar / rhs.m12, scalar / rhs.m13},
                         {scalar / rhs.m21, scalar / rhs.m22, scalar / rhs.m23},
                         {scalar / rhs.m31, scalar / rhs.m32, scalar / rhs.m33}};
    return Matrix33(data);
  }

  // Matrix special operations

  // Diagonal vector from a matrix
  Vector3 diag(const Matrix33 &rhs)
  {
    return Vector3(rhs.m11, rhs.m22, rhs.m33);
  }
  // Diagonal matrix from a vector
  Matrix33 diag(const Vector3 &vector)
  {
    double data[3][3] = {{vector.x, 0, 0},
                         {0, vector.y, 0},
                         {0, 0, vector.z}};
    return Matrix33(data);
  }
  Matrix33 transpose(const Matrix33 &rhs)
  {
    double data[3][3] = {{rhs.m11, rhs.m21, rhs.m31},
                         {rhs.m12, rhs.m22, rhs.m32},
                         {rhs.m13, rhs.m23, rhs.m33}};
    return Matrix33(data);
  }

  double determinant(const Matrix33 &rhs) // Determinant of a matrix
  {
    double det = rhs.m11 * (rhs.m22 * rhs.m33 - rhs.m23 * rhs.m32) -
                 rhs.m12 * (rhs.m21 * rhs.m33 - rhs.m23 * rhs.m31) +
                 rhs.m13 * (rhs.m21 * rhs.m32 - rhs.m22 * rhs.m31);
    return det;
  }
  // Inverse of a matrix
  Matrix33 inverse(const Matrix33 &rhs)
  {
    double det = determinant(rhs);
    if (det == 0)
    {
      throw std::invalid_argument("Matrix is not invertible");
      return Matrix33(NAN);
    }
    double data[3][3] = {{(rhs.m22 * rhs.m33 - rhs.m23 * rhs.m32) / det, (rhs.m13 * rhs.m32 - rhs.m12 * rhs.m33) / det, (rhs.m12 * rhs.m23 - rhs.m13 * rhs.m22) / det},
                         {(rhs.m23 * rhs.m31 - rhs.m21 * rhs.m33) / det, (rhs.m11 * rhs.m33 - rhs.m13 * rhs.m31) / det, (rhs.m13 * rhs.m21 - rhs.m11 * rhs.m23) / det},
                         {(rhs.m21 * rhs.m32 - rhs.m22 * rhs.m31) / det, (rhs.m12 * rhs.m31 - rhs.m11 * rhs.m32) / det, (rhs.m11 * rhs.m22 - rhs.m12 * rhs.m21) / det}};
    return Matrix33(data);
  }

  std::ostream &operator<<(std::ostream &os, const Matrix33 &rhs)
  {
    os << "[[" << rhs.m11 << " " << rhs.m12 << " " << rhs.m13 << "]" << std::endl;
    os << "[" << rhs.m21 << " " << rhs.m22 << " " << rhs.m23 << "]" << std::endl;
    os << "[" << rhs.m31 << " " << rhs.m32 << " " << rhs.m33 << "]]" << std::endl;
    return os;
  }

}