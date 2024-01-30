### Introduction

- Different attitude representations 
    - Limitations, advantages and disadvantages
- We need to find the correct representation for each suitable situation
- Need to become subject matter expert!
- Course Coverage.
    - Basic Linear Algebra
    - Diff. Attitude representation
        - Direct cosine matrices
        - Euler Angles
        - Quaternion
    - For each one above, we cover
        - Theory
        - Conversion
        - Use cases
        - Python & C++ Math library
    	- Bonus : 

### Attitude representation

- Attitude or orientation : How an object is oriented in a 3-dimentional space.
- Co-ordinate system:
    - 3D Cartesian co-ordinate system
    - Polar co-ordination
- When a co-ordinate system is fixed to an object, then it becomes a reference frame
- World co-ordinate system 
    - Fixed in space
- Body co-ordinate system
    - Rigidly attached to a system.
- Attitude  : Is the description that maps the world frame to the body frame. Or vice versa.
    - Rotation as well as transformation between two frames.   
    - Maps the world frame to the rotated body frame --> this is the convention that will be used in the course.
    - Inverse of one convention will be the other. 
- Attitude Representation advantages & disadvantages:
    - Ease of user interpretation - Can you picture it in head? And describe it?
    - Storage - Size in the memory
    - Numerical Issues - Stability, computation performance, uniqueness
    - Integration and Kinematics - How to describe the rotating object or changing attitude.
    - Interpolation - 
- Attitude Kinematics
  - How the attitude is changing over the time. - common problem
  - Rotation : Angular rate
    - X : Roll
    - Y : Pitch
    - Z : Yaw
- Rate of change of attitude is not equal to the rate of change of the angular velocity of a rigid object.
- Attitude Interpolation
  - Create smooth animations between two different key attitudes


### Basic Algebra

- Matrix : A capital bold letter
- Matrix order has to be the same for addition and subtraction.
- Scalar multiplication or division is possible. Each elements will be effected.
- [3x2] = [3x3] * [3x2]
- Matrix multiplication is not commutative
- AB != BA
- Left or right multiplication order matters.
- Matrix Transpose : Flipping a matrix along the diagonal.
- Matrix determinant : a.d - b.c
- Matrix Inverse : A'.A = A.A'= I
- Not all square matrix is invertible. Only if the determinant is non-zero.
- Orthogonal matrix : Transpose == Inverse 
  - Also Determinant = 1
- Type of vectors :
  - Row vector
  - Column vector
  