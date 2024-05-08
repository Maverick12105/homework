#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
	int PIN[5] = {7,1,2,1,3};
	int randMask[9];
	int PINEntry;
	int correctNum;
	int PINcheck;

	do 
	{
		cout << "PIN: 1 2 3 4 5 6 7 8 9" << endl;
		cout << "NUM:";
		for (int i = 0; i < 9; ++i)
		{
			randMask[i] = rand() % 4;
			cout << " " << randMask[i];
		}
		cout << "\n=> ";
		while (true)
		{
			cin >> PINEntry;
			if (0 <= PINEntry && PINEntry <= 99999) break;
			cout << "invalid Input, try again => ";
		}
		correctNum = 0;
		for (int i = 0; i < 5; ++i)
		{
			PINcheck = PINEntry / int(pow(10, 4 - i)) % 10;
			if (randMask[PIN[i] - 1] != PINcheck)
			{
				cout << "incorrect PIN, try again" << endl;
				break;
			}
			++correctNum;
		}
	} while (correctNum < 5);
	cout << "PIN correct";


	return 0;
}