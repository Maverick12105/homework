#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> grade;
	int gradeinput;
	int	i = 0, j = 0;

	cout << "Enter -1 to end input" << endl;
	for (int i = 1;; ++i)
	{
		cout << "Student " << i << " grade => ";
		cin >> gradeinput;
		if (gradeinput < 0) break;
		grade.push_back(gradeinput);
	}

	int grademax = 0;
	for (i = 0; i < grade.size(); ++i) if (grademax < grade[i]) grademax = grade[i];
	int grademin = grademax;
	for (i = 0; i < grade.size(); ++i) if (grademin > grade[i]) grademin = grade[i];

	int currentgrade;
	for (i = grademin; i < grademax + 1; ++i)
	{
		currentgrade = 0;
		for (j = 0; j < grade.size(); ++j)
		{
			if (grade[j] == i)
			{
				++currentgrade;
			}
		}
		if (currentgrade != 0) cout << currentgrade << " grade(s) of " << i << endl;
	}

	return 0;
}