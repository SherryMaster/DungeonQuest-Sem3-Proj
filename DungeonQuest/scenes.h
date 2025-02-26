#pragma once
#include<iostream>
#include <string>
#include<vector>
#include<fstream>
#include<conio.h>
#include"MenuSelection.h"
#include"display_components.h"
#include"Player.h"
#include"DataManager.h"
#include"LootBox.h"
using namespace std;

void testing(Player& player); // For development purposes only.
void config_managment_scene(Player& player); // Where the Configs for the items and game objects are generated
	void sword_management_scene(Player& player); // Where developer has options to manage swords data.
		void swords_list_scene(Player& player); // Where developer can view and choose to edit the sword files with ease! Chosen in sword_management_scene.
		void selected_sword_scene(Player& player, string sword_name); // Where the developer can manage the selected sword file. Chosen in swords_list_scene.
		void sword_edit_scene(Player& player, string sword_name); // Where developer can edit the sword files. Chosen in selected_sword_scene.
		void generate_sword_scene(Player& player); // Generates Sword Files uses the configs in the folder. Chosen in config_managment_scene.
	void armor_management_scene(Player& player); // Where developer has options to manage armor data.
		void armors_list_scene(Player& player); // Where developer can view and choose to edit the armor files with ease! Chosen in armor_management_scene.
		void selected_armor_scene(Player& player, string armor_name); // Where the developer can manage the selected armor file. Chosen in armors_list_scene.
		void armor_edit_scene(Player& player, string armor_name); // Where developer can edit the armor files. Chosen in selected_armor_scene.
		void generate_armor_scene(Player& player); // Generates Armor Files using the config in the folder. Chose in config_managment_scene.
	void potion_management_scene(Player& player); // Where developer has options to manage potion data.
		void potions_list_scene(Player& player); // Where developer can view and choose to edit the potion files with ease! Chosen in potion_management_scene.
		void selected_potion_scene(Player& player, string potion_name); // Where the developer can manage the selected potion file. Chosen in potions_list_scene.
		void potion_edit_scene(Player& player, string potion_name); // Where developer can edit the potion files. Chosen in selected_potion_scene.
		void generate_potion_scene(Player& player); // Generates Potion Files using the config in the folder. Chose in config_managment_scene.

void item_obtain_scene(Player& player); // The scene for testing purpose where the player can obtain items. chosen in testing.

void mainScene(Player& player); // The first scene the player see. // Chosen when exiting the gameScene. 
void selectPlayerFileScene(Player& player); // The scene where the player selects the file to load. // Chosen in mainScene.
void newSaveCreationScene(Player& player, string file_path); // The scene where the player creates a new save file. // Chosen in selectPlayerFileScene.
void loadSaveDataScene(Player& player, string file_path); // The scene where the player loads the save file. // Chosen in selectPlayerFileScene.
void startMenuScene(Player& player); // When player is selected this becomes the main menu. // Chosen through player selecion in newSaveCreationScene and loadSaveDataScene + exiting in gameScene.
void optionsScene(Player& player); // When player selects the options menu. // Chosen in startMenuScene.
void confirmClearDataScene(Player& player); // When player selects the clear data option. // Chosen in optionsScene.
void playerDataClearedScene(Player& player); // When player confirms the clear data option. // Chosen in confirmClearDataScene.
void gameScene(Player& player); // The main game scene. // Chosen in startMenuScene + exiting the optionsScene and playerStatsScene.
void inventoryScene(Player& player); // The scene where the player can see their inventory. // Chosen in startMenuScene.
	void swordInventoryScene(Player& player); // The scene where the player can see their sword inventory. // Chosen in inventoryScene.
	void armorInventoryScene(Player& player); // The scene where the player can see their armor inventory. // Chosen in inventoryScene.
	void potionInventoryScene(Player& player); // The scene where the player can see their potion inventory. // Chosen in inventoryScene.
void playerStatsScene(Player& player); // The scene where the player can see their stats. // Chosen in startMenuScene.