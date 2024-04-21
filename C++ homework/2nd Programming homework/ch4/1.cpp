#include <iostream>
using namespace std;

void input(int& hour, int& minute);
void conversion(int& hour, int minute, char& meridiem);
void output(int hour, int minute, char meridiem);

int main()
{
	int hour, minute;
	char meridiem, repeat;

	while (true)
	{
		input(hour, minute);
		conversion(hour, minute, meridiem);
		output(hour, minute, meridiem);
		cout << "Do you wish to do it again? y/n:" << endl;
		cin >> repeat;
		if (repeat == 'n') break;
	}

	return 0;
}

void input(int& hour, int& minute)
{
	cout << "Please enter the time you wish to convert in 24-hour notation" << endl;
	while(true)
	{
		cout << "Hour => ";
		cin >> hour;
		cout << "Minute => ";
		cin >> minute;
		if ((hour >= 0 && hour < 24) && (minute >= 0 && minute < 60)) break;
		cout << "Invlid input, please try again." << endl;
	} 
}

void conversion(int& hour, int minute, char& meridiem)
{
	if (hour >= 12)
	{
		meridiem = 'P';
		if (hour > 12)
		{
			hour -= 12;
		}
	}
	else
	{
		meridiem = 'A';
		if (hour == 0)
		{
			hour = 12;
		}
	}
}

void output(int hour, int minute, char meridiem)
{
	if (hour < 10) cout << 0 << hour;
	else cout << hour;
	cout << ":";
	if (minute < 10) cout << 0 << minute;
	else cout << minute;
	switch (meridiem)
	{
	case 'A':
		cout << "AM" << endl;
		break;
	case 'P':
		cout << "PM" << endl;
		break;
	}
}