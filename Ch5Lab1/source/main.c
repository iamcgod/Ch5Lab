#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define std 3
#define exam 4

void minimum(int grade[][exam], int pupils, int tests);
void maximum(int grade[][exam], int pupils, int tests);
void ave(int grade[][exam], int pupils, int tests);
void printArr(int grade[][exam], int pupils, int tests);
void printMenu(void);

int main(void)
{
	void(*processGrades[4])(int[][exam], int, int) = { printArr,minimum,maximum,ave };
	int choice = 0;
	int stdGrades[std][exam] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };

	while (choice!=4)
	{
		do {
			printMenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
		{
			(*processGrades[choice])(stdGrades, std, exam);
		}
		else
		{
			printf("ProgramEnded\n");
		}
	}
	system("pause");
	return 0;
}

void minimum(int grade[][exam], int pupils, int tests)
{
	int i, j, low = 100;
	for (i = 0; i <= pupils - 1; i++)
		for (j = 0; j <= tests - 1; j++)
			if (grade[i][j] < low)
				low = grade[i][j];
	printf("\n\tThe lowest grade is %d\n", low);
}
void maximum(int grade[][exam], int pupils, int tests)
{
	int i, j, low = 0;
	for (i = 0; i <= pupils - 1; i++)
		for (j = 0; j <= tests - 1; j++)
			if (grade[i][j] > low)
				low = grade[i][j];
	printf("\n\tThe highest grade is %d\n", low);
}
void ave(int grade[][exam], int pupils, int tests)
{
	int i, j, total;
	printf("\n");
	for (i = 0; i <= pupils - 1; i++)
	{
		total = 0;
		for (j = 0; j <= tests - 1; j++)
			total += grade[i][j];
		printf("\tThe average grade for std%d is %.1f\n", i+1,(double)total/tests);

	}
		
}
void printArr(int grade[][exam], int pupils, int tests)
{
	int i, j;
	printf("\n\t       [0]  [1]  [2]  [3]");
	for (i = 0; i <= pupils - 1; i++)
	{
		printf("\n\tstdGrades[%d]", i);
		for (j = 0; j <= tests - 1; j++)
			printf("%-7d", grade[i][j]);
		printf("\n");

	}
}
void printMenu(void)
{
	printf("\n\tEnter a choice:\n\t  0  Print the array of grades\n\t  1  Find the minjmum of grade\n\t"
			"  2  Find the maximum grade\n\t  3  Print the average on all\n\t  tests for each student\n\t  4  End prigram\n\t?");

}