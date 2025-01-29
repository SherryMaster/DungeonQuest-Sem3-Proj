#pragma once
#include<string>
#include<vector>
#include"DataManager.h"

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

	void clear();

};

class Item {
	string name;
	int price;
	string rarity;

	int quantity;
	string type;

	bool stackable;

protected:
	DataManager dm;

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
	int durability;

public:
	Sword();
	Sword(string name);

	Sword& setDamage(int dmg);
	Sword& setDurability(int dur);

	int getDamage() const;
	int getDurability() const;
};

class Armor : public Item {
	int defense;
	int durability;

public:
	Armor();
	Armor(string name);

	Armor& setDefense(int def);
	Armor& setDurability(int dur);

	int getDefense() const;
	int getDurability() const;
};

class Potion : public Item {
	int health;

public:
	Potion();
	Potion(string name);

	Potion& setHealth(int hp);

	int getHealth() const;
};