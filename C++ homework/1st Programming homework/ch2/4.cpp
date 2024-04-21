#include <iostream>
using namespace std;

int main()
{
	for (int i = 3; i <= 100; ++i)
	{
		for (int j = i / 2;; --j)
		{
			if (i % j == 0) break;
			if (j < 3)
			{
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}