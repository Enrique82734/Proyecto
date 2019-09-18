#include "pch.h"
#include "Vector.h"


Vector::Vector()
{
	x, y = 0;
}

Vector::Vector(float a, float b)
{
	x = a;
	y = b;
}

Vector::Vector(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}

Vector Vector::operator+(Vector vector)
{
	Vector temp;
	temp.x = x + vector.x;
	temp.y = y + vector.y;
	return temp;
}

Vector Vector::operator-(Vector vector)
{
	Vector temp;
	temp.x = x - vector.x;
	temp.y = y - vector.y;
	return temp;
}

Vector Vector::operator*(float escalar)
{
	Vector temp;
	temp.x = escalar * this->x;
	temp.y = escalar * this->y;
	return temp;
}

float Vector::operator*(Vector vector) {
	float temp;
	temp = (x * vector.x) + (y * vector.y);
	return temp;
}

Vector Vector::operator=(Vector vector)
{
	Vector temp;
	temp.x = vector.x;
	temp.y = vector.y;
	return temp;
}

Vector::~Vector()
{
}
