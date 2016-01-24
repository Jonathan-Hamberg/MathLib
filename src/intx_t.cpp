#include "intx_t.h"
#include <iostream>
#include <algorithm>

intx_t::intx_t() {
	this->data.push_back(0);
}

intx_t::intx_t(int8_t value) {
    this->data.push_back(uint8_t(value & 0xFF));
}

intx_t::intx_t(int16_t value) {
    this->data.push_back(uint8_t(value & 0xFF));
    this->data.push_back(uint8_t((value & (0xFF << 8)) >> 8));

    this->minimizeCapacity();
}

intx_t::intx_t(int32_t value)
{

    this->data.push_back(uint8_t(value & 0xFF));
    this->data.push_back(uint8_t((value & (0xFF) << 8)>> 8));
    this->data.push_back(uint8_t((value & (0xFF) << 16) >> 16));
    this->data.push_back(uint8_t((value & (0xFF) << 24) >> 24));

    this->minimizeCapacity();
}

intx_t::intx_t(int64_t value) {
	this->data.push_back(uint8_t(value & 0xFF));
	this->data.push_back(uint8_t((value & (int64_t(0xFF) << 8)) >> 8));
	this->data.push_back(uint8_t((value & (int64_t(0xFF) << 16)) >> 16));
	this->data.push_back(uint8_t((value & (int64_t(0xFF) << 24)) >> 24));
	this->data.push_back(uint8_t((value & (int64_t(0xFF) << 32)) >> 32));
	this->data.push_back(uint8_t((value & (int64_t(0xFF) << 40)) >> 40));
	this->data.push_back(uint8_t((value & (int64_t(0xFF) << 48)) >> 48));
	this->data.push_back(uint8_t((value & (int64_t(0xFF) << 56)) >> 56));

    this->minimizeCapacity();
}

intx_t::intx_t(std::string str) {
    this->fromString(str);
}

intx_t::intx_t(const intx_t &other) {
	this->data = other.data;
}
 
void intx_t::addition(const intx_t &other) {
	uint16_t result;
	uint8_t carry = 0;
	uint8_t otherData;

	bool isOtherNegative = other.isNegative();

	// Make sure this object has equal value of the other object.
	if (this->getCapacity() < other.getCapacity()) {
		this->setCapacity(other.getCapacity());
	}  
	else if(std::abs(this->data.back()) >= 64 || std::abs(other.data.back()) >= 64){
        // If the most significant bit is set in both this object and the other object
        // increase  the capacity of this object to hold the result.
		this->setCapacity(this->data.size() + 1);
	}


	// Perform the addition on every byte and carry the overflow.
	for (unsigned i = 0; i < this->data.size(); i++) {
		if (i < other.data.size()) {
			otherData = other.data[i];
		}
		else {
			otherData = isOtherNegative ? 0xFF : 0;
		}

		// The result is the addition of thisData + otherData + carry of the last operation.
		result = this->data[i] + otherData + carry;

		// The carry value of this operation is anything that doesn't fit in the
		// first 8 bits of the result variable.
		carry = (result & 0xFF00) >> 8;

		// Store the lower 8 bits of the operation.
		this->data[i] = result & 0xFF;
	}

    // Minimize the capacity needed.
    this->minimizeCapacity();
}

void intx_t::subtract(const intx_t &other) {
	// Perform a subtraction by using 2s bitwise_complement method.
	this->addition(-other);
}

void intx_t::multipy(const intx_t &other) {
    intx_t result(0);

    // Determine the sign of the final result.
    auto isNegative = (this->isNegative() && !other.isNegative()) ||
        (!this->isNegative() && other.isNegative());
    // Make sure the other object is positive.
    intx_t otherInt = other.isNegative() ? -other : other;

    // Make sure this object is positive.
    if (this->isNegative()) {
        *this = -*this;
    }

    // Perform the binary multiplication
    for (int i = 0; i < this->data.size(); i++)
    {
        for (int j = 0; j < other.data.size(); j++)
        {
            result += intx_t(this->data[i] * other.data[j]) << ((i + j) * 8);
        }
    }

    // Make sure the result has the correct sign.
    *this = isNegative ? -result : result;
}


void intx_t::multiply_one(const intx_t &other)
{
    intx_t result(0);


    // Determine the sign of the final result.
    auto isNegative = (this->isNegative() && !other.isNegative()) ||
        (!this->isNegative() && other.isNegative());
    // Make sure the other object is positive.
    intx_t otherInt = other.isNegative() ? -other : other;

    // Make sure this object is positive.
    if (this->isNegative()) {
        *this = -*this;
    }

    // Perform the binary multiplication.
    for (unsigned i = 0; i < otherInt.data.size() * 8; i++) {
        if (otherInt.getBit(i) == 1) {
            result += *this << i;
        }
    }

    // Make sure the result has the correct sign.
    *this = isNegative ? -result : result;
}

