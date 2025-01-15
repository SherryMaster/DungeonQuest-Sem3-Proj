#include"scenes.h"

void testing(Player player) {

	vector<MenuItem> main_menu_items = { MenuItem("Generate Swords"), MenuItem("Back")};
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
		generate_sword_scene(player);
	}
	if (choice == 1) {
		mainScene(player);
	}
	else {
		return;
	}

}

void generate_sword_scene(Player player) {
	DataManager dm;

	dm.setDataRoot(dm.getConfigsFolder() + "\\Inventory\\Swords");

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
					dm.addData("Name", name);
					dm.addData("Damage", to_string(damage));
					dm.addData("Durability", to_string(durability));
					dm.addData("Rarity", to_string(rarity));
					


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

	cout << "Name of sword saved as: " << dm.getData("Name") << endl;
	cout << "Damage of " << dm.getData("Name") << " Saved as: " << dm.getData("Damage") << endl;
	cout << "Durability of " << dm.getData("Name") << " Saved as: " << dm.getData("Durability") << endl;
	cout << "Rarity of " << dm.getData("Name") << " Saved as: " << dm.getData("Rarity") << endl;

	dm.saveData(name + ".txt");

	cout << endl << "Press any key to continue...";
	_getch();

	testing(player);
}

void item_obtain_scene(Player player) {
	// The scene where the player can obtain items for testing purposes

	vector<MenuItem> menuItems = { MenuItem("Obtain Sword"), MenuItem("Obtain Armor"), MenuItem("Obtain Potion"), MenuItem("Back") };
	Menu mainMenu("Obtain Item", menuItems);
	MenuManager menuManager;

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
	if (choice == 0) {
		//player.obtainSword();
		goto render;
	}
	else if (choice == 1) {
		//player.obtainArmor();
		goto render;
	}
	else if (choice == 2) {
		//player.obtainPotion();
		goto render;
	}
	else {
		gameScene(player);
	}

}

/////////////////////////////////
// Scenes
/////////////////////////////////

void mainScene(Player player) {
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
		headerBoardContent = { "", "Welcome to", "Dungeon Quest", "" };
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

void startMenuScene(Player player) {
	// Scene where the player will have options for starting the game or to go back

	vector<MenuItem> play_menu_items = { MenuItem("Play"), MenuItem("Options"), MenuItem("Back")};
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

void selectPlayerFileScene(Player player) {
	vector<MenuItem> files;

	DataManager data_manager;

	for (int i = 0; i < 5; i++) {
		string file_name;
		Player tempP;
		tempP.setPlayerDataPath("player_data_" + to_string(i + 1) + ".txt");
		if (data_manager.fileExists(tempP.getPlayerDataPath(), false)) {

			string actual_file_name = tempP.getPlayerDataPath();

			tempP.loadPlayerData();

			file_name = to_string(i) + ") " + tempP.getName() + " - LeveL: " + to_string(tempP.getLevel());

			files.push_back(MenuItem(file_name, 1));
		}
		else {
			file_name = to_string(i) + ") NEW SAVE";
			files.push_back(MenuItem(file_name, 2));
		}
	}

	files.push_back(MenuItem("6) Back"));

	Menu save_file_menu("Save File Menu", files);
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
			loadSaveDataScene(player, "player_data_" + to_string(choice + 1) + ".txt");
			break;
		case 2:
			// file does not exists, need to make a file
			newSaveCreationScene(player, "player_data_" + to_string(choice + 1) + ".txt");
			break;
		default:
			break;
		}
	}
	else {
		mainScene(player);
	}
}

void newSaveCreationScene(Player player, string file_path) {
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

void loadSaveDataScene(Player player, string file_path) {
	// When the player wants to load a save file

	player.setPlayerDataPath(file_path);
	player.loadPlayerData();

	startMenuScene(player);
}

void optionsScene(Player player) {
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

void confirmClearDataScene(Player player) {
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

void playerDataClearedScene(Player player) {
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

void gameScene(Player player)
{
	// The main game scene where the player will play the game

	vector<MenuItem> menuItems = { MenuItem("Go to Town"), MenuItem("Go to Dungeon"), MenuItem("View Inventory"), MenuItem("Save Game"), MenuItem("Exit") };
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
		//inventoryScene(player);
	}
	else if (choice == 3) {
		player.savePlayerData();
		goto render;
	}
	else {
		startMenuScene(player);
	}
}

void inventoryScene(Player player) {
	// The scene where the player can see their inventory

	vector<MenuItem> menuItems = { MenuItem("Back") };
	Menu mainMenu("Inventory", menuItems);
	MenuManager menuManager;

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
		gameScene(player);
	}
}
