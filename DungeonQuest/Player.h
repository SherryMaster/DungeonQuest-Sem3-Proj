#pragma once
#include"Entity.h"
#include"DataManager.h"

class Player : public Entity {
	// Currency
	int coins;
	int gems;

	// stats
	int health;
	int maxHealth;
	int experience_level;
	float experience;
	float experience_to_next_level;

	// dungeon stats
	bool forest_dungeon_cleared = false;
	bool jungle_dungeon_cleared = false;
	bool cavern_dungeon_cleared = false;
	bool underground_dungeon_cleared = false;
	bool volcanic_dungeon_cleared = false;

	int total_enemies_killed = 0;

	int forest_enemies_killed = 0;

	int jungle_enemies_killed = 0;
	
	int cavern_enemies_killed = 0;
	
	int underground_enemies_killed = 0;
	
	int volcano_enemies_killed = 0;


	float next_level_exp_multiplier = 1.25;

	DataManager dataManager;
	string player_data_path = "player_data_1.txt";

public:
	Player();
	~Player();

	void setCoins(int coins);
	void setGems(int gems);
	void setHealth(int health);
	void setMaxHealth(int maxHealth);
	void setLevel(int experience_level);
	void setExperience(int experience);
	void setExperienceToNextLevel(float experience_to_next_level);
	void setPlayerDataPath(string path);

	int getCoins() const;
	int getGems() const;
	int getHealth() const;
	int getMaxHealth() const;
	int getLevel() const;
	int getExperience() const;
	int getExperienceToNextLevel() const;
	string getPlayerDataPath() const;

	void adjustCoins(int coins);
	void adjustGems(int gems);
	void gainExperience(int experience);
	void levelUp();

	void savePlayerData();
	void loadPlayerData();
	void deletePlayerData();

};