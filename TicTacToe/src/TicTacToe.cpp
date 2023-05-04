#include <iostream>
#include "../classes/TicTacToeClass.h"

void errorHanlder(int var) {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Wrong input, please try again ...\n";
	}
}

int main() {

	TicTacToe T;
	int choice = 0;

	while (choice != 2) {

		T.viewGameMenu();
		std::cin >> choice;
		errorHanlder(choice);

		switch (choice) {
		case 1:
			system("cls");
			T.playingGameFunction();
			break;

		case 2:
			return 0;
		}

		if (choice > 2) {
			std::cout << "Wrong input, please try again ...\n";
		}

		system("pause");
		system("cls");
	}

	std::cin.get();
	return EXIT_SUCCESS;
}