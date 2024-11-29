#pragma once
#include"Entity.h"
#include"DataManager.h"

class Player : public Entity {
	int coins;
	int gems;

	int experience_level;
	float experience;
	float experienceToNextLevel;

	float expGainMultiplier = 1.25;

	DataManager dataManager;
	string playerDataPath = "player_data_1.txt";

public:
	Player();
	~Player();

	void setCoins(int coins);
	void setGems(int gems);
	void setLevel(int experience_level);
	void setExperience(int experience);
	void setPlayerDataPath(string path);

	int getCoins() const;
	int getGems() const;
	int getLevel() const;
	int getExperience() const;
	string getPlayerDataPath() const;

	void adjustCoins(int coins);
	void adjustGems(int gems);
	void gainExperience(int experience);
	void levelUp();

	void savePlayerData();
	void loadPlayerData();

};