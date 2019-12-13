#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include "single.h"

using namespace std;

int chooseBox(UT3 boxplay) {
	int newbox;
	cout << "Choose new box to play in:" << endl;
	cin >> newbox;
	if (boxplay.boxwin(newbox) != 0) {
		cout << "That box has already been won, pick again:" << endl;
		return chooseBox(boxplay);
	}
	return newbox;
}

int choosePosition(TicTacBox posPlay) {
	int newPlay;
	cout << "Choose position to play in the box:" << endl;
	cin >> newPlay;
	if (posPlay.getter(newPlay) != 0) {
		cout << "That position has already been played, pick again:" << endl;
		return choosePosition(posPlay);
	}
	return newPlay;
}

int main(int argc, char* argv[]) {
	//variables
	string Player1;
	string Player2;
	UT3 playingBox;
	int play1;
	int play2 = 9;
	//game start
	cout << "Welcome to Ultimate Tic-Tac-Toe!" << endl;
	cout << "Game created by Abinav Sadhneni, NitronGaming Studios";
	cout << "Player 1 Name?" << endl;
	cin >> Player1;
	cout << "Hi " << Player1 << "!" << endl;
	cout << "Player 2 Name?" << endl;
	cin >> Player2;
	cout << "Hi " << Player2 << "!" << endl;

	cout << "Game Start: " << Player1 << " vs " << Player2 << endl;
	while (playingBox.win() == 0) {
		//player 1 turn
		cout << endl << endl;
		cout << Player1 << "'s turn" << endl;
		printout(playingBox);
		if (playingBox.boxwin(play2) != 0 || play2 == 9) {
			play2 = chooseBox(playingBox);
		}
		cout << "Playing in Box " << play2 << endl;
		play1 = choosePosition(playingBox.total[play2]);
		playingBox.boxplay(play1, 1, play2);
		cout << Player1 << " played in Box " << play2 << " in Position " << play1;
		//player 2 turn
		if (playingBox.win() == 0) {
			cout << endl << endl;
			cout << Player2 << "'s turn" << endl;
			printout(playingBox);
			if (playingBox.boxwin(play1) != 0) {
				play1 = chooseBox(playingBox);
			}
			cout << "Playing in Box " << play1 << endl;
			play2 = choosePosition(playingBox.total[play1]);
			playingBox.boxplay(play2, 2, play1);
			cout << Player1 << " played in Box " << play2 << " in Position " << play1;
		}
	}
	cout << endl << endl;
	if (playingBox.win() == 1) {
		cout << Player1 << " wins!";
	}
	else if (playingBox.win() == 2){
		cout << Player2 << " wins!";
	}
	cout << "Created by NitronGaming Studios";
	return 1;
}