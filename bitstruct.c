#include <stdio.h>

struct card{
	int rank;
	int suit;
};

int main(void){
	struct card ace_of_clubs;
	ace_of_clubs.rank = ;
	ace_of_clubs.suit = 'C';

	printf("%d of %c\n", ace_of_clubs.rank, ace_of_clubs.suit);
}
