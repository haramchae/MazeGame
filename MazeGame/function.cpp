#include <iostream>
#include <conio.h>
#include "function.h"

using namespace std;

void setMaze(char mazeMap[21][21], PPOINT startPos, PPOINT endPos, PPLAYER player) {
	startPos->x = 1;
	startPos->y = 1;
	endPos->x = 18;
	endPos->y = 18;
	player->location = *startPos;


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

void dpMap(char mazeMap[21][21], PPLAYER player) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (mazeMap[i][j] == '4') {
				cout << "ⓑ";
			}
			else if (player->location.x == j && player->location.y == i) cout << "♠";
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

void movePlayer(char mazeMap[21][21], PPLAYER player, char cInput) {
	switch (cInput)
	{
	case 'w':
	case 'W':
		moveUp(mazeMap, player);
		break;

	case 's':
	case 'S':
		moveDown(mazeMap, player);
		break;
	case 'a':
	case 'A':
		moveLeft(mazeMap, player);
		break;
	case 'd':
	case 'D':
		moveRight(mazeMap, player);
		break;
	default:
		break;
	}
}

void moveUp(char mazeMap[21][21], PPLAYER player) {
	if (player->location.y - 1 >= 0) {
		if (mazeMap[player->location.y - 1][player->location.x] != '0' &&
			mazeMap[player->location.y - 1][player->location.x] != '4') {
			--player->location.y;
		}
	}
}

void moveDown(char mazeMap[21][21], PPLAYER player) {
	if (player->location.y + 1 < 19) {
		if (mazeMap[player->location.y + 1][player->location.x] != '0' &&
			mazeMap[player->location.y + 1][player->location.x] != '4') {
			++player->location.y;
		}
	}
}

void moveLeft(char mazeMap[21][21], PPLAYER player) {
	if (player->location.x - 1 >= 0) {
		if (mazeMap[player->location.y][player->location.x - 1] != '0' &&
			mazeMap[player->location.y][player->location.x - 1] != '4') {
			--player->location.x;
		}
	}
}

void moveRight(char mazeMap[21][21], PPLAYER player) {
	if (player->location.x + 1 < 19) {
		if (mazeMap[player->location.y][player->location.x + 1] != '0' &&
			mazeMap[player->location.y][player->location.x + 1] != '4') {
			++player->location.x;
		}
	}
}

void createBomb(char mazeMap[21][21], PPLAYER player, PPOINT bombPos, int* addedBomb) {
	if (*addedBomb == 5) return;
	for (int i = 0; i < *addedBomb; i++) {
		if (player->location.y == bombPos[i].y && player->location.x == bombPos[i].x) return;
	}
	bombPos[(*addedBomb)++] = player->location;
	mazeMap[player->location.y][player->location.x] = '4';
}

void fireBomb(char mazeMap[21][21], PPLAYER player, PPOINT bombPos, int* addedBomb) {

	if (deathCheck(player, bombPos, addedBomb) == false) {
		player->location.x = 1;
		player->location.y = 1;
	}
	for (int i = 0; i < *addedBomb; i++) {
		mazeMap[bombPos[i].y][bombPos[i].x] = '1';
		if (bombPos[i].y - 1 > 0) {
			if (mazeMap[bombPos[i].y - 1][bombPos[i].x] == '0') {
				mazeMap[bombPos[i].y - 1][bombPos[i].x] = '1';
			}
		}
		if (bombPos[i].y + 1 <19) {
			if (mazeMap[bombPos[i].y + 1][bombPos[i].x] == '0') {
				mazeMap[bombPos[i].y + 1][bombPos[i].x] = '1';
			}
		}
		if (bombPos[i].x - 1 > 0) {
			if (mazeMap[bombPos[i].y][bombPos[i].x - 1] == '0') {
				mazeMap[bombPos[i].y][bombPos[i].x - 1] = '1';
			}
		}
		if (bombPos[i].x + 1 < 19) {
			if (mazeMap[bombPos[i].y][bombPos[i].x + 1] == '0') {
				mazeMap[bombPos[i].y][bombPos[i].x + 1] = '1';
			}
		}
	}
	*addedBomb = 0;
}

bool deathCheck(PPLAYER player, PPOINT bombPos, int* addedBomb) {
	for (int i = 0; i < *addedBomb; i++) {
		if ((player->location.x == bombPos[i].x && player->location.y == bombPos[i].y) ||
			(player->location.x == bombPos[i].x + 1 && player->location.y == bombPos[i].y) ||
			(player->location.x == bombPos[i].x - 1 && player->location.y == bombPos[i].y) ||
			(player->location.x == bombPos[i].x && player->location.y == bombPos[i].y + 1) ||
			(player->location.x == bombPos[i].x && player->location.y == bombPos[i].y - 1)) {
			return false;
		}
	}
	return true;
}