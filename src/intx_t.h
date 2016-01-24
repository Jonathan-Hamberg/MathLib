#pragma once
#include <vector>

/**
* This class is used to perform integer operations on large integers.  The operations are performed using
* arbitrary sized integers which are increased in size as needed.  All the normal expected operations are
* implemented.  Method to read an integer from a decimal and binary string are implemented as a way to
* input large numbers.  Functions are also available to write the number to a string in decimal and binary
* form.
* Example using.
* cout << intx_t("4567894564894564894") * intx_t("1254894531597894561") << endl; => 5732225910401933392677116602584141534
*/
class intx_t {
	std::vector<uint8_t> data;

public:
	intx_t();
    intx_t(int8_t value);
    intx_t(int16_t value);
    intx_t(int32_t value);
	intx_t(int64_t value);
    intx_t(std::string str);
	intx_t(const intx_t &other);

	void addition(const intx_t &other);
	void subtract(const intx_t &other);
	void multipy(const intx_t &other);
    void multiply_one(const intx_t &other);
    void multiply_two(const intx_t &other);
	uint32_t divide(const int32_t other);
    void bitwise_complement();
    void bitwise_and(const intx_t &other);
    void bitwise_or(const intx_t &other);
    void bitwise_xor(const intx_t &other);
    void shift_left(const unsigned shift);
    void shift_right(const unsigned shift);

	uint8_t getBit(unsigned index) const;
	void setBit(unsigned index, uint8_t value, bool keepSign = false);
	unsigned bits() const;
	bool isNegative() const;
    uint8_t outOfRangeValue() const;
	void setCapacity(unsigned bytes, bool keepSign = true);
	unsigned getCapacity() const;
    void minimizeCapacity();

	std::string toString() const;
	std::string toBinaryString() const;


	intx_t & fromString(std::string str);

	/**
	* This function accepts a string of with the characters 1, 0, and whitespace.  This method
    * converts from a binary string representation into a intx_t value.  If the string contains any
    * invalid characters a invalid_argument exception will be thrown.
	* @param str The string that contains the binary representation of the number.
	* @exception invalid_argument Thrown if any of the characters are something other thann 1, 0,
    *                           or whitespace.
	*/
	intx_t & fromBinaryString(std::string str);

	int64_t toInt64();

	intx_t &operator=(const intx_t &other);

	intx_t operator+(const intx_t &other) const;
	intx_t &operator+=(const intx_t &other);
	intx_t operator-(const intx_t &other) const;
	intx_t &operator-=(const intx_t &other);
	intx_t operator-() const;
	intx_t operator*(const intx_t &other) const;
	intx_t &operator*=(const intx_t &other);
	intx_t operator/(const int32_t other) const;
	intx_t &operator/=(const int32_t other);
	int32_t operator%(const int32_t other) const;

	bool operator==(const intx_t &other) const;
	bool operator!=(const intx_t &other) const;
	bool operator<(const intx_t &other) const;
	bool operator<=(const intx_t &other) const;
	bool operator>(const intx_t &other) const;
	bool operator>=(const intx_t &other) const;

	intx_t operator<<(const unsigned shift) const;
	intx_t &operator<<=(const unsigned shift);
	intx_t operator>>(const unsigned shift) const;
	intx_t &operator >>=(const unsigned shift);
	intx_t operator|(const intx_t &other) const;
    intx_t & operator|=(const intx_t &other);
	intx_t operator&(const intx_t &other) const;
    intx_t & operator&=(const intx_t &other);
    intx_t operator^(const intx_t &other) const;
    intx_t &  operator^=(const intx_t &other);
    intx_t operator~() const;
};
