#include <stdio.h>
#include <string.h>
struct card {
	int rank;
	char suit[8];
};

void print_card(struct card);

int main(void) {
	
	struct card three_of_hearts;
	strncpy(three_of_hearts.suit, "Hearts", 8);
	three_of_hearts.rank = 3;

	print_card(three_of_hearts);
}

void print_card(struct card the_card){
	printf("%d of %s\n", the_card.rank, the_card.suit);
}
