#include "Board.h"
#include <iostream>

using namespace std;

void Board::fillBoard() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			gameSpace[x][y] = emptySpace;
		}
	}
}

void Board::printBoard() {

	cout << "   0  1  2  3  4  5  6  7   " << endl;
	for (int x = 0; x < 8; x++) {
		cout << x << " ";
		for (int y = 0; y < 8; y++) {
			cout << gameSpace[x][y];
		}
		cout << endl;
	}
}

void Board::placePieces() {
	gameSpace[7][0] = pieceRook;
	gameSpace[7][7] = pieceRook;
	gameSpace[7][1] = pieceKnight;
	gameSpace[7][6] = pieceKnight;
	gameSpace[7][2] = pieceBishop;
	gameSpace[7][5] = pieceBishop;
	gameSpace[7][3] = pieceQueen;
	gameSpace[7][4] = pieceKing;

	for (int x = 0; x < 8; x++) {
		gameSpace[6][x] = piecePawn;
	}

}

void Board::movePiece(int positionX, int positionY) {
	if (gameSpace[positionX][positionY] == piecePawn) {
		pawnMovement(positionX, positionY);
	}
	else if (gameSpace[positionX][positionY] == pieceRook) {
		rookMovement(positionX, positionY);
	}
	else if (gameSpace[positionX][positionY] == pieceBishop) {
		bishopMovement(positionX, positionY);
	}
	else if (gameSpace[positionX][positionY] == pieceKnight) {
		knightMovement(positionX, positionY);
	}
	else if (gameSpace[positionX][positionY] == pieceQueen) {
		queenMovement(positionX, positionY);
	}
	else if (gameSpace[positionX][positionY] == pieceKing) {
		kingMovement(positionX, positionY);
	}
	else {
		cout << "That space is unoccupied!" << endl;
	}
}

void Board::pawnMovement(int X, int Y) {
	if (gameSpace[X - 1][Y] != emptySpace) {
		cout << "No available movement options." << endl;
	}
	else {
		gameSpace[X - 1][Y] = "[1]";
		printBoard();
		cout << "Select which space to move to, or enter '0' to choose a different piece." << endl;
		cin >> playerChoice;
		if (playerChoice == 0) {
			gameSpace[X - 1][Y] = emptySpace;
			//Movement loop will end;

		}
		else {
			gameSpace[X - 1][Y] = piecePawn;
			gameSpace[X][Y] = emptySpace;
		}
	}
}

