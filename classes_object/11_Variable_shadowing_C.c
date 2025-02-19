// C Program to demonstrate that we can access a global
// variable if we have a local variable with same name
#include <stdio.h>

// Global variable x
int x = 50;

int main()
{
	// Local variable x
	int x = 10;
	{
		extern int x;
		printf("Value of global x is %d\n", x);
	}
	printf("Value of local x is %d\n", x);
	return 0;
}
