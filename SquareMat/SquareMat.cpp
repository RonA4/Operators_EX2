// Email ---> ronamsalem4@gmail.com
#include "SquareMat.hpp"
#include <cmath>

namespace SquareMatrix
{
/**
 * A helper function that calculates the sum of the elements of a matrix.
 */
const double SquareMat::sum_matrix() const
 {
      double sum = 0;
       for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
            sum += matrix[i][j];
     return sum;
 }

 /**
 * Constructor that initializes an empty square matrix of the given size.
 * @param size ---> The size of the matrix (number of rows and columns). Must be positive.
 * @throws ---> std::invalid_argument if the provided size is zero or negative.
 * This constructor dynamically allocates memory for a size x size matrix
 */
 SquareMat::SquareMat(int size) : size(size)
 {
     if (size <= 0)
          throw invalid_argument("Size must be positive.");
      matrix = new double *[size];
      for (int i = 0; i < size; i++)
        matrix[i] = new double[size];
 }
/**
 * Constructor that initializes a square matrix using an existing 2D array. 
 * @param mat ---> A pointer to an existing 2D array of doubles.
 * @param size ---> The size of the matrix (number of rows and columns). Must match the dimensions of mat.
 * This constructor deep-copies the contents of the provided matrix into a newly allocated matrix.
 */
 SquareMat::SquareMat(double **mat, int size) : SquareMat(size)
 {
     for (int i = 0; i < size; i++)
       for (int j = 0; j < size; j++)
              matrix[i][j] = mat[i][j];
}

/**
 * Destructor that releases the dynamically allocated memory of the matrix.
 * Frees all allocated rows and then the top-level matrix pointer itself.
 * Prevents memory leaks by cleaning up resources upon object destruction.
 */
SquareMat::~SquareMat()
 {
       for (int i = 0; i < size; i++)
           delete[] matrix[i];
  delete[] matrix;
 }
/**
 * Copy constructor that creates a deep copy of another SquareMat object.
 * @param other ---> The matrix to be copied.
 * Delegates to the parameterized constructor to perform a deep copy
 * of the internal 2D array and size.
 */
 SquareMat::SquareMat(const SquareMat &other) : SquareMat(other.matrix, other.size) {}

/**
 * Assignment operator that performs a deep copy of another SquareMat.
 * @param other ---> The matrix to copy from.
 * @return ---> A reference to the updated matrix (*this).
 * If the current matrix and the source are not the same object, this operator:
 1. Frees the previously allocated memory.
 2. Allocates new memory of the appropriate size.
 3. Copies all values from the source matrix.
 */

 SquareMat &SquareMat::operator=(const SquareMat &other)
 {
     if (this != &other)
     {
         for (int i = 0; i < size; i++)
              delete[] matrix[i];
         delete[] matrix;
         size = other.size;
         matrix = new double *[size];
         for (int i = 0; i < size; ++i)
         {
            matrix[i] = new double[size];
             for (int j = 0; j < size; ++j)
                matrix[i][j] = other.matrix[i][j];
           }
      }
      return *this;
 }
/**
 * Fills the matrix with default values based on row and column indices.
 * Each element at position (i, j) is set to the product i * j.
 * This creates a deterministic pattern useful for testing or debugging.
 */
void SquareMat::setMatrix()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
             this->matrix[i][j] = i*j;
}

/**
 * Return the size of matrix
 */
int SquareMat::getSize() const
{
     return this->size;
}

/**
 * Return the  matrix
 */
double **SquareMat::getMatrix() const
{
    return matrix;
 }

/**
  *Addition operator (mat1+mat2) ---> adds elements according to their position between two matrices of the same size.
 */
    SquareMat SquareMat::operator+(const SquareMat &other) const
{
     if (size != other.size)
         throw invalid_argument("Matrix sizes are different\n");
     SquareMat result(size);
      for (int i = 0; i < size; i++)
          for (int j = 0; j < size; j++)
               result.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
      return result;
}
/**
 * Subtraction operator (mat1-mat2) ---> Subtracts elements according to their position between two matrices of the same size.
 */
