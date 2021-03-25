#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include <Types/Math/float3.h>

class float4x4
{
	float m00, m01, m02, m03;
	float m10, m11, m12, m13;
	float m20, m21, m22, m23;
	float m30, m31, m32, m33;

public:
	float4x4(
		float _m00, float _m01, float _m02, float _m03,
		float _m10, float _m11, float _m12, float _m13,
		float _m20, float _m21, float _m22, float _m23,
		float _m30, float _m31, float _m32, float _m33);
	float4x4();

	static const float4x4 identity;

	float4x4 operator+(float4x4 m);
	float4x4 operator-(float4x4 m);
	float4x4 operator-();
	float4x4 operator*(float k);
	float4x4 operator*(float4x4 m);
	float3   operator*(float3 v);
};

#endif // MATRIX4X4_H
