#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
	srand(time(0));
	char option,marker1,marker2;
	const int size = 100;
	char firstPlayer[size], secondPlayer[size];
	do {
		cout << "Enter name of first player: ";
		cin.getline(firstPlayer, size);
		cout << "Enter name of second player: ";
		cin.getline(secondPlayer, size);
		bool flag = rand() % 2;
		if (flag)
			cout << firstPlayer;
		else
			cout << secondPlayer;
		cout << " please select head(H) or tail(T) for toss: ";
		cin >> option;
		while (option != 'H' && option != 'h' && option != 'T' && option != 't') {
			cout << "Wrong option entered! Please choose correct option: ";
			cin >> option;
		}
		bool temp = rand() % 2;
		cout << "Coin tosses for ";
		if (temp == 0)
			cout << "head" << endl;
		else
			cout << "tail" << endl;
		if (temp && (option == 'T' || option == 't')) {
			if (flag) {
				cout << firstPlayer;
				temp = 1;
			}
			else {
				cout << secondPlayer;
				temp = 0;
			}
		}
		else if (temp == 0 && (option == 'h' || option == 'H')) {
			if (flag) {
				cout << firstPlayer;
				temp = 1;
			}
			else {
				cout << secondPlayer;
				temp = 0;
			}
		}
		else {
			if (flag) {
				cout << secondPlayer;
				temp = 0;
			}
			else {
				cout << firstPlayer;
				temp = 1;
			}
		}
		cout << " won the toss!" << endl;
		int turn;
		cout << "Please select your marker [o] or [x]: ";
		if (temp) {
			turn = 1;
			cin >> marker1;
			if (marker1 == 'x' || marker1 == 'X') {
				marker2 = 'o';
			}
			else
				marker2 = 'x';
		}
		else {
			turn = 0;
			cin >> marker2;
			if (marker2 == 'x' || marker2 == 'X') {
				marker1 = 'o';
			}
			else
				marker1 = 'x';
		}
		char arr[10] = "123456789";
		int number;
		for (int i = 1, n = 0; i <= 9; i++) {
			for (int j = 1; j < 18; j++)
			{
				if (j % 6 == 0)
					cout << "|";
				else if (i % 3 == 0 && i < 9)
					cout << "_";
				else if ((i == 2 || i == 5 || i == 8) && j % 3 == 0)
					cout << arr[n++];
				else
					cout << " ";
			}
			cout << endl;
		}
		do {
			flag = true;
			if (turn) {
				cout << firstPlayer << " - [" << marker1 << "] your turn: ";
				do {
					cin >> number;
					for (int i = 0; i < 9; i++) {
						if ((int(arr[i] - 48)) == number) {
							flag = false;
							break;
						}
					}
					if (flag)
						cout << "Wrong input! Please select from options: ";
				} while (flag == true);
				arr[number - 1] = marker1;
				turn--;
			}
			else {
				cout << secondPlayer << " - [" << marker2 << "] your turn: ";
				do {
					cin >> number;
					for (int i = 0; i < 9; i++) {
						if (int(arr[i] - 48) == number) {
							flag = false;
							break;
						}
					}
					if (flag)
						cout << "Wrong input! Please select from options: ";
				} while (flag == true);
				arr[number - 1] = marker2;
				turn++;
			}


			if (arr[0] == arr[1] && arr[1] == arr[2])
				flag = true;
			else if (arr[3] == arr[4] && arr[4] == arr[5])
				flag = true;
			else if (arr[6] == arr[7] && arr[7] == arr[8])
				flag = true;
			else if (arr[0] == arr[3] && arr[3] == arr[6])
				flag = true;
			else if (arr[1] == arr[4] && arr[4] == arr[7])
				flag = true;
			else if (arr[2] == arr[5] && arr[5] == arr[8])
				flag = true;
			else if (arr[0] == arr[4] && arr[4] == arr[8])
				flag = true;
			else if (arr[2] == arr[4] && arr[4] == arr[6])
				flag = true;
			for (int i = 1, n = 0; i <= 9; i++) {
				for (int j = 1; j < 18; j++)
				{
					if (j % 6 == 0)
						cout << "|";
					else if (i % 3 == 0 && i < 9)
						cout << "_";
					else if ((i == 2 || i == 5 || i == 8) && j % 3 == 0)
						cout << arr[n++];
					else
						cout << " ";
				}
				cout << endl;
			}
			if (flag) {
				if (turn)
					cout << secondPlayer;
				else
					cout << firstPlayer;
				cout << " Win the game." << endl;
				break;
			}
			for (int i = 0; i < 9; i++) {
				if (arr[i] >= '1' && arr[i] <= '9') {
					flag = true;
				}
			}
		} while (flag);
		if (flag == false)
			cout << "Match drawn";
		cout << "Want to play again Y/N: ";
		cin >> option;
		while (option != 'Y' && option != 'y' && option != 'n' && option != 'N') {
			cout << "Wrong input! Enter again: ";
			cin >> option;
		}
	} while (option=='y'||option=='Y');
}