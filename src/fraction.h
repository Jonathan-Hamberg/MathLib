#pragma once

#include <string>

/**
* This class is used to represent fractional data.  The fraction is stored as a numerator and denominator part.
* This class has all the method to add, subtract, multiply and divide other fractions.  A toString() and fromString()
* method have been implemented to load the fraction from a string.
*/
class fraction {
private:
	int numerator;
	unsigned denominator;

	void simplify();

public:
	/**
	* This constructor initailizes the fraction object to it's default values which are 0.
	*/
	fraction();

	/**
	* This constructor initializes the numerator of the object to the provided numerator with a denominator of 1.
	*/
	fraction(int numerator);

	/**
	* This constructor initialzes the numerator and the denominator to the provided values.
	*/
	fraction(int numerator, unsigned denominator);

	/**
	* This copy constructor initializes the numerator and denominator to the values from the other fraction object.
	*/
	fraction(const fraction &other);

	/**
	* Gets the numerator from the fraction.
	* @return The numerator of the fraction.
	*/
	int getNumerator() const;

	/**
	* Sets the numerator of the fraction.
	* @param numerator The new numerator of the fraction.
	*/
	void setNumerator(int numerator);

	/**
	* Gets the denominator of the fraction.
	* @return The denominator of the fraction.
	*/
	unsigned getDenominator() const;

	/**
	* Sets the denominator of the fraction.
	* @param denominator The new denominator of the fraction.
	*/
	void setDenominator(unsigned denominator);

	/**
	* Gets the real number representation of the fraction.
	* @return The real representation of the fraction.
	*/
	double getReal() const;

	/**
	* Converts the fraction into a string representation of the fraction.  The
	* fraction is formatted in the following way "(n/d)" where n is the numerator
	* and d is the denominator.  If the denominator is 1 the value of the numerator will
	* be returned without the deniminator in the bottom.  Example "(n)" where n is the
	* numerator.
	*/
	std::string toString() const;

	/**
	* Takes in a string and converts that string into fraction.  The string must be formatted
	* in one of the two following ways.  1. "(n/d)" or "n/d"  where n is the numerator and d is the
	* denominator.  A invalid_format exception will be thrown if the string is formatted incorrectly
	* and the fraction will remain unchanged.
	* The current contents of the fraction will be overwritten by the this function.
	* @param str The string that will be parsed into the fraction.
	* @exception invalid_format If the input string is not in the correct format.
	*/
	void fromString(const std::string str);

	/**
	* Adds another fraction to the current fraction.
	* @param other The other value that will be added to the current value.
	*/
	void add(const fraction &other);

	/**
	* Subtracts another fraction from the current fraction.
	* @param other The other value that will be subtracted from the current value.
	*/
	void subtract(const fraction &other);

	/**
	* Multiplies another fraction to the current fraction.
	* @param other The value that will be multiplied with the current value.
	*/
	void multiply(const fraction &other);

	/**
	* Divides the current fraction by another fraction.
	* @param other The value that that current value will be devided by.
	*/
	void divide(const fraction &other);

	/**
	* Assignment operator.  Copies the values from the other value into this value.
	* A reference to this object is returned when finished.
	* @param other The other value from which this is being assigned to.
	* @return A reference to this object after the assignment operator.
	*/
	fraction & operator=(const fraction &other);

	/**
	* Plus operator.  Adds the other object to this object and returns the result.
	* @param other The other object which is being added to this object.
	* @return The addititon of this object and the other object.
	*/
	fraction operator+(const fraction &other);

	/**
	* Plus equals operator.  Takes another object and adds it to this
	* object.
	* @param object The other object that is added to this object.
	* @return A reference to this object after the addition.
	*/
	fraction & operator+=(const fraction &other);

	/**
	* Subtract operator.  Subtracts the other object from this object and returns the result.
	* @param other The other object which is subtracted from this object.
	* @return The subtraction of the other object from this object.
	*/
	fraction operator-(const fraction &other);

	/**
	* Negation operator.  Returns the negative value of this object.
	* @return The negative value of this object.
	*/
	fraction operator-();

	/**
	* Subtract equals operator.  Takes another object and subtracts it from this object.
	* @param other The other object which is subtracted from this object.
	* @return A reference to this object after the subtraction.
	*/
	fraction & operator-=(const fraction & other);

	/**
	* The multiply operator.  This object and the other object are multiplied together and
	* a new object is returned.
	* @param other The other object that is getting multiplied with this object.
	* @return A new object that contains the result of this object multiplied by the other object.
	*/
	fraction operator*(const fraction &other);

	/**
	* The multiply equals operator.  This object is multiplied by the other object and the
	* results are stored in this object.
	* @param other The other object that this object is being multiplied by.
	* @return A reference to this after the multiplication.
	*/
	fraction & operator*=(const fraction &other);

	/**
	* The divide operator.  Divides this object by another object and returns
	* a new object containing the result.
	* @other The other object which is divided into this object.
	* @return New object containing the division of this object by the other object.
	*/
	fraction operator/(const fraction &other);

	/**
	* Divide equals operator.  Divides this object by another objects and returns a reference
	* to this object after the division.
	* @other The object that this object is being divided by.
	* @return The reference to this after the division has been applied.
	*/
	fraction & operator/=(const fraction &other);

	/**
	* The equality operator.  Returns true if the numerator and denominator have the same value
	* as the other numerator and denominator.
	* @param other The other object that this object is being compared to.
	* @return true if the objects are equal and false if the objects are not equal.
	*/
	bool operator==(const fraction &other);

	/**
	* The inequality operator.  Returns true if this numerator and denominator are different from
	* the other numerator and denominator.
	* @param other The other object that this object is being compared to.
	* @return true if the objects are not equal and false if the objects are equal.
	*/
	bool operator!=(const fraction &other);

	/**
	* The less than operator.  Returns true if this object is less than the other object.
	* @param other The object that this object is being compared with.
	@ retun true if this object is less than the other object and false if this is not less than the other object.
 	*/
	bool operator<(const fraction &other);

	/**
	* The less than equal operator.  Returns true if this object is less than equal to the other object.
	* @param other The object that this object is being compared with.
	* @return true if this object is less than equal to the other and false if this object is greater than the other object.
	*/
	bool operator<=(const fraction &other);

	/**
	* The greater than operator.  Returns true if this object is greater than the other object.
	* @param other The object that this object is being compared with.
	* @return true if this object is greater than the other object and false if this object is less than equal to the other object.
	*/
	bool operator>(const fraction &other);

	/**
	* The greater than equal operator.  Returns true if this object is greater than or equal to the other object.
	* @param other The object that this object is being compared with.
	* @return true if this object is greater than or equal to the other object and false if this object is less than the other object.
	*/
	bool operator>=(const fraction &other);
};