#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Math/float3.h"

class Transform
{
public:
	float3 position, rotation, scale;

	Transform(float3 pos, float3 rot, float3 sc);
	Transform();
};

#endif // TRANSFORM_H