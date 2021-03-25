#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <Types/Object3D.h>
#include <Types/Mesh.h>
#include <Types/Camera.h>

class Object3D;
class Mesh;

class Scene
{
private:
	void AddObject(Object3D* obj);

public:
	std::vector<Object3D*> Objects;
	std::vector<Mesh*> Meshes;
	unsigned int ObjectCount;
	unsigned int MeshCount;

	Camera* MainCamera;

	void AddMesh(Mesh* mesh);
	void AddCamera(Camera* cam);
};

#endif // SCENE_H

