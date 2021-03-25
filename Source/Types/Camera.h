#pragma once

#include <Types/Object3D.h>

class Camera : public Object3D
{
private:
	float near, far, fov;
};
