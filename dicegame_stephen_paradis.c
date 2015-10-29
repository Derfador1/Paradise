#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
//prototypes
void histogram_print(int total, int input, int numbercounter);
void expected_print(int numbercounter, int diceroll, double math1, int math2);

int main (int argc, char *argv[])
{
	srand(time(NULL));
	int diceroll;
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
			printf("Command line argument [1] not a number; Defaulted to 100\n");
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
			if (diceroll <= 0)
			{
				printf("Command line argument [1] less then 0; Defaulted to 100\n");
				diceroll = 100;
			}
			
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
			if (diceroll <= 0)
			{
				printf("Command line argument [1] less then 0; Defaulted to 100\n");
				diceroll = 100;
			}
		}

	
	}
	printf("The histogram number is %d\n", input);
	for(int numbercounter = 2; numbercounter <= 12; numbercounter++)
	{
		total[numbercounter] = 0;	//initializes each value count from 2 to 12 to 0;
	}
	//loop to randomly roll dice and keep count of each value obtained
	for(int numbercounter = 0; numbercounter < diceroll; numbercounter++)
	{
		double dice1 = (rand() % 6) + 1; //random number 1 thru 6
		double dice2 = (rand() % 6) + 1; //random number 1 thru 6
		totalcount = dice1 + dice2;
		total[totalcount]++;
	}
	printf("Number of times rolled %d\n", diceroll);
	printf("Expected information:\n");
	for(int numbercounter = 2; numbercounter < 13; numbercounter++)
	{
		//calls expected print function
		expected_print(numbercounter, diceroll, frequency[numbercounter], total[numbercounter]);
	}

	printf("Histogram information: \n");
	for(int numbercounter = 2; numbercounter < 13; numbercounter++)
	{	
		//calls histogram function to print out '*s'	
		histogram_print(total[numbercounter], input, numbercounter);
	}
	return(0);
}
//prints out '*s' based on number input in
void histogram_print(int total, int input, int numbercounter)
{
	int x;
	double answer = (total/input);
	int remainder = (total % input);
	printf("Number: %d\t", numbercounter);
	for (x = 1; x <= answer; ++x)
	{
		printf("*");
	}
	printf("%s: %d","    Remainder", remainder);
	printf("\n");
}
//prints out number value and expected rools, and percentage for rolled and expected and difference betweent the 2
void expected_print(int numbercounter, int diceroll, double frequency, int total)
{
	double expected_percent = (100.0 * frequency / 36);
	double rolled_percent = (100.0 * total / diceroll);
	double difference = (rolled_percent - expected_percent);
	printf("Number: %d\tPercent of rolled %.2f%%\t\tPercent of expected: %.2f%%\t Difference: %.2f%%\n", numbercounter, 	rolled_percent, expected_percent, difference);
}

