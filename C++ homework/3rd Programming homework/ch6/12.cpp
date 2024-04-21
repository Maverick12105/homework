#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

class BoxOfProduce
{
public:
	void setContent(int ordinal, string content);
	string getContent(int ordinal);
	void output();
private:
	string veggi[3];
};

int main()
{
	BoxOfProduce box;
	fstream vlist;
	string veggis[5];
	char answer;
	int substituteFrom, substituteWith;

	vlist.open("vlist.txt");
	for (int i = 0; i < 5; ++i) vlist >> veggis[i];
	vlist.close();

	for (int i = 0; i < 3; ++i) box.setContent(i, veggis[rand() % 5]);

	do
	{
		box.output();
		cout << "Do you wish substitute any of them? (y/n) ";
		cin >> answer;
		if (answer == 'y')
		{
			cout << "Which one? (number) ";
			cin >> substituteFrom;
			cout << "Please choose one to substitute with:" << endl;
			for (int i = 0; i < 5; ++i) cout << i + 1 << ". " << veggis[i] << endl;
			cin >> substituteWith;
			box.setContent(substituteFrom - 1, veggis[substituteWith - 1]);
		}
	} while (answer != 'n');

	cout << "Thank you, the package consist of ";
	cout << box.getContent(0) << ", ";
	cout << box.getContent(1) << " and ";
	cout << box.getContent(2) << " will be deliver soon.";
	
	return 0;
}

void BoxOfProduce::setContent(int ordinal, string content)
{
	veggi[ordinal] = content;
}

string BoxOfProduce::getContent(int ordinal)
{
	return veggi[ordinal];
}

void BoxOfProduce::output()
{
	cout << "The current content of the box:" << endl;
	for (int i = 0; i < 3; ++i) cout << i + 1 << ". " << veggi[i] << endl;
}