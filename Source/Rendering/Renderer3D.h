#ifndef RENDERER3D_H
#define RENDERER3D_H

#include <SDL.h>
#include <cmath>
#include <array>
#include <Types/Math/float3.h>
#include <Types/Math/Matrix4x4.h>
#include <Rendering/Scene.h>
#include <Types/Mesh.h>
#include <Rendering/Shader.h>

class Renderer3D
{
private:
	void RenderMesh(const Mesh* mesh, SDL_Renderer* tex);
	void ComputeW2P();
	float4x4 W2P;

	float near, far, fov;
	unsigned int screenHeight, screenWidth;

public:
	Scene scene;

	void Render(SDL_Renderer* tex);

	Renderer3D(unsigned int screenw, unsigned int screenh, float near, float far, float fov);
	Renderer3D();
};

#endif // RENDERER3D_H
