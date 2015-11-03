
#include "deck.h"

#include <stdlib.h>
#include <stdio.h>

struct deck *make_deck(void) {
	struct deck *deck = malloc(sizeof(struct deck));
	if(!deck) {
		return NULL;
	}

	for(int s = 0; s < 4; ++s) {
		for(int rank = 2; rank < 15; ++rank) {
			deck->cards[s*13 + rank - 2].suit = s;
			deck->cards[s*13 + rank - 2].rank = rank;
		}
	}
	deck->top = 0;

	return deck;
}

void free_deck(struct deck *deck) { //pointer named deck to a deck structure
	free(deck);
}

void print_card_new(struct deck *deck, int dealt)
{
	for(int n = 0; n < dealt; ++n) 
	{
		char buf[16];
		card_to_str(buf, &deck->cards[n]);
		printf("%s\n", buf);
	}
}


void print_card_abbrev(struct deck *deck){
	for(int n = 0; n <= 51; ++n) {
		char buf[16];
		card_abbrev(buf, &deck->cards[n]);
		printf("%s ", buf);
		if(n % 5 == 4) {
			printf("\n");
		}
	}
}

void shuffle_deck(struct deck *pile) 
{
	for (int n = 51; n > 0; --n)
	{
		int r = rand() % (n+1);
		struct card swap = pile->cards[n];
		pile->cards[n] = pile->cards[r];
		pile->cards[r] = swap;
	}
}
