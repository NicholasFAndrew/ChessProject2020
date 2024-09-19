#pragma once
#include <string>
class Board {
private:
	std::string gameSpace[8][8];

	std::string emptySpace = "[ ]";
	std::string piecePawn = "[P]";
	std::string pieceRook = "[R]";
	std::string pieceBishop = "[B]";
	std::string pieceKnight = "[N]";
	std::string pieceQueen = "[Q]";
	std::string pieceKing = "[K]";

	int playerChoice;

public:
	void fillBoard();

	void printBoard();

	void placePieces();

	void movePiece(int, int);

	void pawnMovement(int, int);

	void rookMovement(int, int);

	void bishopMovement(int, int);

	void knightMovement(int, int);

	void queenMovement(int, int);

	void kingMovement(int, int);

	void cleanBoard();
};