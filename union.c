#include <stdio.h>

union card{
	int rank;
	int suit;
};

int main(void){
	union card ace_of_clubs;
	ace_of_clubs.rank = 514;
	ace_of_clubs.suit = 'C';

	printf("%d of %c\n", ace_of_clubs.rank, ace_of_clubs.suit);
}
