#include "float3.h"

float float3::dot(float3 u, float3 v)
{
	return u.x * v.x + u.y * v.y + u.z * v.z;
}

float3 float3::cross(float3 u, float3 v)
{
	return float3(
		u.y * v.z - u.z * v.y,
		u.z * v.x - u.x * v.z,
		u.x * v.y - u.y * v.x);
}

float3::float3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{

}

float3 float3::operator+(float3 v)
{
	return float3(this->x + v.x, this->y + v.y, this->z + v.z);
}

float3 float3::operator-(float3 v)
{
	return float3(this->x - v.x, this->y - v.y, this->z - v.z);
}

float3 float3::operator-()
{
	return float3(-this->x, -this->y, -this->z);
}

float3 float3::operator*(float fac)
{
	return float3(this->x * fac, this->y * fac, this->z * fac);
}

float3 float3::operator/(float fac)
{
	return *this * (1/fac);
}

float float3::length()
{
	return sqrt(x*x + y*y + z*z);
}

float3 float3::normalized()
{
	return *this * this->length();
}

void float3::normalize()
{
	*this = this->normalized();
}

const float3 float3::one = float3(1, 1, 1);
const float3 float3::zero = float3(0, 0, 0);
