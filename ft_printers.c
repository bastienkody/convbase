#include "convbase.h"

void	print_usage(void)
{
	printf("Usage: convbase <NBR> <BASE_FROM> <BASE_TO>\n");
}

void	print_help()
{
	printf("Convbase converts and prints out the number given in base BASE_FRON to BASE_TO.\n");
	printf("The number max is a signed integer. It can be preceded by spaces, '+' or '-'.\n");
	printf("The amount of '-' determines the sign of the number (odd == negative).\n");
	printf("The bases must not contain twice the same character, neither '+' or '-'.\n");
}

void	print_base_uncorrect(void)
{	
	printf("At least one base is uncorrect. Please see usage, or help with -h option.\n");
}

void	print_nbr_base_uncorrect(void)
{	
	printf("The given number cannot be written with the given base.\n");
}


