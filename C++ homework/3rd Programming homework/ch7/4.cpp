#include <iostream>
using namespace std;

class HotDogStand
{
public:
	HotDogStand(int ID, int numberSold);
	void JustSold();
	int getSold();
	static int getTotalSold();
	int getID();
private:
	int ID;
	int numberSold;
	static int totalSold;
};

int HotDogStand::totalSold = 0;

int main()
{
	int ID, sold;

	cout << "Id for the first stand => ";
	cin >> ID;
	cout << "How many had been sold? => ";
	cin >> sold;
	HotDogStand h1(ID, sold);

	cout << "Id for the second stand => ";
	cin >> ID;
	cout << "How many had been sold? => ";
	cin >> sold;
	HotDogStand h2(ID, sold);

	cout << "Id for the third stand => ";
	cin >> ID;
	cout << "How many had been sold? => ";
	cin >> sold;
	HotDogStand h3(ID, sold);

	h1.JustSold();
	h1.JustSold();
	h2.JustSold();
	h2.JustSold();
	h1.JustSold();
	h3.JustSold();

	cout << "Hotdog stand " << h1.getID() << " sold " << h1.getSold() << " hotdogs." << endl;
	cout << "Hotdog stand " << h2.getID() << " sold " << h2.getSold() << " hotdogs." << endl;
	cout << "Hotdog stand " << h3.getID() << " sold " << h3.getSold() << " hotdogs." << endl;
	cout << "All hotdog stand sold " << HotDogStand::getTotalSold() << " in total.";

	return 0;
}

HotDogStand::HotDogStand(int ID, int numberSold) : ID(ID), numberSold(numberSold)
{
	totalSold += numberSold;
}

void HotDogStand::JustSold()
{
	cout << "Hotdog stand " << ID << " just sold a hotdog" << endl;
	++numberSold;
	++totalSold;
}

int HotDogStand::getSold()
{
	return numberSold;
}

int HotDogStand::getTotalSold()
{
	return totalSold;
}

int HotDogStand::getID()
{
	return ID;
}