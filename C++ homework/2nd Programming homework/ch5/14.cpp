#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int ratingReviewer[4][6] = {{3,1,5,2,1,5},{4,2,1,4,2,4},{3,1,2,4,4,1},{5,1,4,2,4,2}};
	int movieUser[3], ratingUser;
	double ratingDistance[4] = {0,0,0,0};
	char repeat = 'y';

	for (int i = 0; i < 3 && repeat == 'y'; ++i)
	{
		cout << "which movie? => ";
		while (true)
		{
			cin >> movieUser[i];
			if (100 <= movieUser[i] && movieUser[i] <= 105) break;
			cout << "Invalid input, try again => ";
		}
		cout << "rating? => ";
		while (true)
		{
			cin >> ratingUser;
			if (0 <= ratingUser && ratingUser <= 5) break;
			cout << "Invalid input, try again => ";
		}
		
		for (int j = 0; j < 4; ++j) ratingDistance[j] += pow(ratingReviewer[j][movieUser[i] - 100] - ratingUser, 2);
	}

	int closestReviewer[4] = { 0,-1,-1,-1 };
	int closestReviewerNumber = 1;
	double closestReviewerDistance = sqrt(ratingDistance[0]);

	for (int i = 1; i < 4; ++i)
	{
		if (closestReviewerDistance == sqrt(ratingDistance[i]))
		{
			closestReviewer[closestReviewerNumber] = i;
			++closestReviewerNumber;
		}
		if (closestReviewerDistance > sqrt(ratingDistance[i]))
		{
			for (int j = 1; j < 4; ++j)
				closestReviewer[j] = -1;
			closestReviewerDistance = sqrt(ratingDistance[i]);
			closestReviewer[0] = i;
			closestReviewerNumber = 1;
		}
	}

	cout << "prediction:";

	double ratingReviewerSum;
	int j;

	for (int i = 0; i < 6; ++i)
	{
		if (i + 100 == movieUser[0]) continue;
		if (i + 100 == movieUser[1]) continue;
		if (i + 100 == movieUser[2]) continue;
		ratingReviewerSum = 0;
		cout << endl;
		cout << "Rating of ";
		for (j = 0; j < closestReviewerNumber; ++j)
		{
			if (closestReviewer[j] == -1) break;
			ratingReviewerSum += ratingReviewer[closestReviewer[j]][i];
		}
		cout << ratingReviewerSum / j;
		cout << " for movie 10" << i;
	}
	return 0;
}