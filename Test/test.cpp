// Email ---> ronamsalem4@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat/SquareMat.hpp"
#include <sstream> 
using namespace SquareMatrix;
// Function helper - sum of matrix 

TEST_CASE("Matrix sum")
{
SquareMat A(2);
A[0][0] = 1; A[0][1] = 2;
A[1][0] = 3; A[1][1] = 4;
int expected= 10;
double actual = A.sum_matrix();
CHECK(expected==actual);
SquareMat B(2);
B[0][0] = -1; B[0][1] = 7;
B[1][0] = 3; B[1][1] = -4;
int expected1= 5;
double actual1 = B.sum_matrix();
CHECK(expected1==actual1);

}

//Function get size
TEST_CASE("get size")
 {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
     int expected=2;
     int actual = A.getSize() ;
    CHECK(actual == expected);
    }


// ---> + operator <---
TEST_CASE("Matrix addition")
 {
    // create matrix A: 2x2
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    // create matrix B: 2x2
    SquareMat B(2);
    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;

    // expected result C = A + B
    SquareMat expected(2);
    expected[0][0] = 6; expected[0][1] = 8;
    expected[1][0] = 10; expected[1][1] = 12;

    SquareMat actual = A + B;

    // now check element-wise equality
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CHECK(actual[i][j] == expected[i][j]);
}


TEST_CASE("Addition of matrices with different sizes should throw") 
{
    SquareMat A(2);
    SquareMat B(3); // Different size

    CHECK_THROWS_AS(A + B, std::invalid_argument);
}

// ---> - operator <---
TEST_CASE("Matrix Subtraction")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 1; A[0][1] = 2;
A[1][0] = 3; A[1][1] = 4;

// create matrix B: 2x2
SquareMat B(2);
B[0][0] = 5; B[0][1] = 6;
B[1][0] = 7; B[1][1] = 8;

// expected result C = A -B
SquareMat expected(2);
expected[0][0] = -4; expected[0][1] = -4;
expected[1][0] = -4; expected[1][1] = -4;

SquareMat actual = A - B;

// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
        CHECK(actual[i][j] == expected[i][j]);
}

TEST_CASE("Subtraction of matrices with different sizes should throw") 
{
    SquareMat A(2);
    SquareMat B(3); // Different size

    CHECK_THROWS_AS(A - B, std::invalid_argument);
}

// ---> - Unary minus operator <---
TEST_CASE("Unary minus negates all matrix elements")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 1; A[0][1] = 2;
A[1][0] = 3; A[1][1] = 4;

// expected result -A 
SquareMat expected(2);
expected[0][0] = -1; expected[0][1] = -2;
expected[1][0] = -3; expected[1][1] = -4;

SquareMat actual =  -A;

// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
        CHECK(actual[i][j] == expected[i][j]);
}
TEST_CASE("Unary minus - Everything is negative.")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = -1; A[0][1] = -2;
A[1][0] = -3; A[1][1] = -4;

// expected result -A 
SquareMat expected(2);
expected[0][0] = 1; expected[0][1] = 2;
expected[1][0] = 3; expected[1][1] = 4;

SquareMat actual =  -A;

// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
        CHECK(actual[i][j] == expected[i][j]);
}

TEST_CASE("Unary minus -Negative part Positive part.")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = -1; A[0][1] = 2;
A[1][0] = -3; A[1][1] = 4;

// expected result -A 
SquareMat expected(2);
expected[0][0] = 1; expected[0][1] = -2;
expected[1][0] = 3; expected[1][1] = -4;

SquareMat actual =  -A;

// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
        CHECK(actual[i][j] == expected[i][j]);
}

TEST_CASE("Matrix Multiplication ---> Testing the function itself")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 1; A[0][1] = 2;
A[1][0] = 3; A[1][1] = 4;

// create matrix B: 2x2
SquareMat B(2);
B[0][0] = 5; B[0][1] = 6;
B[1][0] = 7; B[1][1] = 8;

// expected result C = A*B
SquareMat expected(2);
expected[0][0] = 19; expected[0][1] = 22;
expected[1][0] = 43; expected[1][1] = 50;

