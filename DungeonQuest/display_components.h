#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

string set_space_H(int amount = 0);
string set_space_V(int amount = 0);
string word_pattern(string word, int times = 1);
string headerBoard(vector<string> inner_content, int space_from_left = 0, int space_from_above = 0, int min_size = 13);
string playerInfoHeader(Player& player);
string progressBar(float current, float max, int width = 20);
