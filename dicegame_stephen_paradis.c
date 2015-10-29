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
	if(argc == 1) //checks if there is only one argument in the command line
	{
		printf("No values given, value defaulted to 100\n");
		diceroll = 100;
		input = 1;
	}
	else if(argc == 2) //checks if there is more then the filename as an argument
	{
		if (!isdigit(*argv[1]))
		{
			printf("Command line argument [1] not a number; Defaulted to 99\n");
			diceroll = 100;
			input = 1;
		}
		else if (isdigit(*argv[1]))
		{
			diceroll = atoi(argv[1]);
			input = 1;
		}
	}
	else if(argc > 2)
	{

		if (!isdigit(*argv[2]))
		{
			printf("Histogram defaulted to 1\n");
			input = 1;
			diceroll = atoi(argv[1]);
		}
		else if(isdigit(*argv[2]))
		{
			input = atoi(argv[2]);
			diceroll = atoi(argv[1]);
			if (input <= 0)
			{
				printf("That was invalid, histogram defaulted to 1\n");
				input = 1;
			}
		}

	
	}
	printf("The histogram number is %d\n", input);
	for(numbercounter = 2; numbercounter <= 12; numbercounter++)
	{
		total[numbercounter] = 0;	//initializes each value count from 2 to 12 to 0;
	}
	//loop to randomly roll dice and keep count of each value obtained
	for(numbercounter = 0; numbercounter < diceroll; numbercounter++)
	{
		double dice1 = (rand() % 6) + 1; //random number 1 thru 6
		double dice2 = (rand() % 6) + 1; //random number 1 thru 6
		totalcount = dice1 + dice2;
		total[totalcount]++;
	}
	//prints out number value of dice, number of times rolled, and percentage the number of times rolled
	printf("Number of times rolled %d\n", diceroll);
	for(numbercounter = 2; numbercounter < 13; numbercounter++)
	{
		double percentage = (100.0 * total[numbercounter] / diceroll);
		printf("Number: %d\tNumber of times rolled: %d\tPercentage: %.2f%%\n",numbercounter,total[numbercounter], percentage);
	}

	printf("Expected information:\n");
	//prints out number value and expected rools, and percentage for each expected value
	for(numbercounter = 2; numbercounter < 13; numbercounter++)
	{
		double expected_percent = (100.0 * frequency[numbercounter] / 36);
		int expected = (diceroll * frequency[numbercounter] / 36);
		double percentage = (100.0 * total[numbercounter] / diceroll);
		printf("Number: %d\tExpected rolls: %d\tPercentage of expected: %.2f%%\t Difference: %.2f%%\n", numbercounter, expected, expected_percent, (percentage - expected_percent));
	}

	printf("Histogram information: \n");
	//prints out number value and "*'s" based on given histogram number
	for(numbercounter = 2; numbercounter < 13; numbercounter++)
	{
		double answer = (total[numbercounter]/input);
		int remainder = (total[numbercounter] % input);
		printf("Number: %d\t", numbercounter);
		histogram(answer, remainder); //calls histogram values needed to print out "*'s"
	}
	return(0);
}
void histogram(double answer, int remainder)
{
	int x;
	//prints out "*'s" based on number input in
	for (x = 1; x <= answer; ++x)
	{
		printf("*");
	}
	printf("%s: %d","    Remainder", remainder);
	printf("\n");
}
