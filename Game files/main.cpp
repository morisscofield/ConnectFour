#include <iostream>
#include <fstream>
#include <vector>
#include "ConnectFour.h"
#include "CheckWin.h"
using namespace std;

void readMoves(vector<int> &moves, ifstream &inFile); // Read in both players' moves
void printBoard(const Array2D &board, ofstream &outFile); // Print the board itself
void printMoves(const string &player, const vector<int> &moves, ofstream &outFile); // Print the moves of a specific player

int main()
{

	// Open all the relevant files
	ifstream blueFile("player1_blue.txt"); // Open the file containing player 1's moves
	ifstream redFile("player2_red.txt"); // Open the file containing player 2's moves
	ifstream sizeFile("input.txt"); // Open the file containing the board sizes
	ofstream outFile("gameResults.txt"); // Open the output file

	vector<int> blueMoves; // Array containing all of player 1's moves for all board sizes
	vector<int> redMoves; // Array containing all of player 2's moves for all board sizes
	int height = 0, width = 0; // Declare variables to store the board size
	int blueCount = 0, redCount = 0; // Keeps track of the position of the player move array

	readMoves(blueMoves, blueFile); // Read in all of player 1's moves
	readMoves(redMoves, redFile); // Read in all of player 2's moves

	while (sizeFile >> height >> width)
	{
		outFile << "size " << height << " x " << width << endl; // Print the board size
		ConnectFour game(height, width); // Make a game object
		CheckWin checker; // Make a checker object
		vector<int> moves1; // Player 1's moves for this specific game
		vector<int> moves2; // Player 2's moves for this specific move

		// Keep playing as long the board isn't full or moves can be made
		while ((blueCount < blueMoves.size() || redCount < redMoves.size()) && !checker.isFull(game.board()))
		{
////////////////////// Blue plays
			int bluePos = blueMoves.at(blueCount);
			game.playBlue(bluePos);
			moves1.push_back(bluePos);
			blueCount++;
			if (checker.isWinner(game.board()))
				break;
////////////////////// Red plays
			int redPos = redMoves.at(redCount);
			game.playRed(redPos);
			moves2.push_back(redPos);
			redCount++;
			if (checker.isWinner(game.board()))
				break;
		}

		printBoard(game.board(), outFile); // Print the board
		printMoves("Player1_blue: ", moves1, outFile); // Print Player 1's moves
		printMoves("Player2_red: ", moves2, outFile); // Print Player 2's moves

		// Print the winner
		if (checker.winner() == 'B')
			outFile << "Winner: " << "Player1_blue" << endl << endl;
		else if (checker.winner() == 'R')
			outFile << "Winner: " << "Player2_red" << endl << endl;
	}

	// Close all files
	blueFile.close();
	redFile.close();
	sizeFile.close();
	outFile.close();
}

void readMoves(vector<int> &moves, ifstream &inFile)
{
	int move = 0;

	while (inFile >> move)
		moves.push_back(move); // Add each move to the end of the array
}

void printBoard(const Array2D &board, ofstream &outFile)
{

	int height = board.size();
	int width = board.at(0).size();

	// Print the dashes above the board
	for (int length = 0; length < width; length++)
		outFile << "-";
	outFile << endl;

	// Print the board itself
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
			outFile << board.at(row).at(col);

		outFile << endl;
	}

	// Print the dashes below the board
	for (int length = 0; length < width; length++)
		outFile << "-";
	outFile << endl;
}

void printMoves(const string &player, const vector<int> &moves, ofstream &outFile)
{
	if (moves.empty()) // Don't print if no moves were made
		return;

	outFile << player;
	for (int move = 0; move < moves.size(); move++)
	{
		outFile << moves.at(move);

		if (move < moves.size() - 1)
			outFile << ", ";
		else
			outFile << endl;
	}
}
