#ifndef FLOAT4_H
#define FLOAT4_H

struct float4
{
public:
	float x, y, z, w;
	float4(float _x, float _y, float _z, float _w);
		 
	float4 operator+(float4 b);
	float4 operator-(float4 b);
	float4 operator-();
	float4 operator*(float fac);
	float4 operator/(float fac);

	static float dot(float4 u, float4 v);
};

#endif // FLOAT4_H
