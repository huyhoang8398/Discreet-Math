#include <stdio.h>
int a[8][4];
int b[2][4];

void input(FILE * stream) {  	
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			fscanf(stream,"%d", &a[i][j]);
		}
	}
}


int main(int argc, char const *argv[])
{
	FILE * pfile = fopen("input.txt","r");
	input(pfile);	
	fclose(pfile);
	
	for (int i = 0; i < 8; ++i)
	{
		if (a[i][3] == 1)
		{
			b[a[i][0]][a[i][1]*2+a[i][2]] = 1;
		}
		
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}