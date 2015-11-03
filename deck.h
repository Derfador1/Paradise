
#ifndef DECK_H
 #define DECK_H

#include "card.h"

struct deck {
	struct card cards[52];
	int top;
};

struct deck *make_deck(void);

void free_deck(struct deck *pile);

void print_card_new(struct deck *deck, int dealt);

void print_card_abbrev(struct deck *deck);

void shuffle_deck(struct deck *pile);

#endif