void intx_t::multiply_two(const intx_t &other)
{
    intx_t result(0);


    // Determine the sign of the final result.
    auto isNegative = (this->isNegative() && !other.isNegative()) ||
        (!this->isNegative() && other.isNegative());
    // Make sure the other object is positive.
    intx_t otherInt = other.isNegative() ? -other : other;

    // Make sure this object is positive.
    if (this->isNegative()) {
        *this = -*this;
    }

    // Perform the binary multiplication
    for (int i = 0; i < this->data.size(); i++)
    {
        for (int j = 0; j < other.data.size(); j++)
        {
            result += intx_t(this->data[i] * other.data[j]) << ((i + j)*8);
        }
    }
    
    // Make sure the result has the correct sign.
    *this = isNegative ? -result : result;
}

uint32_t intx_t::divide(const int32_t other) {
    uint32_t remainder = 0;
    uint32_t ddend;

    // Check for divide by zero error.
    if(other == 0) {
        throw std::invalid_argument("Divide by zero error.");
    }

    // Determine if the result should be positive or negative.
    auto isNegative = (this->isNegative() == false && other < 0) ||
        (this->isNegative() == true && other > 0);

    // Make sure this dividend is positive.
    if(this->isNegative())
    {
        *this = -*this;
    }

    // Make sure the divisor is positive.
    int32_t divisor = other < 0 ? -other : other;

    // Perform the division.
    for (int i = this->data.size() - 1; i >= 0;--i)
    {
        ddend = (remainder << 8) + this->data[i];
        remainder = ddend % divisor;
        this->data[i] = ddend / divisor;;
    }

    // Make sure the object has the correct sign.
    if(isNegative)
    {
        *this = -*this;
    }

    return remainder;
}

void intx_t::bitwise_and(const intx_t &other)
{
    // Make sure the capacity is the size of the larger intx_t.
    this->setCapacity(std::max(this->data.size(), other.data.size()));

    // Perform the bitwise and operation.
    for (unsigned i = 0; i < this->data.size() || i < other.data.size(); i++)
    {
        this->data[i] = (i < this->data.size() ? this->data[i] : this->outOfRangeValue()) &
            (i < other.data.size() ? other.data[i] : other.outOfRangeValue());
    }

    // Minimize the size of the intx_t.
    this->minimizeCapacity();
}

void intx_t::bitwise_or(const intx_t & other)
{
    // Make sure the capacity is the size of the larger intx_t.
    this->setCapacity(std::max(this->data.size(), other.data.size()));

    // Perform the bitwise or operation.
    for (unsigned i = 0; i < this->data.size() || i < other.data.size(); i++)
    {
        this->data[i] = (i < this->data.size() ? this->data[i] : this->outOfRangeValue()) | 
            (i < other.data.size() ? other.data[i] : other.outOfRangeValue());
    }

    // Minimize the size of the intx_t.
    this->minimizeCapacity();
}

void intx_t::bitwise_xor(const intx_t &other)
{
    // Make sure the capacity is the size of the larger intx_t.
    this->setCapacity(std::max(this->data.size(), other.data.size()));

    // Perform the bitwise exclusive or operation.
    for (unsigned i = 0; i < this->data.size() || i < other.data.size(); i++)
    {
        this->data[i] = (i < this->data.size() ? this->data[i] : this->outOfRangeValue()) ^
            (i < other.data.size() ? other.data[i] : other.outOfRangeValue());
    }

    // Minimize the size of the intx_t.
    this->minimizeCapacity();
}

void intx_t::shift_left(const unsigned shift)
{
    
}

void intx_t::shift_right(const unsigned shift)
{
    
}

void intx_t::bitwise_complement()
{
    // Perform the bitwise compolement operation.
    for (unsigned i = 0; i < this->data.size();i++)
    {
        this->data[i] = ~this->data[i];
    }
}

uint8_t intx_t::getBit(unsigned index) const {
	// Return 0 or 1 for out of bound index depending on if the number
	// is positive or negative.
	if (index >= this->data.size() * 8) {
		return this->isNegative() ? 1 : 0;
	}

	// Return the value of the bit.
	return (this->data[index / 8] & (1 << index % 8)) > 0 ? 1 : 0;
}

