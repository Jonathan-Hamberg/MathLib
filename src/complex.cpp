#include "complex.h"

complex::complex()
{
    this->real = 0.0;
    this->imaginary = 0.0;
}

complex::complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

complex::complex(const complex &other)
{
    this->real = other.real;
    this->imaginary = other.imaginary;
}

double complex::getReal() const
{
    return this->real;
}

void complex::setReal(double real)
{
    this->real = real;
}

double complex::getImaginary() const
{
    return this->imaginary;
}

void complex::setImaginary(double imaginary)
{
    this->imaginary = imaginary;
}

void complex::set(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

void complex::add(complex &other)
{
    this->real += other.real;
    this->imaginary += other.imaginary;
}

void complex::subtract(complex &other)
{
    this->real -= other.real;
    this->imaginary -= other.imaginary;
}

void complex::multiply(complex& other)
{
    double r = this->real * other.real - this->imaginary * other.imaginary;
    double i = this->real * other.imaginary + this->imaginary * other.real;

    this->real = r;
    this->imaginary = i;
}

complex complex::operator+(complex& other) const
{
    complex result(*this);
    result.add(other);
    return result;
}

complex& complex::operator+=(complex& other)
{
    this->add(other);
    return *this;
}

complex complex::operator-(complex& other) const
{
    complex result(*this);
    result.subtract(other);
    return result;
}

complex& complex::operator-=(complex& other)
{
    this->subtract(other);
    return *this;
}

complex complex::operator*(complex& other) const
{
    complex result(*this);
    result.multiply(other);
    return result;
}

complex & complex::operator*=(complex& other)
{
    this->multiply(other);
    return *this;
}





