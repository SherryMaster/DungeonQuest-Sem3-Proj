#include"scenes.h"
#include"DataManager.h"
#include"fstream"

void testing(Player player) {

	cout << "Enter testing password: ";
	string password;
	getline(cin, password);

	if (password != "test") {
		cout << "Invalid password!";
		return;
	}

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
		generate_swords();
	}
	if (choice == 1) {
		mainScene(player);
	}
	else {
		return;
	}

}

void generate_swords() {
	DataManager dm;

	dm.setDataRoot(dm.getDataRoot() + "\\Weapons\\Swords");
	dm.loadData("swords_count.txt");
	int total_swords = stoi(dm.getData("total"));
	int common_swords = stoi(dm.getData("common"));
	int uncommon_swords = stoi(dm.getData("uncommon"));
	int rare_swords = stoi(dm.getData("rare"));
	int epic_swords = stoi(dm.getData("epic"));

	int common_damage_range[2] = { 5, 10 };
	int uncommon_damage_range[2] = { 10, 15 };
	int rare_damage_range[2] = { 15, 20 };
	int epic_damage_range[2] = { 20, 25 };

	int common_durability_range[2] = { 10, 25 };
	int uncommon_durability_range[2] = { 20, 50 };
	int rare_durability_range[2] = { 45, 100 };
	int epic_durability_range[2] = { 100, 200 };

	ifstream fin;
	ofstream fout;
	fin.open(dm.getDataRoot() + "\\" + "swords.txt");

	for (int i = 0; i < total_swords; i++) {

		string sword_name;
		int sword_damage_start;
		int sword_damage_end;
		int sword_durabilty_start;
		int sword_durabilty_end;
		string sword_type;

		fin >> sword_name;

		if (common_swords > 0) {
			common_swords--;
			sword_type = "common";
			sword_damage_start = common_damage_range[0];
			sword_damage_end = common_damage_range[1];

			//sword_durabilty = rand() % (common_durability_range[1] - common_durability_range[0] + 1) + common_durability_range[0];
			sword_durabilty_start = common_durability_range[0];
			sword_durabilty_end = common_durability_range[1];
		}
		else if (uncommon_swords > 0) {
			uncommon_swords--;
			sword_type = "uncommon";
			sword_damage_start = uncommon_damage_range[0];
			sword_damage_end = uncommon_damage_range[1];

			//sword_durabilty = rand() % (uncommon_durability_range[1] - uncommon_durability_range[0] + 1) + uncommon_durability_range[0];
			sword_durabilty_start = uncommon_durability_range[0];
			sword_durabilty_end = uncommon_durability_range[1];
		}
		else if (rare_swords > 0) {
			rare_swords--;
			sword_type = "rare";
			sword_damage_start = rare_damage_range[0];
			sword_damage_end = rare_damage_range[1];

			//sword_durabilty = rand() % (rare_durability_range[1] - rare_durability_range[0] + 1) + rare_durability_range[0];
			sword_durabilty_start = rare_durability_range[0];
			sword_durabilty_end = rare_durability_range[1];
		}
		else if (epic_swords > 0) {
			epic_swords--;
			sword_type = "epic";
			sword_damage_start = epic_damage_range[0];
			sword_damage_end = epic_damage_range[1];

			//sword_durabilty = rand() % (epic_durability_range[1] - epic_durability_range[0] + 1) + epic_durability_range[0];
			sword_durabilty_start = epic_durability_range[0];
			sword_durabilty_end = epic_durability_range[1];
		}


		fout.open(dm.getDataRoot() + "\\" + to_string(i + 1) + " " + sword_name + ".txt");
		fout << "name=" << sword_name << endl;
		fout << "rarity=" << sword_type << endl;
		fout << "damage_start=" << sword_damage_start << endl;
		fout << "damage_end=" << sword_damage_end << endl;
		fout << "durability_start=" << sword_durabilty_start << endl;
		fout << "durability_end=" << sword_durabilty_end << endl;
		fout.close();
	}
	fin.close();
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
		testing(player);
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