void intx_t::setBit(unsigned index, uint8_t value, bool keepSign) {
    if(keepSign && index >= this->data.size() * 8 - 1) {
        this->setCapacity((index + 1) / 8 + 1, true);
    }
	else if (index >= this->data.size() * 8) {
		this->setCapacity((index + 1) / 8 + 1, false);
	}

	if (value > 0) {
		this->data[index / 8] |= 1 << (index % 8);
	}
	else {
		this->data[index / 8] &= ~(1 << (index % 8));
	}

}

unsigned intx_t::bits() const {
	// Determine if the number is positive or negative.
	bool isNegative = this->isNegative();

	// If positive search for the highest bit with the value of 1 else
	// search for the highest bit with value of 0.
	for (int i = this->data.size() * 8 - 1; i >= 0; i--) {
		if (isNegative && this->getBit(i) == 0) {
			return i;
		}
		else if (!isNegative && this->getBit(i) == 1) {
			return i;
		}
	}

	// If the highest bit was not found return the index of 0.
	return 0;
}

bool intx_t::isNegative() const {
	// The number is negative if the first bit of the most significant byte is 1.
	return ((this->data.back() & (1 << 7))) > 0;
}

uint8_t intx_t::outOfRangeValue() const
{
    return this->isNegative() ? 0xFF : 0x00;
}

void intx_t::setCapacity(unsigned bytes, bool keepSign) {

    // Do not do anything if the current capacity is the same as the new capacity.
    if (bytes != this->getCapacity()) { 

        // Determine if the number is positive.
        auto isNegative = this->isNegative();

        // Resize the data vector.
        this->data.resize(bytes, keepSign && isNegative ? 0xFF : 0);
}
}

unsigned intx_t::getCapacity() const {
	return this->data.size();
}

void intx_t::minimizeCapacity() {
    this->setCapacity((this->bits() + 1) / 8 + 1);
}

std::string intx_t::toString() const{
	std::string str;
	intx_t result;
	intx_t remainder;

    // Return "0" if the value is zero.
    if(*this == 0){
        return "0";
    }

    // Determine if the number is negative.
    bool isNegative = this->isNegative();

    // Make sure the temp variable is positive.
    intx_t temp = this->isNegative() ? -*this : *this;

	while (temp > 0) {
        str = char(temp.divide(10) + 48) + str;
	}

    // If the result is negative add negative sign.
    str = isNegative ? '-' + str : str;

	return str;
}

std::string intx_t::toBinaryString() const{
	std::string str;

	// Loop through every byte of the intx_t.
	for (unsigned i = 1; i <= data.size(); i++) {
		int8_t byte = data[data.size() - i];

		// Loop through every bit of the byte.
		for (int j = 0; j < 8; j++) {
			if ((byte >> (7 - j) & 1) == 1) {
				str = str + "1";
			}
			else {
				str = str + "0";
			}
		}

		// Add a spacer between the bytes.
		str += " ";
	}

	// Remove the extra space from the end.
	str = str.substr(0, str.size() - 1);
	return str;
}

intx_t & intx_t::fromString(std::string str) { 
    intx_t result;

    auto firstDigit = false;
    auto isNegative = false;

    for (auto iter = str.begin(); iter != str.end();++iter)
    {
        // Ignore the character if it is whitespace.
        if(!isspace(*iter))
        {
            // If it is a digit add it into the result.
            if(isdigit(*iter))
            {
                // The first digit has been processed.
                result = result * 10 + char(*iter - 48);

                // Set the flag that the first digit has been processed.
                firstDigit = true;
            }
            else if(*iter == '-')  { // Negate the number if a negative sign is found.

                // The negative sign has to be at the beginning of the number.
                if (firstDigit) {
                    throw std::invalid_argument("The string contains negative sign in a invalid location.");
                }

                // Set the is negative flag to true.
                isNegative = true;
            }
            else { // Anything else is invalid formatting.
                throw std::invalid_argument("The string contains an invalid character.");
            }
        }
    }

    // Store the result and negate the result if necessary.
    *this = isNegative ? -result : result;
    return *this;
}

intx_t & intx_t::fromBinaryString(std::string str) {
    intx_t result;

    unsigned bitIndex = 0;

    for (auto iter = str.rbegin(); iter != str.rend(); ++iter) {
        // Ignore the character if it is whitespace.
        if (!isspace(*iter)) {
            // If the character is a 1 set the current bitIndex to 1 and advance the current bit
            // index.
            if (*iter == '1') {
                result.setBit(bitIndex, 1);
                bitIndex++;
            }
            else if (*iter == '0') { // If the character is a 0 advance the current bitIndex.
                bitIndex++;
            }
            else { // If the charcter is invalid throw a invlid_argument exception.
                throw std::invalid_argument("The string contains an invalid character.");
            }
        }
    }

    *this = result;
    return *this;
}

