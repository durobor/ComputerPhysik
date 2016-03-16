#include <stdio.h>

int main()
{
	int a, n;

	printf("How many times would you like to print stuff? ");
	scanf("%d", &n);

	for (a=0; a<n; a++)
	{
		printf("Hello World %d\n" , a);
	}

	for (a=0; a<n; a++)
	{
		printf("Hallo Konrad %d\n" , a);
	}
	return 0;
}
