#pragma once

#include <vector>
#include <string>

/**
* The Utils namespace is used for misceleaneous functions that do not seem to fit in any specific class.  For Exaple string
* functions that are not implemented in the string class.  And certain math calculations like the greatest common factor
* and the least common factor.
*/
namespace util{

	/**
	* This function takes a string and a delimiter and splits the string based off the delimiter.
	* If there are any empty pieces they will be ignored and not added to to result vector.
	* @param str The string that is will split.
	* @param delimiter The string that will be used to split the string into multiple pieces.
	* @return A vector list of all the pieces of the split string.
	*/
	std::vector<std::string> split(const std::string str, const std::string delimiter);

	/**
	* This method removes any whitespace characters from the beginning and end of the provided string.
	* A whitespace character includes the following [\\n, \\v, \\f, \\r, \\t, ' '].
	* @param str The string that the white spaces are being trimmed from.
	* @return A new string with the white space character trimmed from the front and back.
	*/
	std::string trim(const std::string str);

	/**
	* This function determins the greatest common factor of num1 and num2.
	* @param num1 The first number that is being used to determine the greatest common factor.
	* @param num2 The second number that is being used to determine the greatest common factor.
	* @return The greatest common factor of num1 and num2.
	*/
	unsigned greatestCommonFactor(unsigned num1, unsigned num2);

	/**
	* This function determines the least common factor of num1 and num2.
	* @param num1 The first number that is being used to determine the least common factor.
	* @param num2 The second number that is being used to determine the least common factor.
	* @return The least common factor of num1 and num2.
	*/
	unsigned leastCommonFactor(unsigned num1, unsigned num2);

	/**
	* This function gets all the factors of the provided number.  The answer is stored in a std::vector with 1 as the first element
	* and num as the last element.
	* @param num The number that the factors are being calculated for.
	* @return All the factors in a std::vector
	*/
	std::vector<unsigned> getFactors(const unsigned num);

	/**
	* This function determines if the string is a number. A string is a number if it is made up
	* of only numeric characters.
	* @param str The string that is being checked to see if it is a numeric representation.
	* @return true if the str is a numeric string and false if it is a non numeric string.
	*/
	bool isNumber(std::string str);

	/**
	* This function returns the sign of the passed value.  
	*	If val is < 0, -1 is returned.
	*	If val == 0, 0 is returned.
	*	If val > 0, 1 is returned.
	* @param val The value that the sign is being determined for.
	* @return -1 for val < 0, 0 for val == 0, 1 for val > 0
	*/
	template <typename T> int sgn(T val) {
		return (T(0) < val) - (val < T(0));
	}

	/**
	* This function determines if a expression has matching opening and closing parenthesis.
	* @param str The string that is being check for opening and closing parenthesis.
	* @return true for matching opening and closing parenthesis and false otherwise.
	*/
	bool hasMatchingParenthesis(std::string str);
}