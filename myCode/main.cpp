/**
 * @file main.cpp
 * @brief Main program for the Reversi Board Game
 *
 * This program runs a two-player Reversi game in the console. Players
 * take turns placing pieces on an 8x8 board, flipping opponent pieces
 * that get trapped between their pieces. The game continues until no
 * one can make a valid move, then counts up the pieces to find the
 * winner.
 * Created on: 12 Nov 2025
 * Author: Nikhil Gatla
 */

// Standard (system) header files
#include <iostream>
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

using namespace std;

/**
 * @brief Main function that runs the Reversi game loop
 *
 * @return 0 on successful execution
 */
int main()
{
	// Create the game board instance
	ReversiBoard board;

	// Create the console view with a pointer to the board
	ReversiConsoleView view(&board);

	// Set the starting player to Player 1
	ReversiBoard::FieldState currentPlayer = ReversiBoard::PLAYER1;

	cout << "Reversi Board Game" << endl;

	// Main game loop - continues until no valid moves from players
	while (true)
	{
		// Print the current state of the board
		view.print();

		// Check if the current player has any valid moves
		if (!board.hasValidMoves(currentPlayer))
		{
			// Determine the other player
			ReversiBoard::FieldState otherPlayer =
					(currentPlayer == ReversiBoard::PLAYER1) ?
							ReversiBoard::PLAYER2 : ReversiBoard::PLAYER1;

			// Check if the other player has valid moves
			if (!board.hasValidMoves(otherPlayer))
			{
				// Neither player can move - game is over
				break;
			}
			else
			{
				// Current player cannot move, but other player can
				cout << "No valid moves available. Game Over" << endl;
				break;
			}
		}

		// Display whose turn it is
		if (currentPlayer == ReversiBoard::PLAYER1)
		{
			cout << "Player 1 (Black - B) turn" << endl;
		}
		else
		{
			cout << "Player 2 (White - W) turn" << endl;
		}

		// Query user for the position where to put the next piece
		int row;
		cout << "Enter row: ";
		cin >> row;

		// Validate row input
		if (row >= 0 && row < 8)
		{
			int col;
			cout << "Enter column: ";
			cin >> col;

			// Validate column input
			if (col >= 0 && col < 8)
			{
				// Attempt to set the field state (place piece and flip)
				bool success = board.setFieldState(row, col, currentPlayer);

				if (success)
				{
					// Move was valid - switch to the other player
					if (currentPlayer == ReversiBoard::PLAYER1)
					{
						currentPlayer = ReversiBoard::PLAYER2;
					}
					else
					{
						currentPlayer = ReversiBoard::PLAYER1;
					}
				}
				else
				{
					// Move was invalid - ask user to try again
					cout << "Invalid move! Try again." << endl;
				}
			}
			else
			{
				// Column out of bounds
				cout << "Invalid column. Must be between 0-7." << endl;
			}
		}
		else
		{
			// Row out of bounds
			cout << "Invalid row. Must be between 0-7." << endl;
		}

		cout << endl;
	}

	// Game has ended
	cout << "Game Over!" << endl;
	return 0;
}
