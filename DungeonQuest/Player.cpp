#include"Player.h"

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