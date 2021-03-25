#include "float4.h"

float float4::dot(float4 u, float4 v)
{
	return u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w;
}

float4::float4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w)
{

}

float4 float4::operator+(float4 v)
{
	return float4(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w);
}

float4 float4::operator-(float4 v)
{
	return float4(this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w);
}

float4 float4::operator-()
{
	return float4(-this->x, -this->y, -this->z, -this->w);
}

float4 float4::operator*(float k)
{
	return float4(this->x * k, this->y * k, this->z * k, this->w * k);
}

float4 float4::operator/(float fac)
{
	return *this * (1 / fac);
}
