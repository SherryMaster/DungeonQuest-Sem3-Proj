#pragma once
#include<string>
#include<vector>
#include"Player.h"
using namespace std;

class Item;
class Weapon;
class Armor;
class Potion;

class Inventory {
	
	vector<Item> items;

public:
	Inventory();
	void addItem(Item item);

	vector<Item> getSwords() const;
	vector<Item> getArmors() const;
	vector<Item> getPotions() const;
	vector<Item> getItems() const;
};

class Item {
	string name;
	int price;
	string rarity;

	int quantity;
	string type;

public:
	Item();
	Item(string name);
	Item(string name, int price);

	void setName(string name);
	void setPrice(int price);
	void setRarity(string rarity);
	void setQuantity(int quantity);
	void setType(string type);

	string getName() const;
	int getPrice() const;
	string getRarity() const;
	int getQuantity() const;
	string getType() const;
};

class Weapon : public Item {
	int damage;

public:
	Weapon();
	Weapon(string name, int price, int damage);

	void setDamage(int dmg);

	int getDamage() const;
};

class Armor : public Item {
	int defense;

public:
	Armor();
	Armor(string name, int price, int defense);

	void setDefense(int def);

	int getDefense() const;
};

class Potion : public Item {
	int health;


public:
	Potion();
	Potion(string name, int price, int health);

	void setHealth(int hp);

	int getHealth() const;

	void use(Player& player);
};