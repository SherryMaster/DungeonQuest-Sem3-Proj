#include"Inventory.h"

Inventory::Inventory() {
	items = vector<Item>();
}

void Inventory::addItem(Item item) {
	items.push_back(item);
}

Item::Item() {
	name = "";
	price = 0;
}

Item::Item(string name) {
	this->name = name;
	price = 0;
}

Item::Item(string name, int price) {
	this->name = name;
	this->price = price;
}

void Item::setName(string name) {
	this->name = name;
}

void Item::setPrice(int price) {
	this->price = price;
}

void Item::setRarity(string rarity) {
	this->rarity = rarity;
}

string Item::getName() const {
	return name;
}

int Item::getPrice() const {
	return price;
}

string Item::getRarity() const {
	return rarity;
}

Weapon::Weapon() {
	damage = 0;
	setType("Weapon");
}

Weapon::Weapon(string name, int price, int damage) : Item(name, price) {
	this->damage = damage;
	setType("Weapon");
}

void Weapon::setDamage(int dmg) {
	damage = dmg;
}

int Weapon::getDamage() const {
	return damage;
}

Armor::Armor() {
	defense = 0;
	setType("Armor");
}

Armor::Armor(string name, int price, int defense) : Item(name, price) {
	this->defense = defense;
	setType("Armor");
}

void Armor::setDefense(int def) {
	defense = def;
}

int Armor::getDefense() const {
	return defense;
}

Potion::Potion() {
	health = 0;
	setType("Potion");
}

Potion::Potion(string name, int price, int health) : Item(name, price) {
	this->health = health;
	setType("Potion");
}

void Potion::setHealth(int hp) {
	health = hp;
}

int Potion::getHealth() const {
	return health;
}


