#pragma once
#include <iostream>
#include "input.h"
#include <chrono>
#include <iomanip>

//void board();
void makeMove(char playerSymbol);
void updateBoard();
bool checkWin(char playerSymbol);
bool checkDraw();
void mainMenu();
void initRandom();
void computerMove(char playerSymbol);
void resetBoard();
void recordGameDuration();

const int ROW_SIZE = 3;
const int COL_SIZE = 3;
int gamesPlayed = 0;

// move later???
char boardUpdate[ROW_SIZE][COL_SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void ticTacToe()
{
	char currentPlayer = 'X'; // Start with player X
	initRandom(); // Initialize random number generator

	std::cout << "Tic-tac-toe (also known as Noughts and crosses or Xs and Os) is a game for two\n";
	std::cout << "players, X and O, who take turns marking the spaces in a 3x3 grid.The player who\n";
	std::cout << "succeeds in placing three of their marks in a horizontal, vertical, or diagonal\n";
	std::cout << "row wins the game.\n";
	std::cout << "This tic-tac-toe program plays against the computer. Human player, X, will always\n";
	std::cout << "first. Time will be recorded for the fastest and the slowest game. Average time will\n";
	std::cout << "then be calculated and displayed.\n\n";
	std::cout << "Game begins ...\n";

	std::cout << "\n\n";
	std::cout << "Tic - Tac - Toe\n";
	std::cout << std::string(1, char(201)) << std::string(3, char(205)) << std::string(1, char(203)) << std::string(3, char(205)) << std::string(1, char(203)) << std::string(3, char(205)) << std::string(1, char(187)) << std::endl;
	std::cout << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << std::endl;
	std::cout << std::string(1, char(204)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(185)) << std::endl;
	std::cout << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << std::endl;
	std::cout << std::string(1, char(204)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(185)) << std::endl;
	std::cout << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << "   " << std::string(1, char(186)) << std::endl;
	std::cout << std::string(1, char(200)) << std::string(3, char(205)) << std::string(1, char(202)) << std::string(3, char(205)) << std::string(1, char(202)) << std::string(3, char(205)) << std::string(1, char(188)) << std::endl;
	std::cout << "\n\n";

	while (true) {

		// Print the number of games played
		std::cout << "Games Played: " << gamesPlayed << std::endl;
		std::cout << "Game Statistics: \n";

		if (currentPlayer == 'X') {
			makeMove(currentPlayer);
		}
		else {
			computerMove(currentPlayer);
			updateBoard();
		}

		// Check for win or draw conditions
		if (checkWin(currentPlayer)) {
			std::cout << (currentPlayer == 'X' ? "Human" : "Computer") << " wins!" << std::endl;
			recordGameDuration();
			resetBoard();
			gamesPlayed++;
			system("pause");
			break;
		}
		else if (checkDraw()) {
			std::cout << "It's a draw!" << std::endl;
			recordGameDuration();
			resetBoard();
			gamesPlayed++;
			system("pause");
			break;
		}

		// Check for win or draw conditions
		// Switch players for the next turn
		currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	}

}

void makeMove(char playerSymbol)
{
	std::cout << "Human moves ...\n\n";
	
	bool validMove = false;

	while (!validMove)
	{
		// Take player input for row and column
		int row = inputInteger("Enter the row (1..3) or 0 to forfeit: ", -1, 3) - 1; // Adjust input to 0-based index
		if (row == -1)
		{
			system("cls"); mainMenu();
		}

		int col = inputInteger("Enter the column (1..3) or 0 to forfeit: ", -1, 3) - 1;
		if (col == -1) 
		{
			system("cls"); mainMenu();
		}

		// Check if the selected position is already occupied
		if (boardUpdate[row][col] == ' ') {
			// Update the board with the player's symbol
			boardUpdate[row][col] = playerSymbol;
			validMove = true;
		}
		else {
			std::cout << "Position already occupied. Try again." << std::endl;
		}

	}

	updateBoard();
}


void updateBoard() {
	std::cout << "\n\n";
	std::cout << "Tic - Tac - Toe\n";
	std::cout << std::string(1, char(201)) << std::string(3, char(205)) << std::string(1, char(203)) << std::string(3, char(205)) << std::string(1, char(203)) << std::string(3, char(205)) << std::string(1, char(187)) << std::endl;

	for (int i = 0; i < ROW_SIZE; i++) {
		std::cout << std::string(1, char(186));
		for (int j = 0; j < COL_SIZE; j++) {
			std::cout << " " << boardUpdate[i][j] << " " << std::string(1, char(186));
		}
		if (i == ROW_SIZE - 1)
		{
			std::cout << std::endl << std::string(1, char(200)) << std::string(3, char(205)) << std::string(1, char(202)) << std::string(3, char(205)) << std::string(1, char(202)) << std::string(3, char(205)) << std::string(1, char(188)) << std::endl;
		}
		else
		{
			std::cout << std::endl << std::string(1, char(204)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(206)) << std::string(3, char(205)) << std::string(1, char(185)) << std::endl;
		}
	}

	std::cout << "\n\n";
}

bool checkWin(char playerSymbol)
{

	// Check rows, columns, and diagonals for a win
	for (int i = 0; i < ROW_SIZE; i++) {
		if (boardUpdate[i][0] == playerSymbol && boardUpdate[i][1] == playerSymbol && boardUpdate[i][2] == playerSymbol) {
			return true; // Row win
		}
		if (boardUpdate[0][i] == playerSymbol && boardUpdate[1][i] == playerSymbol && boardUpdate[2][i] == playerSymbol) {
			return true; // Column win
		}
	}

	if (boardUpdate[0][0] == playerSymbol && boardUpdate[1][1] == playerSymbol && boardUpdate[2][2] == playerSymbol) {
		return true; // Diagonal win (top-left to bottom-right)
	}

	if (boardUpdate[0][2] == playerSymbol && boardUpdate[1][1] == playerSymbol && boardUpdate[2][0] == playerSymbol) {
		return true; // Diagonal win (top-right to bottom-left)
	}

	return false;
}

bool checkDraw()
{
	// Check if the board is full (a draw)
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			if (boardUpdate[i][j] == ' ') {
				return false; // Empty cell found, the game is not a draw
			}
		}
	}

	return true; // All cells are occupied, it's a draw
}

