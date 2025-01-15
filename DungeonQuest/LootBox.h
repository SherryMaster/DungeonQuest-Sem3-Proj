#pragma once
#include"Inventory.h"

class LootBox {
	int number_of_rolls = 0;

	int coins = 0;
	int gems = 0;
	float xp = 0;
	vector<Sword> swords;
	vector<Armor> armors;
	vector<Potion> potions;

	int obtained_coins = 0;
	int obtained_gems = 0;
	float obtained_xp = 0;
	vector<Sword> obtained_swords;
	vector<Armor> obtained_armors;
	vector<Potion> obtained_potions;

	/// luck parameters

	vector<int> item_weights; // nothing, sword, armor, potion
	
	// common, uncommon, rare, epic : weights
	vector<int> sword_rarity_weights;
	vector<int> armor_rarity_weights;
	vector<int> potion_rarity_weights;

	float coins_deviation = 0.1;
	float gems_deviation = 0.1;
	float xp_deviation = 0.2;


	// private utilities

	int sum_of_weights(vector<int> weights);
	int draw_item_index(vector<int> weights, int total_weight);

	// drawing items
	void draw_sword();

public:
	LootBox();

	LootBox& setCoins(int coins);
	LootBox& setGems(int gems);
	LootBox& setXP(float xp);
	LootBox& setSwordsPool(vector<Sword> sword_list);
	LootBox& setSArmorsPool(vector<Armor> armor_list);
	LootBox& setPotionsPool(vector<Potion> potion_list);

	LootBox& addSword(Sword sword);
	LootBox& addArmor(Armor armor);
	LootBox& addPotion(Potion potion);

	LootBox& setNumberOfRolls(int number_of_rolls);
	LootBox& setItemChances(int none, int sword, int armor, int potion);
	LootBox& setItemRarityWeights(vector<int> sword, vector<int> armor, vector<int> potion);

	int getCoins() const;
	int getGems() const;
	float getXP() const;
	vector<Sword> getSwords() const;
	vector<Armor> getArmors() const;
	vector<Potion> getPotions() const;

	void setup();
	//void roll_item();
};