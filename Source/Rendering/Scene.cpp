#include "Scene.h"

void Scene::AddObject(Object3D* obj)
{
	++ObjectCount;
	Objects.push_back(obj);
	obj->belongsTo = this;
}

void Scene::AddMesh(Mesh* mesh)
{
	Meshes.push_back(mesh);
	++MeshCount;
	AddObject(mesh);
}

void Scene::AddCamera(Camera* cam)
{
	MainCamera = cam;
	AddObject(cam);
}
