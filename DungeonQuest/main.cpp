#include"scenes.h"

int main() {
	/*int ch;
	while (true) {
		ch = _getch();
		cout << ch << endl;
	}*/

	// data structure genration
	system("mkdir Data\\Player");

	Player player;

	mainScene(player);
	
	return 0;
}