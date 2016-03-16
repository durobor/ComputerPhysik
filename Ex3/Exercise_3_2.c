#include <stdio.h>
#include <math.h>

int main()
{
        float a;
        float wurzela;

				printf("Enter a non-negative number: ");
				scanf("%f", &a);

				if ( 0 > a ) {
					printf("You're a Dumb@$$!\n");
				}
				else {
					wurzela = sqrt(a);
					printf("The square root of %.0f is %.3f\n", a, wurzela);
				}

        return 0;
}
