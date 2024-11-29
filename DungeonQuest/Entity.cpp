#include"Entity.h"

using namespace std;

Entity::Entity() {
	name = "Entity";
	health = 100;
	maxHealth = 100;
}

Entity::~Entity() {
}

void Entity::setName(string name) {
	this->name = name;
}

void Entity::setHealth(int health) {
	this->health = health;
}

void Entity::setMaxHealth(int maxHealth) {
	this->maxHealth = maxHealth;
}

string Entity::getName() const {
	return name;
}

int Entity::getHealth() const {
	return health;
}

int Entity::getMaxHealth() const {
	return maxHealth;
}