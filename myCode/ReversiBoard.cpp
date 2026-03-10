/**
 * @file ReversiBoard.cpp
 * @brief Implementation of the ReversiBoard class methods
 * Created on: 12 Nov 2025
 * Author: Nikhil Gatla
 */
#include "ReversiBoard.h"

/**
 * @brief Default constructor which initializes the Reversi Board
 *
 * @attention The constructor assigns all the cells of the board
 * to an empty state and sets the initial four pieces in the center
 * for each player
 */
ReversiBoard::ReversiBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			boardState[i][j] = EMPTY;
		}
	}
	boardState[3][3] = PLAYER2;
	boardState[3][4] = PLAYER1;
	boardState[4][3] = PLAYER1;
	boardState[4][4] = PLAYER2;
}

/**
 * @brief Checks if the position is valid in a specific direction for the
 *        current coordinates and player
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
bool ReversiBoard::checkDirection(int row, int column, FieldState player,
		int deltaRow, int deltaColumn)
{
	int currentRow = row + deltaRow;
	int currentColumn = column + deltaColumn;
	int opponentCount = 0;

	while (currentRow >= 0 && currentRow < BOARD_SIZE && currentColumn >= 0
			&& currentColumn < BOARD_SIZE)
	{
		FieldState position = boardState[currentRow][currentColumn];
		if (position == EMPTY)
		{
			return false;
		}
		else if (position != player)
		{
			opponentCount++;
			currentRow += deltaRow;
			currentColumn += deltaColumn;
		}
		else if (position == player)
		{
			if (opponentCount > 0)
			{
				return true;
			}
			else
			{
				break;
			}
		}
	}
	// returning no direction
	return false;
}

/**
 * @brief Flips the opponent pieces in a specific direction
 *
 * @param row         : [IN] The row coordinate
 * @param column      : [IN] The column coordinate
 * @param player      : [IN] The current player's state
 * @param deltaRow    : [IN] The row direction increment
 * @param deltaColumn : [IN] The column direction increment
 */
void ReversiBoard::flipDirection(int row, int column, FieldState player,
		int deltaRow, int deltaColumn)
{
	int currentRow = row + deltaRow;
	int currentColumn = column + deltaColumn;

	while (boardState[currentRow][currentColumn] != player)
	{
		boardState[currentRow][currentColumn] = player;
		currentRow += deltaRow;
		currentColumn += deltaColumn;
	}
}

/**
 * @brief Returns the state of the cell at the specified coordinates
 *
 * @param row    : [IN] The row coordinate
 * @param column : [IN] The column coordinate
 *
 * @return The state of the cell at the specified coordinates if within
 * bounds
 */
ReversiBoard::FieldState ReversiBoard::getFieldState(int row, int column)
{
	return boardState[row][column];
}

/**
 * @brief Sets the state of the cell for the entered coordinates if the move
 *        is valid.
 * If the move is valid, it also flips the opponent's pieces accordingly.
 *
 * @param row    : [IN] The input row coordinate
 * @param column : [IN] The input column coordinate
 * @param player : [IN] The current player's state
 *
 * @return True if the position is valid and the move was made; otherwise
 *         false
 */
bool ReversiBoard::setFieldState(int row, int column, FieldState player)
{
	if (boardState[row][column] != EMPTY)
	{
		return false;
	}

	bool hasOpponentPiece = false;

	//right
	if (checkDirection(row, column, player, 0, 1))
	{
		hasOpponentPiece = true;
	}
	//left
	if (checkDirection(row, column, player, 0, -1))
	{
		hasOpponentPiece = true;
	}
	//down
	if (checkDirection(row, column, player, 1, 0))
	{
		hasOpponentPiece = true;
	}
	//up
	if (checkDirection(row, column, player, -1, 0))
	{
		hasOpponentPiece = true;
	}
	//down-right
	if (checkDirection(row, column, player, 1, 1))
	{
		hasOpponentPiece = true;
	}
	//down-left
	if (checkDirection(row, column, player, 1, -1))
	{
		hasOpponentPiece = true;
	}
	//up-right
	if (checkDirection(row, column, player, -1, 1))
	{
		hasOpponentPiece = true;
	}
	//up-left
	if (checkDirection(row, column, player, -1, -1))
	{
		hasOpponentPiece = true;
	}

	if (!hasOpponentPiece)
	{
		return false;
	}

	boardState[row][column] = player;

	if (checkDirection(row, column, player, 0, 1))
	{
		flipDirection(row, column, player, 0, 1);
	}
	if (checkDirection(row, column, player, 0, -1))
	{
		flipDirection(row, column, player, 0, -1);
	}
	if (checkDirection(row, column, player, 1, 0))
	{
		flipDirection(row, column, player, 1, 0);
	}
	if (checkDirection(row, column, player, -1, 0))
	{
		flipDirection(row, column, player, -1, 0);
	}
	if (checkDirection(row, column, player, 1, 1))
	{
		flipDirection(row, column, player, 1, 1);
	}
	if (checkDirection(row, column, player, 1, -1))
	{
		flipDirection(row, column, player, 1, -1);
	}
	if (checkDirection(row, column, player, -1, 1))
	{
		flipDirection(row, column, player, -1, 1);
	}
	if (checkDirection(row, column, player, -1, -1))
	{
		flipDirection(row, column, player, -1, -1);
	}
	return true;
}

/**
 * @brief Checks if there are any valid moves available for the specified
 *        player
 *
 * @param player : [IN] The current player's state
 *
 * @return True if there are valid moves available for the player; otherwise
 *         false
 */
bool ReversiBoard::hasValidMoves(FieldState player)
{
	for (int row = 0; row < BOARD_SIZE; row++)
	{
		for (int column = 0; column < BOARD_SIZE; column++)
		{
			FieldState position = boardState[row][column];
			if (position == EMPTY)
			{
				if (checkDirection(row, column, player, 0, 1))
				{
					return true;
				}
				if (checkDirection(row, column, player, 0, -1))
				{
					return true;
				}
				if (checkDirection(row, column, player, 1, 0))
				{
					return true;
				}
				if (checkDirection(row, column, player, -1, 0))
				{
					return true;
				}
				if (checkDirection(row, column, player, 1, 1))
				{
					return true;
				}
				if (checkDirection(row, column, player, 1, -1))
				{
					return true;
				}
				if (checkDirection(row, column, player, -1, 1))
				{
					return true;
				}
				if (checkDirection(row, column, player, -1, -1))
				{
					return true;
				}
			}
		}
	}
	return false;
}

/**
 * @brief Destructor (no dynamic memory allocation, so no specific cleanup
 *        required)
 */
ReversiBoard::~ReversiBoard()
{
}
