#pragma once

class TicTacToe {
public:
	void progressBar();
	void viewGameMenu();
	void viewGameBoard();
	void resetGameBoard();
	void viewPlayersMenu();
	void playingGameFunction();
	bool errorHanlder(int, int);
	bool isBoardFull(char[][3]);
	bool checkForWinner(char[][3]);

private:
	char arr[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	struct variables {
		int row, col;
		char choosePlayer;
	} var;
};