#pragma once
#include<string>
#include<vector>
using namespace std;

class Inventory {

};

class Item {
	string name;
	int price;

public:
	Item();
	Item(string name);
	Item(string name, int price);

	void setName(string name);
	void setPrice(int price);

	string getName() const;
	int getPrice() const;
};

class Weapon : public Item {
	int damage;

public:
	Weapon();
	Weapon(string name, int price, int damage);

	void setDamage(int dmg);

	int getDamage() const;
};