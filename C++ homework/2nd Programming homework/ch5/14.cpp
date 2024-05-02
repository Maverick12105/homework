/*
	You have collected reviews from four movie reviewers where the reviewers are numbered 0~3.
	Each reviewer has rated six movies where the movies are numbered 100~105.
	The ratings range from 1 (terrible) to 5 (excellent).
	The reviews are shown in the following table:
		   100 101 102 103 104 105
		0   3   1   5   2   1   5
		1   4   2   1   4   2   4
		2   3   1   2   4   4   1
		3   5   1   4   2   4   2
	Write a program that stores this data using a 2D array.
	Based on this information your program should allow the user to enter ratings for any three movies.
	The program should then find the reviewer whose ratings most closely match the ratings input by the user.
	It should the predict the user's interest in the other movies by outputting the ratings by the reviewer for the movies that were not rated by thr user.
	Use the Cartesian distance as the metric to determine how close the reviewer's movie ratings are to the ratings input by the user.
	This technique is a simple version of the nearest neighbor classification algorithm.
	
	For example, if the user inputs a rating of 
	5 for movie 102, 
	2 for movie 104,
	5 for movie 105,
	then the closest match is reviewer 0 with a distance of sqrt(pow(5 - 5, 2) + pow(2 - 1, 2) + pow(5 - 5, 2)) = 1.
	the program would then predict a 
	rating of 3 for movie 100, 
	rating of 1 for movie 101,
	rating of 2 for movie 103.
	*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int ratingReviewer[4][6] = {{3,1,5,2,1,5},{4,2,1,4,2,4},{3,1,2,4,4,1},{5,1,4,2,4,2}};
	int movieUser[3], ratingUser;
	double ratingDistance[4] = {0,0,0,0};
	char repeat = 'y';

	for (int i = 0; i < 3 && repeat == 'y'; ++i) // add end early
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

	double ph5; //change this
	int j;
	for (int i = 0; i < 6; ++i)
	{
		if (i + 100 == movieUser[0]) continue;
		if (i + 100 == movieUser[1]) continue;
		if (i + 100 == movieUser[2]) continue;
		ph5 = 0;
		cout << endl;
		cout << "Rating of ";
		for (j = 0; j < closestReviewerNumber; ++j)
		{
			if (closestReviewer[j] == -1) break;
			ph5 += ratingReviewer[closestReviewer[j]][i];
		}
		cout << ph5 / j;
		cout << " for movie 10" << i;
	}

	

	return 0;
}