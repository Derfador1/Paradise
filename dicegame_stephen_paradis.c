#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void histogram(double answer, int remainder);

int main (int argc, char *argv[])
{
	srand(time(NULL));
	int diceroll;
	int numbercounter;
	int totalcount;
	int total[13];
	int frequency[13] = { 0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 }; //array for probability of 2 dice outcomes
	int input;
	if(argc == 1)
	{
		printf("No values given, value defaulted to 99\n");
		diceroll = 99;
	}
	else if(argc >= 2)
	{
		if (isalpha(*argv[1]))
		{
			printf("Command line argument [1] not a number; Defaulted to 99\n");
			diceroll = 99;
		}
		else if (isdigit(*argv[1]))
		{
			diceroll = atoi(argv[1]);
		}
	}
	printf("Please enter histogram integer: ");
	scanf("%d", &input);
	for(numbercounter = 2; numbercounter <= 12; numbercounter++)
	{
		total[numbercounter] = 0;	//initializes each value count from 2 to 12 to 0;
	}

	for(numbercounter = 0; numbercounter < diceroll; numbercounter++)
	{
		double dice1 = (rand() % 6) + 1; //1 thru 6
		double dice2 = (rand() % 6) + 1; //1 thru 6
		totalcount = dice1 + dice2;
		total[totalcount]++; //increases the total of the sum of the dice by one each turn
	}

	printf("Number of times rolled %d\n", diceroll);
	for(numbercounter = 2; numbercounter < 13; numbercounter++)
	{
		double percentage = (100.0 * total[numbercounter] / diceroll);
		printf("Number: %d\tNumber of times rolled: %d\tPercentage: %.2f%%\n",numbercounter,total[numbercounter], percentage);
	}

	printf("Expected information:\n");
	for(numbercounter = 2; numbercounter < 13; numbercounter++)
	{
		double expected_percent = (100.0 * frequency[numbercounter] / 36);
		int expected = (diceroll * frequency[numbercounter] / 36);
		printf("Number: %d\tExpected rolls: %d\tPercentage of expected: %.2f%%\t Difference: %d\n", numbercounter, expected, expected_percent, (total[numbercounter] - expected));
	}

	printf("Histogram information: \n");
	for(numbercounter = 2; numbercounter < 13; numbercounter++)
	{
		double answer = (total[numbercounter]/input);
		int remainder = (total[numbercounter] % input);
		printf("Number: %d\t", numbercounter);
		histogram(answer, remainder);
	}
	return(0);
}
void histogram(double answer, int remainder)
{
	int x;
	for (x = 1; x <= answer; ++x)
	{
		printf("*");
	}
	printf("%s: %d","    Remainder", remainder);
	printf("\n");
}
