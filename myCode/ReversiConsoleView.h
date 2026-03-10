/**
 * @file ReversiConsoleView.h
 * @brief Declares the ReversiConsoleView class for displaying the Reversi
 *        game board in the console
 * Created on: 12 Nov 2025
 * Author: Nikhil Gatla
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/**
 * @class ReversiConsoleView
 * @brief This class provides a console-based visual representation of the
 *        Reversi Board game.
 * It is responsible for printing the board's current state and displaying
 * player moves.
 */
class ReversiConsoleView
{
private:

	/** Pointer to a ReversiBoard object, which holds the game state */
	ReversiBoard *board;

public:

	/**
	 * @brief Parameterized Constructor for initializing ReversiConsoleView
	 *        with a ReversiBoard
	 *
	 * @param b : [IN] Pointer to a ReversiBoard object that contains the
	 *              current game state.
	 *              This allows the view to access and display the board.
	 */
	ReversiConsoleView(ReversiBoard *b);

	/**
	 * @brief Prints the current state of the Reversi Board to the console.
	 *        Displays the board grid with symbols for empty cells and
	 *        player pieces.
	 */
	void print();

	/**
	 * @brief Destructor (no dynamic memory cleanup needed)
	 */
	~ReversiConsoleView();
};

#endif /* REVERSICONSOLEVIEW_H_ */
