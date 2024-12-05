#include"Player.h"

using namespace std;

Player::Player() {
	coins = 0;
	gems = 0;
	experience_level = 1;
	experience = 0;
	experience_to_next_level = 100;
	dataManager.setDataRoot(dataManager.getDataRoot() + "\\" + "Player");
}

Player::~Player() {
}

void Player::setCoins(int coins) {
	this->coins = coins;
}

void Player::setGems(int gems) {
	this->gems = gems;
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

string Player::getPlayerDataPath() const {
	return dataManager.getDataRoot() + "\\" + player_data_path;
}

int Player::getCoins() const {
	return coins;
}

int Player::getGems() const {
	return gems;
}

int Player::getLevel() const {
	return experience_level;
}

int Player::getExperience() const {
	return experience;
}

int Player::getExperienceToNextLevel() const
{
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
	vector<string> keys = { "name", "hp", "max_hp", "coins", "gems", "experience_level", "experience", "experienceToNextLevel", "expGainMultiplier"};
	vector<string> values = { getName(), to_string(getHealth()), to_string(getMaxHealth()), to_string(coins), to_string(gems), to_string(experience_level), to_string(experience), to_string(experience_to_next_level), to_string(next_level_exp_multiplier)};

	dataManager.clearData();
	for (int i = 0; i < keys.size(); i++) {
		dataManager.addData(keys[i], values[i]);
	}
	dataManager.saveData(player_data_path);
}

void Player::loadPlayerData() {
	dataManager.loadData(player_data_path);

	if (!dataManager.fileExists(player_data_path)) {
		savePlayerData();
		return;
	}

	vector<string> keys = dataManager.getKeys();
	vector<string> values = dataManager.getValues();

	for (int i = 0; i < keys.size(); i++) {
		if (keys[i] == "name") {
			setName(values[i]);
		}
		else if (keys[i] == "hp") {
			setHealth(stoi(values[i]));
		}
		else if (keys[i] == "max_hp") {
			setMaxHealth(stoi(values[i]));
		}
		else if (keys[i] == "coins") {
			coins = stoi(values[i]);
		}
		else if (keys[i] == "gems") {
			gems = stoi(values[i]);
		}
		else if (keys[i] == "experience_level") {
			experience_level = stoi(values[i]);
		}
		else if (keys[i] == "experience") {
			experience = stof(values[i]);
		}
		else if (keys[i] == "experienceToNextLevel") {
			experience_to_next_level = stof(values[i]);
		}
		else if (keys[i] == "expGainMultiplier") {
			next_level_exp_multiplier = stof(values[i]);
		}
	}
}

void Player::deletePlayerData() {
	dataManager.deleteData(player_data_path);
}