// Function to initialize the random number generator
void initRandom() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Function to generate a random move for the computer
void computerMove(char playerSymbol) 
{

	// Check if AI can win in the next move
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			if (boardUpdate[i][j] == ' ') {
				boardUpdate[i][j] = playerSymbol;
				boardUpdate[i][j] = ' ';
			}
		}
	}

	// Check if player can win in the next move and block it
	playerSymbol == 'X' ? 'O' : 'X';
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			if (boardUpdate[i][j] == ' ') {
				boardUpdate[i][j] = playerSymbol;
				boardUpdate[i][j] = ' ';
			}
		}
	}

	// Check if player can win in the next move and block it
	char playerSymbolNew = (playerSymbol == 'X') ? 'O' : 'X';
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			if (boardUpdate[i][j] == ' ') {
				boardUpdate[i][j] = playerSymbol;
				boardUpdate[i][j] = ' ';
			}
		}
	}


	// If neither side can win in the next move, make a random move
	do {
		int row = std::rand() % ROW_SIZE;
		int col = std::rand() % COL_SIZE;
		if (boardUpdate[row][col] == ' ') {
			boardUpdate[row][col] = playerSymbol;
			return;
		}
	} while (true);

	/*
	// original random code
	
	int row, col;
	do {
		// Generate random row and column
		row = std::rand() % ROW_SIZE;
		col = std::rand() % COL_SIZE;
	} while (boardUpdate[row][col] != ' '); // Keep generating until an empty spot is found

	boardUpdate[row][col] = playerSymbol;
*/

}

void recordGameDuration() {

	// Define variables for tracking game durations
	std::chrono::steady_clock::time_point gameStartTime;
	std::chrono::duration<double> fastestGameDuration = std::chrono::duration<double>::max();
	std::chrono::duration<double> slowestGameDuration = std::chrono::duration<double>::min();

	auto gameEndTime = std::chrono::steady_clock::now();
	std::chrono::duration<double> gameDuration = gameEndTime - gameStartTime;

	// Update fastest and slowest game durations
	if (gameDuration < fastestGameDuration) {
		fastestGameDuration = gameDuration;
	}
	if (gameDuration > slowestGameDuration) {
		slowestGameDuration = gameDuration;
	}

	// Convert to minutes and seconds
	double minutes = gameDuration.count() / 60.0;
	double seconds = static_cast<int>(gameDuration.count()) % 60;

	std::cout << "Game Duration: " << std::fixed << std::setprecision(2) << seconds << " seconds" << std::endl;
}

// Function to reset the board to its initial state
void resetBoard() {
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COL_SIZE; j++) {
			boardUpdate[i][j] = ' ';
		}
	}
}



