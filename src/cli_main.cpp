#include "util.h"
#include "fraction.h"
#include <iostream>


int main()
{
	std::string input;
	fraction num(3);

	num /= -3;


	std::getline(std::cin, input);

	while (input != "q") {

		num.fromString(input);
		std::cout << num.toString() << std::endl;



		std::getline(std::cin, input);
	}

	std::cin.get();
    return 0;


}
