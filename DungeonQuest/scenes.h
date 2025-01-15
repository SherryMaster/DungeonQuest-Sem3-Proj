#pragma once
#include<iostream>
#include <string>
#include<vector>
#include"MenuSelection.h"
#include"display_components.h"
#include"Player.h"
#include"DataManager.h"
#include"fstream"
#include"conio.h"
using namespace std;

void testing(Player player); // For development purposes only.
void config_generation_scene(Player player); // Where the Configs for the items and game objects are generated
void generate_sword_scene(Player player); // Generates Sword Files uses the configs in the folder. Chosen in config_generation_scene.
void generate_armor_scene(Player player); // Generates Armor Files using the config in the folder. Chose in config_generation_scene.
void generate_potion_scene(Player player); // Generates Potion Files using the config in the folder. Chose in config_generation_scene.

void item_obtain_scene(Player player); // The scene for testing purpose where the player can obtain items. chosen in testing.

void mainScene(Player player); // The first scene the player see. // Chosen when exiting the gameScene. 
void selectPlayerFileScene(Player player); // The scene where the player selects the file to load. // Chosen in mainScene.
void newSaveCreationScene(Player player, string file_path); // The scene where the player creates a new save file. // Chosen in selectPlayerFileScene.
void loadSaveDataScene(Player player, string file_path); // The scene where the player loads the save file. // Chosen in selectPlayerFileScene.
void startMenuScene(Player player); // When player is selected this becomes the main menu. // Chosen through player selecion in newSaveCreationScene and loadSaveDataScene + exiting in gameScene.
void optionsScene(Player player); // When player selects the options menu. // Chosen in startMenuScene.
void confirmClearDataScene(Player player); // When player selects the clear data option. // Chosen in optionsScene.
void playerDataClearedScene(Player player); // When player confirms the clear data option. // Chosen in confirmClearDataScene.
void gameScene(Player player); // The main game scene. // Chosen in startMenuScene + exiting the optionsScene and playerStatsScene.
void inventoryScene(Player player); // The scene where the player can see their inventory. // Chosen in startMenuScene.
void playerStatsScene(Player player); // The scene where the player can see their stats. // Chosen in startMenuScene.