#include <iostream>
#include <conio.h>
#include "function.h"
using namespace std;


int main()
{
	POINT startPos;
	POINT endPos;
	POINT playerPos;

	char mazeMap[21][21] = {};
	setMaze(mazeMap, &startPos, &endPos, &playerPos);
	


	while (true) {
		system("cls");
		dpMap(mazeMap, &playerPos);
		if (playerPos.x == endPos.x && playerPos.y == endPos.y) {
			cout << "Congratulation!\n";
			break;
		}
		cout << "w: up d: down a: left d: right q: end \n";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q') break;
		movePlayer(mazeMap, &playerPos, cInput);
	}
	

	return 0;
}

