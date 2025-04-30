
## Overview

This assignment focuses on implementing a **square matrix class in C++** without using the standard template library (STL).  
The goal is to practice **operator overloading**, **friend functions**, and the **Rule of Three**.  
The `SquareMat` class supports a variety of arithmetic and logical operations, including matrix exponentiation, transpose, and determinant calculation.  
All memory is managed manually using raw arrays, and correctness is ensured via **unit testing with Doctest** and **memory analysis with Valgrind**.
 
 ---
###
**Rule of Three**
-  **Destructor** – `~SquareMat()` properly releases the dynamically allocated 2D array.
-  **Copy Constructor** – `SquareMat(const SquareMat &other)` creates a deep copy of another matrix.
-  **Copy Assignment Operator** – `SquareMat &operator=(const SquareMat &other)` first deletes the existing memory and then deep-copies the new one.
---


###
**Friend Functions**

-  `friend SquareMat operator*(double scalar, const SquareMat& mat);`  
  Enables scalar multiplication with the scalar on the left (e.g., `2.5 * matrix`), while accessing internal matrix data.

-  `friend std::ostream &operator<<(std::ostream &os, const SquareMat &mat);`  
  Provides a custom print format for the matrix, allowing access to private matrix values directly.

---
## Implemented Operators

**The SquareMat class represents a square matrix of real numbers and throws exceptions on invalid input.**

- **`+`, `-` operators** – Element-wise addition and subtraction between matrices of the same size.  
- **Unary `-` operator** – Negates all elements of the matrix.  
- **`*` operator (matrix * matrix)** – Standard matrix multiplication.  
- **`*` operator (scalar * matrix / matrix * scalar)** – Scalar multiplication in both directions.  
- **`%` operator (matrix % matrix)** – Element-wise multiplication.  
- **`%` operator (matrix % scalar)** – Element-wise modulo with integer scalar.  
- **`/` operator** – Divides all elements of the matrix by a scalar.  
- **`^` operator** – Raises the matrix to an integer power using repeated multiplication.  
- **`++`, `--` operators** – Pre/post increment and decrement of all elements by 1.  
- **`~` operator** – Matrix transpose (row-column swap).  
- **`[][]` indexing operator** – Access individual elements (read/write) using `matrix[i][j]`.  
- **`==`, `!=` operators** – Matrices are equal if their total element sums are equal.  
- **`<`, `>`, `<=`, `>=` operators** – Compare matrices based on sum of their elements.  
- **`!` operator** – Computes matrix determinant (Laplace expansion).  
- **`+=`, `-=`, `*=`, `/=`, `%=` operators** – Compound assignments with matrix or scalar operands.  
- **`<<` operator** – Prints the matrix in a readable 2D format.
---

## Project Structure

```plaintext
├── squaremat             # Contains the implementation of the SquareMat class
│   ├── squaremat.cpp     # Source file with full implementation of SquareMat methods and operator overloads
│   └── squaremat.hpp     # Header file with declarations of the SquareMat class, functions, and operators
├── test                  # Contains unit tests for the SquareMat class using the doctest framework
│   ├── test.cpp          # C++ file that defines test cases to validate the behavior of SquareMat
│   └── doctest.h         # Header-only testing framework used to write and run tests
├── main.cpp              # Demo file that demonstrates usage of the SquareMat class (not for testing)
├── makefile              # Build automation file to compile, test, run valgrind, and clean the project
├── readme.md             # Project documentation including description, usage instructions, and structure
```

---

## Compilation and Execution

To compile the project, run:

```bash
make
```

### Run the main demo:
```bash
make main
```

### Run unit tests:
```bash
make test
```

### Check for memory leaks:
```bash
make valgrind
```

### Clean all build artifacts:
```bash
make clean
```



## Author

**Ron Amsalem**  
📧 ronamsalem4@gmail.com
