#include <iostream>
using namespace std;

int main()
{
	int number_of_stories, frist_price, base_price, amenities, taxes;
	double amenities_rate, taxes_rate;

	cout << "How many stories does the apartment have?\n=> ";
	cin >> number_of_stories;
	cout << "What is the price of the first floor?\n=> ";
	cin >> frist_price;
	cout << "How much is the amenities rate(decimal)\n=> ";
	cin >> amenities_rate;
	cout << "How much is the taxe rate(decimal)\n=> ";
	cin >> taxes_rate;

	base_price = frist_price;

	for (int i = 1; i <= number_of_stories; ++i)
	{
		cout << i;
		switch (i)
		{
		case(1):
			cout << "st ";
			break;
		case(2):
			cout << "nd ";
			break;
		case(3):
			cout << "rd ";
			break;
		default:
			cout << "th ";
			break;
		}
		cout << "floor's base price = " << base_price;

		amenities = base_price * amenities_rate;
		cout << " amenities charge = " << amenities;
		taxes = (base_price + amenities) * taxes_rate;
		cout << " taxes = " << taxes;
		cout << "the total price = " << base_price + amenities + taxes << endl;
		base_price = frist_price + frist_price * i * 0.02;
	}

	return 0;
}