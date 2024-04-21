#include <iostream>
#include <stdlib.h>
using namespace std;

int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);

int main()
{
	int humanTotalScore = 0, computerTotalScore = 0;

	cout << "Welcome to the game of Pig." << endl;

	while (true)
	{
		humanTotalScore += humanTurn(humanTotalScore);
		if (humanTotalScore >= 100)
		{
			cout << "You Won!";
			break;
		}
			
		computerTotalScore += computerTurn(computerTotalScore);
		if (computerTotalScore >= 100)
		{
			cout << "You lost!";
			break;
		}
	}

	return 0;
}


int humanTurn(int humanTotalScore)
{
	char answer;
	int score, turnScore = 0;

	cout << "Player's turn" << endl;

	do {

		score = rand() % 6 + 1;

		cout << "You rolled a " << score << ". ";

		switch (score)
		{
		case 1:
			cout << "You lose the turn and the score." << endl;
			return 0;
			break;
		default:
			turnScore += score;
			cout << "The total score is currently " << turnScore << endl;
			cout << "Roll or Hold? r/h ";
			cin >> answer;
			break;
		}
	} while (answer == 'r');

	cout << "Your current score is " << humanTotalScore + turnScore << endl;


	return turnScore;
}

int computerTurn(int computerTotalScore)
{
	int score, turnScore = 0;

	cout << "Opponent's turn" << endl;

	do {

		score = rand() % 6 + 1;

		cout << "The opponent rolled a " << score << ". ";

		switch (score)
		{
		case 1:
			cout << "The opponent lose the turn and the score." << endl;
			return 0;
			break;
		default:
			turnScore += score;
			cout << "The total score is currently " << turnScore << endl;
			break;
		}
	} while (turnScore < 20);

	cout << "The opponent's current score is " << computerTotalScore + turnScore << endl;

	return turnScore;
}