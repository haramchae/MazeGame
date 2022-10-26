#pragma once

#ifndef FUNCTION_H
#define FUNCTION_H

struct _PointLocation
{
	int x;
	int y;
};

typedef _PointLocation POINT;
typedef _PointLocation* PPOINT;

struct _PlayerModel {
	_PointLocation location;
	bool wallPush;
	bool push;
	bool transParency;
	int bombPower;
	int bombCount;
};

typedef _PlayerModel PLAYER;
typedef _PlayerModel* PPLAYER;



void setMaze(char mazeMap[21][21], PPOINT startPos, PPOINT endPos, PPLAYER player);
void dpMap(char mazeMap[21][21], PPLAYER player);
void movePlayer(char mazeMap[21][21], PPLAYER player, char cInput);
void moveUp(char mazeMap[21][21], PPLAYER player);
void moveDown(char mazeMap[21][21], PPLAYER player);
void moveLeft(char mazeMap[21][21], PPLAYER player);
void moveRight(char mazeMap[21][21], PPLAYER player);
void createBomb(char mazeMap[21][21], PPLAYER player, PPOINT bombPos, int* addedBomb);
void fireBomb(char mazeMap[21][21], PPLAYER player, PPOINT bombPos, int* addedBomb);
bool deathCheck(PPLAYER player, PPOINT bombPos, int* addedBomb);
bool addItem(char item, PPLAYER player);

#endif // !FUNCTION_H

