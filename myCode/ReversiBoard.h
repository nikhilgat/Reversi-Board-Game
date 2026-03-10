/**
 * @file ReversiBoard.h
 * @brief Declares the ReversiBoard class for the Reversi Board Game
 * Created on: 12 Nov 2025
 * Author: Nikhil Gatla
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/**
 * @class ReversiBoard
 *
 * @brief This class is a representation of the Reversi Board Game and its
 *        methods
 */
class ReversiBoard {
public:

	/**
	 * @enum FieldState
	 *
	 * @brief Enum represents the states of a cell on the Reversi Board
	 */
	typedef enum {
		EMPTY = 0, PLAYER1 = 1, PLAYER2 = 2
	} FieldState;

private:

	/** Size of the Reversi Board */
	static const int BOARD_SIZE = 8;

	/** 2D array of FieldState type to represent the Reversi Board */
	FieldState boardState[BOARD_SIZE][BOARD_SIZE];

	/**
	 * @brief Checks if the position is valid in a specific direction for
	 * the current coordinates and player
	 *
	 *
	 * @param row         : [IN] The row coordinate
	 * @param column      : [IN] The column coordinate
	 * @param player      : [IN] The current player's state
	 * @param deltaRow    : [IN] The row direction increment
	 * @param deltaColumn : [IN] The column direction increment
	 *
	 * @return True if the position is valid in the given direction for the
	 *         player; otherwise false
	 */
	bool checkDirection(int row, int column, FieldState player,
			int deltaRow, int deltaColumn);

	/**
	 * @brief Flips the opponent pieces in a specific direction
	 *
	 * @param row         : [IN] The row coordinate
	 * @param column      : [IN] The column coordinate
	 * @param player      : [IN] The current player's state
	 * @param deltaRow    : [IN] The row direction increment
	 * @param deltaColumn : [IN] The column direction increment
	 */
	void flipDirection(int row, int column, FieldState player, int deltaRow,
			int deltaColumn);

public:

	/**
	 * @brief Default constructor which initializes the Reversi Board
	 *
	 * @attention The constructor assigns all the elements of the Reversi
	 *            Board to the empty state and sets the initial four pieces
	 *            for PLAYER1 and PLAYER2
	 */
	ReversiBoard();

	/**
	 * @brief Returns the state of the cell at the specified coordinates
	 *
	 * @param row    : [IN] The row coordinate
	 * @param column : [IN] The column coordinate
	 *
	 * @return The state of the cell at the specified coordinates if they
	 *         are within bounds; otherwise, undefined
	 */
	FieldState getFieldState(int row, int column);

	/**
	 * @brief Sets the state of the cell for the entered coordinates if the
	 *        move is valid.
	 * If the move is valid, it also flips the opponent's pieces accordingly
	 *
	 * @param row    : [IN] The input row coordinate
	 * @param column : [IN] The input column coordinate
	 * @param player : [IN] The current player's state
	 *
	 * @return True if the position is valid and the move was made;
	 *         otherwise false
	 */
	bool setFieldState(int row, int column, FieldState player);

	/**
	 * @brief Checks if there are any valid moves available for the
	 *        specified player
	 *
	 * @param player : [IN] The current player's state
	 *
	 * @return True if there are valid moves available for the player;
	 *         otherwise false
	 */
	bool hasValidMoves(FieldState player);

	/**
	 * @brief Destructor (no dynamic memory allocation, so no specific
	 *        cleanup required)
	 */
	~ReversiBoard();
};

#endif /* REVERSIBOARD_H_ */
