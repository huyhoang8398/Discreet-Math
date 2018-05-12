#include <stdio.h>

int a[100];

void print(int n, int x) {
	if (x == n)
	{
		for (int i = 0; i < 8; ++i)
		{
			printf("%d ", a[i] );
		}
		printf("\n");
	}
	else 
	{
		for (int i = 0; i < 2; ++i)
		{
			a[x] = i;
			print(n,x+1);
		}
	}
}

int main(int argc, char const *argv[])
{
	printf("All possible cases of a boolean function of degree three (256 cases) :\n");
	print(8,0);
	return 0;
}
