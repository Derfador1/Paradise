
#include <stdio.h>

#include "card.h"

const char * const ranks[] = {"(null)", "(null)", "Two", "Three", "Four",
	"Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King",
	"Ace"};
const char * const ranks_abbrev[] = {"(null)", "(null)", "2", "3", "4",
	"5", "6", "7", "8", "9", "10", "J", "Q", "K",
	"A"};
const char * const suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

const char * const suits_abbrev[] = {"C", "D", "H", "S"};


int card_to_str(char *dst, const struct card *card)
{	
	if (dst == NULL || card == NULL)
	{
		fprintf(stderr, "Error");
		return 1;
	}
	else if(card->rank >= 2 && card->rank <= 14)
	{
		if(card->suit >= 0 && card->suit <= 3)
		{
			snprintf(dst, 20, "%s-%s", ranks[card->rank], suits[card->suit]);
			return 0;
		}
		else
		{
			printf("Error 3");
			return 4;
		}
	}
	else
	{
		printf("Error 2");
		return 2;
	}
}


int card_abbrev(char *abbrev, const struct card *card)
{
	if (abbrev == NULL || card == NULL)
	{
		printf("Error 1");
		return 1;
	}
	else if(card->rank >= 2 && card->rank <= 14)
	{
		if(card->suit >= 0 && card->suit <= 3)
		{
			snprintf(abbrev, 10, "%s-%s", ranks_abbrev[card->rank], suits_abbrev[card->suit]);
			return 0;
		}
		else
		{
			printf("Error 3");
			return 4;
		}
	}
	else
	{
		printf("Error 2");
		return 2;
	}
	
}
