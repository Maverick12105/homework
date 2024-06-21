/*
	Define a class named MyInteger that stores an integer and has functions to get and set the integer's value.
	Then, overload the [] operator so that the index returns the digit in position i, where i = 0 is the least-significant digit.
	If no such digit exists then -1 should be returned.

	For example, if x is of type MyInteger and is set to 418, then 
	x[0] should return 8, 
	x[1] should return 1, 
	x[2] should return 4,
	x[3] should return -1.

	pg.454
*/

#include <iostream>
using namespace std;

class MyInteger
{
public:
	MyInteger();
	MyInteger(int number);
	int& operator [] (int index);
private:
	int number;
};

int main()
{
	int input, index;

	cout << "number";
	cin >> input;
	MyInteger x(input);

	cout << "index";
	cin >> index;
	cout << x[index];

	return 0;
}

MyInteger::MyInteger() {}

MyInteger::MyInteger(int number) : number(number) {}

int& MyInteger::operator [] (int index)
{
	double temp;
	int error = -1, output;

	temp = number / pow(10, index);
	if (temp < 1 && number != 0)
		return error;
	
	output = int(temp) % 10;

	return output;
}
