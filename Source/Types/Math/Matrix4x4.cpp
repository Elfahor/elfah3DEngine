#include "Matrix4x4.h"

float4x4::float4x4(float _m00, float _m01, float _m02, float _m03, float _m10, float _m11, float _m12, float _m13, float _m20, float _m21, float _m22, float _m23, float _m30, float _m31, float _m32, float _m33)
	: m00(_m00), m01(_m01), m02(_m02), m03(_m03), m10(_m10), m11(_m11), m12(_m12), m13(_m13), m20(_m20), m21(_m21) , m22(_m22), m23(_m23), m30(_m30), m31(_m31), m32(_m32), m33(_m33)
{
}

float4x4::float4x4()
{
	*this = float4x4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

float4x4 float4x4::operator*(float4x4 m)
{
	return float4x4(
		this->m00 * m.m00, this->m01 * m.m01, this->m02 * m.m02, this->m03 * m.m03,
		this->m10 * m.m10, this->m11 * m.m11, this->m12 * m.m12, this->m13 * m.m13,
		this->m20 * m.m20, this->m21 * m.m21, this->m22 * m.m22, this->m23 * m.m23,
		this->m30 * m.m30, this->m31 * m.m31, this->m32 * m.m32, this->m33 * m.m33
	);
}

const float4x4 float4x4::identity = float4x4(
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1);
