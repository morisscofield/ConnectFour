#include "CheckWin.h"

CheckWin::CheckWin()
{
	winner_ = '.';
}

bool CheckWin::isWinner(const Array2D &board)
{
	if (isHorizontalWin_(board))
		return true;
	if (isVerticalWin_(board))
		return true;
	if (isDiagonalRowWin_(board))
		return true;
	if (isDiagonalColWin_(board))
		return true;

	return false;
}

bool CheckWin::isFull(const Array2D &board) const
{
	int height = board.size();
	int width = board.at(0).size();

	for(int row = 0; row < height; row++)
		for(int col = 0; col < width; col++)
			if (board.at(row).at(col) == '.')
				return false;

	return true;
}

char CheckWin::winner() const
{
	return winner_;
}

bool CheckWin::isHorizontalWin_(const Array2D &board)
{
	int height = board.size();
	int width = board.at(0).size();

	for (int row = 0; row < height; row++)
	{
		int counterBlue = 0;
		int counterRed = 0;
		for (int col = 0; col < width; col++)
			if (isGameOver_(board, row, col, counterRed, counterBlue))
				return true;
	}

	return false;
}

bool CheckWin::isVerticalWin_(const Array2D &board)
{
	int height = board.size();
	int width = board.at(0).size();

	for (int col = 0; col < width; col++)
	{
		int counterBlue = 0;
		int counterRed = 0;
		for (int row = 0; row < height; row++)
			if (isGameOver_(board, row, col, counterRed, counterBlue))
				return true;

	}

	return false;
}

bool CheckWin::isDiagonalRowWin_(const Array2D &board) // Check the diagonal by going across the row
{
	int height = board.size();
	int width = board.at(0).size();

	for (int diag = 0; diag < height; diag++) // Go down the row
	{
		int counterBlue = 0;
		int counterRed = 0;
		// Check by going left to right across the columns
		for (int row = diag, col = 0; row < height && col < width; row++, col++)
			if (isGameOver_(board, row, col, counterRed, counterBlue))
				return true;

		counterBlue = 0;
		counterRed = 0;
		// Check by going right to left across the columns
		for (int row = diag, col = width - 1; row < height && col >= 0; row++, col--)
			if (isGameOver_(board, row, col, counterRed, counterBlue))
				return true;
	}

	return false;
}

bool CheckWin::isDiagonalColWin_(const Array2D &board) // Check the diagonal by going across the column
{
	int height = board.size();
	int width = board.at(0).size();

	for (int diag = 0; diag < width; diag++) // Go left to right across the column
	{
		int counterBlue = 0;
		int counterRed = 0;
		// Check by going down the row
		for (int row = 0, col = diag; row < height && col < width; row++, col++)
			if (isGameOver_(board, row, col, counterRed, counterBlue))
				return true;

		counterBlue = 0;
		counterRed = 0;
		// Check by going up the row
		for (int row = height - 1, col = diag; row >= 0 && col < width; row--, col++)
			if (isGameOver_(board, row, col, counterRed, counterBlue))
				return true;
	}

	return false;
}

// The & is by reference and makes this process more memory efficient
bool CheckWin::isGameOver_(const Array2D &board, const int &row, const int &col,
		int &counterRed, int &counterBlue)
{
////////////////////// Check if blue wins
	if (board.at(row).at(col) == 'B')
		counterBlue++;
	else
		counterBlue = 0;

	if (counterBlue == 4)
	{
		winner_ = 'B';
		return true;
	}
////////////////////// Check if red wins
	if (board.at(row).at(col) == 'R')
		counterRed++;
	else
		counterRed = 0;

	if (counterRed == 4)
	{
		winner_ = 'R';
		return true;
	}

	return false;
}
