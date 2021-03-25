#include "Object3D.h"

Object3D::Object3D()
{
	*this = Object3D(Transform());
}

Object3D::Object3D(Transform _transform)
	: transform(_transform)
{
}
