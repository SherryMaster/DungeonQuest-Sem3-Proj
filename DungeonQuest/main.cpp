#include"scenes.h"

int main() {
	/*int ch;
	while (true) {
		ch = _getch();
		cout << ch << endl;
	}*/

	// data structure genration
	system("mkdir Data\\Players\\Player 1");
	system("mkdir Data\\Players\\Player 2");
	system("mkdir Data\\Players\\Player 3");
	system("mkdir Data\\Players\\Player 4");
	system("mkdir Data\\Players\\Player 5");

	system("mkdir Configs\\Inventory\\Swords");
	system("mkdir Configs\\Inventory\\Armors");
	system("mkdir Configs\\Inventory\\Potions");

	Inventory playerInv;
	Player player(playerInv);

	mainScene(player);
	
	return 0;
}