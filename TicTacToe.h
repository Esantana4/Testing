#pragma once
#include <iostream>
#include "input.h"

void board();

void ticTacToe()
{
	board();

	int board[3][3] = { (0, 1, 2), (0, 1, 2)};

	int boardPostion00 = board[0][0];
	int boardPostion01 = board[0][1];
	int boardPostion02 = board[0][2];
	int boardPostion10 = board[1][0];
	int boardPostion11 = board[1][1];
	int boardPostion12 = board[1][2];
	int boardPostion20 = board[2][0];
	int boardPostion21 = board[2][1];
	int boardPostion22 = board[2][2];

	int player1 = inputInteger("Enter the board's row # (1..3) or 0 to forfeit: ", 1, 3);
	int player2 = inputInteger("Enter the board's column # (1..3) or 0 to forfeit: ", 1, 3);

	if (player1 == boardPostion00)
	{
		player1 = board[0][0];
		std::cout << "X";
	}

	if (player2 == boardPostion00)
	{
		player2 = board[0][0];
		//board[0][0] = static_cast<int>("Y");
		std::cout << "Y";
	}
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

void player1Move(int playerX)
{

}



