#include <iostream>
using namespace std;

class Pizza
{
public:
	void outputDescription();
	double computePrice();
	void input();
private:
	char pizzaType[12];
	char pizzaSize;
	int topping;
};

int main()
{
	Pizza pizza;

	pizza.input();
	pizza.outputDescription();
	cout << pizza.computePrice() << " dollar";

	return 0;
}

void Pizza::outputDescription()
{
	switch (pizzaSize)
	{
	case 's':
	case 'S':
		cout << "Small "; break;
	case 'm':
	case 'M':
		cout << "Medium "; break;
	case 'l':
	case 'L':
		cout << "Large "; break;
	default:
		cout << "fail";
		break;
	}
	switch (pizzaType[0])
	{
	case 'd':
	case 'D':
		cout << "Deep dish "; break;
	case 'h':
	case 'H':
		cout << "Hand tossed "; break;
	case 'p':
	case 'P':
		cout << "pan "; break;
	default:
		cout << "fail";
		break;
	}
	cout << "pizza with " << topping << "pepperonicheese" << endl;
}

double Pizza::computePrice()
{
	cout << "it will be total of ";
	switch (pizzaSize)
	{
	case 's':
	case 'S':
		return 10 + 2 * topping;
	case 'm':
	case 'M':
		return 14 + 2 * topping;
	case 'l':
	case 'L':
		return 17 + 2 * topping;
	default:
		cout << "fail";
		break;
	}
}

void Pizza::input()
{
	int pepperoni, cheese;

	cout << "Flavor of the pizza? ";
	cin >> pizzaType;
	cout << "Size of the pizza? (S/M/L) ";
	cin >> pizzaSize;
	cout << "How many pepperoni would you want to add? ";
	cin >> pepperoni;
	cout << "How many cheese would you want to add? ";
	cin >> cheese;
	cout << endl;

	topping = pepperoni + cheese;
}