void Board::rookMovement(int X, int Y) {
	if ((X - 1 < 0 || gameSpace[X - 1][Y] != emptySpace) && (X + 1 > 7 || gameSpace[X + 1][Y] != emptySpace) && (Y - 1 < 0 || gameSpace[X][Y - 1] != emptySpace) && (Y + 1 > 7 || gameSpace[X][Y - 1] != emptySpace)) {
		cout << "No available movement options." << endl;
	}
	else {

		if (X > 0) {
			if (gameSpace[X - 1][Y] == emptySpace) {
				gameSpace[X - 1][Y] = "[1]";
			}
		}
		if (Y < 7) {
			if (gameSpace[X][Y + 1] == emptySpace) {
				gameSpace[X][Y + 1] = "[2]";
			}
		}
		if (X < 7) {
			if (gameSpace[X + 1][Y] == emptySpace) {
				gameSpace[X + 1][Y] = "[3]";
			}
		}
		if (Y > 0) {
			if (gameSpace[X][Y - 1] == emptySpace) {
				gameSpace[X][Y - 1] = "[4]";
			}
		}
		printBoard();
		cout << "Which direction would you like to move in?" << endl;
		cout << "Up (1)" << endl << "Right (2)" << endl << "Down (3)" << endl << "Left (4)" << endl;
		cin >> playerChoice;
		switch (playerChoice) {
		case 1:
			if (gameSpace[X - 1][Y] == "[1]") {
				cleanBoard();
				for (int i = 0; i < X + 1; i++) {
					if (gameSpace[X - i][Y] == emptySpace) {
						gameSpace[X - i][Y] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - playerChoice][Y] = pieceRook;
			}
			break;
		case 2:
			if (gameSpace[X][Y + 1] == "[2]") {
				cleanBoard();
				for (int i = 0; i < 8 - Y; i++) {
					if (gameSpace[X][Y + i] == emptySpace) {
						gameSpace[X][Y + i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X][Y + playerChoice] = pieceRook;
			}
			break;

		case 3:
			if (gameSpace[X + 1][Y] == "[3]") {
				cleanBoard();
				for (int i = 0; i < 8 - X; i++) {
					if (gameSpace[X + i][Y] == emptySpace) {
						gameSpace[X + i][Y] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + playerChoice][Y] = pieceRook;
			}
			break;
		case 4:
			if (gameSpace[X][Y - 1] == "[4]") {
				cleanBoard();
				for (int i = 0; i <= Y; i++) {
					if (gameSpace[X][Y - i] == emptySpace) {
						gameSpace[X][Y - i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X][Y - playerChoice] = pieceRook;
			}
			break;
		default:
			break;
		}
		cleanBoard();
	}
}

void Board::bishopMovement(int X, int Y) {
	if ((X - 1 < 0 || Y - 1 < 0 || gameSpace[X - 1][Y - 1] != emptySpace) && (X - 1 < 0 || Y + 1 > 7 || gameSpace[X - 1][Y + 1] != emptySpace) && (Y - 1 < 0 || X + 1 > 7 || gameSpace[X + 1][Y - 1] != emptySpace) && (Y + 1 > 7 || X + 1 > 7 || gameSpace[X + 1][Y + 1] != emptySpace)) {
		cout << "No available movement options." << endl;
	}
	else {
		if (X > 0 && Y > 0 && gameSpace[X - 1][Y - 1] == emptySpace) {
			gameSpace[X - 1][Y - 1] = "[1]";
		}
		if (X > 0 && Y < 7 && gameSpace[X - 1][Y + 1] == emptySpace) {
			gameSpace[X - 1][Y + 1] = "[2]";
		}
		if (X < 7 && Y > 0 && gameSpace[X + 1][Y - 1] == emptySpace) {
			gameSpace[X + 1][Y - 1] = "[3]";
		}
		if (X < 7 && Y < 7 && gameSpace[X + 1][Y + 1] == emptySpace) {
			gameSpace[X + 1][Y + 1] = "[4]";
		}
		printBoard();
		cout << "Which direction would you like to move in?" << endl;
		cout << "Up-left (1)" << endl << "Up-right (2)" << endl << "Down-right (3)" << endl << "Down-left (4)" << endl;
		cin >> playerChoice;
		switch (playerChoice) {
		case 1:
			if (gameSpace[X - 1][Y - 1] == "[1]") {
				cleanBoard();
				for (int i = 0; i < Y + 1 && i < X + 1; i++) {
					if (gameSpace[X - i][Y - i] == emptySpace) {
						gameSpace[X - i][Y - i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - playerChoice][Y - playerChoice] = pieceBishop;
			}
			break;
		case 2:
			if (gameSpace[X - 1][Y + 1] == "[2]") {
				cleanBoard();
				for (int i = 0; i < X + 1 && i < 7; i++) {
					if (gameSpace[X - i][Y + i] == emptySpace) {
						gameSpace[X - i][Y + i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {
					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - playerChoice][Y + playerChoice] = pieceBishop;
			}
			break;
		case 3:
			if (gameSpace[X + 1][Y - 1] == "[3]") {
				cleanBoard();
				for (int i = 0; i < Y && i < 7; i++) {
					if (gameSpace[X + i][Y - i] == emptySpace) {
						gameSpace[X + i][Y - i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + playerChoice][Y - playerChoice] = pieceBishop;
			}
			break;
		case 4:
			if (gameSpace[X + 1][Y + 1] == "[4]") {
				cleanBoard();
				for (int i = 0; i < 7; i++) {
					if (gameSpace[X + i][Y + i] == emptySpace) {
						gameSpace[X + i][Y + i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + playerChoice][Y + playerChoice] = pieceBishop;
			}
			break;
		default:
			break;
		}
		cleanBoard();
	}

}

void Board::knightMovement(int X, int Y) {
	if ((X - 1 < 0 || Y - 2 < 0 || gameSpace[X - 1][Y - 2] != emptySpace) && (X - 2 < 0 || Y - 1 < 0 || gameSpace[X - 2][Y - 1] != emptySpace) && (X - 2 < 0 || Y + 1 > 7 || gameSpace[X - 2][Y + 1] != emptySpace) && (X - 1 < 0 || Y + 2 > 7 || gameSpace[X - 1][Y + 2] != emptySpace) && (X + 1 > 7 || Y + 2 > 7 || gameSpace[X + 1][Y + 2] != emptySpace) && (X + 2 > 7 || Y + 1 > 7 || gameSpace[X + 2][Y + 1] != emptySpace) && (X + 2 > 7 || Y - 1 < 0 || gameSpace[X + 2][Y - 1] != emptySpace) && (X + 1 > 7 || Y - 2 < 0 || gameSpace[X + 1][Y - 2] != emptySpace)) {
		cout << "No available movement options." << endl;
	}
	else {
		if (X - 1 >= 0 && Y - 2 >= 0 && gameSpace[X - 1][Y - 2] == emptySpace) {
			gameSpace[X - 1][Y - 2] = "[1]";
		}
		if (X - 2 >= 0 && Y - 1 >= 0 && gameSpace[X - 2][Y - 1] == emptySpace) {
			gameSpace[X - 2][Y - 1] = "[2]";
		}
		if (X - 2 >= 0 && Y + 1 <= 7 &&gameSpace[X - 2][Y + 1] == emptySpace) {
			gameSpace[X - 2][Y + 1] = "[3]";
		}
		if (X - 1 >= 0 && Y + 2 <= 7 && gameSpace[X - 1][Y + 2] == emptySpace) {
			gameSpace[X - 1][Y + 2] = "[4]";
		}
		if (X + 1 <= 7 && Y + 2 <= 7 && gameSpace[X + 1][Y + 2] == emptySpace) {
			gameSpace[X + 1][Y + 2] = "[5]";
		}
		if (X + 2 <= 7 && Y + 1 <= 7 && gameSpace[X + 2][Y + 1] == emptySpace) {
			gameSpace[X + 2][Y + 1] = "[6]";
		}
		if (X + 2 <= 7 && Y - 1 >= 0 && gameSpace[X + 2][Y - 1] == emptySpace) {
			gameSpace[X + 2][Y - 1] = "[7]";
		}
		if (X + 1 <= 7 && Y - 2 >= 0 && gameSpace[X + 1][Y - 2] == emptySpace) {
			gameSpace[X + 1][Y - 2] = "[8]";
		}
		printBoard();
		cout << "Which space would you like to move to?" << endl;
		cout << "(1) (2) (3) (4) (5) (6) (7) (8)" << endl;
		cin >> playerChoice;
		switch (playerChoice) {
		case 1:
			if (gameSpace[X - 1][Y - 2] == "[1]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - 1][Y - 2] = pieceKnight;
			}
			break;
		case 2:
			if (gameSpace[X - 2][Y - 1] == "[2]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - 2][Y - 1] = pieceKnight;
			}
			break;
		case 3:
			if (gameSpace[X - 2][Y + 1] == "[3]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - 2][Y + 1] = pieceKnight;
			}
			break;
		case 4:
			if (gameSpace[X - 1][Y + 2] == "[4]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - 1][Y + 2] = pieceKnight;
			}
			break;
		case 5:
			if (gameSpace[X + 1][Y + 2] == "[5]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + 1][Y + 2] = pieceKnight;
			}
			break;
		case 6:
			if (gameSpace[X + 2][Y + 1] == "[6]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + 2][Y + 1] = pieceKnight;
			}
			break;
		case 7:
			if (gameSpace[X + 2][Y - 1] == "[7]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + 2][Y - 1] = pieceKnight;
			}
			break;
		case 8:
			if (gameSpace[X + 1][Y - 2] == "[8]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + 1][Y - 2] = pieceKnight;
			}
			break;
		default:
			break;
		}
		cleanBoard();
	}
}

void Board::queenMovement(int X, int Y) {
	if ((X - 1 < 0 || gameSpace[X - 1][Y] != emptySpace) && (X + 1 > 7 || gameSpace[X + 1][Y] != emptySpace) && (Y - 1 < 0 || gameSpace[X][Y - 1] != emptySpace) && (Y + 1 > 7 || gameSpace[X][Y - 1] != emptySpace) && (X - 1 < 0 || Y - 1 < 0 || gameSpace[X - 1][Y - 1] != emptySpace) && (X - 1 < 0 || Y + 1 > 7 || gameSpace[X - 1][Y + 1] != emptySpace) && (Y - 1 < 0 || X + 1 > 7 || gameSpace[X + 1][Y - 1] != emptySpace) && (Y + 1 > 7 || X + 1 > 7 || gameSpace[X + 1][Y + 1] != emptySpace)) {
		cout << "No available movement options." << endl;
	}
	else {
		if (X > 0) {
			if (gameSpace[X - 1][Y] == emptySpace) {
				gameSpace[X - 1][Y] = "[1]";
			}
		}
		if (Y < 7) {
			if (gameSpace[X][Y + 1] == emptySpace) {
				gameSpace[X][Y + 1] = "[3]";
			}
		}
		if (X < 7) {
			if (gameSpace[X + 1][Y] == emptySpace) {
				gameSpace[X + 1][Y] = "[5]";
			}
		}
		if (Y > 0) {
			if (gameSpace[X][Y - 1] == emptySpace) {
				gameSpace[X][Y - 1] = "[7]";
			}
		}
		if (X > 0 && Y > 0 && gameSpace[X - 1][Y - 1] == emptySpace) {
			gameSpace[X - 1][Y - 1] = "[8]";
		}
		if (X > 0 && Y < 7 && gameSpace[X - 1][Y + 1] == emptySpace) {
			gameSpace[X - 1][Y + 1] = "[2]";
		}
		if (X < 7 && Y > 0 && gameSpace[X + 1][Y - 1] == emptySpace) {
			gameSpace[X + 1][Y - 1] = "[6]";
		}
		if (X < 7 && Y < 7 && gameSpace[X + 1][Y + 1] == emptySpace) {
			gameSpace[X + 1][Y + 1] = "[4]";
		}
		printBoard();
		cout << "Which direction would you like to move to?" << endl;
		cout << "(1) (2) (3) (4) (5) (6) (7) (8)" << endl;
		cin >> playerChoice;
		switch (playerChoice) {
		case 1:
			if (gameSpace[X - 1][Y] == "[1]") {
				cleanBoard();
				for (int i = 0; i < X + 1; i++) {
					if (gameSpace[X - i][Y] == emptySpace) {
						gameSpace[X - i][Y] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - playerChoice][Y] = pieceQueen;
			}
			break;
		case 2:
			if (gameSpace[X - 1][Y + 1] == "[2]") {
				cleanBoard();
				for (int i = 0; i < X + 1 && i < 7; i++) {
					if (gameSpace[X - i][Y + i] == emptySpace) {
						gameSpace[X - i][Y + i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {
					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - playerChoice][Y + playerChoice] = pieceQueen;
			}
			break;
		case 3:
			if (gameSpace[X][Y + 1] == "[3]") {
				cleanBoard();
				for (int i = 0; i < 8 - Y; i++) {
					if (gameSpace[X][Y + i] == emptySpace) {
						gameSpace[X][Y + i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X][Y + playerChoice] = pieceQueen;
			}
			break;
		case 4:
			if (gameSpace[X + 1][Y + 1] == "[4]") {
				cleanBoard();
				for (int i = 0; i < 7; i++) {
					if (gameSpace[X + i][Y + i] == emptySpace) {
						gameSpace[X + i][Y + i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + playerChoice][Y + playerChoice] = pieceQueen;
			}
			break;
		case 5:
			if (gameSpace[X + 1][Y] == "[5]") {
				cleanBoard();
				for (int i = 0; i < 8 - X; i++) {
					if (gameSpace[X + i][Y] == emptySpace) {
						gameSpace[X + i][Y] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + playerChoice][Y] = pieceQueen;
			}
			break;
		case 6:
			if (gameSpace[X + 1][Y - 1] == "[6]") {
				cleanBoard();
				for (int i = 0; i < Y && i < 7; i++) {
					if (gameSpace[X + i][Y - i] == emptySpace) {
						gameSpace[X + i][Y - i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + playerChoice][Y - playerChoice] = pieceQueen;
			}
			break;
		case 7:
			if (gameSpace[X][Y - 1] == "[7]") {
				cleanBoard();
				for (int i = 0; i <= Y; i++) {
					if (gameSpace[X][Y - i] == emptySpace) {
						gameSpace[X][Y - i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X][Y - playerChoice] = pieceQueen;
			}
			break;
		case 8:
			if (gameSpace[X - 1][Y - 1] == "[8]") {
				cleanBoard();
				for (int i = 0; i < Y + 1 && i < X + 1; i++) {
					if (gameSpace[X - i][Y - i] == emptySpace) {
						gameSpace[X - i][Y - i] = "[" + to_string(i) + "]";
					}
					else if (i == 0) {

					}
					else {
						break;
					}
				}
				printBoard();
				cout << "Which space would you like to move?" << endl;
				cin >> playerChoice;
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - playerChoice][Y - playerChoice] = pieceQueen;
			}
			break;
		default:
			break;
		}
		cleanBoard();

	}

}

void Board::kingMovement(int X, int Y) {
	if ((X - 1 < 0 || gameSpace[X - 1][Y] != emptySpace) && (X + 1 > 7 || gameSpace[X + 1][Y] != emptySpace) && (Y - 1 < 0 || gameSpace[X][Y - 1] != emptySpace) && (Y + 1 > 7 || gameSpace[X][Y - 1] != emptySpace) && (X - 1 < 0 || Y - 1 < 0 || gameSpace[X - 1][Y - 1] != emptySpace) && (X - 1 < 0 || Y + 1 > 7 || gameSpace[X - 1][Y + 1] != emptySpace) && (Y - 1 < 0 || X + 1 > 7 || gameSpace[X + 1][Y - 1] != emptySpace) && (Y + 1 > 7 || X + 1 > 7 || gameSpace[X + 1][Y + 1] != emptySpace)) {
		cout << "No available movement options." << endl;
	}
	else {
		if (X > 0) {
			if (gameSpace[X - 1][Y] == emptySpace) {
				gameSpace[X - 1][Y] = "[1]";
			}
		}
		if (Y < 7) {
			if (gameSpace[X][Y + 1] == emptySpace) {
				gameSpace[X][Y + 1] = "[3]";
			}
		}
		if (X < 7) {
			if (gameSpace[X + 1][Y] == emptySpace) {
				gameSpace[X + 1][Y] = "[5]";
			}
		}
		if (Y > 0) {
			if (gameSpace[X][Y - 1] == emptySpace) {
				gameSpace[X][Y - 1] = "[7]";
			}
		}
		if (X > 0 && Y > 0 && gameSpace[X - 1][Y - 1] == emptySpace) {
			gameSpace[X - 1][Y - 1] = "[8]";
		}
		if (X > 0 && Y < 7 && gameSpace[X - 1][Y + 1] == emptySpace) {
			gameSpace[X - 1][Y + 1] = "[2]";
		}
		if (X < 7 && Y > 0 && gameSpace[X + 1][Y - 1] == emptySpace) {
			gameSpace[X + 1][Y - 1] = "[6]";
		}
		if (X < 7 && Y < 7 && gameSpace[X + 1][Y + 1] == emptySpace) {
			gameSpace[X + 1][Y + 1] = "[4]";
		}
		printBoard();
		cout << "Which direction would you like to move to?" << endl;
		cout << "(1) (2) (3) (4) (5) (6) (7) (8)" << endl;
		cin >> playerChoice;
		switch (playerChoice) {
		case 1:
			if (gameSpace[X - 1][Y] == "[1]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - 1][Y] = pieceKing;
			}
			break;
		case 2:
			if (gameSpace[X - 1][Y + 1] == "[2]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - 1][Y + 1] = pieceKing;
			}
			break;
		case 3:
			if (gameSpace[X][Y + 1] == "[3]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X][Y + 1] = pieceKing;
			}
			break;
		case 4:
			if (gameSpace[X + 1][Y + 1] == "[4]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + 1][Y + 1] = pieceKing;
			}
			break;
		case 5:
			if (gameSpace[X + 1][Y] == "[5]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + 1][Y] = pieceKing;
			}
			break;
		case 6:
			if (gameSpace[X + 1][Y - 1] == "[6]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X + 1][Y - 1] = pieceKing;
			}
			break;
		case 7:
			if (gameSpace[X][Y - 1] == "[7]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X][Y - 1] = pieceKing;
			}
			break;
		case 8:
			if (gameSpace[X - 1][Y - 1] == "[8]") {
				gameSpace[X][Y] = emptySpace;
				gameSpace[X - 1][Y - 1] = pieceKing;
			}
			break;
		default:
			break;
		}
		cleanBoard();

	}

}

void Board::cleanBoard() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (gameSpace[x][y] != emptySpace && gameSpace[x][y] != piecePawn && gameSpace[x][y] != pieceRook && gameSpace[x][y] != pieceBishop && gameSpace[x][y] != pieceKnight && gameSpace[x][y] != pieceQueen && gameSpace[x][y] != pieceKing) {
				gameSpace[x][y] = emptySpace;
			}
		}
	}
}