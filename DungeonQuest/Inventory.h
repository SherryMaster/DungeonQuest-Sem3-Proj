#pragma once
#include<string>
#include<vector>
//#include"Player.h"
using namespace std;

class Inventory;
class Item;
class Sword;
class Armor;
class Potion;

class Inventory {
	
	vector<Item> items;

public:
	Inventory();
	void addItem(Item item);

	vector<Sword> getSwords() const;
	vector<Armor> getArmors() const;
	vector<Potion> getPotions() const;
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

class Sword : public Item {
	int damage;

public:
	Sword();
	Sword(string name, int price, int damage);

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
};