#ifndef MESH_H
#define MESH_H

#include <Types/Object3D.h>
#include <vector>
#include <array>

class Mesh : public Object3D
{
public:
	unsigned int triCount;
	unsigned int vertCount;
	std::vector<std::array<float3, 3>> triangles;
	Mesh();
	Mesh(std::vector<std::array<float3, 3>> triangles, Transform transform);
};

#endif // MESH_H

