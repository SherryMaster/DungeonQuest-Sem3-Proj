#include"scenes.h"

void testing(Player& player) {

	vector<MenuItem> main_menu_items = { MenuItem("Config Management"), MenuItem("Loot Management Simulation"), MenuItem("Back")};
	Menu MainMenu("Test", main_menu_items);
	MenuManager menuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", "Testing Panel", "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(MainMenu);

		int mode = menuManager.handleMenuSelection(MainMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();
	if (choice == 0) {
		config_managment_scene(player);
	}
	else if (choice == 1) {
		item_obtain_scene(player);
	}
	else if (choice == 2) {
		mainScene(player);
	}
	else {
		return;
	}

}


void config_managment_scene(Player& player) {
	vector<MenuItem> config_items = { MenuItem("Sword Management"), MenuItem("Armor Management"), MenuItem("Potion Management"), MenuItem("Back") };
	Menu ConfigMenu("Config", config_items);
	MenuManager menuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", "Config", "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(ConfigMenu);

		int mode = menuManager.handleMenuSelection(ConfigMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();
	if (choice == 0) {
		sword_management_scene(player);
	}
	else if (choice == 1) {
		armor_management_scene(player);
	}
	else if (choice == 2) {
		potion_management_scene(player);
	}
	else if (choice == 3) {
		testing(player);
	}
	else {
		return;
	}
}

void sword_management_scene(Player& player) {
	vector<MenuItem> main_menu_items = { MenuItem("Swords List"), MenuItem("Generate Swords"), MenuItem("Back")};
	Menu MainMenu("Test", main_menu_items);
	MenuManager menuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", "Sword Management", "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(MainMenu);

		int mode = menuManager.handleMenuSelection(MainMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();
	if (choice == 0) {
		swords_list_scene(player);
	}
	else if (choice == 1) {
		generate_sword_scene(player);
	}
	else if (choice == 2) {
		config_managment_scene(player);
	}
	else {
		return;
	}
}

void swords_list_scene(Player& player) {
	DataManager swords_dm;
	swords_dm.setDataRoot(swords_dm.getDataRoot() + "\\Configs\\Inventory\\Swords");
	vector<MenuItem> sword_list = {};
	swords_dm.loadItemList("swords.txt");

	for (int i = 0; i < swords_dm.getItems().size(); i++) {
		sword_list.push_back(MenuItem(swords_dm.getItems()[i]));
	}
	sword_list.push_back(MenuItem("Back"));

	Menu swordMenu("Swords", sword_list);
	MenuManager menuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent = { "", "Edit Swords", "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(swordMenu);

		int mode = menuManager.handleMenuSelection(swordMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();

	if (choice == sword_list.size() - 1) {
		sword_management_scene(player);
	}
	else {
		selected_sword_scene(player, sword_list[choice].getItemName());
	}
}

void selected_sword_scene(Player& player, string sword_name) {
	vector<MenuItem> sword_menu_items = { MenuItem("Edit Sword"), MenuItem("Delete Sword"), MenuItem("Back") };
	vector<MenuItem> yes_no_menu_items = { MenuItem("Yes"), MenuItem("No") };
	Menu SwordMenu("Sword Menu", sword_menu_items);
	Menu YesNoMenu("Yes/No", yes_no_menu_items);
	MenuManager menuManager;

	// Render
	while (true) {
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", sword_name, "What do you want to do with this sword?" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(SwordMenu);

		int mode = menuManager.handleMenuSelection(SwordMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();

	if (choice == 0) {
		sword_edit_scene(player, sword_name);
	}
	else if (choice == 1) {
		menuManager.reset();
		while (true) {
		confirm_delete_render:
			system("cls");

			vector<string> headerBoardContent;
			headerBoardContent = { "", "Delete Sword", sword_name, "Are you sure you want to delete this sword?" };
			cout << headerBoard(headerBoardContent, 30, 5);

			cout << set_space_V(3);
			menuManager.displayMenu(YesNoMenu);

			int mode = menuManager.handleMenuSelection(YesNoMenu);

			if (mode == 5) { // Enter Pressed
				break;
			}
		}
		// End of Render

		int choice = menuManager.getSelectionPos();
		if (choice == 0) {
			DataManager swords_dm;
			swords_dm.setDataRoot(swords_dm.getDataRoot() + "\\Configs\\Inventory\\Swords");
			swords_dm.loadItemList("swords.txt");
			swords_dm.deleteData(sword_name + ".txt");
			swords_dm.removeItem(sword_name);
			swords_dm.saveItemList("swords.txt");
			swords_list_scene(player);
		}
		else {
			goto confirm_delete_render;
		}

	}
	else if (choice == 2) {
		swords_list_scene(player);
	}
	else {
		return;
	}
}

void sword_edit_scene(Player& player, string sword_name) {
	DataManager swords_dm;
	swords_dm.setDataRoot(swords_dm.getDataRoot() + "\\Configs\\Inventory\\Swords");

	swords_dm.loadData(sword_name + ".txt");
	string name = swords_dm.getData("Name");
	int damage = stoi(swords_dm.getData("Damage"));
	int durability = stoi(swords_dm.getData("Durability"));
	int rarity = stoi(swords_dm.getData("Rarity"));

	string rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));

	vector<MenuItem> edit_options = { MenuItem("Name"), MenuItem("Damage"), MenuItem("Durability"), MenuItem("Rarity"), MenuItem("Exit")};
	vector<MenuItem> rarity_menu = { MenuItem("Common"), MenuItem("Uncommon"), MenuItem("Rare"), MenuItem("Epic") };
	Menu  editMenu("Edit", edit_options), rarityMenu("Rarity", rarity_menu);
	MenuManager editMenuManager, rarityMenuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", "Edit Sword", sword_name, "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << "Name: " << name << endl;
		cout << "Damage: " << damage << endl;
		cout << "Durability: " << durability << endl;
		cout << "Rarity: " << rarity_text << endl;

		cout << set_space_V(3);

		cout << "What do you want to edit?" << endl << endl;
		editMenuManager.displayMenu(editMenu);
		int mode = editMenuManager.handleMenuSelection(editMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = editMenuManager.getSelectionPos();
	if (choice == 0) { // name edit
		cout << "Enter new name: ";
		getline(cin, name);
		goto render;
	}
	else if (choice == 1) { // damage edit
		cout << "Enter new damage: ";
		cin >> damage;
		goto render;
	}
	else if (choice == 2) { // durability edit
		cout << "Enter new durability: ";
		cin >> durability;
		goto render;
	}
	else if (choice == 3) { // rarity edit
		while (true) {
		rarity_render:
			system("cls");

			vector<string> headerBoardContent;
			headerBoardContent = { "", "Edit Sword", sword_name, "" };
			cout << headerBoard(headerBoardContent, 30, 5);

			cout << "Name: " << name << endl;
			cout << "Damage: " << damage << endl;
			cout << "Durability: " << durability << endl;
			cout << "Rarity: " << rarity_text << endl;

			cout << set_space_V(3);
			cout << "Select new rarity: " << endl << endl;
			rarityMenuManager.displayMenu(rarityMenu);
			int mode = rarityMenuManager.handleMenuSelection(rarityMenu);
			if (mode == 5) { // Enter Pressed
				rarity = rarityMenuManager.getSelectionPos() + 1;
				rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
				goto render;
			}
		}
	}
	else {
		swords_dm.addData("Name", name);
		swords_dm.addData("Damage", to_string(damage));
		swords_dm.addData("Durability", to_string(durability));
		swords_dm.addData("Rarity", to_string(rarity));

		swords_dm.saveData(sword_name + ".txt");

		swords_list_scene(player);
	}

}

void generate_sword_scene(Player& player) {
	DataManager swords_dm;
	
	swords_dm.setDataRoot(swords_dm.getDataRoot() + "\\Configs\\Inventory\\Swords");

	swords_dm.loadItemList("swords.txt");

	string name = "";
	int damage = 0;
	int durability = 0;
	int rarity = 0;

	string rarity_text = "";

	vector<MenuItem> rarity_menu = { MenuItem("Common"), MenuItem("Uncommon"), MenuItem("Rare"), MenuItem("Epic") };
	Menu rarityMenu("Rarity", rarity_menu);
	MenuManager menuManager;

	bool input_name = false;
	bool input_damage = false;
	bool input_durabilty = false;
	bool input_rarity = false;

	cin.ignore();
	// render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent = { "", "Enter details for sword", "" };
		cout << headerBoard(headerBoardContent, 25, 5);

		if (input_name && input_damage && input_durabilty && input_rarity) {
			vector<MenuItem> ok_menu_items = { MenuItem("Yes save it!"), MenuItem("No I want to change somthing!") };

			cout << "Sword Name: " << name << endl;
			cout << "Damage: " << damage << endl;
			cout << "Durability: " << durability << endl;
			cout << "Rarity: " << rarity_text << endl << endl;
			cout << "Is this Info OK or do you want to edit?" << endl << endl;

			Menu ok_menu("Confirm", ok_menu_items);
			menuManager.displayMenu(ok_menu);

			int mode = menuManager.handleMenuSelection(ok_menu);

			if (mode == 5) { // Enter Press
				int choice = menuManager.getSelectionPos();
				if (choice == 0) { // Yes, Save It!
					swords_dm.addData("Name", name);
					swords_dm.addData("Damage", to_string(damage));
					swords_dm.addData("Durability", to_string(durability));
					swords_dm.addData("Rarity", to_string(rarity));
					


					//goto render;
					break;
				}
				else if (choice == 1) { // No I want to change somthing!
					menuManager.reset();

					while (true) {
					choice_render:
						system("cls");

						vector<string> headerBoardContent = { "", "Enter details for sword", "" };
						cout << headerBoard(headerBoardContent, 25, 5);
						vector<MenuItem> choices = { MenuItem("Name"), MenuItem("Damage"), MenuItem("Durability"), MenuItem("Rarity") };

						Menu choiceMenu("Edit", choices);
						menuManager.displayMenu(choiceMenu);
						int mode = menuManager.handleMenuSelection(choiceMenu);

						if (mode == 5) { // Enter Press
							int choice = menuManager.getSelectionPos();

							if (choice == 0) { // Name
								cout << "Enter new name: ";
								getline(cin, name);
							}
							else if (choice == 1) { // damage
								cout << "Enter new damage: ";
								cin >> damage;
							}
							else if (choice == 2) { // durability
								cout << "Enter new durability: ";
								cin >> durability;
							}
							else if (choice == 3) { // rarity
								menuManager.reset();
								while (true) {
									system("cls");

									vector<string> headerBoardContent = { "", "Enter details for sword", "" };
									cout << headerBoard(headerBoardContent, 25, 5);

									cout << endl << endl;
									cout << "Select New Rarity: " << endl << endl;

									menuManager.displayMenu(rarityMenu);
									int mode = menuManager.handleMenuSelection(rarityMenu);
									if (mode == 5) { // Enter Pressed
										rarity = menuManager.getSelectionPos() + 1;
										rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
										menuManager.reset();
										break;
									}
								}
							}

							goto render;
						}
					}
				}
			}
		}

		if (!input_name) {
			cout << "Enter Sword name: ";
			getline(cin, name);
			if (swords_dm.fileExists(name + ".txt")) {
				swords_dm.loadData(name + ".txt");
				damage = stoi(swords_dm.getData("Damage"));
				durability = stoi(swords_dm.getData("Durability"));
				rarity = stoi(swords_dm.getData("Rarity"));
				rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
				input_damage = true;
				input_durabilty = true;
				input_rarity = true;
			}
			input_name = true;
		}
		else if (!input_damage) {
			cout << "Sword Name: " << name << endl;
			cout << "Enter Damage: ";
			cin >> damage;
			input_damage = true;
		}
		else if (!input_durabilty) {
			cout << "Sword Name: " << name << endl;
			cout << "Damage: " << damage << endl;
			cout << "Enter Durability: ";
			cin >> durability;
			input_durabilty = true;
		}
		else if (!input_rarity) {
			cout << "Sword Name: " << name << endl;
			cout << "Damage: " << damage << endl;
			cout << "Durability: " << durability << endl;
			cout << "Select Rarity: " << endl;
			menuManager.displayMenu(rarityMenu);
			int mode = menuManager.handleMenuSelection(rarityMenu);
			if (mode == 5) { // Enter Pressed
				rarity = menuManager.getSelectionPos() + 1;
				rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
				menuManager.reset();
				input_rarity = true;
			}
		}
	}
	// end of render

	cout << "Name of sword saved as: " << swords_dm.getData("Name") << endl;
	cout << "Damage of " << swords_dm.getData("Name") << " Saved as: " << swords_dm.getData("Damage") << endl;
	cout << "Durability of " << swords_dm.getData("Name") << " Saved as: " << swords_dm.getData("Durability") << endl;
	cout << "Rarity of " << swords_dm.getData("Name") << " Saved as: " << swords_dm.getData("Rarity") << endl;

	swords_dm.saveData(name + ".txt");
	swords_dm.addItem(name);
	swords_dm.saveItemList("swords.txt");

	cout << endl << "Press any key to continue...";
	_getch();

	testing(player);
}

void armor_management_scene(Player& player) {
	vector<MenuItem> main_menu_items = { MenuItem("Armors List"), MenuItem("Generate Armors"), MenuItem("Back") };
	Menu MainMenu("Test", main_menu_items);
	MenuManager menuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", "Armor Management", "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(MainMenu);

		int mode = menuManager.handleMenuSelection(MainMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();
	if (choice == 0) {
		armors_list_scene(player);
	}
	else if (choice == 1) {
		generate_armor_scene(player);
	}
	else if (choice == 2) {
		config_managment_scene(player);
	}
	else {
		return;
	}
}

void armors_list_scene(Player& player) {
	DataManager armors_dm;
	armors_dm.setDataRoot(armors_dm.getDataRoot() + "\\Configs\\Inventory\\Armors");
	vector<MenuItem> armor_list = {};
	armors_dm.loadItemList("armors.txt");

	for (int i = 0; i < armors_dm.getItems().size(); i++) {
		armor_list.push_back(MenuItem(armors_dm.getItems()[i]));
	}
	armor_list.push_back(MenuItem("Back"));

	Menu armorMenu("Armors", armor_list);
	MenuManager menuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent = { "", "Edit Armors", "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(armorMenu);

		int mode = menuManager.handleMenuSelection(armorMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();

	if (choice == armor_list.size() - 1) {
		armor_management_scene(player);
	}
	else {
		selected_armor_scene(player, armor_list[choice].getItemName());
	}
}

void selected_armor_scene(Player& player, string armor_name) {
	vector<MenuItem> armor_menu_items = { MenuItem("Edit Armor"), MenuItem("Delete Armor"), MenuItem("Back") };
	vector<MenuItem> yes_no_menu_items = { MenuItem("Yes"), MenuItem("No") };
	Menu ArmorMenu("Armor Menu", armor_menu_items);
	Menu YesNoMenu("Yes/No", yes_no_menu_items);
	MenuManager menuManager;

	// Render
	while (true) {
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", armor_name, "What do you want to do with this armor?" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(ArmorMenu);

		int mode = menuManager.handleMenuSelection(ArmorMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();

	if (choice == 0) {
		armor_edit_scene(player, armor_name);
	}
	else if (choice == 1) {
		menuManager.reset();
		while (true) {
		confirm_delete_render:
			system("cls");

			vector<string> headerBoardContent;
			headerBoardContent = { "", "Delete Armor", armor_name, "Are you sure you want to delete this armor?" };
			cout << headerBoard(headerBoardContent, 30, 5);

			cout << set_space_V(3);
			menuManager.displayMenu(YesNoMenu);

			int mode = menuManager.handleMenuSelection(YesNoMenu);

			if (mode == 5) { // Enter Pressed
				break;
			}
		}
		// End of Render

		int choice = menuManager.getSelectionPos();
		if (choice == 0) {
			DataManager armors_dm;
			armors_dm.setDataRoot(armors_dm.getDataRoot() + "\\Configs\\Inventory\\Armors");
			armors_dm.loadItemList("armors.txt");
			armors_dm.deleteData(armor_name + ".txt");
			armors_dm.removeItem(armor_name);
			armors_dm.saveItemList("armors.txt");
			armors_list_scene(player);
		}
		else {
			goto confirm_delete_render;
		}

	}
	else if (choice == 2) {
		armors_list_scene(player);
	}
	else {
		return;
	}
}

void armor_edit_scene(Player& player, string armor_name) {
	DataManager armors_dm;
	armors_dm.setDataRoot(armors_dm.getDataRoot() + "\\Configs\\Inventory\\Armors");

	armors_dm.loadData(armor_name + ".txt");
	string name = armors_dm.getData("Name");
	int defense = stoi(armors_dm.getData("Defense"));
	int durability = stoi(armors_dm.getData("Durability"));
	int rarity = stoi(armors_dm.getData("Rarity"));

	string rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));

	vector<MenuItem> edit_options = { MenuItem("Name"), MenuItem("Defense"), MenuItem("Durability"), MenuItem("Rarity"), MenuItem("Exit") };
	vector<MenuItem> rarity_menu = { MenuItem("Common"), MenuItem("Uncommon"), MenuItem("Rare"), MenuItem("Epic") };
	Menu  editMenu("Edit", edit_options), rarityMenu("Rarity", rarity_menu);
	MenuManager editMenuManager, rarityMenuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", "Edit Armor", armor_name, "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << "Name: " << name << endl;
		cout << "Defense: " << defense << endl;
		cout << "Durability: " << durability << endl;
		cout << "Rarity: " << rarity_text << endl;

		cout << set_space_V(3);

		cout << "What do you want to edit?" << endl << endl;
		editMenuManager.displayMenu(editMenu);
		int mode = editMenuManager.handleMenuSelection(editMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = editMenuManager.getSelectionPos();
	if (choice == 0) { // name edit
		cout << "Enter new name: ";
		getline(cin, name);
		goto render;
	}
	else if (choice == 1) { // defense edit
		cout << "Enter new defense: ";
		cin >> defense;
		goto render;
	}
	else if (choice == 2) { // durability edit
		cout << "Enter new durability: ";
		cin >> durability;
		goto render;
	}
	else if (choice == 3) { // rarity edit
		while (true) {
		rarity_render:
			system("cls");

			vector<string> headerBoardContent;
			headerBoardContent = { "", "Edit Armor", armor_name, "" };
			cout << headerBoard(headerBoardContent, 30, 5);

			cout << "Name: " << name << endl;
			cout << "Defense: " << defense << endl;
			cout << "Durability: " << durability << endl;
			cout << "Rarity: " << rarity_text << endl;

			cout << set_space_V(3);
			cout << "Select new rarity: " << endl << endl;
			rarityMenuManager.displayMenu(rarityMenu);
			int mode = rarityMenuManager.handleMenuSelection(rarityMenu);
			if (mode == 5) { // Enter Pressed
				rarity = rarityMenuManager.getSelectionPos() + 1;
				rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
				goto render;
			}
		}
	}
	else {
		armors_dm.addData("Name", name);
		armors_dm.addData("Defense", to_string(defense));
		armors_dm.addData("Durability", to_string(durability));
		armors_dm.addData("Rarity", to_string(rarity));

		armors_dm.saveData(armor_name + ".txt");

		armors_list_scene(player);
	}

}

void generate_armor_scene(Player& player) {
	DataManager armors_dm;

	armors_dm.setDataRoot(armors_dm.getDataRoot() + "\\Configs\\Inventory\\Armors");

	armors_dm.loadItemList("armors.txt");

	string name = "";
	int defense = 0;
	int durability = 0;
	int rarity = 0;

	string rarity_text = "";

	vector<MenuItem> rarity_menu = { MenuItem("Common"), MenuItem("Uncommon"), MenuItem("Rare"), MenuItem("Epic") };
	Menu rarityMenu("Rarity", rarity_menu);
	MenuManager menuManager;

	bool input_name = false;
	bool input_defense = false;
	bool input_durabilty = false;
	bool input_rarity = false;

	cin.ignore();
	// render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent = { "", "Enter details for armor", "" };
		cout << headerBoard(headerBoardContent, 25, 5);

		if (input_name && input_defense && input_durabilty && input_rarity) {
			vector<MenuItem> ok_menu_items = { MenuItem("Yes save it!"), MenuItem("No I want to change somthing!") };

			cout << "Armor Name: " << name << endl;
			cout << "Defense: " << defense << endl;
			cout << "Durability: " << durability << endl;
			cout << "Rarity: " << rarity_text << endl << endl;
			cout << "Is this Info OK or do you want to edit?" << endl << endl;

			Menu ok_menu("Confirm", ok_menu_items);
			menuManager.displayMenu(ok_menu);

			int mode = menuManager.handleMenuSelection(ok_menu);

			if (mode == 5) { // Enter Press
				int choice = menuManager.getSelectionPos();
				if (choice == 0) { // Yes, Save It!
					armors_dm.addData("Name", name);
					armors_dm.addData("Defense", to_string(defense));
					armors_dm.addData("Durability", to_string(durability));
					armors_dm.addData("Rarity", to_string(rarity));

					break;
				}
				else if (choice == 1) { // No I want to change something
					menuManager.reset();

					while (true) {
					choice_render:
						system("cls");

						vector<string> headerBoardContent = { "", "Enter details for armor", "" };
						cout << headerBoard(headerBoardContent, 25, 5);
						vector<MenuItem> choices = { MenuItem("Name"), MenuItem("Defense"), MenuItem("Durability"), MenuItem("Rarity") };

						Menu choiceMenu("Edit", choices);
						menuManager.displayMenu(choiceMenu);
						int mode = menuManager.handleMenuSelection(choiceMenu);

						if (mode == 5) { // Enter Press
							int choice = menuManager.getSelectionPos();

							if (choice == 0) { // Name
								cout << "Enter new name: ";
								getline(cin, name);
							}
							else if (choice == 1) { // defense
								cout << "Enter new defense: ";
								cin >> defense;
							}
							else if (choice == 2) { // durability
								cout << "Enter new durability: ";
								cin >> durability;
							}
							else if (choice == 3) { // rarity
								menuManager.reset();
								while (true) {
									system("cls");

									vector<string> headerBoardContent = { "", "Enter details for armor", "" };
									cout << headerBoard(headerBoardContent, 25, 5);

									cout << endl << endl;
									cout << "Select New Rarity: " << endl << endl;

									menuManager.displayMenu(rarityMenu);
									int mode = menuManager.handleMenuSelection(rarityMenu);
									if (mode == 5) { // Enter Pressed
										rarity = menuManager.getSelectionPos() + 1;
										rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
										menuManager.reset();
										break;
									}
								}
							}

							goto render;
						}
					}
				}
			}
		}
		
		if (!input_name) {
			cout << "Enter Armor name: ";
			getline(cin, name);
			if (armors_dm.fileExists(name + ".txt")) {
				armors_dm.loadData(name + ".txt");
				defense = stoi(armors_dm.getData("Defense"));
				durability = stoi(armors_dm.getData("Durability"));
				rarity = stoi(armors_dm.getData("Rarity"));
				rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
				input_defense = true;
				input_durabilty = true;
				input_rarity = true;
			}
			input_name = true;
		}
		else if (!input_defense) {
			cout << "Armor Name: " << name << endl;
			cout << "Enter Defense: ";
			cin >> defense;
			input_defense = true;
		}
		else if (!input_durabilty) {
			cout << "Armor Name: " << name << endl;
			cout << "Defense: " << defense << endl;
			cout << "Enter Durability: ";
			cin >> durability;
			input_durabilty = true;
		}
		else if (!input_rarity) {
			cout << "Armor Name: " << name << endl;
			cout << "Defense: " << defense << endl;
			cout << "Durability: " << durability << endl;
			cout << "Select Rarity: " << endl;
			menuManager.displayMenu(rarityMenu);
			int mode = menuManager.handleMenuSelection(rarityMenu);
			if (mode == 5) { // Enter Pressed
				rarity = menuManager.getSelectionPos() + 1;
				rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
				menuManager.reset();
				input_rarity = true;
			}
		}
	}
	// end of render

	cout << "Name of armor saved as: " << armors_dm.getData("Name") << endl;
	cout << "Defense of " << armors_dm.getData("Name") << " Saved as: " << armors_dm.getData("Defense") << endl;
	cout << "Durability of " << armors_dm.getData("Name") << " Saved as: " << armors_dm.getData("Durability") << endl;
	cout << "Rarity of " << armors_dm.getData("Name") << " Saved as: " << armors_dm.getData("Rarity") << endl;

	armors_dm.saveData(name + ".txt");
	armors_dm.addItem(name);
	armors_dm.saveItemList("armors.txt");

	cout << endl << "Press any key to continue...";
	_getch();

	testing(player);
}

void potion_management_scene(Player& player) {
	vector<MenuItem> main_menu_items = { MenuItem("Potions List"), MenuItem("Generate Potions"), MenuItem("Back") };
	Menu MainMenu("Test", main_menu_items);
	MenuManager menuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", "Potion Management", "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(MainMenu);

		int mode = menuManager.handleMenuSelection(MainMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();
	if (choice == 0) {
		potions_list_scene(player);
	}
	else if (choice == 1) {
		generate_potion_scene(player);
	}
	else if (choice == 2) {
		config_managment_scene(player);
	}
	else {
		return;
	}
}

void potions_list_scene(Player& player) {
	DataManager potions_dm;
	potions_dm.setDataRoot(potions_dm.getDataRoot() + "\\Configs\\Inventory\\Potions");
	vector<MenuItem> potion_list = {};
	potions_dm.loadItemList("potions.txt");

	for (int i = 0; i < potions_dm.getItems().size(); i++) {
		potion_list.push_back(MenuItem(potions_dm.getItems()[i]));
	}
	potion_list.push_back(MenuItem("Back"));

	Menu potionMenu("Potions", potion_list);
	MenuManager menuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent = { "", "Edit Potions", "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(potionMenu);

		int mode = menuManager.handleMenuSelection(potionMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();

	if (choice == potion_list.size() - 1) {
		potion_management_scene(player);
	}
	else {
		selected_potion_scene(player, potion_list[choice].getItemName());
	}
}

void selected_potion_scene(Player& player, string potion_name) {
	vector<MenuItem> potion_menu_items = { MenuItem("Edit Potion"), MenuItem("Delete Potion"), MenuItem("Back") };
	vector<MenuItem> yes_no_menu_items = { MenuItem("Yes"), MenuItem("No") };
	Menu PotionMenu("Potion Menu", potion_menu_items);
	Menu YesNoMenu("Yes/No", yes_no_menu_items);
	MenuManager menuManager;

	// Render
	while (true) {
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", potion_name, "What do you want to do with this potion?" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(PotionMenu);

		int mode = menuManager.handleMenuSelection(PotionMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();

	if (choice == 0) {
		potion_edit_scene(player, potion_name);
	}
	else if (choice == 1) {
		menuManager.reset();
		while (true) {
		confirm_delete_render:
			system("cls");

			vector<string> headerBoardContent;
			headerBoardContent = { "", "Delete Potion", potion_name, "Are you sure you want to delete this potion?" };
			cout << headerBoard(headerBoardContent, 30, 5);

			cout << set_space_V(3);
			menuManager.displayMenu(YesNoMenu);

			int mode = menuManager.handleMenuSelection(YesNoMenu);

			if (mode == 5) { // Enter Pressed
				break;
			}
		}
		// End of Render

		int choice = menuManager.getSelectionPos();
		if (choice == 0) {
			DataManager potions_dm;
			potions_dm.setDataRoot(potions_dm.getDataRoot() + "\\Configs\\Inventory\\Potions");
			potions_dm.loadItemList("potions.txt");
			potions_dm.deleteData(potion_name + ".txt");
			potions_dm.removeItem(potion_name);
			potions_dm.saveItemList("potions.txt");
			potions_list_scene(player);
		}
		else {
			goto confirm_delete_render;
		}

	}
	else if (choice == 2) {
		potions_list_scene(player);
	}
	else {
		return;
	}
}

void potion_edit_scene(Player& player, string potion_name) {
	DataManager potions_dm;
	potions_dm.setDataRoot(potions_dm.getDataRoot() + "\\Configs\\Inventory\\Potions");

	potions_dm.loadData(potion_name + ".txt");
	string name = potions_dm.getData("Name");
	int heal = stoi(potions_dm.getData("Heal"));
	int rarity = stoi(potions_dm.getData("Rarity"));

	string rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));

	vector<MenuItem> edit_options = { MenuItem("Name"), MenuItem("Heal"), MenuItem("Rarity"), MenuItem("Exit") };
	vector<MenuItem> rarity_menu = { MenuItem("Common"), MenuItem("Uncommon"), MenuItem("Rare"), MenuItem("Epic") };
	Menu  editMenu("Edit", edit_options), rarityMenu("Rarity", rarity_menu);
	MenuManager editMenuManager, rarityMenuManager;

	// Render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", "Edit Potion", potion_name, "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		cout << "Name: " << name << endl;
		cout << "Heal: " << heal << endl;
		cout << "Rarity: " << rarity_text << endl;

		cout << set_space_V(3);

		cout << "What do you want to edit?" << endl << endl;
		editMenuManager.displayMenu(editMenu);
		int mode = editMenuManager.handleMenuSelection(editMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = editMenuManager.getSelectionPos();
	if (choice == 0) { // name edit
		cout << "Enter new name: ";
		getline(cin, name);
		goto render;
	}
	else if (choice == 1) { // heal edit
		cout << "Enter new heal: ";
		cin >> heal;
		goto render;
	}
	else if (choice == 2) { // rarity edit
		while (true) {
		rarity_render:
			system("cls");

			vector<string> headerBoardContent;
			headerBoardContent = { "", "Edit Potion", potion_name, "" };
			cout << headerBoard(headerBoardContent, 30, 5);

			cout << "Name: " << name << endl;
			cout << "Heal: " << heal << endl;
			cout << "Rarity: " << rarity_text << endl;

			cout << set_space_V(3);
			cout << "Select new rarity: " << endl << endl;
			rarityMenuManager.displayMenu(rarityMenu);
			int mode = rarityMenuManager.handleMenuSelection(rarityMenu);
			if (mode == 5) { // Enter Pressed
				rarity = rarityMenuManager.getSelectionPos() + 1;
				rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
				goto render;
			}
		}
	}

	else {
		potions_dm.addData("Name", name);
		potions_dm.addData("Heal", to_string(heal));
		potions_dm.addData("Rarity", to_string(rarity));

		potions_dm.saveData(potion_name + ".txt");

		potions_list_scene(player);
	}

}

void generate_potion_scene(Player& player) {
	DataManager potions_dm;

	potions_dm.setDataRoot(potions_dm.getDataRoot() + "\\Configs\\Inventory\\Potions");

	potions_dm.loadItemList("potions.txt");

	string name = "";
	int heal = 0;
	int rarity = 0;

	string rarity_text = "";

	vector<MenuItem> rarity_menu = { MenuItem("Common"), MenuItem("Uncommon"), MenuItem("Rare"), MenuItem("Epic") };
	Menu rarityMenu("Rarity", rarity_menu);
	MenuManager menuManager;

	bool input_name = false;
	bool input_heal = false;
	bool input_rarity = false;

	cin.ignore();
	// render
	while (true) {
	render:
		system("cls");

		vector<string> headerBoardContent = { "", "Enter details for potion", "" };
		cout << headerBoard(headerBoardContent, 25, 5);

		if (input_name && input_heal && input_rarity) {
			vector<MenuItem> ok_menu_items = { MenuItem("Yes save it!"), MenuItem("No I want to change somthing!") };

			cout << "Potion Name: " << name << endl;
			cout << "Heal: " << heal << endl;
			cout << "Rarity: " << rarity_text << endl << endl;
			cout << "Is this Info OK or do you want to edit?" << endl << endl;

			Menu ok_menu("Confirm", ok_menu_items);
			menuManager.displayMenu(ok_menu);

			int mode = menuManager.handleMenuSelection(ok_menu);

			if (mode == 5) { // Enter Press
				int choice = menuManager.getSelectionPos();
				if (choice == 0) { // Yes, Save It!
					potions_dm.addData("Name", name);
					potions_dm.addData("Heal", to_string(heal));
					potions_dm.addData("Rarity", to_string(rarity));

					break;
				}
				else if (choice == 1) { // No I want to change something
					menuManager.reset();

					while (true) {
					choice_render:
						system("cls");

						vector<string> headerBoardContent = { "", "Enter details for potion", "" };
						cout << headerBoard(headerBoardContent, 25, 5);
						vector<MenuItem> choices = { MenuItem("Name"), MenuItem("Heal"), MenuItem("Rarity") };

						Menu choiceMenu("Edit", choices);
						menuManager.displayMenu(choiceMenu);
						int mode = menuManager.handleMenuSelection(choiceMenu);

						if (mode == 5) { // Enter Press
							int choice = menuManager.getSelectionPos();

							if (choice == 0) { // Name
								cout << "Enter new name: ";
								getline(cin, name);
							}
							else if (choice == 1) { // heal
								cout << "Enter new heal: ";
								cin >> heal;
							}
							else if (choice == 2) { // rarity
								menuManager.reset();
								while (true) {
									system("cls");

									vector<string> headerBoardContent = { "", "Enter details for potion", "" };
									cout << headerBoard(headerBoardContent, 25, 5);

									cout << endl << endl;
									cout << "Select New Rarity: " << endl << endl;

									menuManager.displayMenu(rarityMenu);
									int mode = menuManager.handleMenuSelection(rarityMenu);
									if (mode == 5) { // Enter Pressed
										rarity = menuManager.getSelectionPos() + 1;
										rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
										menuManager.reset();
										break;
									}
								}
							}

							goto render;
						}
					}
				}
			}
		}

		if (!input_name) {
			cout << "Enter Potion name: ";
			getline(cin, name);
			if (potions_dm.fileExists(name + ".txt")) {
				potions_dm.loadData(name + ".txt");
				heal = stoi(potions_dm.getData("Heal"));
				rarity = stoi(potions_dm.getData("Rarity"));
				rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
				input_heal = true;
				input_rarity = true;
			}
			input_name = true;
		}
		else if (!input_heal) {
			cout << "Potion Name: " << name << endl;
			cout << "Enter Heal: ";
			cin >> heal;
			input_heal = true;
		}
		else if (!input_rarity) {
			cout << "Potion Name: " << name << endl;
			cout << "Heal: " << heal << endl;
			cout << "Select Rarity: " << endl;
			menuManager.displayMenu(rarityMenu);
			int mode = menuManager.handleMenuSelection(rarityMenu);
			if (mode == 5) { // Enter Pressed
				rarity = menuManager.getSelectionPos() + 1;
				rarity_text = rarity == 1 ? "Common" : (rarity == 2 ? "Uncommon" : (rarity == 3 ? "Rare" : "Epic"));
				menuManager.reset();
				input_rarity = true;
			}
		}
	}
	// end of render

	cout << "Name of potion saved as: " << potions_dm.getData("Name") << endl;
	cout << "Heal of " << potions_dm.getData("Name") << " Saved as: " << potions_dm.getData("Heal") << endl;
	cout << "Rarity of " << potions_dm.getData("Name") << " Saved as: " << potions_dm.getData("Rarity") << endl;

	potions_dm.saveData(name + ".txt");
	potions_dm.addItem(name);
	potions_dm.saveItemList("potions.txt");

	cout << endl << "Press any key to continue...";
	_getch();

	testing(player);
}

void item_obtain_scene(Player& player) {
	// The scene where the player can obtain items for testing purposes

	vector<MenuItem> menuItems = { MenuItem("Common Crate"), MenuItem("Uncommon Crate"), MenuItem("Rare Crate"), MenuItem("Epic Crate"), MenuItem("Back")};
	Menu mainMenu("Obtain Item", menuItems);
	MenuManager menuManager;

	LootBox loot_box;
	Inventory inventory;
	int num_of_rolls = 1;

	// Render
	while (true) {
	render:

		system("cls");

		cout << playerInfoHeader(player);

		vector<string> headerBoardContent = { "", "Obtain Item", "" };

		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(mainMenu);

		int mode = menuManager.handleMenuSelection(mainMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}

	}
	// End of Render

	int choice = menuManager.getSelectionPos();
    switch (choice) {
		case 0:
			inventory.clear();
			inventory.addSword(Sword("Wooden Sword"));
			inventory.addArmor(Armor("Wooden Armor"));
			inventory.addPotion(Potion("Small HP Potion"));

			loot_box.clear();
			loot_box.setItemsPool(inventory);
			loot_box.setCoins(100);
			loot_box.setGems(10);
			loot_box.setXP(250);
			loot_box.setItemAppearanceChances(100, 20, 15, 40);
			loot_box.setItemRarityWeights({1}, {1}, {1});

			loot_box.setNumberOfRolls(num_of_rolls);

			loot_box.setup();
			loot_box.display_loot();
			_getch();
			loot_box.give_loot_to_player(player);

			goto render;

		case 1:
			inventory.clear();
			inventory.addSword(Sword("Wooden Sword"));
			inventory.addSword(Sword("Iron Sword"));
			inventory.addArmor(Armor("Wooden Armor"));
			inventory.addArmor(Armor("Iron Armor"));
			inventory.addPotion(Potion("Small HP Potion"));
			inventory.addPotion(Potion("Medium HP Potion"));

			loot_box.clear();
			loot_box.setItemsPool(inventory);
			loot_box.setCoins(200);
			loot_box.setGems(20);
			loot_box.setXP(550);
			loot_box.setItemAppearanceChances(70, 25, 20, 40);
			loot_box.setItemRarityWeights({ 100, 25 }, { 100, 20 }, { 100, 30 });

			loot_box.setNumberOfRolls(num_of_rolls);

			loot_box.setup();
			loot_box.display_loot();
			_getch();
			loot_box.give_loot_to_player(player);
			goto render;

		case 2:
			inventory.clear();
			inventory.addSword(Sword("Wooden Sword"));
			inventory.addSword(Sword("Iron Sword"));
			inventory.addSword(Sword("Steel Sword"));
			inventory.addArmor(Armor("Wooden Armor"));
			inventory.addArmor(Armor("Iron Armor"));
			inventory.addArmor(Armor("Steel Armor"));
			inventory.addPotion(Potion("Small HP Potion"));
			inventory.addPotion(Potion("Medium HP Potion"));
			inventory.addPotion(Potion("Large HP Potion"));

			loot_box.clear();
			loot_box.setItemsPool(inventory);
			loot_box.setCoins(350);
			loot_box.setGems(50);
			loot_box.setXP(1150);
			loot_box.setItemAppearanceChances(45, 20, 20, 40);
			loot_box.setItemRarityWeights({ 100, 40, 15 }, { 100, 45, 13 }, { 100, 55, 20 });

			loot_box.setNumberOfRolls(num_of_rolls);

			loot_box.setup();
			loot_box.display_loot();
			_getch();
			loot_box.give_loot_to_player(player);
			goto render;

		case 3:
			inventory.clear();
			inventory.addSword(Sword("Wooden Sword"));
			inventory.addSword(Sword("Iron Sword"));
			inventory.addSword(Sword("Steel Sword"));
			inventory.addSword(Sword("Diamond Sword"));
			inventory.addArmor(Armor("Wooden Armor"));
			inventory.addArmor(Armor("Iron Armor"));
			inventory.addArmor(Armor("Steel Armor"));
			inventory.addArmor(Armor("Diamond Armor"));
			inventory.addPotion(Potion("Small HP Potion"));
			inventory.addPotion(Potion("Medium HP Potion"));
			inventory.addPotion(Potion("Large HP Potion"));
			inventory.addPotion(Potion("XL HP Potion"));

			loot_box.clear();
			loot_box.setItemsPool(inventory);
			loot_box.setCoins(1000);
			loot_box.setGems(100);
			loot_box.setXP(5500);
			loot_box.setItemAppearanceChances(20, 40, 35, 50);
			loot_box.setItemRarityWeights({ 50, 30, 20, 10 }, { 55, 40, 20, 9 }, { 40, 35, 20, 12 });

			loot_box.setNumberOfRolls(num_of_rolls);

			loot_box.setup();
			loot_box.display_loot();
			_getch();
			loot_box.give_loot_to_player(player);
			goto render;

		default:
			gameScene(player);
    }

}

/////////////////////////////////
// Scenes
/////////////////////////////////

void mainScene(Player& player) {
	// Main scene where the player will have options to play, go to options or exit the game
	// This is the very first scene to be displayed when launcing the game

	vector<MenuItem> main_menu_items = { MenuItem("Start"), MenuItem("Exit"), MenuItem("Test")};
	Menu MainMenu("Main", main_menu_items);
	MenuManager menuManager;

	// Render
	while (true) {
		render:
		system("cls");

		vector<string> headerBoardContent;
		headerBoardContent = { "", "Welocome To", "Dungeon Quest", "" };
		cout << headerBoard(headerBoardContent, 30, 5);

		headerBoardContent = { "", "Here you have to kill enemies collect Loot and build yourself Stronger!", "" };
		cout << headerBoard(headerBoardContent, 5, 1);

		cout << set_space_V(3);
		menuManager.displayMenu(MainMenu);

		int mode = menuManager.handleMenuSelection(MainMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menuManager.getSelectionPos();
	if (choice == 0) {
		selectPlayerFileScene(player);
	}
	else if (choice == 1) {
		return;
	}
	else if (choice == 2) {
		cout << "Enter testing password: ";
		string password;
		getline(cin, password);

		if (password != "test") {
			cout << "Invalid password!";
			_getch();
			goto render;
		}
		else {
			testing(player);
		}
		//goto render;
	}
}

void startMenuScene(Player& player) {
	// Scene where the player will have options for starting the game or to go back

	vector<MenuItem> play_menu_items = { MenuItem("Play"), MenuItem("Options"), MenuItem("Back to Start Screen")};
	Menu play_menu("Play", play_menu_items);
	MenuManager menu_manager;
	// Render
	while (true) {
		system("cls");

		cout << playerInfoHeader(player);

		vector<string> headerBoardContent = { "", "Welcome to", "Dungeon Quest", "", "@nl", "Play"};
		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menu_manager.displayMenu(play_menu);

		int mode = menu_manager.handleMenuSelection(play_menu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menu_manager.getSelectionPos();
	if (choice == 0) {
		gameScene(player);
	}
	else if (choice == 1) {
		optionsScene(player);
	}
	else {
		mainScene(player);
	}
}

void selectPlayerFileScene(Player& player) {
	vector<MenuItem> player_items;

	DataManager data_manager;
	for (int i = 0; i < 5; i++) {
		string player_item;
		int player_data_exists = 0;
		Inventory temPInv;/*
		Player tempP(temPInv);*/
		player.setPlayerDataPath("Player " + to_string(i + 1));
		player.loadPlayerData();

		string player_name = player.getName();
		if (player_name != "Entity") {
			player_item = player.getName() + " - Level " + to_string(player.getLevel());
			player_data_exists = 1;
		}
		else {
			player_item = "Empty";
			player_data_exists = 2;
		}

		player_items.push_back(MenuItem(to_string(i + 1) + ") " + player_item, player_data_exists));
	}

	player_items.push_back(MenuItem("6) Back"));

	Menu save_file_menu("Save File Menu", player_items);
	MenuManager menu_manager;

	// Render
	while (true) {
		system("cls");

		vector<string> headerBoardContent = { "", "Welcome to", "Dungeon Quest", "", "@nl", "Select a File to Play" };

		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menu_manager.displayMenu(save_file_menu);

		int mode = menu_manager.handleMenuSelection(save_file_menu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menu_manager.getSelectionPos();
	if (choice >= 0 && choice <= 4) {
		int start_mode = menu_manager.getSelectionValue(save_file_menu);
		switch (start_mode)
		{
		case 1:
			// file exists
			player.clearDataKeysAndValues();
			loadSaveDataScene(player, "Player " + to_string(choice + 1));
			break;
		case 2:
			// file does not exists, need to make a file
			player.clearDataKeysAndValues();
			newSaveCreationScene(player, "Player " + to_string(choice + 1));
			break;
		default:
			break;
		}
	}
	else {
		mainScene(player);
	}
}

void newSaveCreationScene(Player& player, string file_path) {
	// When the player wants to create a new save file
	string name;

	cout << set_space_V(3);
	cout << "Enter your player name: ";
	getline(cin, name);

	player.setName(name);
	player.setPlayerDataPath(file_path);
	player.savePlayerData();

	startMenuScene(player);
}

void loadSaveDataScene(Player& player, string file_path) {
	// When the player wants to load a save file
	player.setPlayerDataPath(file_path);
	player.loadPlayerData();

	startMenuScene(player);
}

void optionsScene(Player& player) {
	// When player selects the options menu
	
	vector<MenuItem> options_menu_items = { MenuItem("Clear Data"), MenuItem("Back") };
	Menu play_menu("Play", options_menu_items);
	MenuManager menu_manager;

	// Render
	while (true) {
		system("cls");

		vector<string> headerBoardContent = { "", "Player settings for", player.getName(), ""};

		cout << playerInfoHeader(player);
		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menu_manager.displayMenu(play_menu);

		int mode = menu_manager.handleMenuSelection(play_menu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menu_manager.getSelectionPos();
	if (choice == 0) {
		confirmClearDataScene(player);
	}
	else if (choice == 1) {
		startMenuScene(player);
	}

}

void confirmClearDataScene(Player& player) {
	// When the player wants to clear the data

	vector<MenuItem> confirm_menu_items = { MenuItem("Yes"), MenuItem("No") };
	Menu confirm_menu("Confirm", confirm_menu_items);
	MenuManager menu_manager;

	// Render
	while (true) {
		system("cls");

		vector<string> headerBoardContent = { "", "Are you sure you want to clear the data?", "You will lose the progress made and will start", "from beggining!", ""};

		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menu_manager.displayMenu(confirm_menu);

		int mode = menu_manager.handleMenuSelection(confirm_menu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	int choice = menu_manager.getSelectionPos();
	if (choice == 0) {
		player.deletePlayerData();
		playerDataClearedScene(player);
	}
	else if (choice == 1) {
		mainScene(player);
	}
}

void playerDataClearedScene(Player& player) {
	// When the player has deleted the data

	vector<MenuItem> confirm_menu_items = { MenuItem("Ok!") };
	Menu confirm_menu("Go Back", confirm_menu_items);
	MenuManager menu_manager;

	// Render
	while (true) {
		system("cls");

		vector<string> headerBoardContent = { "", "Data Cleared!", "You can now start a new game", "" };

		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menu_manager.displayMenu(confirm_menu);

		int mode = menu_manager.handleMenuSelection(confirm_menu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}
	// End of Render

	mainScene(player);
}

void gameScene(Player& player)
{
	// The main game scene where the player will play the game

	vector<MenuItem> menuItems = { MenuItem("Go to Town"), MenuItem("Go to Dungeon"), MenuItem("View Inventory"), MenuItem("Save Game"), MenuItem("Obtain Item (TESTING)"),MenuItem("Exit")};
	Menu mainMenu("Main Menu", menuItems);
	MenuManager menuManager;

	// Render
	while (true) {
		render:

		system("cls");

		cout << playerInfoHeader(player);

		vector<string> headerBoardContent = { "", "Choose an option!", "" };

		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(mainMenu);

		int mode = menuManager.handleMenuSelection(mainMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}

	}
	// End of Render

	int choice = menuManager.getSelectionPos();
	if (choice == 0) {
		//townScene(player);
	}
	else if (choice == 1) {
		//dungeonScene(player);
	}
	else if (choice == 2) {
		inventoryScene(player);
	}
	else if (choice == 3) {
		player.savePlayerData();
		goto render;
	}
	else if (choice == 4) {
		item_obtain_scene(player);
	}
	else {
		startMenuScene(player);
	}
}

void inventoryScene(Player& player) {
	// The scene where the player can see their inventory

	vector<MenuItem> menuItems;
	MenuManager menuManager;

	// Add menu items
	menuItems.push_back(MenuItem("Swords [" + to_string(player.getInventory().getSwords().size()) + "]"));
	menuItems.push_back(MenuItem("Armors [" + to_string(player.getInventory().getArmors().size()) + "]"));
	menuItems.push_back(MenuItem("Potions [" + to_string(player.getInventory().getPotions().size()) + "]"));
	menuItems.push_back(MenuItem("Back"));

	Menu mainMenu("Inventory", menuItems);
	// Boolean variables to track selected items
	bool swordsSelected = false;
	bool armorsSelected = false;
	bool potionsSelected = false;

	// Render
	while (true) {
	render:

		system("cls");

		cout << playerInfoHeader(player);

		vector<string> headerBoardContent = { "", "Inventory", "" };

		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(mainMenu);

		int mode = menuManager.handleMenuSelection(mainMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}

	}
	// End of Render

	int choice = menuManager.getSelectionPos();
	if (choice == 0) {
		swordsSelected = true;
	}
	else if (choice == 1) {
		armorsSelected = true;
	}
	else if (choice == 2) {
		potionsSelected = true;
	}
	else if (choice == 3) {
		gameScene(player);
		return;
	}

	// Render selected item scene
	if (swordsSelected) {
		swordInventoryScene(player);
	}
	else if (armorsSelected) {
		armorInventoryScene(player);
	}
	else if (potionsSelected) {
		potionInventoryScene(player);
	}
}

void swordInventoryScene(Player& player) {
	vector<MenuItem> swordItems;
	DataManager swords_dm;
	
	swords_dm.setDataRoot(swords_dm.getDataRoot() + "\\Configs\\Inventory\\Swords");
	vector<Sword> swords_in_inventory = player.getInventory().getSwords();

	for (int i = 0; i < swords_in_inventory.size(); i++) {
		Sword sword = swords_in_inventory[i];

		swordItems.push_back(MenuItem(sword.getName() + " - Damage: " + to_string(sword.getDamage()) + " - Durability: " + to_string(sword.getDurability())));

		// Assuming getSwordDetails returns a string with the required format
		//swordItems.push_back(MenuItem(getSwordDetails(item)));
	}
	swordItems.push_back(MenuItem("Back"));

	Menu swordMenu("Swords", swordItems);
	MenuManager menuManager;

	while (true) {
		system("cls");

		vector<string> headerBoardContent = { "", "Swords", "" };
		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(swordMenu);

		int mode = menuManager.handleMenuSelection(swordMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}

	}
	int choice = menuManager.getSelectionPos();
	if (choice == swordItems.size() - 1) {
		inventoryScene(player);
	}
	else {
		// Display sword details
		//displaySwordDetails(swords_dm.getItems()[choice]);
	}
}

void armorInventoryScene(Player& player) {
	vector<MenuItem> armorItems;
	DataManager armors_dm;
	armors_dm.setDataRoot(armors_dm.getDataRoot() + "\\Configs\\Inventory\\Armors");

	vector<Armor> armors_in_inventory = player.getInventory().getArmors();

	for (int i = 0; i < armors_in_inventory.size(); i++) {
		Armor armor = armors_in_inventory[i];
		armorItems.push_back(MenuItem(armor.getName() + " - Defense: " + to_string(armor.getDefense()) + " - Durability: " + to_string(armor.getDurability())));
		// Assuming getArmorDetails returns a string with the required format
		//armorItems.push_back(MenuItem(getArmorDetails(item)));
	}
	armorItems.push_back(MenuItem("Back"));

	Menu armorMenu("Armors", armorItems);
	MenuManager menuManager;

	while (true) {
		system("cls");

		vector<string> headerBoardContent = { "", "Armors", "" };
		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(armorMenu);

		int mode = menuManager.handleMenuSelection(armorMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}
	}

	int choice = menuManager.getSelectionPos();
	if (choice == armorItems.size() - 1) {
		inventoryScene(player);
	}
	else {
		// Display armor details
		//displayArmorDetails(armors_dm.getItems()[choice]);
	}
}

void potionInventoryScene(Player& player) {
	vector<MenuItem> potionItems;
	DataManager potions_dm;
	potions_dm.setDataRoot(potions_dm.getDataRoot() + "\\Configs\\Inventory\\Potions");

	vector<Potion> potions_in_inventory = player.getInventory().getPotions();
	for (int i = 0; i < potions_in_inventory.size(); i++) {
		Potion potion = potions_in_inventory[i];
		potionItems.push_back(MenuItem(potion.getName() + " - Heal: " + to_string(potion.getHealth()) + " - In inventory: " + to_string(potion.getQuantity())));
		// Assuming getPotionDetails returns a string with the required format
		//potionItems.push_back(MenuItem(getPotionDetails(item)));
	}
	potionItems.push_back(MenuItem("Back"));

	Menu potionMenu("Potions", potionItems);
	MenuManager menuManager;

	while (true) {
		system("cls");

		vector<string> headerBoardContent = { "", "Potions", "" };
		cout << headerBoard(headerBoardContent, 25, 5);

		cout << set_space_V(3);
		menuManager.displayMenu(potionMenu);

		int mode = menuManager.handleMenuSelection(potionMenu);

		if (mode == 5) { // Enter Pressed
			break;
		}

	}
	int choice = menuManager.getSelectionPos();
	if (choice == potionItems.size() - 1) {
		inventoryScene(player);
	}
	else {
		// Display potion details
		//displayPotionDetails(potions_dm.getItems()[choice]);
	}
}
