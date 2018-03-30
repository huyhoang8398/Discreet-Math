#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter money:");
	scanf("%d", &n);
 	int qt = n/25;
 	n = n%25;
 	printf("%d quarters\n", qt);
 	int dim = n/10;
 	n = n%10;
 	printf("%d dimes\n", dim);
 	int nk = n/5;
 	n = n%5;
 	printf("%d nickels\n", nk);
 	printf("%d pennies\n", n);
	return 0;
}