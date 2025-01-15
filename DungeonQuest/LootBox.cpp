#include"LootBox.h"

// utility functions
int LootBox::sum_of_weights(vector<int> weights) {
	int sum = 0;
	for (int i = 0; i < weights.size(); i++) {
		sum += weights[i];
	}

	return sum;
}

int LootBox::draw_item_index(vector<int> weights, int total_weight) {
	int random_number = rand() % total_weight;
	int index = 0;
	int max_elements = weights.size();
	int total = total_weight;
	while (true) {
		total -= weights[index];
		if (total < 0) {
			return index;
		}

		index++;
		if (index == max_elements) {
			index = 0;
		}
	}
}


// main functions

LootBox::LootBox() {
	coins = 0;
	gems = 0;
	xp = 0;

	obtained_coins = 0;
	obtained_gems = 0;
	obtained_xp = 0;
}

LootBox& LootBox::setCoins(int coins) {
	this->coins = coins;
	return *this;
}

LootBox& LootBox::setGems(int gems) {
	this->gems = gems;
	return *this;
}

LootBox& LootBox::setXP(float xp) {
	this->xp = xp;
	return *this;
}

LootBox& LootBox::setSwordsPool(vector<Sword> sword_list) {
	swords = sword_list;
	return *this;
}

LootBox& LootBox::setSArmorsPool(vector<Armor> armor_list) {
	armors = armor_list;
	return *this;
}

LootBox& LootBox::setPotionsPool(vector<Potion> potion_list) {
	potions = potion_list;
	return *this;
}

LootBox& LootBox::addSword(Sword sword) {
	swords.push_back(sword);
	return *this;
}

LootBox& LootBox::addArmor(Armor armor) {
	armors.push_back(armor);
	return *this;
}

LootBox& LootBox::addPotion(Potion potion) {
	potions.push_back(potion);
	return *this;
}

LootBox& LootBox::setNumberOfRolls(int number_of_rolls) {
	this->number_of_rolls = number_of_rolls;
	return *this;
}

LootBox& LootBox::setItemChances(int none, int sword, int armor, int potion) {
	item_weights = { none, sword, armor, potion };
	return *this;
}

LootBox& LootBox::setItemRarityWeights(vector<int> sword, vector<int> armor, vector<int> potion) {
	sword_rarity_weights = sword;
	armor_rarity_weights = armor;
	potion_rarity_weights = potion;
	return *this;
}

int LootBox::getCoins() const {
	return obtained_coins;
}

int LootBox::getGems() const {
	return obtained_gems;
}

float LootBox::getXP() const {
	return obtained_xp;
}

vector<Sword> LootBox::getSwords() const {
	return obtained_swords;
}

vector<Armor> LootBox::getArmors() const {
	return obtained_armors;
}

vector<Potion> LootBox::getPotions() const {
	return obtained_potions;
}

void LootBox::setup() {
	obtained_coins = coins * (1 - coins_deviation) + (rand() % (int)(coins * coins_deviation * 2));
	obtained_gems = gems * (1 - gems_deviation) + (rand() % (int)(gems * gems_deviation * 2));
	obtained_xp = xp * (1 - xp_deviation) + (rand() % (int)(xp * xp_deviation * 2));
}

