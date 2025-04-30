// email ---> ronamsalem4@gmail.com
// This file (SquareMat.hpp) is a declaration file for functions and operator overloading that we needed to perform.

#ifndef SQUARE_MAT_HPP
#define SQUARE_MAT_HPP
#include <iostream>
#include <stdexcept>
using namespace std;

namespace SquareMatrix
{
    class SquareMat
    {
    private:
        double **matrix; // Pointer to a 2D dynamically allocated array representing the matrix
        int size;  // Size of the square matrix (rows = columns)
    public:
        const double sum_matrix() const; // Helper function that returns the sum of all matrix elements
        SquareMat(int size); // Constructor ---> creates an empty matrix of given size.
        SquareMat(double **mat, int size);// Constructor ---> initializes matrix with an existing 2D array.
        ~SquareMat(); // Destructor ---> frees allocated memory
        SquareMat(const SquareMat &other);  // Copy constructor
        SquareMat &operator=(const SquareMat &other); // Assignment operator
        void setMatrix(); // Fills the matrix 
        int getSize() const; // Returns the matrix size
        double **getMatrix() const; // Returns the matrix as a pointer to a 2D array
        SquareMat operator+(const SquareMat &other) const; // Matrix addition
        SquareMat operator-(const SquareMat &other) const; // Matrix subtraction
        SquareMat &operator-(); // Unary minus: negates each element in the matrix
        SquareMat operator*(const SquareMat &other) const;  // Matrix multiplication
        SquareMat operator*(double scalar) const; // Scalar multiplication matrix*scalar 
        friend SquareMat operator*(double scalar, const SquareMat& mat); // Scalar multiplication scalar*matrix 
        SquareMat operator%(const SquareMat &other) const; // Element-wise multiplication
        SquareMat operator%(int scalar) const; // Scalar modulo operation
        SquareMat operator/(double scalar) const;// Scalar division
        SquareMat operator^(int power) const; // Matrix exponentiation ---> raises matrix to the power
        SquareMat& operator--(); // --prefix
        SquareMat operator--(int); // postfix--
        SquareMat& operator++(); // ++prefix
        SquareMat operator++(int); // postfix++
        SquareMat operator~() const; // Matrix transpose 
        double* operator[](int i); // Access matrix row for reading/writing
        const double* operator[](int i) const; // Access matrix row for reading only
        bool operator==(const SquareMat& other) const;// Equality comparison: returns true if sum is equals
        bool operator!=(const SquareMat& other) const; // Inequality comparison

        // Comparison based on matrix sum
        bool operator<(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;

        double operator!() const; // Calculating the determinant
        //Perform addition, subtraction, multiplication, division, or modulo operations on the matrix and update it directly
        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);
        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator*=(double scalar);
        SquareMat& operator/=(const SquareMat& other);
        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator%=(int scalar);
        //An operator that prints the matrix in a logical way.      
        friend std::ostream &operator<<(std::ostream &os, const SquareMat &mat);
  };
}
#endif
