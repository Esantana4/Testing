#pragma once
#include <iostream>
#include "input.h"

void board();
void makeMove(char playerSymbol);
void updateBoard();

const int ROW_SIZE = 3;
const int COL_SIZE = 3;

// move later???
char boardUpdate[ROW_SIZE][COL_SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void ticTacToe()
{

	std::cout << "Tic-tac-toe (also known as Noughts and crosses or Xs and Os) is a game for two\n";
	std::cout << "players, X and O, who take turns marking the spaces in a 3╫3 grid.The player who\n";
	std::cout << "succeeds in placing three of their marks in a horizontal, vertical, or diagonal\n";
	std::cout << "row wins the game.\n";
	std::cout << "This tic-tac-toe program plays against the computer. Human player, X, will always\n";
	std::cout << "first. Time will be recorded for the fastest and the slowest game. Average time will\n";
	std::cout << "then be calculated and displayed.\n\n";
	std::cout << "Game begins ...\n";

	std::cout << "\n\n";
	std::cout << "Tic - Tac - Toe\n";
	std::cout << "|---|---|---|\n";
	std::cout << "|   |   |   |\n";
	std::cout << "|---|---|---|\n";
	std::cout << "|   |   |   |\n";
	std::cout << "|---|---|---|\n";
	std::cout << "|   |   |   |\n";
	std::cout << "|---|---|---|\n";
	std::cout << "\n\n";

	char currentPlayer = 'X'; // Start with player X

	while (true) {
		makeMove(currentPlayer);

		// Check for win or draw conditions
		// Switch players for the next turn
		currentPlayer = (currentPlayer == 'X') ? 'Y' : 'X';
	}

}

void makeMove(char playerSymbol) {

	std::cout << "Human moves ...\n\n";

	// Take player input for row and column
	int row = inputInteger("Enter the row (1..3): ", 1, 3) - 1; // Adjust input to 0-based index
	int col = inputInteger("Enter the column (1..3): ", 1, 3) - 1;

	// Check if the selected position is already occupied
	if (boardUpdate[row][col] == ' ') {
		// Update the board with the player's symbol
		boardUpdate[row][col] = playerSymbol;
		updateBoard();
	}
	else {
		std::cout << "Position already occupied. Try again." << std::endl;
		makeMove(playerSymbol); // Recursive call to try again
	}
}

void updateBoard() {
	std::cout << "\n\n";
	std::cout << "Tic - Tac - Toe\n";
	std::cout << "|---|---|---|\n";

	for (int i = 0; i < ROW_SIZE; i++) {
		std::cout << "| ";
		for (int j = 0; j < COL_SIZE; j++) {
			std::cout << boardUpdate[i][j] << " | ";
		}
		std::cout << "\n|---|---|---|\n";
	}

	std::cout << "\n\n";
}


void board()
{

	std::cout << "\n\n";
	std::cout << "Tic - Tac - Toe\n";
	std::cout << "|---|---|---|\n";
	std::cout << "|   |   |   |\n";
	std::cout << "|---|---|---|\n";
	std::cout << "|   |   |   |\n";
	std::cout << "|---|---|---|\n";
	std::cout << "|   |   |   |\n";
	std::cout << "|---|---|---|\n";
	std::cout << "\n\n";

}



