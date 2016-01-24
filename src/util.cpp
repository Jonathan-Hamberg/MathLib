#include "util.h"
#include <cctype>

std::vector<std::string> util::split(const std::string str, const std::string delimiter) {
	// Creates the vector class that stores the results of the string split.
	std::vector<std::string> results;

	// Finds the index of the first delimiter.
	size_t delimiterIndex = str.find(delimiter);
	size_t lastIndex = 0;

	// Find each delimiter and add the contents between the delimiters to the result vector.
	while (delimiterIndex != -1) {
		if (delimiterIndex - lastIndex != 0) {
			results.push_back(str.substr(lastIndex, delimiterIndex - lastIndex));
		}

		// Store the position of the last index so it isn't found again next time.
		lastIndex = delimiterIndex + delimiter.length();
		delimiterIndex = str.find(delimiter, lastIndex);
	}

	// Add the last result to the list of results.
	if (lastIndex != str.length()) {
		results.push_back(str.substr(lastIndex));
	}

	return results;
}

std::string util::trim(const std::string str) {
	// Create new string from the original string.
	std::string newString(str);

	// Erase all the white space character from the beginning of the string.
	for (auto it = newString.begin(); it != newString.end() && std::isspace(*it) ;) {
		newString.erase(it);
	}

	// Erase all the white space character from the end of the string.
	for (auto it = newString.rbegin(); it != newString.rend() && std::isspace(*it) ;++it) {
		newString.erase(--it.base());
	}

	// Return the newString that has been trimmed of white spaces.
	return newString;
}

unsigned util::greatestCommonFactor(unsigned num1, unsigned num2) {
	if (num1 % num2 == 0) {
		return num2;
	}
	else {
		return greatestCommonFactor(num2, num1 % num2);
	}
}

//TODO: not implemented yet.
unsigned util::leastCommonFactor(unsigned num1, unsigned num2) {
	auto num1Factors = getFactors(num1);
	auto num2Factors = getFactors(num2);

	return 0;
}

std::vector<unsigned> util::getFactors(const unsigned num) {
	std::vector<unsigned> factors;

	for (unsigned i = 1; i <= num; i++) {
		if (num % i == 0) {
			factors.push_back(i);
		}
	}

	return factors;
}

bool util::isNumber(std::string str) {
	// Iterate throw every character and return false if any of the
	// characters are not a digit.
	for (auto it = str.begin(); it != str.end(); ++it) {
		if (!std::isdigit(*it)) {
			return false;
		}
	}

	// Non of the characters were non digits so return true.
	return true;
}

bool util::hasMatchingParenthesis(std::string str) {
	int parenthesisCount = 0;

	for (auto it = str.begin(); it != str.end(); ++it) {
		if (*it == '(') {
			++parenthesisCount;
		}

		if (*it == ')') {
			--parenthesisCount;
		}
	}

	// If the parenthesisCount is 0 then there are matching openening and closing parenthesis
	// if not 0 the opening and closing parenthesis do not match.
	return parenthesisCount == 0;
}