#pragma once
#include<iostream>
#include <string>
#include<vector>
#include"MenuSelection.h"
#include"display_components.h"
#include"Player.h"
using namespace std;

void testing(Player player); // For development purposes only.
void generate_swords(); // Generates Sword Files uses the configs in the folder.

void mainScene(Player player); // The first scene the player see. // Chosen when exiting the gameScene. 
void selectPlayerFileScene(Player player); // The scene where the player selects the file to load. // Chosen in mainScene.
void newSaveCreationScene(Player player, string file_path); // The scene where the player creates a new save file. // Chosen in selectPlayerFileScene.
void loadSaveDataScene(Player player, string file_path); // The scene where the player loads the save file. // Chosen in selectPlayerFileScene.
void startMenuScene(Player player); // When player is selected this becomes the main menu. // Chosen through player selecion in newSaveCreationScene and loadSaveDataScene + exiting in gameScene.
void optionsScene(Player player); // When player selects the options menu. // Chosen in startMenuScene.
void confirmClearDataScene(Player player); // When player selects the clear data option. // Chosen in optionsScene.
void playerDataClearedScene(Player player); // When player confirms the clear data option. // Chosen in confirmClearDataScene.
void gameScene(Player player); // The main game scene. // Chosen in startMenuScene + exiting the optionsScene and playerStatsScene.
void playerStatsScene(Player player); // The scene where the player can see their stats. // Chosen in startMenuScene.