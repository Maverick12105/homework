#include <iostream>
using namespace std;

class Money
{
public:
	void input();
	double output();
private:
	int dollars;
	int cents;
};

int main()
{
	Money m;
	char repeat;

	do 
	{
		m.input();
		cout << m.output() << "$" << endl;
		cout << "repeat? y/n ";
		cin >> repeat;
	} while (repeat != 'n');

	return 0;
}

void Money::input()
{
	cout << "dollars ";
	cin >> dollars;
	cout << "cents ";
	cin >> cents;
}

double Money::output()
{
	return dollars + cents / 100.0;
}
