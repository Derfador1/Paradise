#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int total_guesses = 0;
	char computer_guess[4] = {'0', '0', '0', '0'};
	char guess[4];
	//guess = malloc(sizeof(guess));
	int red;
	int white = 0;
	int y;
	int x;
	srand(time(NULL));
	for (int count = 0; count < 4; count++)
	{
		int r = (rand() % 10) + '0';
		computer_guess[count] = r;
		printf("%c", computer_guess[count]);
	}
	printf("\n");
	while(1)
	{
		printf("Guess a number: ");
		scanf("%s", guess);

		printf("\n");
		
		for (y = 0; y < 4; y++)
		{
			if (computer_guess[y] == guess[y])
			{
				red++;
				guess[y] = 11;
			}
			else
			{
				for (x = 0; x < 4; x++)
				{
					if (computer_guess[y] == guess[x])
					{
						white++;
						guess[x] = 11;
						break;
					}
				}
			}
		}
		printf("R:%d and W:%d\n", red, white);
		total_guesses++;
		if (red == 4)
		{
			printf("You have won in %d guesses\n", total_guesses);
			break;
		}
		red = 0;
		white = 0;
	}
	//free(guess);
}
