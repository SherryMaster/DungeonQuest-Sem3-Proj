#include "LootBox.h"

// utility functions
int LootBox::sum_of_weights(vector<int> weights) {
    int sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        sum += weights[i];
    }

    return sum;
}

int LootBox::draw_item_index(vector<int> weights, int total_weight) {
    int random_number = rand() % total_weight;
    int index = 0;
    int max_elements = static_cast<int>(weights.size()); // Fix for Problem 4
    int total = random_number;
    while (true) {
        total -= weights[index];
        if (total <= 0) {
            return index;
        }

        index++;
        if (index == max_elements) {
            index = 0;
        }
    }
}

void LootBox::draw_item(int item_type) {
    switch (item_type) {
    case 0:
        break;
    case 1: {
        int sword_index = draw_item_index(sword_rarity_weights, sum_of_weights(sword_rarity_weights));
        obtained_items.addSword(available_items.getSwords()[sword_index]);
        break;
    }
    case 2: {
        int armor_index = draw_item_index(armor_rarity_weights, sum_of_weights(armor_rarity_weights));
        obtained_items.addArmor(available_items.getArmors()[armor_index]);
        break;
    }
    case 3: {
        int potion_index = draw_item_index(potion_rarity_weights, sum_of_weights(potion_rarity_weights));
        obtained_items.addPotion(available_items.getPotions()[potion_index]);
        break;
    }
    }
}

void LootBox::roll() {
    int item_type = draw_item_index(item_weights, sum_of_weights(item_weights));
    draw_item(item_type);
}

// main functions

LootBox::LootBox() {
    coins = 0;
    gems = 0;
    xp = 0;

    obtained_coins = 0;
    obtained_gems = 0;
    obtained_xp = 0;
}

LootBox& LootBox::setCoins(int coins) {
    this->coins = coins;
    return *this;
}

LootBox& LootBox::setGems(int gems) {
    this->gems = gems;
    return *this;
}

LootBox& LootBox::setXP(float xp) {
    this->xp = xp;
    return *this;
}

LootBox& LootBox::setItemsPool(Inventory items) {
    available_items = items;
    return *this;
}

LootBox& LootBox::setNumberOfRolls(int number_of_rolls) {
    this->number_of_rolls = number_of_rolls;
    return *this;
}

LootBox& LootBox::setItemAppearanceChances(int none, int sword, int armor, int potion) {
    item_weights = { none, sword, armor, potion };
    return *this;
}

LootBox& LootBox::setItemRarityWeights(vector<int> sword, vector<int> armor, vector<int> potion) {
    sword_rarity_weights = sword;
    armor_rarity_weights = armor;
    potion_rarity_weights = potion;
    return *this;
}

int LootBox::getCoins() const {
    return obtained_coins;
}

int LootBox::getGems() const {
    return obtained_gems;
}

float LootBox::getXP() const {
    return obtained_xp;
}

vector<Sword> LootBox::getSwords() const {
    return obtained_items.getSwords();
}

vector<Armor> LootBox::getArmors() const {
    return obtained_items.getArmors();
}

vector<Potion> LootBox::getPotions() const {
    return obtained_items.getPotions();
}

void LootBox::setup() {
    obtained_coins = static_cast<int>(coins * (1 - coins_deviation) + (rand() % static_cast<int>(coins * coins_deviation * 2))); // Fix for Problem 3
    obtained_gems = static_cast<int>(gems * (1 - gems_deviation) + (rand() % static_cast<int>(gems * gems_deviation * 2))); // Fix for Problem 5
    obtained_xp = xp * (1 - xp_deviation) + (rand() % static_cast<int>(xp * xp_deviation * 2));

    for (int i = 0; i < number_of_rolls; i++) {
        roll();
    }
}

void LootBox::display_loot() {
    cout << "You have obtained the Following Items: " << endl;
    cout << "Coins: " << obtained_coins << endl;
    cout << "Gems: " << obtained_gems << endl;
    cout << "XP: " << obtained_xp << endl;
    cout << endl;
    vector<Sword> swords = obtained_items.getSwords();
    vector<Armor> armors = obtained_items.getArmors();
    vector<Potion> potions = obtained_items.getPotions();

    cout << "Swords: " << endl;
    for (int i = 0; i < swords.size(); i++) {
        cout << swords[i].getName() << " - " << swords[i].getRarity() << endl;
    }
    cout << endl;

    cout << "Armors: " << endl;
    for (int i = 0; i < armors.size(); i++) {
        cout << armors[i].getName() << " - " << armors[i].getRarity() << endl;
    }
    cout << endl;

    cout << "Potions: " << endl;
    for (int i = 0; i < potions.size(); i++) {
        cout << potions[i].getName() << " - " << potions[i].getRarity() << endl;
    }
}

void LootBox::clear() {
    obtained_coins = 0;
    obtained_gems = 0;
    obtained_xp = 0;
    obtained_items.clear();
}
