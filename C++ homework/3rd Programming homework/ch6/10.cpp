#include <iostream>
using namespace std;

class Weight
{
public:
	void setWeightPounds();
	void setWeightKilograms();
	void setWeightOunces();
	void output();
private:
	double lbs;
};

int main()
{
	Weight w;
	char weightScale;

	cout << "(lb/kg/oz)? ";
	cin >> weightScale;
	cout << "=> ";

	switch (weightScale)
	{
	case 'l':
		w.setWeightPounds(); break;
	case 'k':
		w.setWeightKilograms(); break;
	case 'o':
		w.setWeightOunces(); break;
	default:
		break;
	}

	w.output();

	return 0;
}

void Weight::setWeightPounds()
{
	cin >> lbs;
}

void Weight::setWeightKilograms()
{
	cin >> lbs;
	lbs *= 2.21;
}

void Weight::setWeightOunces()
{
	cin >> lbs;
	lbs /= 16;
}

void Weight::output()
{
	cout << lbs << "lbs" << endl;
	cout << lbs / 2.21<< "kg" << endl;
	cout << lbs * 16 << "oz" << endl;
}