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
	for (int i = 0; i < potions.size(); i++) {
		if (potions[i].getName() == potion.getName()) {
			potions[i].setQuantity(potions[i].getQuantity() + potion.getQuantity());
			return;
		}
	}
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

void Inventory::clear() {
	swords.clear();
	armors.clear();
	potions.clear();
}

Item::Item() {
	name = "";
	price = 0;
	quantity = 1;
	stackable = false;
}

Item::Item(string name, int price, int quantity) {
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	stackable = false;
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

Sword::Sword(string name) {
	setType("Weapon");
	stackAble(false);

	dm.loadData("Configs\\Inventory\\Swords\\" + name + ".txt");

	setName(dm.getData("Name"));
	int rarity = stoi(dm.getData("Rarity"));
	setRarity(rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic")));
	setDamage(stoi(dm.getData("Damage")));
	setDurability(stoi(dm.getData("Durability")));
	setPrice(0);
}

Sword& Sword::setDamage(int dmg) {
	damage = dmg;
	return *this;
}

Sword& Sword::setDurability(int dur) {
	durability = dur;
	return *this;
}

int Sword::getDamage() const {
	return damage;
}

int Sword::getDurability() const {
	return durability;
}

Armor::Armor() {
	defense = 0;
	setType("Armor");
	stackAble(false);
}

Armor::Armor(string name) {
	setType("Armor");
	stackAble(false);

	dm.loadData("Configs\\Inventory\\Armors\\" + name + ".txt");


	setName(dm.getData("Name"));
	int rarity = stoi(dm.getData("Rarity"));
	setRarity(rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic")));
	setDefense(stoi(dm.getData("Defense")));
	setDurability(stoi(dm.getData("Durability")));
	setPrice(0);
}

Armor& Armor::setDefense(int def) {
	defense = def;
	return *this;
}

Armor& Armor::setDurability(int dur) {
	durability = dur;
	return *this;
}

int Armor::getDefense() const {
	return defense;
}

int Armor::getDurability() const {
	return durability;
}

Potion::Potion() {
	health = 0;
	setType("Potion");
	stackAble(true);
}

Potion::Potion(string name) {
	this->health = health;
	setType("Potion");
	stackAble(true);

	dm.loadData("Configs\\Inventory\\Potions\\" + name + ".txt");
	setName(dm.getData("Name"));
	int rarity = stoi(dm.getData("Rarity"));
	setRarity(rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic")));
	setHealth(stoi(dm.getData("Heal")));
	setPrice(0);
}
																																																
Potion& Potion::setHealth(int hp) {
	health = hp;
	return *this;
}

int Potion::getHealth() const {
	return health;
}


