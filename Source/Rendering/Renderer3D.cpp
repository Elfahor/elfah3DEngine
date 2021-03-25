#include "Renderer3D.h"

void Renderer3D::RenderMesh(const Mesh* mesh, SDL_Renderer* tex)
{
	float4x4 scaleMatrix = float4x4(
		mesh->transform.scale.x, 0, 0, 0,
		0, mesh->transform.scale.y, 0, 0,
		0, 0, mesh->transform.scale.z, 0,
		0, 0, 0, 1
	);
	float rotX = mesh->transform.rotation.x;
	float rotY = mesh->transform.rotation.y;
	float rotZ = mesh->transform.rotation.z;
	float4x4 rotationX = float4x4(
		1, 0,			0,			0,
		0, cos(rotX),	sin(rotX),	0,
		0, -sin(rotX),	cos(rotX),	0,
		0, 0,			0,			1
	);
	float4x4 rotationY = float4x4(
		cos(rotY),	0, sin(rotY),	0,
		0,			1, 0,			0,
		-sin(rotY), 0, cos(rotY),	0,
		0,			0, 0,			1
	);
	float4x4 rotationZ = float4x4(
		cos(rotZ),  sin(rotZ),  0, 0,
		-sin(rotZ), cos(rotZ),  0, 0,
		0,          0,          1, 0,
		0,          0,          0, 1
	);
	float4x4 rot = rotationX * rotationY * rotationZ;
	float4x4 M2W = rot * scaleMatrix;

	for (unsigned int i = 0; i < mesh->triCount; i++)
	{
		std::array<float3, 3> currentTri = mesh->triangles[i];

		float3 v1 = currentTri[0];
		float3 v2 = currentTri[1];
		float3 v3 = currentTri[2];

		float3 wv1 = M2W * v1;
		float3 wv2 = M2W * v2;
		float3 wv3 = M2W * v3;

		wv1 = wv1 + mesh->transform.position;
		wv2 = wv2 + mesh->transform.position;
		wv3 = wv3 + mesh->transform.position;

		float3 a = v3 - v1;
		float3 b = v2 - v1;
		float3 faceNorm = float3::cross(a, b);
		faceNorm.normalize();
		float dot = float3::dot(faceNorm, float3(1, 0, 0));
		if (dot > 0)
		{
			Shader::appdata vert1, vert2, vert3;
			vert1.worldPosition = v1;
			vert2.worldPosition = v2;
			vert3.worldPosition = v3;
			vert1.screenPosition = W2P * v1;
			vert2.screenPosition = W2P * v2;
			vert3.screenPosition = W2P * v3;

			vert1.screenPosition.x = vert1.screenPosition.x * 0.5 * screenWidth;
			vert1.screenPosition.y = vert1.screenPosition.y * 0.5 * screenHeight;
			vert2.screenPosition.x = vert2.screenPosition.x * 0.5 * screenWidth;
			vert2.screenPosition.y = vert2.screenPosition.y * 0.5 * screenHeight;
			vert3.screenPosition.x = vert3.screenPosition.x * 0.5 * screenWidth;
			vert3.screenPosition.y = vert3.screenPosition.y * 0.5 * screenHeight;

			SDL_RenderDrawLineF(tex, vert1.screenPosition.x, vert1.screenPosition.y, vert2.screenPosition.x, vert2.screenPosition.y);
			SDL_RenderDrawLineF(tex, vert1.screenPosition.x, vert1.screenPosition.y, vert3.screenPosition.x, vert3.screenPosition.y);
			SDL_RenderDrawLineF(tex, vert2.screenPosition.x, vert2.screenPosition.y, vert3.screenPosition.x, vert3.screenPosition.y);

		}
	}
}

void Renderer3D::Render(SDL_Renderer* tex)
{
	for (unsigned int i = 0; i < scene.MeshCount; i+=3)
	{
		Mesh* currentMesh = scene.Meshes[i];
		RenderMesh(currentMesh, tex);
	}

}

void Renderer3D::ComputeW2P()
{
	float fovRad = 1.0f / tan(fov * 0.5 / 180.0 * M_PI);
	float aspectRatio = screenHeight / screenWidth;

	W2P = float4x4(
		aspectRatio * fovRad,	0,		0,							0,
		0,						fovRad,	0,							0,
		0,						0,		far/(far-near),				1,
		0,						0,		(-far * near)/(far-near),	0
	);
}

Renderer3D::Renderer3D(unsigned int screenw, unsigned int screenh, float _near, float _far, float _fov)
	: screenHeight(screenh), screenWidth(screenw), near(_near), far(_far), fov(_fov)
{
	ComputeW2P();
}

Renderer3D::Renderer3D()
{
	*this = Renderer3D(800, 600, 0.001, 1000, 90);
}