SquareMat SquareMat::operator-(const SquareMat &other) const
{
    if (size != other.size)
          throw invalid_argument("Matrix sizes are different\n");
    SquareMat result(size);
     for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
             result.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];
     return result;
}

 /**
* Reverses the sign of all elements in a matrix (positive to negative and vice versa).
 */

SquareMat &SquareMat::operator-()
{
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (this->matrix[i][j]==0)
                {
                   continue;
                }
                this->matrix[i][j] = -this->matrix[i][j];
            }
        }
        
            return *this;
 }

 /**
 * Multiplication operator (mat2*mat1) - performs multiplication between 2 matrices.
*/
SquareMat SquareMat::operator*(const SquareMat &other) const
{
        if (size != other.size)
            throw invalid_argument("Matrix sizes are different\n");
        SquareMat result(size);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < size; k++)
                    result.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
            }
        return result;
}
/**
* Scalar multiplication operator ( matrix*scalar)
*/
SquareMat SquareMat::operator*(double scalar) const
{
    SquareMat result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.matrix[i][j] = matrix[i][j] * scalar;
    return result;
}

/**
* Scalar multiplication operator (scalar*matrix)
*/
SquareMat operator*(double scalar, const SquareMat& mat) {
return mat * scalar;
}

/**
 * Multiplies each element in one matrix by the corresponding element in the other matrix
 */
SquareMat SquareMat::operator%(const SquareMat &other) const
{
    if (size != other.size)
        throw invalid_argument("Matrix sizes are different\n");
    SquareMat result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        result.matrix[i][j] = this->matrix[i][j] * other.matrix[i][j];
    return result;
}

/**
 * Performs a modulo operation on each element of a matrix with a given integer.
 */
SquareMat SquareMat::operator%(int scalar) const
{
    if(scalar==0){
        throw std::invalid_argument("Modulo 0 is not allowed!");
    }
    SquareMat result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)

            result.matrix[i][j] = fmod(matrix[i][j],scalar);
    return result;
}

/**
 * Divides each element in a matrix by a scalar number.
 */
    SquareMat SquareMat::operator/(double scalar) const
{
        if (scalar == 0)
            throw invalid_argument("Division by zero.");
        SquareMat result(size);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                result.matrix[i][j] = matrix[i][j] / scalar;
        return result;
 }
/**
 * Raises the matrix to a power by repeatedly multiplying the matrix by itself.
 * @param power ---> The power to which we want to raise the matrix
 */
    SquareMat SquareMat::operator^(int power) const
{
        if (power < 0)
            throw invalid_argument("Negative power is not allowed");

        SquareMat result(size);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                result.matrix[i][j] = (i == j) ? 1.0 : 0.0;

        for (int p = 0; p < power; ++p)
            result = result * (*this);

        return result;
}

/**
 * Prefix operator (matrix--)
 * Decreases each element in the matrix by 1 and returns the modified matrix.
 */
SquareMat& SquareMat::operator--()
{
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j]--;
        return *this;
 }

/**
 * Postfix operator --(matrix)
 * Decreases each element in the matrix by 1.
 * Returns the matrix as it was before the decrement.
 */
SquareMat SquareMat::operator--(int)
{
    SquareMat temp = *this;  
    --(*this);               
    return temp;              
}

/**
 * Prefix increment operator (++matrix)
 * Increases each element in the matrix by 1 and returns the updated matrix.
 * This operation modifies the matrix in place and returns it after the increment.
 */
 SquareMat& SquareMat::operator++()
{
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                ++matrix[i][j];
        return *this;
}


/**
 * Postfix increment operator (matrix++)
 * Increases each element in the matrix by 1.
 * Returns a copy of the matrix as it was before the increment.
 */
SquareMat SquareMat::operator++(int)
{
        SquareMat temp = *this;  
        ++(*this);               
        return temp;  
}

/**
 * Transposes the matrix: Swaps the rows with columns of the matrix.
 */
  SquareMat SquareMat::operator~() const
{
        SquareMat result(size);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                result.matrix[j][i] = matrix[i][j];
        return result;
 }

 /** 
* Access operator for modifying matrix elements. 
* Returns a pointer to the i-th row of the matrix, allowing both read and write access. 
* @param i ---> The index of the row to access . 
* @return  ---> A pointer to the i-th row of the matrix. 
* @throws ---> std::out_of_range if i is not in the range [0, size). 
*/
 double* SquareMat::operator[](int i)
 {
     if (i < 0 || i >= size)
           throw out_of_range("Index out of range");
     return matrix[i];
 }

