#pragma once
#include <string>
using namespace std;

class Entity {
	string name;
public:
	Entity();
	~Entity();

	void setName(string name);

	string getName() const;
};