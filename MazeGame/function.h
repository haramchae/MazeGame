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



void setMaze(char mazeMap[21][21], PPOINT startPos, PPOINT endPos, PPOINT playerPos);
void dpMap(char mazeMap[21][21], PPOINT playerPos);
void movePlayer(char mazeMap[21][21], PPOINT playerPos, char cInput);
void moveUp(char mazeMap[21][21], PPOINT playerPos);
void moveDown(char mazeMap[21][21], PPOINT playerPos);
void moveLeft(char mazeMap[21][21], PPOINT playerPos);
void moveRight(char mazeMap[21][21], PPOINT playerPos);

#endif // !FUNCTION_H

