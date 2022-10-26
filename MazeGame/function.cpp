#include <iostream>
#include <conio.h>
#include "function.h"

using namespace std;

void setMaze(char mazeMap[21][21], PPOINT startPos, PPOINT endPos, PPOINT playerPos) {
	playerPos->x = 1;
	playerPos->y = 1;
	startPos->x = 0;
	startPos->y = 0;
	endPos->x = 18;
	endPos->y = 18;


	strcpy_s(mazeMap[0], "00000000000000000000");
	strcpy_s(mazeMap[1], "02110000001111100000");
	strcpy_s(mazeMap[2], "00011111110000000000");
	strcpy_s(mazeMap[3], "00011100011110000000");
	strcpy_s(mazeMap[4], "01010111000000000000");
	strcpy_s(mazeMap[5], "00010001110000000000");
	strcpy_s(mazeMap[6], "00011000001000100100");
	strcpy_s(mazeMap[7], "00001100000000011110");
	strcpy_s(mazeMap[8], "01011000000000000000");
	strcpy_s(mazeMap[9], "00010001110000000000");
	strcpy_s(mazeMap[10], "00010000001110000000");
	strcpy_s(mazeMap[11], "00011111111000000000");
	strcpy_s(mazeMap[12], "00011110000000000000");
	strcpy_s(mazeMap[13], "00010011100000000000");
	strcpy_s(mazeMap[14], "00010000111000000000");
	strcpy_s(mazeMap[15], "00010000001110000000");
	strcpy_s(mazeMap[16], "00010000000011100000");
	strcpy_s(mazeMap[17], "00010000000011100000");
	strcpy_s(mazeMap[18], "00010000000000111130");
	strcpy_s(mazeMap[19], "00000000000000000000");

}

void dpMap(char mazeMap[21][21], PPOINT playerPos) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (playerPos->x == j && playerPos->y == i) cout << "♠";
			else if (mazeMap[i][j] == '0') {
				cout << "□";
			}
			else if (mazeMap[i][j] == '1') {
				cout << "  ";
			}
			else if (mazeMap[i][j] == '2') {
				cout << "$ ";
			}
			else if (mazeMap[i][j] == '3') {
				cout << "★";
			}
		}
		cout << "\n";
	}
}

void movePlayer(char mazeMap[21][21], PPOINT playerPos, char cInput) {
	switch (cInput)
	{
	case 'w':
	case 'W':
		moveUp(mazeMap, playerPos);
		break;

	case 's':
	case 'S':
		moveDown(mazeMap, playerPos);
		break;
	case 'a':
	case 'A':
		moveLeft(mazeMap, playerPos);
		break;
	case 'd':
	case 'D':
		moveRight(mazeMap, playerPos);
		break;
	default:
		break;
	}
}

void moveUp(char mazeMap[21][21], PPOINT playerPos) {
	if (playerPos->y - 1 >= 0) {
		if (mazeMap[playerPos->y - 1][playerPos->x] != '0') {
			--playerPos->y;
		}
	}
}

void moveDown(char mazeMap[21][21], PPOINT playerPos) {
	if (playerPos->y + 1 < 19) {
		if (mazeMap[playerPos->y + 1][playerPos->x] != '0') {
			++playerPos->y;
		}
	}
}

void moveLeft(char mazeMap[21][21], PPOINT playerPos) {
	if (playerPos->x - 1 >= 0) {
		if (mazeMap[playerPos->y][playerPos->x - 1] != '0') {
			--playerPos->x;
		}
	}
}

void moveRight(char mazeMap[21][21], PPOINT playerPos) {
	if (playerPos->x + 1 >= 0) {
		if (mazeMap[playerPos->y][playerPos->x + 1] != '0') {
			++playerPos->x;
		}
	}
}