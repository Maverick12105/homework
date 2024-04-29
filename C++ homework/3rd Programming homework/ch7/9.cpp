#include <iostream>
using namespace std;

class ticTacToe
{
public:
	void start();
private:
	char board[9] = { '1','2','3','4','5','6','7','8','9' };
	char currentPlayer;
	char anotherRound = 'y';
	void conditionCheck();
	void turn(char player);
	void endRound();
	void getboard();
	void resetboard();
};

int main()
{
	ticTacToe game;

	game.start();

	return 0;
}

void ticTacToe::start()
{
	cout << "Game start" << endl;

	while (anotherRound != 'n')
	{
		turn('X');
		turn('O');
	}
}

void ticTacToe::conditionCheck()
{
	for (int i = 0; i < 3; ++i)
	{
		if (board[i + 1] == board[i] && board[i] == board[i + 2]) endRound();
		if (board[i + 3] == board[i] && board[i] == board[i + 6]) endRound();
	}
	if (board[0] == board[4] && board[4] == board[8]) endRound();
	if (board[2] == board[4] && board[4] == board[6]) endRound();
}

void ticTacToe::turn(char player)
{
	currentPlayer = player;

	char number;

	while (anotherRound != 'n')
	{
		number = 0;
		getboard();
		cout << currentPlayer << "'s turn, choose a number => ";
		cin >> number;
		number -= '1';
		if (0 <= number && number <= 8)
		{
			if (board[number] != 'X' && board[number] != 'O')
			{
				board[number] = currentPlayer;
				conditionCheck();
				break;
			}
		}
		cout << "invalid input" << endl;
	}

}

void ticTacToe::endRound()
{
	getboard();
	cout << "Player " << currentPlayer << " win" << endl;
	cout << "another round? (y/n) ";
	while (true)
	{
		cin >> anotherRound;
		if (anotherRound == 'y' || anotherRound == 'n')
		{
			resetboard();
			break;
		}
		cout << "invalid input, try again => " << endl;
	}
}

void ticTacToe::getboard()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = i * 3; j < i * 3 + 3; ++j)
			cout << " " << board[j];
		cout << endl;
	}
}

void ticTacToe::resetboard()
{
	for (int i = 0; i < 9; ++i) board[i] = i + '1';
}