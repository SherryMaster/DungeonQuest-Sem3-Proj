#include"Player.h"
#include<fstream>
using namespace std;

Player::Player() {
	coins = 0;
	gems = 0;
	health = 100;
	maxHealth = 100;
	experience_level = 1;
	experience = 0;
	experience_to_next_level = 100;
	dataManager.setDataRoot(dataManager.getDataRoot() + "\\" + "Players");
}

Player::~Player() {
}

void Player::setCoins(int coins) {
	this->coins = coins;
}

void Player::setGems(int gems) {
	this->gems = gems;
}

void Player::setHealth(int health) {
	this->health = health;
}

void Player::setMaxHealth(int maxHealth) {
	this->maxHealth = maxHealth;
}

void Player::setLevel(int experience_level) {
	this->experience_level = experience_level;
}

void Player::setExperience(int experience) {
	this->experience = experience;
}

void Player::setExperienceToNextLevel(float experience_to_next_level)
{
	this->experience_to_next_level = experience_to_next_level;
}

void Player::setPlayerDataPath(string path) {
	this->player_data_path = path;
}

void Player::setPlayerNum(int num) {
	this->player_num = num;
	player_data_path = "Player " + to_string(num);
}

string Player::getPlayerDataPath() const {
	return dataManager.getDataRoot() + "\\" + player_data_path;
}

int Player::getCoins() const {
	return coins;
}

int Player::getGems() const {
	return gems;
}

int Player::getHealth() const {
	return health;
}

int Player::getMaxHealth() const {
	return maxHealth;
}

int Player::getLevel() const {
	return experience_level;
}

int Player::getExperience() const {
	return experience;
}

int Player::getExperienceToNextLevel() const{
	return experience_to_next_level;
}

void Player::adjustCoins(int coins) {
	this->coins += coins;
}

void Player::adjustGems(int gems) {
	this->gems += gems;
}

void Player::gainExperience(int experience) {
	this->experience += experience;
	if (this->experience >= experience_to_next_level) {
		levelUp();
	}
}

void Player::levelUp() {
	experience_level++;
	experience = 0;
	experience_to_next_level *= next_level_exp_multiplier;
}

void Player::setupInventory() {
	DataManager dm;
	if (!dm.fileExists(dataManager.getDataRoot() + "inventory.txt")) {
		ofstream fout;
		ifstream fin;

		dm.loadData("Configs\\Inventory\\items count.txt");
		int swords = stoi(dm.getData("swords"));
		int swords_rarities[4] = { stoi(dm.getData("sword_common")), stoi(dm.getData("sword_uncommon")), stoi(dm.getData("sword_rare")), stoi(dm.getData("sword_epic")) };
		int armors = stoi(dm.getData("armors"));
		int armors_rarities[4] = { stoi(dm.getData("armor_common")), stoi(dm.getData("armor_uncommon")), stoi(dm.getData("armor_rare")), stoi(dm.getData("armor_epic")) };
		int potions = stoi(dm.getData("potions"));
		int potions_rarities[4] = { stoi(dm.getData("potion_common")), stoi(dm.getData("potion_uncommon")), stoi(dm.getData("potion_rare")), stoi(dm.getData("potion_epic")) };

		vector<Sword> sword_items;
		vector<Armor> armor_items;
		vector<Potion> potion_items;

		fin.open( dm.getDataRoot() + "\\Configs\\Inventory\\all item list.txt");
		for (int i = 0; i < (swords + armors + potions); i++) {
			if (swords) {
				if (swords_rarities[0]) {
					Sword sword;
					sword.setName("Common Sword");
					sword.setPrice(10);
					sword.setRarity("Common");
					sword.setDamage(5);
					sword_items.push_back(sword);
					swords_rarities[0]--;
				}
				else if (swords_rarities[1]) {
					Sword sword;
					sword.setName("Uncommon Sword");
					sword.setPrice(20);
					sword.setRarity("Uncommon");
					sword.setDamage(10);
					sword_items.push_back(sword);
					swords_rarities[1]--;
				}
				else if (swords_rarities[2]) {
					Sword sword;
					sword.setName("Rare Sword");
					sword.setPrice(30);
					sword.setRarity("Rare");
					sword.setDamage(15);
					sword_items.push_back(sword);
					swords_rarities[2]--;
				}
				else if (swords_rarities[3]) {
					Sword sword;
					sword.setName("Epic Sword");
					sword.setPrice(40);
					sword.setRarity("Epic");
					sword.setDamage(20);
					sword_items.push_back(sword);
					swords_rarities[3]--;
				}
			}
		}
	}
}

void Player::savePlayerData() {
	vector<string> personal_stats_keys = { "name", "hp", "max_hp", "coins", "gems", "experience_level", "experience", "experienceToNextLevel", "expGainMultiplier" };
	vector<string> personal_stats_values = { getName(), to_string(getHealth()), to_string(getMaxHealth()), to_string(coins), to_string(gems), to_string(experience_level), to_string(experience), to_string(experience_to_next_level), to_string(next_level_exp_multiplier)};

	dataManager.clearData();
	for (int i = 0; i < personal_stats_keys.size(); i++) {
		dataManager.addData(personal_stats_keys[i], personal_stats_values[i]);
	}
	dataManager.saveData(player_data_path + "personal stats.txt");
}

void Player::loadPlayerData() {
	if (!dataManager.fileExists(player_data_path)) {
		savePlayerData();
		return;
	}
	
	dataManager.loadData(player_data_path + "personal stats.txt");

	vector<string> personal_stats_keys = dataManager.getKeys();
	vector<string> personal_stats_values = dataManager.getValues();

	for (int i = 0; i < personal_stats_keys.size(); i++) {
		if (personal_stats_keys[i] == "name") {
			setName(personal_stats_values[i]);
		}
		else if (personal_stats_keys[i] == "hp") {
			setHealth(stoi(personal_stats_values[i]));
		}
		else if (personal_stats_keys[i] == "max_hp") {
			setMaxHealth(stoi(personal_stats_values[i]));
		}
		else if (personal_stats_keys[i] == "coins") {
			coins = stoi(personal_stats_values[i]);
		}
		else if (personal_stats_keys[i] == "gems") {
			gems = stoi(personal_stats_values[i]);
		}
		else if (personal_stats_keys[i] == "experience_level") {
			experience_level = stoi(personal_stats_values[i]);
		}
		else if (personal_stats_keys[i] == "experience") {
			experience = stof(personal_stats_values[i]);
		}
		else if (personal_stats_keys[i] == "experienceToNextLevel") {
			experience_to_next_level = stof(personal_stats_values[i]);
		}
		else if (personal_stats_keys[i] == "expGainMultiplier") {
			next_level_exp_multiplier = stof(personal_stats_values[i]);
		}
	}
}

void Player::deletePlayerData() {
	dataManager.deleteData(player_data_path);
}