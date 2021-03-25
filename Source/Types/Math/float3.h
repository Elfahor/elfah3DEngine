#ifndef FLOAT3_H
#define FLOAT3_H

#include <cmath>

struct float3
{
public:
	float x, y, z;
	float3(float _x, float _y, float _z);

	float3 operator+(float3 b);
	float3 operator-(float3 b);
	float3 operator-();
	float3 operator*(float fac);
	float3 operator/(float fac);

	float length();
	float3 normalized();
	void normalize();

	static float dot(float3 u, float3 v);
	static float3 cross(float3 u, float3 v);

	static const float3 zero;
	static const float3 one;
};

#endif // FLOAT3_H
