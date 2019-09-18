#pragma once
class Vector
{
private:
	float x, y, z;
public:
	Vector();

	Vector(float x, float y);
	Vector(float x, float y, float z);

	Vector operator + (Vector vector);
	Vector operator - (Vector vector);
	float operator * (Vector vector);
	Vector operator * (float vector);
	Vector operator = (Vector vector);

	~Vector();
};

