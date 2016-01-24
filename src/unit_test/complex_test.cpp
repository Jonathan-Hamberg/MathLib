#include <gtest/gtest.h>
#include "../complex.h"

TEST(complex, constructors)
{
    complex c;
    EXPECT_EQ(0.0, c.getReal()) << "Unexpected real component from the default constructor.";
    EXPECT_EQ(0.0, c.getImaginary()) << "Unexpected imaginary component from the default constructor.";

    c = complex(3.0, -4.0);
    EXPECT_EQ(3.0, c.getReal()) << "Unexpected real component from the value constructor.";
    EXPECT_EQ(-4.0, c.getImaginary()) << "Unexpected imaginary component from the value constructor.";

    complex d(c);

    EXPECT_EQ(3.0, d.getReal()) << "Unexpected real component from the copy constructor.";
    EXPECT_EQ(-4.0, d.getImaginary()) << "Unexpected imaginary component from the copy constructor.";
}

TEST(complex, addition)
{
    complex c(5, 6), d(8, 9);
    complex result = c + d;

    EXPECT_EQ(13, result.getReal()) << "Unexpected real component from complex addition.";
    EXPECT_EQ(15, result.getImaginary()) << "Unexpected imaginary component from complex addition.";

    c = complex(5, 6);
    d = complex(-10, -10);
    result = c + d;

    EXPECT_EQ(-5, result.getReal()) << "Unexpected real component from complex addition.";
    EXPECT_EQ(-4, result.getImaginary()) << "Unexpected imaginary component from complex addition.";
}

TEST(complex, subtraction)
{
    
}

TEST(complex, multiplication)
{
    complex c(4, 5), d(3, 2);
    complex result = c * d;

    EXPECT_EQ(2, result.getReal()) << "Unexpected real component from complex multiplication.";
    EXPECT_EQ(23, result.getImaginary()) << "Unexpected imaginary component from complex multiplication.";

    c = complex(5, 2);
    d = complex(7, 12);
    result = c * d;

    EXPECT_EQ(11, result.getReal()) << "Unexpected real component from complex multiplication.";
    EXPECT_EQ(74, result.getImaginary()) << "Unexpected real commponent from complex multiplicaiton.";
}