SquareMat actual = A * B;

// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}


TEST_CASE("Matrix Multiplication ---> of matrices with different sizes should throw") 
{
    SquareMat A(2);
    SquareMat B(3); // Different size

    CHECK_THROWS_AS(A*B, std::invalid_argument);
}


TEST_CASE("multiplication operator (matrix*scalar)")
    {
    // create matrix A: 2x2
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
     int scalar = 4;

    SquareMat expected(2);
    expected[0][0] = 4; expected[0][1] = 8;
    expected[1][0] = 12; expected[1][1] = 16;
    
    SquareMat actual = A * scalar ;
    
    // now check element-wise equality
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        CHECK(actual[i][j] == expected[i][j]);
    }

    
TEST_CASE("multiplication operator (scalar*matrix)")
 {
    // create matrix A: 2x2
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
     int scalar = 4;

    SquareMat expected(2);
    expected[0][0] = 4; expected[0][1] = 8;
    expected[1][0] = 12; expected[1][1] = 16;
    
    SquareMat actual =  scalar*A ;
    
    // now check element-wise equality
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        CHECK(actual[i][j] == expected[i][j]);
}

TEST_CASE("Element-wise multiplication")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 1; A[0][1] = 4;
A[1][0] = 8; A[1][1] = 7;

// create matrix B: 2x2
SquareMat B(2);
B[0][0] = 2; B[0][1] = 5;
B[1][0] = 9; B[1][1] = 8;

// expected result C =A%B
SquareMat expected(2);
expected[0][0] = 2; expected[0][1] = 20;
expected[1][0] = 72; expected[1][1] = 56;

SquareMat actual = A % B;

// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

// ---> modulo operator <---
TEST_CASE("Model each element in the matrix")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 4;
A[1][0] = 4; A[1][1] = 4;
int scalar = 4;

// expected result C =A%B
SquareMat expected(2);
expected[0][0] = 0; expected[0][1] = 0;
expected[1][0] = 0; expected[1][1] = 0;

SquareMat actual = A % scalar;

// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

// ---> / operator <---

TEST_CASE("Divides each element in a matrix by a scalar number.")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 4;
A[1][0] = 4; A[1][1] = 4;
int scalar = 4;

// expected result C =A%B
SquareMat expected(2);
expected[0][0] = 1; expected[0][1] = 1;
expected[1][0] = 1; expected[1][1] = 1;

SquareMat actual = A / scalar;
// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

TEST_CASE("Division by a scalar equal to 0")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 4;
A[1][0] = 4; A[1][1] = 4;
int scalar = 0;
CHECK_THROWS(A / 0);
}

TEST_CASE("Matrix exponentiation")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 3;
A[1][0] = 5; A[1][1] = 7;
int power = 5;

// expected result A^5
SquareMat expected(2);
expected[0][0] = 26779; expected[0][1] = 30273;
expected[1][0] = 50455; expected[1][1] = 57052;

SquareMat actual = A ^ 5;
// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

// ---> --matrix (Prefix) operator <---
TEST_CASE("--matrix (Prefix)")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 3;
A[1][0] = 5; A[1][1] = 7;

SquareMat expected(2);
expected[0][0] = 3; expected[0][1] = 2;
expected[1][0] = 4; expected[1][1] = 6;

SquareMat actual =-- A;
// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

// ---> matrix-- (Postfix) operator <---
TEST_CASE(" matrix-- (Postfix)")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 3;
A[1][0] = 5; A[1][1] = 7;

SquareMat expected(2);
expected[0][0] = 4; expected[0][1] = 3;
expected[1][0] = 5; expected[1][1] = 7;

SquareMat actual = A-- ;
// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

TEST_CASE("Matrix exponentiation")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 3;
A[1][0] = 5; A[1][1] = 7;
int power = 5;

// expected result A^5
SquareMat expected(2);
expected[0][0] = 26779; expected[0][1] = 30273;
expected[1][0] = 50455; expected[1][1] = 57052;

SquareMat actual = A ^ 5;
// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

