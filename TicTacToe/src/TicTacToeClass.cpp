#include <iostream>
#include <Windows.h>
#include "../classes/TicTacToeClass.h"

void TicTacToe::viewGameMenu() {
	std::cout << "--- Tic Tac Toe Game ---\n\n";
	std::cout << "1- Play the game\n";
	std::cout << "2- Exit the game\n\n";
	std::cout << "Enter your choice : ";
}

bool TicTacToe::errorHanlder(int first_var, int second_var) {

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Wrong input, please try again ...\n";
	}
	
	return true;
}

void TicTacToe::progressBar() {

	// Set ASCII to print special characters
	// Code page 437
	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	int bar1 = 177, bar2 = 219;
	std::cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ...";
	std::cout << "\n\n\t\t\t\t\t\t";

	for (int i = 0; i < 25; i++)
		std::cout << char(bar1);

	std::cout << '\r';
	std::cout << "\t\t\t\t\t\t";

	for (int i = 0; i < 25; i++) {
		std::cout << char(bar2);
		Sleep(150);
	}
	system("cls");
}

void TicTacToe::viewPlayersMenu() {
	std::cout << "      --- Welcome to TicTacToe Game ---\n\n";
	std::cout << "Choose your player (X) or (O) or 0 to return : ";
}

void TicTacToe::viewGameBoard() {
	std::cout << "\n|---|---|---|\n";
	std::cout << "| " << arr[0][0] << " | " << arr[0][1]
		<< " | " << arr[0][2] << " | \n";
	std::cout << "|---|---|---|\n";
	std::cout << "| " << arr[1][0] << " | " << arr[1][1]
		<< " | " << arr[1][2] << " | \n";
	std::cout << "|---|---|---|\n";
	std::cout << "| " << arr[2][0] << " | " << arr[2][1]
		<< " | " << arr[2][2] << " | \n";
	std::cout << "|---|---|---|\n";
}

bool TicTacToe::isBoardFull(char arr[][3]) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == ' ') {
				return false;
			}
		}
	}

	return true;
}

bool TicTacToe::checkForWinner(char arr[][3]) {

	//checking the win for Rows and Column
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ') {
			return true;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ') {
			return true;
		}
	}

	//checking the win for both diagonal
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ') {
		return true;
	}
	else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ') {
		return true;
	}

	return false; //return false only if no win condition was found
}

void TicTacToe::resetGameBoard() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->arr[i][j] = ' ';
		}
	}
}

void TicTacToe::playingGameFunction() {

	progressBar();
	viewPlayersMenu();
	std::cin >> var.choosePlayer;

	if (var.choosePlayer == 'x' || var.choosePlayer == 'X') {
		system("cls");

	start1:
		std::cout << "\nPlayer 1 plays, Choose row and col : ";
		std::cin >> var.row >> var.col;

		if (errorHanlder(var.row, var.col)) {
			return;
		}

		if (arr[var.row - 1][var.col - 1] == ' ') {

			arr[var.row - 1][var.col - 1] = 'X';
			viewGameBoard();

			if (checkForWinner(arr)) {
				std::cout << "\nPlayer 1 -> (X), Is the Winner!\n";
				resetGameBoard();
				return;
			}

			if (isBoardFull(arr)) {
				std::cout << "\nGame is draw!\n";
				resetGameBoard();
				return;
			}

			var.choosePlayer = 'O';
		}

		else {
			std::cout << "\nSorry you can't place (X) on top of it ...\n";
		}

		goto start2;
	}

	if (var.choosePlayer == 'o' || var.choosePlayer == 'O') {
		system("cls");

	start2:
		std::cout << "\nPlayer 2 plays, Choose row and col : ";
		std::cin >> var.row >> var.col;

		if (errorHanlder(var.row, var.col)) {
			return;
		}

		if (arr[var.row - 1][var.col - 1] == ' ') {

			arr[var.row - 1][var.col - 1] = 'O';
			viewGameBoard();

			if (checkForWinner(arr)) {
				std::cout << "\nPlayer 2 -> (O), Is the Winner!\n";
				resetGameBoard();
				return;
			}

			if (isBoardFull(arr)) {
				std::cout << "\nGame is draw!\n";
				resetGameBoard();
				return;
			}

			var.choosePlayer = 'X';
		}

		else {
			std::cout << "\nSorry you can't place (O) on top of it ...\n";
		}

		goto start1;
	}

	else if (var.choosePlayer != '0') {
		std::cout << "\nInvild input, please try again ...\n";
		return;
	}
}