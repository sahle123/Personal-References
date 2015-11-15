// atoi.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc < 2)
		return 1;
	
	printf("The argc is: %i\n", argc);
	printf("Here is !atoi: %i\n", !atoi(argv[1]));
	return 0;
}
