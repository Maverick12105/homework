#include <iostream>
using namespace std;

double converToMPH(int minute, int second);
double converToMPH(double kph);

int main()
{
	int minute, second;
	double kph;
	char ans;

	do {
		cout << "time per mile or kph? 1/2" << endl << "=> ";
		cin >> ans;
		while (ans == '1')
		{
			cout << "minute => ";
			cin >> minute;
			cout << "second => ";
			cin >> second;
			if ((second >= 0 && second < 60) && (minute >= 0 && minute < 60))
			{
				cout << converToMPH(minute, second) << "mph" << endl;
				break;
			}
			cout << "Invlid Input";
		}
		if (ans == '2')
		{
			cout << "kph => ";
			cin >> kph;
			cout << converToMPH(kph) << "mph" << endl;
		}

		cout << "repeat? y/n" << endl << " => ";
		cin >> ans;

	} while (ans == 'y');

	return 0;
}

double converToMPH(int minute, int second)
{
	return 3600 / (minute * 60 + second);
}

double converToMPH(double kph)
{
	return kph * 1.61;
}