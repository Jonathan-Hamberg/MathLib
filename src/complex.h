
/**
* The complex class is used to represent a complex number which
* contains a real component and an imaginary componenet.  The complex
* class supports complex addition, complex subtraction, and complex
* multiplication.
*/
class complex
{
    /**
    * The real component of the complex number.
    */
    double real;

    /**
    * The imaginary component of the complex number.
    */
    double imaginary;

public:

    /**
    * Constructs the complex with the default real and imaginary components of 0.0
    */
    complex();

    /**
    * Constructs the complex with the desired real and imaginary components.
    * @param real The real component of the complex number.
    * @param imaginary The Imaginary component of the complex number.
    */
    complex(double real, double imaginary);

    /**
    * Constructs the complex as a copy of the desired complex number.
    * @param other The other complex number that is being copied.
    */
    complex(const complex &other);

    /**
    * Gets the real component of the complex number.
    * @return The real component of the complex number.
    */
    double getReal() const;

    /**
    * Set the real component of the complex number.
    * @param real The desired real component of the complex number.
    */
    void setReal(double real);

    /**
    * Gets the imaginary component of the complex number.
    * @return The imaginary component of the complex number.
    */
    double getImaginary() const;

    /**
    * Set the imaginary component of the complex number.
    * @param imaginary The desired imaginary component of the complex number.
    */
    void setImaginary(double imaginary);

    /**
    * Set the real and imaginary components of the complex number.
    * @param real The real component of the complex number.
    * @param imaginary The imaginary component of the complex number.
    */
    void set(double real, double imaginary);
    /**
    * Performs an addition with another complex number.
    * @param other The other complex that is being added to this.
    */
    void add(complex &other);

    /**
    * Performs an subtraction with another complex number.
    * @param other The other complex that is being subtracted with this.
    */
    void subtract(complex &other);

    /**
    * Performs an multiplication with another complex number.
    * @param other The other complex that is being multiplied with this.
    */
    void multiply(complex &other);

    /**
    * Operator overload of the addition operator with another complex.
    * @param other The other complex that is being added with this.
    * @return A new complex that contains the sum of this complex with the other complex.
    */
    complex operator+(complex &other) const;

    /**
    * Operator overload of the plus equals operator with another complex.
    * @param other The other complex that is being added to this.
    * @return A reference to this complex after the addition.
    */
    complex &operator+=(complex &other);

    /**
    * Operator overload of the subtraction operator with another complex.
    * @param other The other complex that is being subtracted from this.
    * @return A new complex that contains the subtraction of the other complex from this.
    */
    complex operator-(complex &other) const;

    /**
    * Operator overload of the minus equals operator with another complex.
    * @param other The other complex that is being subtracted from this.
    * @return A reference to this complex after the subtraction.
    */
    complex &operator-=(complex &other);

    /**
    * Operator overload of the multiply operator with another complex.
    * @param other The other complex that is being multiplied with this.
    * @return A new complex that contains the multiplication of this with the other complex.
    */
    complex operator*(complex &other) const;

    /**
    * Operator overload of the multiply equals operator with another complex.
    * @param The other complex that is being multiplied with this.
    * @return A referen to this complex after the multiplication.
    */
    complex &operator*=(complex &other);
};