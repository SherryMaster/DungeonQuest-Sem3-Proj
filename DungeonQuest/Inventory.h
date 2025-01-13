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
	
	vector<Sword> swords;
	vector<Armor> armors;
	vector<Potion> potions;

public:
	Inventory();

	void addSword(Sword sword);
	void addArmor(Armor armor);
	void addPotion(Potion potion);

	vector<Sword> getSwords() const;
	vector<Armor> getArmors() const;
	vector<Potion> getPotions() const;

};

class Item {
	string name;
	int price;
	string rarity;

	int quantity;
	string type;

	bool stackable;

public:
	Item();
	Item(string name, int price, int quantity);

	Item& setName(string name);
	Item& setPrice(int price);
	Item& setRarity(string rarity);
	Item& setQuantity(int quantity);
	Item& setType(string type);
	Item& stackAble(bool boolean);

	string getName() const;
	int getPrice() const;
	string getRarity() const;
	int getQuantity() const;
	string getType() const;
	bool isStackable() const;
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