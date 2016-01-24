#pragma once

#include <stdint.h>

class color_rgb 
{
public:
	/**
	* Constructs the default color_rgb with a color of black.
	*/
	color_rgb();
	/**
	* Constructs the color_rgb with the desired grayscale value.
	* @param value The desired grayscale value with 0 being black and 255 being white.
	*/
	color_rgb(uint8_t value);
	/**
	* Constructs the color_rgb with the desired red, green, and blue values.
	* @param r The red component of the color.
	* @param g The green component of the color.
	* @param b The Blue component of the color.
	*/
	color_rgb(uint8_t r, uint8_t g, uint8_t b);

	/**
	* Sets the red, green, and blue components of the color.
	* @param r  The red component of the color.
	* @param g The green component of the color.
	* @param b The blue component of the color.
	*/
	void set(uint8_t r, uint8_t g, uint8_t b);

	/**
	* Get the red component of the  color.
	* @return The red component of the color.
	*/
	uint8_t getR() const;

	/**
	* Get the green component of the color.
	* @return The green component of the color.
	*/
	uint8_t getG() const;

	/**
	* Get the blue component of the color.
	* @return The blue component of the color.
	*/
	uint8_t getB() const;

	/**
	* Set the red component of the color.
	* @param r The red component of the color.
	*/
	void setR(uint8_t r);

	/**
	* Set the green component of the color.
	* @param g The green component of the color.
	*/
	void setG(uint8_t g);

	/**
	* Set the blue component of the color.
	* @param b The blue component of the color.
	*/
	void setB(uint8_t b);

	union 
	{
		/**
		* Allows access to the components in the form of an array.
		*/
		uint8_t data[3];

		/**
		* Allows access to the components using field names.
		*/
		struct 
		{
			uint8_t r;
			uint8_t g;
			uint8_t b;
		};
	};
};