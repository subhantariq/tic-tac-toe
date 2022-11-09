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
		bool flag = rand() % 2;//randomly selecting person for toss
		if (flag)
			cout << firstPlayer;
		else
			cout << secondPlayer;
		cout << " please select head(H) or tail(T) for toss: ";
		cin >> option;
		while (option != 'H' && option != 'h' && option != 'T' && option != 't') {
			cout << "Wrong option entered! Please choose correct option: ";
			cin >> option;//taking value again if wrong input entered
		}
		if (option == 'H' || option == 'h')//this is for checking either a person win toss or not
			option = '1';
		else 
			option = '0';
		bool temp = rand() % 2;//toss happening here
		cout << "Coin tosses for ";
		if (temp == 0)
			cout << "head" << endl;
		else
			cout << "tail" << endl;
		if (int(option) == int(temp)) {//checking toss results
			if (flag)
				temp = 1;
			else
				temp = 0;
		}
		else {
			if (flag)
				temp = 0;
			else
				temp = 1;
		}
		if (temp) {
			cout <<firstPlayer<< " won the toss!" << endl;
			cout << "Please select your marker [o] or [x]: ";
			cin >> marker1;
			while (marker1 != 'x' && marker1 != 'X' && marker1 != '0' && marker1 != 'o' && marker1 != 'O') {
				cout << "Wrong marker selected! Enter again: ";
				cin >> marker1;
			}
			if (marker1 == 'x' || marker1 == 'X') {
				marker2 = 'o';
			}
			else
				marker2 = 'x';
		}
		else {
			cout << secondPlayer << " won the toss!" << endl;
			cout << "Please select your marker [o] or [x]: ";
			cin >> marker2;
			while (marker2 != 'x' && marker2 != 'X' && marker2 != '0' && marker2 != 'o' && marker2 != 'O') {
				cout << "Wrong marker selected! Enter again: ";
				cin >> marker2;
			}
			if (marker2 == 'x' || marker2 == 'X') {
				marker1 = 'o';
			}
			else
				marker1 = 'x';
		}
		char arr[10] = "123456789";
		int number;
		for (int i = 1, n = 0; i <= 9; i++) {//tic tac toe pattern
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
			if (temp) {
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
				temp=temp-1;
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
				temp++;
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
				if (temp)
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
			cout << "Match drawn" << endl;
		cout << "Want to play again Y/N: ";
		cin >> option;
		while (option != 'Y' && option != 'y' && option != 'n' && option != 'N') {
			cout << "Wrong input! Enter again: ";
			cin >> option;
		}
		cin.ignore(); /* if user wants to play again newline character will
		not remove from input stream (screen) created due to cin >> option if
		this line is not entered while choosing yes it will not ask for first player
		name because it directly recieves a newline with is terminator for getline*/
	} while (option=='y'||option=='Y');
}