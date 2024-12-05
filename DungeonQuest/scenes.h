#pragma once
#include<iostream>
#include <string>
#include<vector>
#include"MenuSelection.h"
#include"display_components.h"
#include"Player.h"
using namespace std;


void mainScene(Player player);
void startMenuScene(Player player);
void selectPlayerFileScene(Player player);
void newSaveCreationScene(Player player, string file_path);
void loadSaveDataScene(Player player, string file_path);
void optionsScene(Player);
void confirmClearDataScene(Player player);
void playerDataClearedScene(Player player);
void gameScene(Player player);
void playerStatsScene(Player player);