#ifndef CONNECTFOUR_H_
#define CONNECTFOUR_H_
#include <vector>
using namespace std;
typedef vector<vector<char> > Array2D; // use a typedef to make the 2D vector data type easier to read

class ConnectFour
{
public:
	ConnectFour(const int &height, const int &width); // Constructor to initialize the board variables
	void playBlue(const int &pos); // Player 1 move function
	void playRed(const int &pos); // Player 2 move function
	Array2D board() const; // Returns the board for analysis and printing moves to the console

private: // Private variables
	int height_; // The height of the board (Number of rows)
	int width_; // The width of the board for (Number of columns)
	Array2D board_; // A record of all the moves made on the board

private: // Private functions
	void initialize_(Array2D &board) const; // Fill the board from the getBoard() function with "."
	void fill_(Array2D &board) const; // Fill the board from the getBoard() function with the correct moves
	bool isValidMove_(const int &pos) const; // Check if a move is valid
};

#endif
