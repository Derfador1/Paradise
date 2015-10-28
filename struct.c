#include <stdio.h>

struct card {
	int rank;
	char suit;
};

void print_card(struct card);

int main(void) {
	struct card three_of_hearts;
	three_of_hearts.rank = 3;
	three_of_hearts.suit = 'H';

	print_card(three_of_hearts);
}

void print_card(struct card the_card){
	printf("%d of %c\n", the_card.rank, the_card.suit);
}
