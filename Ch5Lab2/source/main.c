#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define issue 5
#define rating 10

void recordResponse(int i, int response);
void highestRatings();
void lowestRatings();
float averageRatings(int iss);
void display();

int responses[issue][rating];
const char *topics[issue] = { "GlobalWarming","TheEconomy","War","HealthCare","Education" };


int main(void)
{
	int response, i;
	do
	{
		printf("Please rate the following topics on a scale from 1-10\n 1 = least improtant, 10 = most important\n");

		for (i = 0; i < issue; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("?");
				scanf_s("%d", &response);
			} while (response<1||response>10);
			recordResponse(i, response);
		}
		printf("Enter 1 to stop.Enter 0 to rate the issues again");
		scanf_s("%d", &response);
	} while (response!=1);

	display();
	system("pause");
	return 0;
}

void recordResponse(int iss, int rat)
{
	responses[iss][rat - 1]++;
}
void highestRatings()
{
	int highrat=0, hightop=0, i, j;
	for (i = 0; i < issue; i++)
	{
		int topicRat = 0;
		for (j = 0; j < rating; j++)
			topicRat += responses[i][j] * (j + 1);
		if (highestRatings < topicRat)
		{
			highrat = topicRat;
			hightop = i;
		}
	}
	printf("The highest rated topic was %s with a total rating of %d\n",topics[hightop],highrat);
}
void lowestRatings()
{
	int highrat, hightop, i, j;
	for (i = 0; i < issue; i++)
	{
		int topicRat = 0;
		for (j = 0; j < rating; j++)
			topicRat += responses[i][j] * (j + 1);
		if (i == 0)
			highrat = topicRat;
		if (highestRatings > topicRat)
		{
			highrat = topicRat;
			hightop = i;
		}
	}
	printf("The lowest rated topic was %s with a total rating of %d\n", topics[hightop], highrat);
}
float averageRatings(int iss)
{
	float total=0.0;
	int counter=0, j;
	for(j=0;j<rating;j++)
		if (responses[iss][j] != 0)
		{
			total += responses[iss][j] * (j + 1);
			counter += responses[iss][j];
		}
	return total / counter;
}
void display()
{
	int i, j;
	printf("%20s", "Topic");
	for (j = 1; j <= rating; j++)
		printf("%4d", j);
	printf("%20s", "Average Rating\n");

	for (i = 0; i < issue; i++)
	{
		printf("%20s", topics[i]);
		for (j = 0; j < rating; j++)
			printf("%4d", responses[i][j]);
		printf("%20.2f\n", averageRatings(i));
	}
	highestRatings();
	lowestRatings();
}