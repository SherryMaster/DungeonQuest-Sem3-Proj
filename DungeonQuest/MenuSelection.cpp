#include <iostream>
#include <string>
#include <vector>
#include "MenuSelection.h"
#include <conio.h>
using namespace std;

MenuItem::MenuItem() {
    itemName = "MenuItem";
    value = 0;
}

MenuItem::MenuItem(string name) {
    itemName = name;
    value = 0;
    value_externally_set = false;
}

MenuItem::MenuItem(string name, int value) {
    itemName = name;
    this->value = value;
    value_externally_set = true;
}

MenuItem::~MenuItem() {
}

void MenuItem::setItemName(string name) {
    itemName = name;
}

void MenuItem::setValue(int value) {
    this->value = value;
}

void MenuItem::setMenu(Menu menu) {
    this->menu = menu;
}

string MenuItem::getItemName() const {
    return itemName;
}

int MenuItem::getValue() const {
    return value;
}

Menu MenuItem::getMenu() const {
    return menu;
}

Menu::Menu() {
    title = "Default";
}

Menu::Menu(string title, vector<MenuItem> items) : title(title), items(items) {
    for (auto& item : this->items) {
        item.setMenu(*this);
        if (!item.value_externally_set) {
            //item.value = this->items.
        }
    }
}

Menu::~Menu() {
}

void Menu::addItem(MenuItem item) {
    items.push_back(item);
}

void Menu::removeItem(MenuItem item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getItemName() == item.getItemName()) {
            items.erase(it);
            break;
        }
    }
}

MenuItem Menu::getItemAt(int index) const {
    if (index >= 0 && index < items.size()) {
        return items[index];
    }
    else {
        throw out_of_range("Index out of range");
    }
}

int Menu::getTotalItems() const {
    return items.size();
}

std::string Menu::getTitle() const {
    return title;
}

MenuManager::MenuManager() {
    selection_pos = 0;
}

int MenuManager::handleMenuSelection(Menu& menu) {
    
    bool arrow_mode = false;

    int action_mode = 0;
    
    while (true) {
        int key = _getch();

        action_mode = 0;

        if (arrow_mode) {

            switch (key)
            {
            case 72: //up
                selection_pos -= 1;
                if (selection_pos < 0) {
                    selection_pos = menu.items.size() - 1;
                }
                action_mode = 1;
                break;
			case 80: //down
				selection_pos += 1;
				if (selection_pos >= menu.items.size()) {
					selection_pos = 0;
				}
                action_mode = 2;
                break;
            default:
                break;
            }
        }

        // handling arrow keys
        if (key == 13) {
            action_mode = 5;
        }

        if (key == 224) { // handling arrow keys
            arrow_mode = true;
        }

        if (action_mode != 0) {
            return action_mode;
        }
    }

    return -1;
}

void MenuManager::reset() {
    selection_pos = 0;
}


void MenuManager::displayMenu(Menu& menu) {
	for (int i = 0; i < menu.getTotalItems(); i++) {
		if (i == selection_pos) {
			cout << ">>";
		}
		else {
			cout << "  ";
		}
		cout << menu.getItemAt(i).getItemName() << endl;
	}
}

int MenuManager::getSelectionPos() const {
	return selection_pos;
}

int MenuManager::getSelectionValue(Menu& menu) const {
	return menu.getItemAt(selection_pos).getValue();
}
