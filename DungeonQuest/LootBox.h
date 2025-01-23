#pragma once
#include"Inventory.h"

class LootBox {
	int number_of_rolls = 0;

	int coins = 0;
	int gems = 0;
	float xp = 0;
	Inventory available_items;

	int obtained_coins = 0;
	int obtained_gems = 0;
	float obtained_xp = 0;
	Inventory obtained_items;

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
	void draw_item(int item_type);
	void roll();

public:
	LootBox();

	LootBox& setCoins(int coins);
	LootBox& setGems(int gems);
	LootBox& setXP(float xp);
	LootBox& setItemsPool(Inventory items);

	LootBox& setNumberOfRolls(int number_of_rolls);
	LootBox& setItemAppearanceChances(int none, int sword, int armor, int potion);
	LootBox& setItemRarityWeights(vector<int> sword, vector<int> armor, vector<int> potion);

	int getCoins() const;
	int getGems() const;
	float getXP() const;
	vector<Sword> getSwords() const;
	vector<Armor> getArmors() const;
	vector<Potion> getPotions() const;

	void setup();
	void display_loot();

	void clear();
};