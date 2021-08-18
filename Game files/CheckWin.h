#ifndef CHECKWIN_H_
#define CHECKWIN_H_
#include "ConnectFour.h"

// Checks if either player has won the game
class CheckWin
{
public:
	CheckWin(); // Constructor to initialize the winner_ variable as a blank char
	bool isWinner(const Array2D &board); // Check if there is winner
	bool isFull(const Array2D &board) const; // Check if the board is full
	char winner() const; // Returns the winner

private: // Private variables
	char winner_; // Stores the winner of the game, if there is one

private: // Private functions
	bool isHorizontalWin_(const Array2D &board); // Check if there is a winner by checking each row
	bool isVerticalWin_(const Array2D &board); // Check if there is a winner by checking each column
	bool isDiagonalRowWin_(const Array2D &board); // Check if there is a winner by checking the diagonal by traversing each row
	bool isDiagonalColWin_(const Array2D &board); // Check if there is a winner by checking the diagonal by traversing each column
	bool isGameOver_(const Array2D &board, const int &row, const int &col,
			int &counterRed, int &counterBlue); // The common checker for all the other private checker functions
};

#endif
