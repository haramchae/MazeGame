#include <iostream>
#include <conio.h>
#include "function.h"
using namespace std;

/*
* 0: Wall
* 1: Road
* 2: start
* 3: Destination
* 4: Bomb
* 5: Bomb Power item
* 6: Push item
* 7: transparency item
* 8: add bomb count
*/


int main()
{
	const int bombSize = 5;
	int addedBomb = 0;

	PLAYER player = {};
	player.bombPower = 1;
	player.bombCount = 1;
	POINT startPos;
	POINT endPos;
	POINT bombPos[bombSize];

	char mazeMap[21][21] = {};
	setMaze(mazeMap, &startPos, &endPos, &player);


	while (true) {
		system("cls");
		dpMap(mazeMap, &player);
		if (player.location.x == endPos.x && player.location.y == endPos.y) {
			cout << "Congratulation!\n";
			break;
		}
		cout << "Items: " << "\n";
		cout << "Bomb count: " << player.bombCount << "\n";
		cout << "Bomb power: " << player.bombPower<<"\n";
		cout << "Transparency: ";
		if (player.transParency) cout << "O\n";
		else cout << "X\n";
		cout << "Wall push: ";
		if (player.wallPush) cout << "O";
		else cout << "X";
		cout << "\t Push: ";
		if (player.push) cout << "ON\n";
		else cout << "OFF\n";

		cout << "Control: " << "\n";
		cout << "b: bomb n: boom! \n";
		cout << "m: push on/off\n";
		cout << "w: up d: down a: left d: right q: end \n";
		
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q') break;
		else if (cInput == 'b' || cInput == 'B') {
			createBomb(mazeMap, &player, bombPos, &addedBomb);
		}
		else if (cInput == 'n' || cInput == 'N') {
			fireBomb(mazeMap, &player, bombPos, &addedBomb);
		}
		else if (cInput == 'm' || cInput == 'M') {
			if (player.wallPush) {
				player.push = !player.push;
			}
		}
		movePlayer(mazeMap, &player, cInput);
	}
	

	return 0;
}

