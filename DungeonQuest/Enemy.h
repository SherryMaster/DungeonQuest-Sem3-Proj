#pragma once
#include"Entity.h"

class Enemy {
	int health;
	int maxHealth;
	int defense;
	int damage;

public:
	Enemy(string name);
};