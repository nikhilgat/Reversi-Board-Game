/**
 * @file ReversiConsoleView.cpp
 * @brief Implementation of the ReversiConsoleView class methods
 * Created on: 12 Nov 2025
 * Author: Nikhil Gatla
 */
#include "ReversiConsoleView.h"
#include <iostream>

using namespace std;

/**
 * @brief Parameterized Constructor for initializing ReversiConsoleView with
 *        a ReversiBoard
 *
 * @param b : [IN] Pointer to a ReversiBoard object that contains the
 *              current game state
 */
ReversiConsoleView::ReversiConsoleView(ReversiBoard *b)
{
	board = b;
}

/**
 * @brief Prints the current state of the Reversi Board to the console.
 *        Displays the board grid with symbols for empty cells and player
 *        pieces.
 */
void ReversiConsoleView::print()
{
	cout << "  0 1 2 3 4 5 6 7" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 8; j++)
		{
			ReversiBoard::FieldState state = board->getFieldState(i, j);
			if (state == ReversiBoard::EMPTY)
			{
				cout << "- ";
			}
			else if (state == ReversiBoard::PLAYER1)
			{
				cout << "B ";
			}
			else if (state == ReversiBoard::PLAYER2)
			{
				cout << "W ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

/**
 * @brief Destructor (no dynamic memory cleanup needed)
 */
ReversiConsoleView::~ReversiConsoleView()
{
}
