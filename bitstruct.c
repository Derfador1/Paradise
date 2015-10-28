#include <stdio.h>

struct card{
	int rank:5;
	int suit:2;
};

int main(void){
	
	printf("size is %zd\n", sizeof(struct card));
}
