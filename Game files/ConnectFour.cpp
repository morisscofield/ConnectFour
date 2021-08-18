#include "ConnectFour.h"

ConnectFour::ConnectFour(const int &height, const int &width)
{
	// initialize class members
	height_ = height;
	width_ = width;
	board_.resize(width_); // Set the correct number of columns
}

void ConnectFour::playBlue(const int &pos)
{
	// If a move is invalid, don't play
	if (!isValidMove_(pos))
		return;

	board_.at(pos).push_back('B');
}

void ConnectFour::playRed(const int &pos)
{
	// If a move is invalid, don't play
	if (!isValidMove_(pos))
		return;

	board_.at(pos).push_back('R');
}

Array2D ConnectFour::board() const
{
	Array2D board;
	initialize_(board);
	fill_(board);

	return board;
}

void ConnectFour::initialize_(Array2D &board) const
{
	board.resize(height_); // Set the correct number of rows

	for (int row = 0; row < height_; row++) // For each row, set the correct number of columns
	{
		board.at(row).resize(width_);
		for (int col = 0; col < width_; col++)
			board.at(row).at(col) = '.'; // Populate each coordinate on the board with a '*'
	}
}

void ConnectFour::fill_(Array2D &board) const
{
	for (int col = 0; col < board_.size(); col++)
		for (int row = 0; row < board_.at(col).size(); row++)
			board.at(height_ - row - 1).at(col) = board_.at(col).at(row);
}

bool ConnectFour::isValidMove_(const int &pos) const
{
	if (pos >= width_ || pos < 0) // If the move is out of bounds, don't play
		return false;
	if (board_.at(pos).size() >= height_) // If the board is full, don't play
		return false;

	return true;
}
