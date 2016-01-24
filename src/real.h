#pragma once

#include <string>

class real {
private:
	double number;
	int significant_figures;
	int precision;
public:
	real();
	real(double value);
	real(double value, int significant_figures);
	real(const real &other);

	void add(real &other);
	void subtract(real &other);
	void multiply(real &other);
	void divide(real &other);

	std::string toString();
	void fromString(std::string str);

	/**
	* Assignment operator.  Copies the values from the other value into this value.
	* A reference to this object is returned when finished.
	* @param other The other value from which this is being assigned to.
	* @return A reference to this object after the assignment operator.
	*/
	real & operator=(const real &other);

	/**
	* Plus operator.  Adds the other object to this object and returns the result.
	* @param other The other object which is being added to this object.
	* @return The addititon of this object and the other object.
	*/
	real operator+(const real &other);

	/**
	* Plus equals operator.  Takes another object and adds it to this
	* object.
	* @param object The other object that is added to this object.
	* @return A reference to this object after the addition.
	*/
	real & operator+=(const real &other);

	/**
	* Subtract operator.  Subtracts the other object from this object and returns the result.
	* @param other The other object which is subtracted from this object.
	* @return The subtraction of the other object from this object.
	*/
	real operator-(const real &other);

	/**
	* Negation operator.  Returns the negative value of this object.
	* @return The negative value of this object.
	*/
	real operator-();

	/**
	* Subtract equals operator.  Takes another object and subtracts it from this object.
	* @param other The other object which is subtracted from this object.
	* @return A reference to this object after the subtraction.
	*/
	real & operator-=(const real & other);

	/**
	* The multiply operator.  This object and the other object are multiplied together and
	* a new object is returned.
	* @param other The other object that is getting multiplied with this object.
	* @return A new object that contains the result of this object multiplied by the other object.
	*/
	real operator*(const real &other);

	/**
	* The multiply equals operator.  This object is multiplied by the other object and the
	* results are stored in this object.
	* @param other The other object that this object is being multiplied by.
	* @return A reference to this after the multiplication.
	*/
	real & operator*=(const real &other);

	/**
	* The divide operator.  Divides this object by another object and returns
	* a new object containing the result.
	* @other The other object which is divided into this object.
	* @return New object containing the division of this object by the other object.
	*/
	real operator/(const real &other);

	/**
	* Divide equals operator.  Divides this object by another objects and returns a reference
	* to this object after the division.
	* @other The object that this object is being divided by.
	* @return The reference to this after the division has been applied.
	*/
	real & operator/=(const real &other);

	/**
	* The equality operator.  Returns true if the numerator and denominator have the same value
	* as the other numerator and denominator.
	* @param other The other object that this object is being compared to.
	* @return true if the objects are equal and false if the objects are not equal.
	*/
	bool operator==(const real &other);

	/**
	* The inequality operator.  Returns true if this numerator and denominator are different from
	* the other numerator and denominator.
	* @param other The other object that this object is being compared to.
	* @return true if the objects are not equal and false if the objects are equal.
	*/
	bool operator!=(const real &other);

	/**
	* The less than operator.  Returns true if this object is less than the other object.
	* @param other The object that this object is being compared with.
	* @return true if this object is less than the other object and false if this is not less than the other object.
	*/
	bool operator<(const real &other);

	/**
	* The less than equal operator.  Returns true if this object is less than equal to the other object.
	* @param other The object that this object is being compared with.
	* @return true if this object is less than equal to the other and false if this object is greater than the other object.
	*/
	bool operator<=(const real &other);

	/**
	* The greater than operator.  Returns true if this object is greater than the other object.
	* @param other The object that this object is being compared with.
	* @return true if this object is greater than the other object and false if this object is less than equal to the other object.
	*/
	bool operator>(const real &other);

	/**
	* The greater than equal operator.  Returns true if this object is greater than or equal to the other object.
	* @param other The object that this object is being compared with.
	* @return true if this object is greater than or equal to the other object and false if this object is less than the other object.
	*/
	bool operator>=(const real &other);
};