/**
 * Access operator for reading matrix elements (const version).
 * Returns a const pointer to the i-th row of the matrix, allowing read-only access.
 * @param i ---> The index of the row to access (0-based).
 * @return ---> A const pointer to the i-th row of the matrix.
 * @throws ---> std::out_of_range if i is not in the range [0, size).
 */

 const double* SquareMat::operator[](int i) const
{
    if (i < 0 || i >= size)
         throw out_of_range("Index out of range");
    return matrix[i];
}

/**
 * Equality operator.
 * Compares two matrices for approximate equality based on the sum of their elements.
 * @param other ---> The matrix to compare with.
 * @return ---> True if the absolute difference between the sums of both matrices is less than 1e-9.
 */
bool SquareMat::operator==(const SquareMat& other) const
 {
    return fabs(this->sum_matrix() - other.sum_matrix()) < 1e-9;
 }

 /**
 * Inequality operator.
 * Returns the logical negation of the equality comparison.
 * @param other ---> The matrix to compare with.
 * @return ---> True if the matrices are not approximately equal.
 */
 bool SquareMat::operator!=(const SquareMat& other) const
 {
    return !(*this == other);
 }


/**
 * Less-than operator.
 * Compares this matrix to another by comparing the sum of their elements.
 * @param other ---> The matrix to compare with.
 * @return ---> True if the sum of this matrix is strictly less than the sum of the other matrix.
 */
 bool SquareMat::operator<(const SquareMat& other) const
 {
     return this->sum_matrix() < other.sum_matrix();
 }


 /**
 * Less-than operator.
 * Compares this matrix to another by comparing the sum of their elements.
 * @param other ---> The matrix to compare with.
 * @return ---> True if the sum of this matrix is strictly less than the sum of the other matrix.
 */
bool SquareMat::operator>(const SquareMat& other) const
 {
     return this->sum_matrix() > other.sum_matrix();
 }

 /**
 * Less-than or equal-to operator.
 * Returns true if this matrix is less than or equal to the other based on the sum of elements. 
 * @param other ---> The matrix to compare with.
 * @return ---> True if this matrix is not greater than the other.
 */

 bool SquareMat::operator<=(const SquareMat& other) const
 {
     return !(*this > other);
 }


/**
 * Greater-than or equal-to operator.
 * Returns true if this matrix is greater than or equal to the other based on the sum of elements.
 * @param other  ---> The matrix to compare with.
 * @return ---> True if this matrix is not less than the other.
 */
 bool SquareMat::operator>=(const SquareMat& other) const
 {
     return !(*this < other);
 }

 /**
 * Determinant operator (!matrix).
 * Calculates and returns the determinant of the square matrix.
 * For a 1x1 matrix ---> returns the single element.
 * For a 2x2 matrix ---> returns the result of ad - bc.
 * For larger matrices ---> uses Laplace expansion along the first row recursively.
 * @return ---> The determinant of the matrix as a double.
 */

double SquareMat::operator!() const
{
    if (size == 1)
           return matrix[0][0];
      if (size == 2)
         return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
 double determinant = 0;
    for (int col = 0; col < size; ++col)
    {
    SquareMat minor(size - 1);
        for (int i = 1; i < size; ++i)
         {
            int minorCol = 0;
             for (int j = 0; j < size; ++j)
             {
                 if (j == col)
                      continue;
                minor.matrix[i - 1][minorCol++] = matrix[i][j];
            }
        }
        int sign = (col % 2 == 0) ? 1 : -1;
        determinant += sign * matrix[0][col] * !minor;
    }
    return determinant;
}

/**
 * Addition-assignment operator (matrix += other).
 * Adds the corresponding elements of another matrix to this matrix, in place.
 * @param other ---> The matrix to add.
 * @return  ---> A reference to the modified matrix (*this).
 * @throws ---> std::invalid_argument if the matrices are of different sizes.
 */
