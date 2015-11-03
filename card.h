
#ifndef CARD_H
 #define CARD_H

enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

struct card {
	int rank;
	enum suit suit;
};

int card_to_str(char *dst, const struct card *card);

int card_abbrev(char *abbrev, const struct card *card);

#endif
