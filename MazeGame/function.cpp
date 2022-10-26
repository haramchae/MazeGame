#include <iostream>
#include <conio.h>
#include "function.h"
#include <time.h>

using namespace std;

void setMaze(char mazeMap[21][21], PPOINT startPos, PPOINT endPos, PPLAYER player) {
	startPos->x = 1;
	startPos->y = 1;
	endPos->x = 18;
	endPos->y = 18;
	player->location = *startPos;

	strcpy_s(mazeMap[0], "00000000000000000000");
	strcpy_s(mazeMap[1], "02110000000000100000");
	strcpy_s(mazeMap[2], "00000000010000000000");
	strcpy_s(mazeMap[3], "00011100011110000000");
	strcpy_s(mazeMap[4], "01010111000000000000");
	strcpy_s(mazeMap[5], "00010001110000000000");
	strcpy_s(mazeMap[6], "00011000001000100100");
	strcpy_s(mazeMap[7], "00001100000000011110");
	strcpy_s(mazeMap[8], "01011000000000000000");
	strcpy_s(mazeMap[9], "00010001110000000000");
	strcpy_s(mazeMap[10], "00010000001110000000");
	strcpy_s(mazeMap[11], "00000000001000000000");
	strcpy_s(mazeMap[12], "00000010000000000000");
	strcpy_s(mazeMap[13], "00000010000000000000");
	strcpy_s(mazeMap[14], "00000000001000000000");
	strcpy_s(mazeMap[15], "00000000000110000000");
	strcpy_s(mazeMap[16], "00000000000000100000");
	strcpy_s(mazeMap[17], "00000000000000100000");
	strcpy_s(mazeMap[18], "00000000000000000030");
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
			else if (mazeMap[i][j] == '5') {
				cout << "ⓟ";
			}
			else if (mazeMap[i][j] == '6') {
				cout << "ⓦ";
			}
			else if (mazeMap[i][j] == '7') {
				cout << "ⓣ";
			}
			else if (mazeMap[i][j] == '8') {
				cout << "ⓒ";
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
	if (player->location.y - 1 > 0) {
		if (mazeMap[player->location.y - 1][player->location.x] != '0' &&
			mazeMap[player->location.y - 1][player->location.x] != '4') {
			--player->location.y;
		}
		else if (player->push) {
			if (player->location.y > 2) {
				if (mazeMap[player->location.y - 2][player->location.x] == '1' &&
					mazeMap[player->location.y - 1][player->location.x] == '0') {
					mazeMap[player->location.y - 2][player->location.x] = '0';
					mazeMap[player->location.y - 1][player->location.x] = '1';
					--player->location.y;
				}
			}
		}
		else if (player->transParency) {
			--player->location.y;
		}
		if (addItem(mazeMap[player->location.y][player->location.x] ,player)) {
			mazeMap[player->location.y][player->location.x] = '1';
		}
	}
}

void moveDown(char mazeMap[21][21], PPLAYER player) {
	if (player->location.y + 1 < 19) {
		if (mazeMap[player->location.y + 1][player->location.x] != '0' &&
			mazeMap[player->location.y + 1][player->location.x] != '4') {
			++player->location.y;
		}
		else if (player->push) {
			if (player->location.y < 17) {
				if (mazeMap[player->location.y + 2][player->location.x] == '1' &&
					mazeMap[player->location.y + 1][player->location.x] == '0') {
					mazeMap[player->location.y + 2][player->location.x] = '0';
					mazeMap[player->location.y + 1][player->location.x] = '1';
					++player->location.y;
				}
			}
		}
		else if (player->transParency) {
			++player->location.y;
		}
		if (addItem(mazeMap[player->location.y][player->location.x], player)) {
			mazeMap[player->location.y][player->location.x] = '1';
		}
	}
}

void moveLeft(char mazeMap[21][21], PPLAYER player) {
	if (player->location.x - 1 > 0) {
		if (mazeMap[player->location.y][player->location.x - 1] != '0' &&
			mazeMap[player->location.y][player->location.x - 1] != '4') {
			--player->location.x;
		}
		else if (player->push) {
			if (player->location.y > 2) {
				if (mazeMap[player->location.y ][player->location.x -2] == '1' &&
					mazeMap[player->location.y ][player->location.x-1] == '0') {
					mazeMap[player->location.y ][player->location.x-2] = '0';
					mazeMap[player->location.y ][player->location.x-1] = '1';
					--player->location.x;
				}
			}
		}
		else if (player->transParency) {
			--player->location.x;
		}
		if (addItem(mazeMap[player->location.y][player->location.x], player)) {
			mazeMap[player->location.y][player->location.x] = '1';
		}
	}
}

void moveRight(char mazeMap[21][21], PPLAYER player) {
	if (player->location.x + 1 < 19) {
		if (mazeMap[player->location.y][player->location.x + 1] != '0' &&
			mazeMap[player->location.y][player->location.x + 1] != '4') {
			++player->location.x;
		}
		else if (player->push) {
			if (player->location.y < 17) {
				if (mazeMap[player->location.y][player->location.x + 2] == '1' &&
					mazeMap[player->location.y][player->location.x + 1] == '0') {
					mazeMap[player->location.y][player->location.x + 2] = '0';
					mazeMap[player->location.y][player->location.x + 1] = '1';
					++player->location.x;
				}
			}
		}
		else if (player->transParency) {
			++player->location.x;
		}
		if (addItem(mazeMap[player->location.y][player->location.x], player)) {
			mazeMap[player->location.y][player->location.x] = '1';
		}
	}
}

void createBomb(char mazeMap[21][21], PPLAYER player, PPOINT bombPos, int* addedBomb) {
	if (*addedBomb >= player->bombCount) return;
	if (*addedBomb == 5) return;
	else if (mazeMap[player->location.y][player->location.x] == '0') return;
	for (int i = 0; i < *addedBomb; i++) {
		if (player->location.y == bombPos[i].y && player->location.x == bombPos[i].x) return;
	}
	bombPos[(*addedBomb)++] = player->location;
	mazeMap[player->location.y][player->location.x] = '4';
}

void fireBomb(char mazeMap[21][21], PPLAYER player, PPOINT bombPos, int* addedBomb) {
	srand((unsigned int)time(0));
	

	for (int i = 0; i < *addedBomb; i++) {
		mazeMap[bombPos[i].y][bombPos[i].x] = '1';
		for (int j = 1; j < player->bombPower+1; j++) {
			if (bombPos[i].y - j > 0) {
				if (mazeMap[bombPos[i].y - j][bombPos[i].x] =='0' &&
					bombPos[i].y - j != 0)  {
					if (rand() % 100 < 5) {
						int percent = rand() % 100;
						if (percent < 40) {
							mazeMap[bombPos[i].y - j][bombPos[i].x] = '8';
						}
						else if (percent < 70) {
							mazeMap[bombPos[i].y - j][bombPos[i].x] = '5';
						}
						else if (percent < 80) {
							mazeMap[bombPos[i].y - j][bombPos[i].x] = '6';
						}
						else {
							mazeMap[bombPos[i].y - j][bombPos[i].x] = '7';
						}
					}
					else {
						mazeMap[bombPos[i].y - j][bombPos[i].x] = '1';
					}
				}
			}
			if (bombPos[i].y + j < 19) {
				if (mazeMap[bombPos[i].y + j][bombPos[i].x] == '0') {
					if (rand() % 100 < 5) {
						int percent = rand() % 100;
						if (percent < 40) {
							mazeMap[bombPos[i].y + j][bombPos[i].x] = '8';
						}
						else if (percent < 70) {
							mazeMap[bombPos[i].y + j][bombPos[i].x] = '5';
						}
						else if (percent < 80) {
							mazeMap[bombPos[i].y + j][bombPos[i].x] = '6';
						}
						else {
							mazeMap[bombPos[i].y + j][bombPos[i].x] = '7';
						}
					}
					else {
						mazeMap[bombPos[i].y + j][bombPos[i].x] = '1';
					}
					
				}
			}
			if (bombPos[i].x - j > 0) {
				if (mazeMap[bombPos[i].y][bombPos[i].x - j] == '0') {
					if (rand() % 100 < 5) {
						int percent = rand() % 100;
						if (percent < 40) {
							mazeMap[bombPos[i].y][bombPos[i].x - j] = '8';
						}
						else if (percent < 70) {
							mazeMap[bombPos[i].y][bombPos[i].x - j] = '5';
						}
						else if (percent < 80) {
							mazeMap[bombPos[i].y][bombPos[i].x - j] = '6';
						}
						else {
							mazeMap[bombPos[i].y][bombPos[i].x - j] = '7';
						}
					}
					else {
						mazeMap[bombPos[i].y][bombPos[i].x - j] = '1';
					}
					
				}
			}
			if (bombPos[i].x + j < 19) {
				if (mazeMap[bombPos[i].y][bombPos[i].x + j] == '0') {
					if (rand() % 100 < 5) {
						int percent = rand() % 100;
						if (percent < 40) {
							mazeMap[bombPos[i].y][bombPos[i].x + j] = '8';
						}
						else if (percent < 70) {
							mazeMap[bombPos[i].y][bombPos[i].x + j] = '5';
						}
						else if (percent < 80) {
							mazeMap[bombPos[i].y][bombPos[i].x + j] = '6';
						}
						else {
							mazeMap[bombPos[i].y][bombPos[i].x + j] = '7';
						}
					}
					else {
						mazeMap[bombPos[i].y][bombPos[i].x + j] = '1';
					}
					
				}
			}
		}
		
		
	}
	if (deathCheck(player, bombPos, addedBomb) == false) {
		player->location.x = 1;
		player->location.y = 1;
		player->bombPower = 1;
		player->bombCount = 1;
		player->push = false;
		player->transParency = false;
		player->wallPush = false;
	}
	*addedBomb = 0;
}

bool deathCheck(PPLAYER player, PPOINT bombPos, int* addedBomb) {
	for (int i = 0; i < *addedBomb; i++) {
		for (int j = 0; j < player->bombPower + 1; j++) {
			if ((player->location.x == bombPos[i].x && player->location.y == bombPos[i].y) ||
				(player->location.x == bombPos[i].x + j && player->location.y == bombPos[i].y) ||
				(player->location.x == bombPos[i].x - j && player->location.y == bombPos[i].y) ||
				(player->location.x == bombPos[i].x && player->location.y == bombPos[i].y + j) ||
				(player->location.x == bombPos[i].x && player->location.y == bombPos[i].y - j)) {
				return false;
			}
		}
		
	}
	return true;
}

bool addItem(char item, PPLAYER player) {
	if (item == '5') {
		if (player->bombPower < 4) {
			player->bombPower++;
		}
		return true;
	}
	else if (item == '6') {
		player->wallPush = 1;
		return true;
	}
	else if (item == '7') {
		player->transParency = 1;
		return true;
	}
	else if (item == '8') {
		if (player->bombCount < 5) {
			player->bombCount++;
		}
		return true;
	}

	return false;
}