#include "fraction.h"
#include "util.h"
#include <exception>

fraction::fraction() : fraction(0, 1) {

}

fraction::fraction(int numerator) : fraction(numerator, 1) {

}

fraction::fraction(int numerator, unsigned denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
	this->simplify();
}

fraction::fraction(const fraction &other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
}

int fraction::getNumerator() const {
	return this->numerator;
}

void fraction::setNumerator(int numerator) {
	this->numerator = numerator;
}

unsigned fraction::getDenominator() const {
	return this->denominator;
}

void fraction::setDenominator(unsigned denominator) {
	this->denominator = denominator;
}

double fraction::getReal() const {
	return ((double)this->numerator) / denominator;
}

std::string fraction::toString() const {

	if (denominator == 1) {
		return "(" + std::to_string(this->numerator) + ")";
	}
	else
	{
		return "(" + std::to_string(this->numerator) + "/" + std::to_string(this->denominator) + ")";
	}
}

void fraction::fromString(const std::string str) {

	// The fraction must be surrounded by parenthesis or have no parenthesis.
	size_t leftParanCount = std::count(str.begin(), str.end(), '(');
	size_t rightParanCount = std::count(str.begin(), str.end(), ')');
	size_t divideCount = std::count(str.begin(), str.end(), '/');

	// Throw invalid format the correct number of parenthesis or divide symbols
	// are not present.
	if (!(((leftParanCount == 1 && rightParanCount == 1) ||
		leftParanCount == 0 && rightParanCount == 0) &&
		divideCount == 1)) {
		throw std::invalid_argument("Invalid number of parenthesis or divide symbols.");
	}

	// If there are parenthesis then remove them from the string.
	std::string newString = util::trim(str);
	if (leftParanCount == 1) {
		newString = newString.substr(1, newString.length() - 2);
	}

	// Split the fraction into the numerator and denominator portions.
	auto values = util::split(newString, "/");

	// Trim the whitespace from the values.
	values[0] = util::trim(values[0]);
	values[1] = util::trim(values[1]);

	// Parse the values of the fraction into the fraction.
	if (!util::isNumber(values[0]) || !util::isNumber(values[1])) {
		throw std::invalid_argument("Invalid number formatting of the numerator or denominator.");
	}

	this->numerator = std::stoi(values[0]);
	this->denominator = std::stoi(values[1]);
	this->simplify();
}

void fraction::add(const fraction &other) {
	this->numerator = this->numerator * other.denominator + this->denominator * other.numerator;
	this->denominator = this->denominator * other.denominator;
	this->simplify();
}

void fraction::subtract(const fraction &other) {
	this->numerator = this->numerator * other.denominator - this->denominator * other.numerator;
	this->denominator = this->denominator * other.denominator;
	this->simplify();
}

void fraction::multiply(const fraction &other) {
	this->numerator *= other.numerator;
	this->denominator *= other.denominator;
	this->simplify();
}

void fraction::divide(const fraction &other) {
	this->numerator *= other.denominator;
	this->denominator *= abs(other.numerator);
	this->simplify();
}

void fraction::simplify() {
	unsigned GCD = util::greatestCommonFactor(this->numerator, this->denominator);
	this->numerator /= GCD;
	this->denominator /= GCD;
}

fraction & fraction::operator=(const fraction &other){
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	return *this;
}

fraction fraction::operator+(const fraction &other) {
	fraction object(*this);
	object.add(other);
	return object;
}

fraction & fraction::operator+=(const fraction &other) {
	this->add(other);
	return *this;
}

fraction fraction::operator-(const fraction &other) {
	fraction object(*this);
	object.subtract(other);
	return object;
}

fraction & fraction::operator-=(const fraction & other) {
	this->subtract(other);
	return *this;
}

fraction fraction::operator-() {
	fraction object(-this->numerator, this->denominator);
	return object;
}

fraction fraction::operator/(const fraction &other) {
	fraction object(*this);
	object.divide(other);
	return object;
}

fraction & fraction::operator/=(const fraction &other) {
	this->divide(other);
	return *this;
}

fraction fraction::operator*(const fraction &other) {
	fraction object(*this);
	object.multiply(other);
	return object;
}

fraction & fraction::operator*=(const fraction &other) {
	this->multiply(other);
	return *this;
}

bool fraction::operator==(const fraction &other) {
	return this->numerator == other.numerator && 
		this->denominator == other.denominator;
}

bool fraction::operator!=(const fraction &other) {
	return !this->operator==(other);
}

bool fraction::operator<(const fraction &other) {
	return this->getReal() < other.getReal();
}

bool fraction::operator<=(const fraction &other) {
	return this->operator<(other) && this->operator==(other);
}

bool fraction::operator>(const fraction &other) {
	return this->getReal() > other.getReal();
}

bool fraction::operator>=(const fraction &other) {
	return this->operator>(other) && this->operator==(other);
}
