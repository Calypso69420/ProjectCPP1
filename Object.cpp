#include "Object.h"
#include "Game.h"
#include <algorithm>
#include <vector>

Object::Object() {}

Object::~Object() {					/* Destructor */ 
	auto it = std::find(ObjectList.begin(), ObjectList.end(), this);	/* Algorithm (find) */
	if (it != ObjectList.end())
		ObjectList.erase(it);
}