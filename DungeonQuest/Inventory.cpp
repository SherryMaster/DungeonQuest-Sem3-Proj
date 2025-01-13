#include"Inventory.h"

Inventory::Inventory() {
	swords = vector<Sword>();
}

void Inventory::addSword(Sword sword) {
	swords.push_back(sword);
}

void Inventory::addArmor(Armor armor) {
	armors.push_back(armor);
}

void Inventory::addPotion(Potion potion) {
	potions.push_back(potion);
}

vector<Sword> Inventory::getSwords() const {
	return swords;
}

vector<Armor> Inventory::getArmors() const {
	return armors;
}

vector<Potion> Inventory::getPotions() const {
	return potions;
}

Item::Item() {
	name = "";
	price = 0;
	quantity = 1;
}

Item::Item(string name, int price, int quantity) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
}

Item& Item::setName(string name) {
	this->name = name;
	return *this;
}

Item& Item::setPrice(int price) {
	this->price = price;
	return *this;
}

Item& Item::setRarity(string rarity) {
	this->rarity = rarity;
	return *this;
}

Item& Item::setQuantity(int quantity) {
	this->quantity = quantity;
	return *this;
}

Item& Item::setType(string type) {
	this->type = type;
	return *this;
}

Item& Item::stackAble(bool boolean) {
	stackable = boolean;
	return *this;
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

int Item::getQuantity() const {
	return quantity;
}

string Item::getType() const {
	return type;
}

bool Item::isStackable() const {
	return stackable;
}

Sword::Sword() {
	damage = 0;
	setType("Weapon");
	stackAble(false);
}

Sword::Sword(string name, int price, int damage) : Item(name, price, 1) {
	this->damage = damage;
	setType("Weapon");
	stackAble(false);
}

void Sword::setDamage(int dmg) {
	damage = dmg;
}

int Sword::getDamage() const {
	return damage;
}

Armor::Armor() {
	defense = 0;
	setType("Armor");
	stackAble(false);
}

Armor::Armor(string name, int price, int defense) : Item(name, price, 1) {
	this->defense = defense;
	setType("Armor");
	stackAble(false);
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
	stackAble(true);
}

Potion::Potion(string name, int price, int health) : Item(name, price, 1) {
	this->health = health;
	setType("Potion");
	stackAble(true);
}
																																																
void Potion::setHealth(int hp) {
	health = hp;
}

int Potion::getHealth() const {
	return health;
}