// ---> ++matrix (Prefix) operator <---
TEST_CASE("--matrix (Prefix)")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 3;
A[1][0] = 5; A[1][1] = 7;

SquareMat expected(2);
expected[0][0] = 5; expected[0][1] = 4;
expected[1][0] = 6; expected[1][1] = 8;

SquareMat actual = ++ A;
// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

// ---> matrix++ (Postfix) operator <---
TEST_CASE(" matrix ++ (Postfix)")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 3;
A[1][0] = 5; A[1][1] = 7;

SquareMat expected(2);
expected[0][0] = 4; expected[0][1] = 3;
expected[1][0] = 5; expected[1][1] = 7;

SquareMat actual = A++ ;
// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

// ---> ~ operator <---
TEST_CASE(" matrix transpose")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 3;
A[1][0] = 5; A[1][1] = 7;

SquareMat expected(2);
expected[0][0] = 4; expected[0][1] = 5;
expected[1][0] = 3; expected[1][1] = 7;

SquareMat actual = ~ A;
// now check element-wise equality
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    CHECK(actual[i][j] == expected[i][j]);
}

// ---> []  operator  (only read)<---
TEST_CASE(" Direct access to a specific element in a matrix ")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 3;
A[1][0] = 5; A[1][1] = 7;
int i = 0 ;

SquareMat actual = A[i][1];
 CHECK(actual ==3);
}
// ---> []  operator  (read and change )<---
TEST_CASE(" Direct access to a specific element in a matrix ")
{
// create matrix A: 2x2
SquareMat A(2);
A[0][0] = 4; A[0][1] = 3;
A[1][0] = 5; A[1][1] = 7;
int i = 0 ;
SquareMat actual = A[i][1];
 CHECK(actual ==3);
 A[1][1] = 20;
 SquareMat new_actual = A[1][1];
 CHECK(new_actual ==20);
}

// ---> ==  operator <---
TEST_CASE("two matrix is equals")
 {
    // create matrix A: 2x2
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    // create matrix B: 2x2
    SquareMat B(2);
    B[0][0] = 2; B[0][1] = 2;
    B[1][0] = 2; B[1][1] = 4;
    CHECK(A == B) ;
}

// ---> != operator  <---
TEST_CASE("two matrix NOT is equals")
 {
    // create matrix A: 2x2
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    // create matrix B: 2x2
    SquareMat B(2);
    B[0][0] = 6; B[0][1] = 2;
    B[1][0] = 2; B[1][1] = 4;
    CHECK(A != B) ;
}

// ---> > operator  <---
TEST_CASE("Matrix A is really big matrix B")
 {
    // create matrix A: 2x2
    SquareMat A(2);
    A[0][0] = 9; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    // create matrix B: 2x2
    SquareMat B(2);
    B[0][0] = 6; B[0][1] = 2;
    B[1][0] = 2; B[1][1] = 4;
    CHECK(A > B) ;
}

// ---> >= operator  <---
TEST_CASE("Matrix A is greater than or equal to matrix B.")
 {
    // create matrix A: 2x2
    SquareMat A(2);
    A[0][0] = 7; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    // create matrix B: 2x2
    SquareMat B(2);
    B[0][0] = 6; B[0][1] = 2;
    B[1][0] = 2; B[1][1] = 4;
    CHECK(A >= B) ;
    A[0][0] = 6; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    CHECK(A >= B) ;
}

// ---> < operator  <---
TEST_CASE("Matrix A is really small matrix B")
 {
    // create matrix A: 2x2
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    // create matrix B: 2x2
    SquareMat B(2);
    B[0][0] = 6; B[0][1] = 2;
    B[1][0] = 2; B[1][1] = 4;
    CHECK(A < B) ;
}

// ---> <= operator  <---
TEST_CASE("Matrix A is less than or equal to matrix B.")
 {
    // create matrix A: 2x2
    SquareMat A(2);
    A[0][0] = 3; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    // create matrix B: 2x2
    SquareMat B(2);
    B[0][0] = 6; B[0][1] = 2;
    B[1][0] = 2; B[1][1] = 4;
    CHECK(A <= B) ;
    A[0][0] = 6; A[0][1] = 2;
    A[1][0] = 2; A[1][1] = 4;
    CHECK(A <= B) ;
}

