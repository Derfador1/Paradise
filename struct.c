#include <stdio.h>
#include <string.h>
struct card {
	int rank;
	char suit_lookup;
};


char *suit_names[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
void print_card(struct card);

int main(void) {
	
	struct card three_of_hearts;
	//strncpy(three_of_hearts.suit, "Hearts", sizeof(three_of_hearts.suit));
	three_of_hearts.rank = 3;
	three_of_hearts.suit_lookup = 2;


	print_card(three_of_hearts);
}

void print_card(struct card the_card){
	printf("%d of %s\n", the_card.rank, suit_names[the_card.suit_lookup]);
}
