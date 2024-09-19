#include "Board.h"

#include <iostream>

using namespace std;

Board board;

int main() {
	
	int playerChoiceX, playerChoiceY;
	bool playing = true;
	newGame:
	board.fillBoard();
	board.placePieces();
	board.printBoard();

	while (playing) {

		cout << "Enter the coodinates of the desired piece to be moved: " << endl;
		cout << "(or enter -1 for either coodinate to end program, or -1 for both to start a new game)" << endl;

		cin >> playerChoiceX >> playerChoiceY;

		if (playerChoiceX <= -1 && playerChoiceY <= -1) {
			goto newGame;
		}
		if (playerChoiceX <= -1 || playerChoiceY <= -1) {
			exit(0);
		}
		

		board.movePiece(playerChoiceX, playerChoiceY);

		board.printBoard();

	}

	return 0;
}