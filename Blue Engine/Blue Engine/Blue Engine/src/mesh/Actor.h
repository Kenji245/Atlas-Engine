#ifndef ACTOR_H
#define ACTOR_H

#include "../system.h"
#include "mesh.h"

class Actor {

public:
	Actor(Mesh* mesh);

	mat4 modelMatrix;
	mat4 transformedMatrix;

	Mesh* mesh;

	bool render;
	bool castShadow;

};

#endif