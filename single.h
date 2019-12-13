#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class TicTacBox
{
public:
	TicTacBox();
	~TicTacBox();

	//Allows player to code into box
	void playBox(int play, int player); 

	//detects if the box has been won
	int win();

	//getter for the array
	int getter(int get);

	int arr[9];

private:
	
};

TicTacBox::TicTacBox()
{
	for (int i = 0; i < 9; i++) {
		arr[i] = 0;
	}
}

TicTacBox::~TicTacBox()
{
}

void TicTacBox::playBox(int play, int player) {
	if (arr[play] == 0) {
		arr[play] = player;
	}
}

int TicTacBox::win() {
	if (arr[0] == arr[4] && arr[0] == arr[8] && arr[0] != 0) {
		return arr[0];
	}
	else if (arr[2] == arr[4] && arr[2] == arr[6] && arr[2] != 0) {
		return arr[2];
	}
	else if (arr[0] == arr[3] && arr[0] == arr[6] && arr[0] != 0) {
		return arr[0];
	}
	else if (arr[1] == arr[4] && arr[1] == arr[7] && arr[1] != 0) {
		return arr[1];
	}
	else if (arr[2] == arr[5] && arr[2] == arr[8] && arr[2] != 0) {
		return arr[2];
	}
	else if (arr[0] == arr[1] && arr[0] == arr[2] && arr[2] != 0) {
		return arr[2];
	}
	else if (arr[3] == arr[4] && arr[3] == arr[5] && arr[3] != 0) {
		return arr[3];
	}
	else if (arr[6] == arr[7] && arr[6] == arr[8] && arr[6] != 0) {
		return arr[6];
	}
	return 0;
}

int TicTacBox::getter(int get) {
	return arr[get];
}

//Ultimate box implementation
class UT3
{
public:
	UT3();
	~UT3();

	//play in box
	void boxplay(int play, int player, int box);

	//win
	int win();

	int boxwin(int box);

	//getter
	int getter(int getBox, int getPlay);

	TicTacBox total[9];

private:
	
};

UT3::UT3()
{
}

UT3::~UT3()
{
}

void UT3::boxplay(int play, int player, int box) {
	total[box].playBox(play, player);
}

int UT3::win() {
	if (total[0].win() == total[4].win() && total[0].win() == total[8].win() && total[0].win() != 0) {
		return total[0].win();
	}
	else if (total[2].win() == total[4].win() && total[2].win() == total[6].win() && total[2].win() != 0) {
		return total[2].win();
	}
	else if (total[0].win() == total[3].win() && total[0].win() == total[6].win() && total[0].win() != 0) {
		return total[0].win();
	}
	else if (total[1].win() == total[4].win() && total[1].win() == total[7].win() && total[1].win() != 0) {
		return total[1].win();
	}
	else if (total[2].win() == total[5].win() && total[2].win() == total[8].win() && total[2].win() != 0) {
		return total[2].win();
	}
	else if (total[0].win() == total[1].win() && total[0].win() == total[2].win() && total[0].win() != 0) {
		return total[0].win();
	}
	else if (total[3].win() == total[4].win() && total[3].win() == total[5].win() && total[3].win() != 0) {
		return total[3].win();
	}
	else if (total[6].win() == total[7].win() && total[6].win() == total[8].win() && total[8].win() != 0) {
		return total[6].win();
	}
	return 0;
}

int UT3::getter(int getBox, int getPlay) {
	return total[getBox].getter(getPlay);
}

void printout(UT3 out) {
	cout << "Current played box: " << endl;
	//row 1
	cout << out.getter(0, 0) << out.getter(0, 1) << out.getter(0, 2) << "|";
	cout << out.getter(1, 0) << out.getter(1, 1) << out.getter(1, 2) << "|";
	cout << out.getter(2, 0) << out.getter(2, 1) << out.getter(2, 2) << endl;
	//row 2
	cout << out.getter(0, 3) << out.getter(0, 4) << out.getter(0, 5) << "|";
	cout << out.getter(1, 3) << out.getter(1, 4) << out.getter(1, 5) << "|";
	cout << out.getter(2, 3) << out.getter(2, 4) << out.getter(2, 5) << endl;
	//row 3
	cout << out.getter(0, 6) << out.getter(0, 7) << out.getter(0, 8) << "|";
	cout << out.getter(1, 6) << out.getter(1, 7) << out.getter(1, 8) << "|";
	cout << out.getter(2, 6) << out.getter(2, 7) << out.getter(2, 8) << endl;
	cout << "-----------" << endl;
	//row 4
	cout << out.getter(3, 0) << out.getter(3, 1) << out.getter(3, 2) << "|";
	cout << out.getter(4, 0) << out.getter(4, 1) << out.getter(4, 2) << "|";
	cout << out.getter(5, 0) << out.getter(5, 1) << out.getter(5, 2) << endl;
	//row 5
	cout << out.getter(3, 3) << out.getter(3, 4) << out.getter(3, 5) << "|";
	cout << out.getter(4, 3) << out.getter(4, 4) << out.getter(4, 5) << "|";
	cout << out.getter(5, 3) << out.getter(5, 4) << out.getter(5, 5) << endl;
	//row 6
	cout << out.getter(3, 6) << out.getter(3, 7) << out.getter(3, 8) << "|";
	cout << out.getter(4, 6) << out.getter(4, 7) << out.getter(4, 8) << "|";
	cout << out.getter(5, 6) << out.getter(5, 7) << out.getter(5, 8) << endl;
	cout << "-----------" << endl;
	//row 7
	cout << out.getter(6, 0) << out.getter(6, 1) << out.getter(6, 2) << "|";
	cout << out.getter(7, 0) << out.getter(7, 1) << out.getter(7, 2) << "|";
	cout << out.getter(8, 0) << out.getter(8, 1) << out.getter(8, 2) << endl;
	//row 8
	cout << out.getter(6, 3) << out.getter(6, 4) << out.getter(6, 5) << "|";
	cout << out.getter(7, 3) << out.getter(7, 4) << out.getter(7, 5) << "|";
	cout << out.getter(8, 3) << out.getter(8, 4) << out.getter(8, 5) << endl;
	//row 9
	cout << out.getter(6, 6) << out.getter(6, 7) << out.getter(6, 8) << "|";
	cout << out.getter(7, 6) << out.getter(7, 7) << out.getter(7, 8) << "|";
	cout << out.getter(8, 6) << out.getter(8, 7) << out.getter(8, 8) << endl;
}

int UT3::boxwin(int box) {
	return total[box].win();
}