#include <stdio.h>


int main()
{
	int a;
	a = 9 & (1-9) >> 31;
	printf("%d", a);
	return 0;
}