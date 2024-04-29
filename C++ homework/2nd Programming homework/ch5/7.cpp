#include <iostream>
using namespace std;

int main()
{
	int grade[6] = { 0, 0, 0, 0, 0, 0 };
	int gradeinput = 0;

	cout << "Enter -1 to end input" << endl;
	for (int i = 1;; ++i)
	{
		cout << "Student " << i << " grade => ";
		cin >> gradeinput;
		if (gradeinput < 0) break;
		++grade[gradeinput];
	}
	
	for (int i = 0; i < 6; ++i)
	{
		cout << "   |" << endl;
		cout << " " << i << " |";
		for (int j = 0; j < grade[i]; j++) cout << "I";
		cout << endl;
	}
	cout << "   |" << endl;

	return 0;
}