#include"Entity.h"

using namespace std;

Entity::Entity() {
	name = "Entity";
}

Entity::~Entity() {
}

void Entity::setName(string name) {
	this->name = name;
}

string Entity::getName() const {
	return name;
}