// ---> ! operator  <---
TEST_CASE("Calculating the determinant of a matrix")
 {
    // create matrix A: 3x3
    SquareMat A(3);
    A[0][0] = 5;  A[0][1] = 4;  A[0][2] = 8;
    A[1][0] = 2; A[1][1] = 7; A[1][2] = 4;
    A[2][0] = 2; A[2][1] = 3; A[2][2] = 4;
    double det = 16;
    double real_det = !A;
    CHECK(det==real_det) ;
}

// ---> += operator  <---
TEST_CASE("Matrix += operator") {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    SquareMat B(2);
    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;
    A += B;
    SquareMat expected(2);
    expected[0][0] = 6; expected[0][1] = 8;
    expected[1][0] = 10; expected[1][1] = 12;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CHECK(A[i][j] == expected[i][j]);
}

// ---> -= operator  <---
TEST_CASE("Matrix += operator") {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    SquareMat B(2);
    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;
    A -= B;
    SquareMat expected(2);
    expected[0][0] = -4; expected[0][1] = -4;
    expected[1][0] = -4; expected[1][1] = -4;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CHECK(A[i][j] == expected[i][j]);
}


// ---> *= operator  <---
TEST_CASE("Matrix *= operator") {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    SquareMat B(2);
    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;
    A *= B;
    SquareMat expected(2);
    expected[0][0] = 19; expected[0][1] = 22;
    expected[1][0] = 43; expected[1][1] = 50;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CHECK(A[i][j] == expected[i][j]);
}

// ---> *= operator - scalar <---
TEST_CASE("Matrix *= operator") {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    int scalar =4;
    A *= scalar;
    SquareMat expected(2);
    expected[0][0] = 4; expected[0][1] = 8;
    expected[1][0] = 12; expected[1][1] = 16;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CHECK(A[i][j] == expected[i][j]);
}

// ---> /= operator  <---
TEST_CASE("Matrix /= operator") {
    SquareMat A(2);
    A[0][0] = 4.0; A[0][1] = 2.0;
    A[1][0] = 6.0; A[1][1] = 4.0;
    SquareMat B(2);
    B[0][0] = 2.0; B[0][1] = 2.0;
    B[1][0] = 2.0; B[1][1] = 2.0;
    A /= B;
    SquareMat expected(2);
    expected[0][0] = 2.0; expected[0][1] = 1.0;
    expected[1][0] = 3.0; expected[1][1] = 2.0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CHECK(A[i][j] == expected[i][j]);
}

// ---> %= operator  <---
TEST_CASE("Matrix %= operator") {
    SquareMat A(2);
    A[0][0] = 4.0; A[0][1] = 2.0;
    A[1][0] = 6.0; A[1][1] = 7.0;
    SquareMat B(2);
    B[0][0] = 2.0; B[0][1] = 2.0;
    B[1][0] = 2.0; B[1][1] = 2.0;
    A %= B;
    SquareMat expected(2);
    expected[0][0] = 0.0; expected[0][1] = 0.0;
    expected[1][0] = 0.0; expected[1][1] = 1.0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CHECK(A[i][j] == expected[i][j]);
}

// ---> %= operator - scalar <---
TEST_CASE("Matrix %= operator") {
    SquareMat A(2);
    A[0][0] = 8.0; A[0][1] = 13.0;
    A[1][0] = 11.0; A[1][1] = 4.0;
    int scalar =2;
    A %= scalar;
    SquareMat expected(2);
    expected[0][0] = 0.0; expected[0][1] = 1.0;
    expected[1][0] = 1.0; expected[1][1] = 0.0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CHECK(A[i][j] == expected[i][j]);
}



TEST_CASE("Matrix output stream (<<)") {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    std::ostringstream oss;
    oss << A;
    std::string expected = "1 2 \n3 4 \n";

    CHECK(oss.str() == expected);
}
