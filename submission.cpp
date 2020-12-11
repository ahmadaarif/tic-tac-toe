#include<iostream>
#include<windows.h>
using namespace std;
int start();
void board();
void instruction();
void colourchg();
int checkwin();
char sqr[10] = { '0','1','2','3','4','5','6','7','8','9' };
char sqr1[10] = { '0','1','2','3','4','5','6','7','8','9' };
void main()
{
	int  player = 1, i = 0;
	char x = '0', put, choice;
	while (x != '4')
	{
		x = start();
		if (x == '1')
		{
			do
			{
				board();
				if (player % 2 == true)
					player = 1;
				else
					player = 2;
				cout << "\nPLAYER " << player << ", enter a number=  ";
				cin >> choice;
				if (player == true)
					put = 'X';
				else
					put = 'O';
				if (choice == '1' && sqr[1] == '1')
					sqr[1] = put;
				else if (choice == '2' && sqr[2] == '2')
					sqr[2] = put;
				else if (choice == '3' && sqr[3] == '3')
					sqr[3] = put;
				else if (choice == '4' && sqr[4] == '4')
					sqr[4] = put;
				else if (choice == '5' && sqr[5] == '5')
					sqr[5] = put;
				else if (choice == '6' && sqr[6] == '6')
					sqr[6] = put;
				else if (choice == '7' && sqr[7] == '7')
					sqr[7] = put;
				else if (choice == '8' && sqr[8] == '8')
					sqr[8] = put;
				else if (choice == '9' && sqr[9] == '9')
					sqr[9] = put;
				else
				{
					cout << "INVALID MOVE ";
					Sleep(500);
				}
				i = checkwin();

				player++;
			} while (i == -1);
			board();
			if (i == 1)
				cout << "CONGRATS PLAYER " << --player << " WINS " << endl;
			else
				cout << "GAME DRAWN" << endl;
			for (int k = 0; k < 10; k++)
			{
				sqr[k] = sqr1[k];
			}
			Sleep(3500);
			system("cls");
		}
		else if (x == '2')
		{
			instruction();
		}
		else if (x == '3')
		{
			colourchg();
		}
		else if (x == '4')
		{
			Sleep(700);
		}
		else
		{
			cout << "INVALID ENTRY.";
			Sleep(700);
			system("cls");
		}
	}
}
int start()
{
	char xx;
	cout << "_______ _____  _____    _______  _____   _____    _______  _____   _____" << endl;
	cout << "   |      |   |            |    |     | |            |    |     | |" << endl;
	cout << "   |      |   |            |    |-----| |            |    |     | |---" << endl;
	cout << "   |    __|__ |_____       |    |     | |_____       |    |_____| |_____" << endl;

	cout << "\n\n\n\n";
	cout << "PRESS" << endl;
	cout << "1: NEW GAME" << endl;
	cout << "2: INSTRUCTIONS" << endl;
	cout << "3: CHANGE COLOUR" << endl;
	cout << "4: EXIT" << endl;
	cin >> xx;
	return xx;
}
void board()
{
	system("cls");
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "           |     |     " << endl;
	cout << "        " << sqr[1] << "  |  " << sqr[2] << "  |  " << sqr[3] << endl;
	cout << "      _____|_____|_____" << endl;
	cout << "           |     |     " << endl;
	cout << "        " << sqr[4] << "  |  " << sqr[5] << "  |  " << sqr[6] << endl;
	cout << "      _____|_____|_____" << endl;
	cout << "           |     |     " << endl;
	cout << "        " << sqr[7] << "  |  " << sqr[8] << "  |  " << sqr[9] << endl;
	cout << "           |     |     " << endl << endl;
}
void instruction()
{
	system("cls");
	char a = '1';
	while (a != '0')
	{
		cout << "                     INSTRUCTIONS: \n\n";
		cout << "1. ENTER THE NUMBER BETWEEN 1-9 WHICH YOU WANT TO SELECT " << endl;
		cout << "2. YOU CANNOT SELECT SAME NUMBER TWICE" << endl;
		cout << "3. YOU CANNOT CHANGE THE POSITION AFTER YOU  HAVE SELECTED" << endl;
		cout << "4. THE PERSON WHO MAKE 3 IN A ROW, COLUMN OR DIAGONAL SHALL WIN" << endl;
		cout << "PRESS 0 FOR BACK \n";
		cin >> a;
		system("cls");
	}
}
void colourchg()
{
	system("cls");
	char i;
	for (;;)
	{
		cout << "PRESS \n 1- BLUE \n 2- GREEN \n 3- RED \n 4- PURPLE \n 5- YELLOW \n 6- WHITE \n";
		cin >> i;
		if (i == '1')
		{
			system("COLOR 1");
			break;
		}
		else if (i == '2')
		{
			system("COLOR 2");
			break;
		}
		else if (i == '3')
		{
			system("COLOR 4");
			break;
		}
		else if (i == '4')
		{
			system("COLOR 5");
			break;
		}
		else if (i == '5')
		{
			system("COLOR 6");
			break;
		}
		else if (i == '6')
		{
			system("COLOR 7");
			break;
		}
		else
		{
			cout << "ENTER VALID KEY." << endl;
			Sleep(500);
			system("cls");
		}
	}
	system("cls");
}
int checkwin()
{
	if (sqr[1] == sqr[2] && sqr[2] == sqr[3])
		return 1;
	else if (sqr[4] == sqr[5] && sqr[5] == sqr[6])
		return 1;
	else if (sqr[7] == sqr[8] && sqr[8] == sqr[9])
		return 1;
	else if (sqr[1] == sqr[4] && sqr[4] == sqr[7])
		return 1;
	else if (sqr[2] == sqr[5] && sqr[5] == sqr[8])
		return 1;
	else if (sqr[3] == sqr[6] && sqr[6] == sqr[9])
		return 1;
	else if (sqr[1] == sqr[5] && sqr[5] == sqr[9])
		return 1;
	else if (sqr[3] == sqr[5] && sqr[5] == sqr[7])
		return 1;
	else if (sqr[1] != '1' && sqr[2] != '2' && sqr[3] != '3' && sqr[4] != '4' && sqr[5] != '5' && sqr[6] != '6' && sqr[7] != '7' && sqr[8] != '8' && sqr[9] != '9')
		return 0;
	else
		return -1;
}
