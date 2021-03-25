#pragma once
#include <Types/Math/float3.h>
#include <Types/Math/float4.h>

class Shader
{
public:
	struct appdata
	{
		float3 normal;
		float3 worldPosition;
		float3 screenPosition;

		appdata(float3 _normal, float3 worldPos, float3 screenPos);
		appdata();
	};
	struct v2f
	{
		float3 normal;
		float3 worldPosition;
		float3 screenPosition;
	};
	
	virtual v2f vert(appdata a) = 0;
	virtual float4 frag(v2f i) = 0;
};