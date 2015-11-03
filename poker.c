
#include <stdio.h>
#include <stdlib.h>

#include "card.h"
#include "deck.h"

int main(int argc, char *argv[])
{
	double dealt;
	char* endptr1;
	if(argc == 2)
	{
		dealt = strtod(argv[1], &endptr1);
	}
	else if(argc == 1)
	{
		dealt = 5;
	}
	printf("Welcome to the Poker Table\n");

	struct deck *deck = make_deck();

		
	shuffle_deck(deck);

	if(!deck) {
		fprintf(stderr, "Could not create deck");
		return 1;
	}
	if(dealt > 52 || dealt < 0)
	{
		printf("%.2f was not a correct number of cards.\n", dealt);
		dealt = 5;
		printf("You were dealt %.2f cards.\n", dealt);
		print_card_new(deck, dealt);
		//print_card_abbrev(deck);
	}
	else if(dealt <= 52)
	{
		print_card_new(deck, dealt); //passes the variable 'deck' because it expects a pointer to a deck structure
		//print_card_abbrev(deck);
	}
	free_deck(deck);

}
