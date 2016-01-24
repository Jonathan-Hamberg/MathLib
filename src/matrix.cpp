#include "Matrix.h"
#include <stdexcept>

template <class T>
Matrix<T>::Matrix(uint8_t rows, uint8_t columns)
{
    this->rows = rows;
    this->columns = columns;

    this->data = new T [rows * columns];
}

template <class T>
Matrix<T>::~Matrix()
{
    delete [] this->data;
}

template <class T>
uint8_t Matrix<T>::getRows() const
{
    return this->rows;
}

template <class T>
uint8_t Matrix<T>::getColumns() const
{
    return this->columns;
}

template <class T>
void Matrix<T>::set(uint8_t row, uint8_t column, T value)
{
    // Check for index out of bounds.
    if(row * column > this->rows * this->columns)
    {
        throw std::invalid_argument("Row or column is out of bounds.");
    }

    // Set the desired coefficient.
    this->data[row * this->columns + column] = value;
}

template <class T>
T Matrix<T>::get(uint8_t row, uint8_t column) const
{
    // Check for index out of bounds.
    if (row * column > this->rows * this->columns)
    {
        throw std::invalid_argument("Row or column is out of bounds.");
    }

    // Get the desired coefficient.
    return this->data[row * this->columns + column];
}

template <class T>
void Matrix<T>::rowSwap(uint8_t i, uint8_t j)
{
    // Check for out of bounds row.
    if(i >= this->rows || j >= this->rows)
    {
        throw std::invalid_argument("Row or column is out of bounds.");
    }

    // Iterate through all the columns.
    for (uint8_t column = 0; column < this->columns;column++)
    {
        // Swap the coefficient of the two rows in the column.
        T temp = this->data[i * this->columns + column];
        this->data[i * this->columns + column] = this->data[j * this->columns + column];
        this->data[j * this->columns + column] = temp;
    }
}

template <class T>
void Matrix<T>::rowMultiply(uint8_t row, T value)
{
    // Check for out of bounds row.
    if(row >= this->rows)
    {
        throw std::invalid_argument("Row or column is out of bounds.");
    }

    // Iterate through all the columns.
    for (uint8_t column = 0; column < this->columns;column++)
    {
        // Multiply the coefficient times the value.
        this->data[row * this->columns + column] *= value;
    }
}

template <class T>
void Matrix<T>::rowAddMultiple(uint8_t rowI, uint8_t rowJ, T value)
{
    
}