SquareMat& SquareMat::operator+=(const SquareMat& other)
{
if (size != other.size)
        throw invalid_argument("Matrix sizes are different\n");
    for (int i = 0; i < size; i++)
     for (int j = 0; j < size; j++)
          matrix[i][j] += other.matrix[i][j];
return *this;
}

/**
 * Subtraction-assignment operator (matrix -= other).
 * Subtracts the corresponding elements of another matrix from this matrix, in place.
 * @param other ---> The matrix to subtract.
 * @return ---> A reference to the modified matrix (*this).
 * @throws ---> std::invalid_argument if the matrices are of different sizes.
 */
SquareMat& SquareMat::operator-=(const SquareMat& other)
{
    if (size != other.size)
         throw invalid_argument("Matrix sizes are different\n");
     for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] -= other.matrix[i][j];
     return *this;
}

/**
 * Matrix multiplication-assignment operator (matrix *= other).
 * Multiplies this matrix by another matrix and stores the result in this matrix.
 * @param other ---> The matrix to multiply by.
 * @return ---> A reference to the updated matrix (*this).
 * @throws ---> std::invalid_argument if the matrices are of different sizes.
 */
SquareMat& SquareMat::operator*=(const SquareMat& other)
{
    if (size != other.size)
        throw invalid_argument("Matrix sizes are different\n");
    *this = *this * other;
    return *this;
}

/**
 * Scalar multiplication-assignment operator (matrix *= scalar).
 * Multiplies each element of the matrix by a scalar value, in place.
 * @param scalar ---> The scalar value to multiply each matrix element by.
 * @return ---> A reference to the modified matrix (*this).
 */
SquareMat& SquareMat::operator*=(double scalar)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
               matrix[i][j] *= scalar;
     return *this;
}
/**
 * Matrix division-assignment operator (matrix /= other).
 * Divides each element of this matrix by the corresponding element of another matrix, in place.
 * @param other ---> The matrix to divide by.
 * @return ---> A reference to the updated matrix (*this).
 * @throws---> std::invalid_argument if the matrices are of different sizes or if division by zero occurs.
 */
SquareMat& SquareMat::operator/=(const SquareMat& other)
{
if(size != other.size)
    throw invalid_argument("Matrix Sizes are Different");
for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
    {
        if(other.matrix[i][j] == 0)
            throw invalid_argument("Zero Division");
        matrix[i][j] /= other.matrix[i][j];
    }
return *this; 
}

/**
 * Element-wise modulo-assignment operator (matrix %= other).
 * Applies the floating-point modulo operation (fmod) between corresponding elements of this matrix and another matrix, in place.
 * @param other ---> The matrix to modulo with.
 * @return ---> A reference to the updated matrix (*this).
 * @throws ---> std::invalid_argument if the matrices are of different sizes or if a modulo by zero is attempted.
 */
 SquareMat& SquareMat::operator%=(const SquareMat& other)
{
if (size != other.size)
    throw invalid_argument("Matrix Sizes are Different");
for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        if (other.matrix[i][j] == 0) {
            throw invalid_argument("Cannot modulo with 0");
        }
        matrix[i][j] = fmod(matrix[i][j], other.matrix[i][j]);
    }
  }
return *this;
}

/**
 * Scalar modulo-assignment operator (matrix %= scalar).
 * Applies the floating-point modulo operation (fmod) between each element of the matrix and a scalar value, in place.
 * @param scalar ---> The scalar value to apply modulo with.
 * @return --->  A reference to the updated matrix (*this).
 */
SquareMat& SquareMat::operator%=( int scalar)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
           matrix[i][j] = fmod(matrix[i][j],scalar);
 return *this;

}

/**
 * Output stream operator (<<).
 * Prints the matrix elements to the given output stream, with each row on a separate line.
 * @param os ---> The output stream to write to.
 * @param mat ---> The matrix to be printed.
 * @return ---> A reference to the output stream (os).
 */
ostream &operator<<(ostream &os, const SquareMat &mat)
{
    for (int i = 0; i < mat.getSize(); i++)
    {
        for (int j = 0; j < mat.getSize(); j++)
        {
            double value = mat[i][j];
            if (std::fabs(value) < 1e-9)  
                value = 0.0;
            os << value << " ";
        }
        os << endl;
    }
    return os;
}  
}
