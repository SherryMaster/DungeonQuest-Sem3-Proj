#pragma once
#include <string>
using namespace std;

class Entity {
	string name;
	int health;
	int maxHealth;
public:
	Entity();
	~Entity();

	void setName(string name);
	void setHealth(int health);
	void setMaxHealth(int maxHealth);

	string getName() const;
	int getHealth() const;
	int getMaxHealth() const;
};