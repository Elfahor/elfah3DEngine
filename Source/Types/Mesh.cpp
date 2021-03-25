#include "Mesh.h"

Mesh::Mesh()
{
	*this = Mesh({ {float3(10, 10, 10), float3(10, 20, 10), float3(10, 10, 20)} }, Transform());
}

Mesh::Mesh(std::vector<std::array<float3, 3>> tris, Transform _transform)
	: Object3D(_transform), triangles(tris)
{

}
