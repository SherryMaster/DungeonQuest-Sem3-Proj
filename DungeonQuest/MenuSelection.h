#pragma once
#include <vector>
#include <string>
using namespace std;

class Menu;
class MenuItem;

class Menu {
    string title;
    vector<MenuItem> items;
public:
	Menu();
	Menu(string title, vector<MenuItem> items);
    ~Menu();

    void addItem(MenuItem item);
    void removeItem(MenuItem item);

    MenuItem getItemAt(int index) const;
    int getTotalItems() const;
    string getTitle() const;

    friend class MenuManager;
};

class MenuItem {
	Menu menu;
    string itemName;
    int value;
	bool value_externally_set;
public:
    MenuItem();
    MenuItem(string name);
    MenuItem(string name, int value);
    ~MenuItem();

    void setItemName(string name);
    void setValue(int value);
	void setMenu(Menu menu);

    string getItemName() const;
    int getValue() const;
	Menu getMenu() const;

	friend class Menu;
};

class MenuManager {
    int selection_pos;
public:
    MenuManager();

    int handleMenuSelection(Menu& menu);
	void displayMenu(Menu& menu);

	int getSelectionPos() const;
    int getSelectionValue(Menu& menu) const;

    void reset();
};