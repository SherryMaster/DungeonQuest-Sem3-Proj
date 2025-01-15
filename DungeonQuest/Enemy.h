#pragma once
#include"Entity.h"
#include"LootBox.h"

class Enemy: public Entity {
	int health;
	int maxHealth;
	int defense;
	int damage;

	LootBox loot;

public:
	Enemy(string name);
};