#include "Shader.h"

Shader::appdata::appdata(float3 _normal, float3 worldPos, float3 screenPos)
	: normal(_normal), worldPosition(worldPos), screenPosition(screenPos)
{
}

Shader::appdata::appdata()
{
	*this = appdata(float3(0, 0, 0), float3(0, 0, 0), float3(0, 0, 0));
}
