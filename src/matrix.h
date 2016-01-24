#pragma once

#include <stdint.h>
#include <string>

template <class T>
class Matrix
{
public:
    Matrix(uint8_t rows, uint8_t columns);
    ~Matrix();

    /**
    * Gets the number of rows in this matrix.
    * @return The number of rows in the matrix.
    */
    uint8_t getRows() const;

    /**
    * Gets the number of columns in this matrix.
    * @return The number of rows in the matrix.
    */
    uint8_t getColumns() const;

    /**
    * Set a particular coefficient of the matrix.
    * @param row The row of the coefficient being set.
    * @param column The column of the coefficient being set.
    * @value The value the coefficient is being set to.
    * @exception invalid_argument If the row or column is out of bounds.
    */
    void set(uint8_t row, uint8_t column, T value);

    /**
    * Get the specified coefficient from the matrix.
    * @param row The row of the specifed coefficient.
    * @param column The column of the specified coefficient.
    * @return The coefficient specified by the row and column.
    * @exception invalid_argument If the row or column is out of bounds.
    */
    T get(uint8_t row, uint8_t column) const;

    std::string toString();

    void fromString(std::string str);
    /**
    * Swap the position of two rows.
    * @param i The first row to be swapped.
    * @param j THe second row to be swapped.
    * @exception invalid_argument If either row is out of bounds.
    */
    void rowSwap(uint8_t i, uint8_t j);

    /**
    * Multiply the entire row by a value.
    * @param row The row that is being multiplied.
    * @param value The value the row is being multiplied by.
    */
    void rowMultiply(uint8_t row, T value);


    void rowAddMultiple(uint8_t rowI, uint8_t rowJ, T value);

    /**
    * Convert the matrix into the row echelon form.
    * @exception runtime_error if the matrix is inconsistent.
    */
    void echelonForm();

    /**
    * Convert the matrix into the reduced row echelon form.
    * @exception runtime_error If the matrix is inconsistent.
    */
    void rowReducedEchelonForm();

private:
    uint8_t rows;
    uint8_t columns;

    /**
    * The data pointer contains all the coefficients of the matrix.  The matrix is stored row
    * by row.  eg row 2 and column 3 in a 4x4 matrix is accessed like the following data[(row-1)*columns + column] 
    */
    T *data;
};