#include"scenes.h"
#include"DataManager.h"

void mainScene(Player player) {
	// Main scene where the player will have options to play, go to options or exit the game
	// This is the very first scene to be displayed when launcing the game

	vector<MenuItem> main_menu_items = { MenuItem("Play"), MenuItem("Options"), MenuItem("Exit") };
	Menu MainMenu("Main", main_menu_items);
	MenuManager menuManager;

	// Render
	while (true) {
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
		//optionsScene();
	}
	else if (choice == 2) {
		return;
	}
}

void playMenuScene(Player player) {
	// Scene where the player will have options for starting the game or to go back

	vector<MenuItem> play_menu_items = { MenuItem("New Game"), MenuItem("Back") };
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
		//newGameScene(player);
	}
	else if (choice == 1) {
		mainScene(player);
	}
}

void selectPlayerFileScene(Player player) {
	vector<MenuItem> files;

	DataManager data_manager;

	for (int i = 0; i < 5; i++) {
		string file_name;
		if (data_manager.fileExists("player_data_" + to_string(i + 1))) {

			string actual_file_name = "player_data_" + to_string(i + 1);

			Player tempP;
			tempP.setPlayerDataPath(actual_file_name);
			tempP.loadPlayerData();

			file_name = to_string(i) + ") " + tempP.getName() + " - LeveL: " + to_string(tempP.getLevel());

			files.push_back(MenuItem(file_name, 1));
		}
		else {
			file_name = to_string(i) + ") NEW SAVE";
			files.push_back(MenuItem(file_name, 2));
		}
	}

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
			loadSaveDataScene(player, "player_data_" + to_string(choice + 1));
			break;
		case 2:
			// file does not exists, need to make a file
			newSaveCreationScene(player, "player_data_" + to_string(choice + 1));
			break;
		default:
			break;
		}
	}
	else if (choice == 1) {
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

	playMenuScene(player);
}

void loadSaveDataScene(Player player, string file_path) {
	// When the player wants to load a save file

	player.setPlayerDataPath(file_path);
	player.loadPlayerData();

	playMenuScene(player);
}

void optionsScene(Player) {
	// When player selects the options menu
	
	vector<MenuItem> options_menu_items = { MenuItem("Clear Data"), MenuItem("Back") };
	Menu play_menu("Play", options_menu_items);
	MenuManager menu_manager;



}