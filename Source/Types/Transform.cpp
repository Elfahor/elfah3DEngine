#include "Transform.h"

Transform::Transform(float3 pos, float3 rot, float3 sc)
	: position(pos), rotation(rot), scale(sc)
{
}

Transform::Transform()
{
	*this = Transform(float3(0, 0, 0), float3(0, 0, 0), float3(1, 1, 1));
}
