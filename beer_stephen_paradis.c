#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	char *singledigit[] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven", "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
	char *tens[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
	
	int bottlecount;
	if(argc == 1)
	{
		printf("Bottlecount defaulted to 99\n");
		bottlecount = 99;
	}
	else if(argc >= 2)
	{
		if (!isdigit(*argv[1]))
		{
			printf("Command line argument [1] not a number; Defaulted to 99\n");
			bottlecount = 99;
		}
		else if (isdigit(*argv[1]))
		{
			bottlecount = atoi(argv[1]);
		}
	}	
	else
	{
		break;
	}
	while(1)
	{
		int bottle_ones;
		int bottle_tens;
		int next_ones;
		int next_tens;
		int nextbottle = bottlecount - 1;
		bottle_ones = bottlecount % 10;//bottle ones place
		bottle_tens = bottlecount / 10;//bottle tens places
		next_ones = nextbottle % 10;//next bottle ones place
		next_tens = nextbottle / 10;//next bottle tens place
		if(bottlecount >= 3)
		{

			if (bottle_ones == 0 && bottle_tens == 2) //check for 20 to 19
			{
				printf("%s bottles of beer on the wall\n", tens[bottle_tens]);
				printf("%s bottles of beer\n", tens[bottle_tens]);
				printf("Take one down\n"); 
				printf("Pass it around\n");
				printf("%s bottles of beer on the wall\n", singledigit[nextbottle]);
				bottlecount = bottlecount - 1;
				printf("\n");
			}
			else if (bottle_tens < 2) //checks for teens and lower
			{
				printf("%s bottles of beer on the wall\n", singledigit[bottlecount]);
				printf("%s bottles of beer\n", singledigit[bottlecount]);
				printf("Take one down\n"); 
				printf("Pass it around\n");
				printf("%s bottles of beer on the wall\n", singledigit[nextbottle]);
				bottlecount = bottlecount - 1;
				printf("\n");
			}
			else if (next_ones == 0) //checks 31 to 30 etc..
			{
				printf("%s-%s bottles of beer on the wall\n", tens[bottle_tens], singledigit[bottle_ones]);
				printf("%s-%s bottles of beer\n", tens[bottle_tens], singledigit[bottle_ones]);
				printf("Take one down\n"); 
				printf("Pass it around\n");
				printf("%s bottles of beer on the wall\n", tens[next_tens]);
				bottlecount = bottlecount - 1;
				printf("\n");
			}

			else if (bottle_ones == 0) //checks 30 to 29
			{
				printf("%s bottles of beer on the wall\n", tens[bottle_tens]);
				printf("%s bottles of beer\n", tens[bottle_tens]);
				printf("Take one down\n"); 
				printf("Pass it around\n");
				printf("%s-%s bottles of beer on the wall\n", tens[next_tens], singledigit[next_ones]);
				bottlecount = bottlecount - 1;
				printf("\n");
			}
			else if (bottle_tens >= 2) //checks everything greater then 20
			{
				printf("%s-%s bottles of beer on the wall\n", tens[bottle_tens], singledigit[bottle_ones]);
				printf("%s-%s bottles of beer\n", tens[bottle_tens], singledigit[bottle_ones]);
				printf("Take one down\n"); 
				printf("Pass it around\n");
				printf("%s-%s bottles of beer on the wall\n", tens[next_tens], singledigit[next_ones]);
				bottlecount = bottlecount - 1;
				printf("\n");
			}
		}
		else if(bottlecount == 2) //if bottle count is 2
		{
			printf("%s bottles of beer on the wall\n", singledigit[bottlecount]);
			printf("%s bottles of beer\n",singledigit[bottlecount]);
			printf("Take one down\n"); 
			printf("Pass it around\n");
			printf("%s bottle of beer on the wall\n", singledigit[nextbottle]);
			bottlecount = bottlecount - 1;
			printf("\n");
		}
		else if(bottlecount == 1) //if bottle count is 1
		{
			printf("%s bottle of beer on the wall\n", singledigit[bottlecount]);
			printf("%s bottle of beer\n", singledigit[bottlecount]);
			printf("Take one down\n"); 
			printf("Pass it around\n");
			printf("No more bottles of beer on the wall");
			printf("\n");
			break;
		}
	}
}

