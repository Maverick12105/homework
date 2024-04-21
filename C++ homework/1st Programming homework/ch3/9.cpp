#include <iostream>
#include <stdlib.h>
using namespace std;

int dice_roll();

int main()
{
	double wins = 0, losses = 0;
	int rolls, rolls2;

	for (int i = 0; i < 10000; ++i)
	{
		rolls = dice_roll();

		switch (rolls)
		{
		case 7:
		case 11:
			++wins;
			break;

		case 2:
		case 3:
		case 12:
			++losses;
			break;

		default:
			while (true)
			{
				rolls2 = dice_roll();

				if (rolls2 == rolls)
				{
					++wins;
					break;
				}

				if (rolls2 == 7)
				{
					++losses;
					break;
				}
			}
			break;
		}
	}

	cout << wins / (wins + losses);
			
	return 0;
}

int dice_roll()
{
	return (rand() % 6 + rand() % 6) + 2;
}