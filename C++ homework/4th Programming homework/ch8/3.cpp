/*
	Define a aclass for complex numbers.
	A complex number is a number of the form: 
		a + b * i
	where for our purposesm a and b are number of type double, and i is a number that represents the quantity กิ-1.
	Represent a complex number as two values of type double.
	Name the member variables real and imaginary. (The variable for the number that is multiplied by i is the one called imaginary.)
	Call the class Complex.
	Include a constructor with two parameters of type double that can be used to set the member variable of an object to any values.
	Include a constructor that has only a single parameter of type double;
	call this parameter realPart and define the constructor so that the object will be initialized to realPart + 0*i.
	Include a default constructor that initializes an object to 0 (that is, to 0 + 0*i).
	Overload all the following operators so that they correctly apply to the type Complex: ==, +, -, *, >>, and <<.
	You should also write a test program to test your class.
	Hints: to add or subtract two complex numbers, add or subtract the two member variables.
	The product of two complex numbers is given by the following formula:
		(a+b*i)*(c+d*i)==(a*c-b*d)+(a*d+b*c)*i
	In the interface file, you should define a constant i as follows:
		const Complex i(0, 1);
	This defined constant i will be the same as the i discussed above.
	*/

#include <iostream>
#include <string>
using namespace std;

class Complex
{
public:
	Complex(const double& realPart, const double& imaginaryPart);
	Complex(const double& realPart);
	Complex();
	friend bool operator == (const Complex& a, const Complex& b);
	friend const Complex operator + (const Complex& a, const Complex& b);
	friend const Complex operator - (const Complex& a, const Complex& b);
	friend const Complex operator * (const Complex& a, const Complex& b);
	friend istream& operator >> (istream& inputstream, Complex& a);
	friend ostream& operator << (ostream& outputstream, const Complex& a);
private:
	double real;
	double imaginary;
};

int main()
{
	const Complex i(0, 1);

	return 0;
}

Complex::Complex(const double& realPart, const double& imaginaryPart): real(realPart), imaginary(imaginaryPart)
{}

Complex::Complex(const double& realPart): real(realPart), imaginary(0)
{}

Complex::Complex(): real(0), imaginary(0)
{}

bool operator == (const Complex& a, const Complex& b)
{
	return (a.real == b.real) && (a.imaginary == b.imaginary);
}

const Complex operator + (const Complex& a, const Complex& b)
{
	return Complex(a.real + b.real, a.imaginary + b.imaginary);
}

const Complex operator - (const Complex& a, const Complex& b)
{
	return Complex(a.real - b.real, a.imaginary - b.imaginary);
}

const Complex operator * (const Complex& a, const Complex& b)
{
	return Complex((a.real * b.real - a.imaginary * b.imaginary), (a.real * b.imaginary + a.imaginary * b.real));
}

istream& operator >> (istream& inputstream, Complex& a)
{
	string c;

	cin >> c;

	cout << c;

	return inputstream;
}

ostream& operator << (ostream& outputstream, const Complex& a)
{
	cout << a.real << " + " << a.imaginary << "*i";

	return outputstream;
}