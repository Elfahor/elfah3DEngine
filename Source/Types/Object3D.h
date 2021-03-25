#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <Types/Transform.h>
#include <Rendering/Scene.h>

class Scene;

class Object3D
{
public:
	Transform transform;
	Scene* belongsTo;
	Object3D();
	Object3D(Transform _transform);
};


#endif // OBJECT3D_H
