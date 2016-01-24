#include "color_rgb.h"

color_rgb::color_rgb() 
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

color_rgb::color_rgb(uint8_t value) 
{
	this->r = value;
	this->g = value;
	this->b = value;
}

color_rgb::color_rgb(uint8_t r, uint8_t g, uint8_t b) 
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void color_rgb::set(uint8_t r, uint8_t g, uint8_t b) 
{
	this->r = r;
	this->g = g;
	this->b = b;
}

uint8_t color_rgb::getR() const 
{
	return this->r;
}

uint8_t color_rgb::getG() const
{
	return this->g;
}

uint8_t color_rgb::getB() const
{
	return this->b;
}