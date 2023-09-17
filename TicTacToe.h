#pragma once
#include <iostream>
#include "input.h"

void board();
void makeMove(char playerSymbol);
void updateBoard();

const int ROW_SIZE = 3;
const int COL_SIZE = 3;
char boardUpdate[ROW_SIZE][COL_SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void ticTacToe()
{
	char currentPlayer = 'X'; // Start with player X

	while (true) {
		makeMove(currentPlayer);

		// Check for win or draw conditions
		// Switch players for the next turn
		currentPlayer = (currentPlayer == 'X') ? 'Y' : 'X';
	}

}


void makeMove(char playerSymbol) {
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