int64_t intx_t::toInt64() {
	uint64_t value = 0;
	auto isNegative = this->isNegative();

	for (unsigned i = 0; i < 8; i++) {
		// OR each byte into the integer value.
		if (i < this->data.size()) {
			value |= uint64_t(this->data[i]) << (8 * i);
		}
		else {
			// If the intx_t doesn't not contain 8 bytes substitue 0 or 255
			// to conserve the value of the number.
			value |= isNegative ? uint64_t(0xFF) << (i * 8) : 0;
		}
	}

	return value;
}

intx_t &intx_t::operator=(const intx_t &other) {
	this->data = other.data;
	return *this;
}

intx_t intx_t::operator+(const intx_t &other) const{
	intx_t result(*this);
	result.addition(other);
	return result;
}

intx_t &intx_t::operator+=(const intx_t &other) {
	this->addition(other);
	return *this;
}

intx_t intx_t::operator-(const intx_t &other) const {
	intx_t result(*this);
	result.subtract(other);
	return result;
}

intx_t &intx_t::operator-=(const intx_t &other) {
	this->subtract(other);
	return *this;
}

intx_t intx_t::operator-() const {
	intx_t result(*this);
    result.bitwise_complement();
    result.addition(1);
	return result;
}

intx_t intx_t::operator*(const intx_t &other) const {
	intx_t result(*this);
	result.multipy(other);
	return result;
}

intx_t &intx_t::operator*=(const intx_t &other) {
	this->multipy(other);
	return *this;
}

intx_t intx_t::operator/(const int32_t other) const {
	intx_t result(*this);
	result.divide(other);
	return result;
}

intx_t &intx_t::operator/=(const int32_t other) {
	this->divide(other);
	return *this;
}

int32_t intx_t::operator%(const int32_t other) const {
	intx_t dividend(*this);
	return dividend.divide(other);
}

bool intx_t::operator==(const intx_t &other) const {
    intx_t result(*this - other);
    return result.getCapacity() == 1 && result.data[0] == 0;
}

bool intx_t::operator!=(const intx_t &other) const {
	return !(*this == other);
}

bool intx_t::operator<(const intx_t &other) const {
	return (*this - other).isNegative();
}

bool intx_t::operator<=(const intx_t &other) const {
	return !(*this > other);
}

bool intx_t::operator>(const intx_t &other) const {
	return (other - *this).isNegative();
}

bool intx_t::operator>=(const intx_t &other) const {
	return !(*this < other);
}

intx_t intx_t::operator<<(const unsigned shift) const {
	intx_t result = this->isNegative() ? intx_t(-1) : intx_t(0);
	unsigned highestBitIndex = this->bits();

	// Shift the existing bits.
	for (int i = highestBitIndex; i >= 0; i--) {
		result.setBit(i + shift, this->getBit(i), true);
	}

	// The rest of the bits are 0.
	for (int i = shift - 1; i >= 0; i--) {
		result.setBit(i, 0, true);
	}

	return result;
}

intx_t &intx_t::operator<<=(const unsigned shift) {
	*this = *this << shift;
	return *this;
}

intx_t intx_t::operator>>(const unsigned shift) const {
	intx_t result = this->isNegative() ? intx_t(-1) : intx_t(0);

    auto highestBitIndex = this->bits();

	// Shift the existing bits.
	for (int i = highestBitIndex; i - int(shift) >= 0; i--) {
		result.setBit(i - shift, this->getBit(i), true);
	}

	return result;
}

intx_t &intx_t::operator>>=(const unsigned shift) {
	*this = *this >> shift;
	return *this;
}

intx_t intx_t::operator|(const intx_t &other) const {
	intx_t result;
    result.bitwise_or(other);
	return result;
}

intx_t & intx_t::operator|=(const intx_t &other) {
    this->bitwise_or(other);
    return *this;
}

intx_t intx_t::operator&(const intx_t &other) const {
	intx_t result;
    result.bitwise_and(other);
	return result;
}

intx_t & intx_t::operator&=(const intx_t &other) {
    this->bitwise_and(other);
    return *this;
}

intx_t intx_t::operator^(const intx_t &other) const {
    intx_t result(*this);
    result.bitwise_xor(other);
    return result;
}

intx_t & intx_t::operator^=(const intx_t &other) {
    this->bitwise_xor(other);
    return *this;
}

intx_t intx_t::operator~() const {
    intx_t result(*this);
    result.bitwise_complement();
    return result;
}