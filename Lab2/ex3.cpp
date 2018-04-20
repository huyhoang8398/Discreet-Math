#include <stdio.h>
int a[100][100];
int n,m;
int apr[100][100];

void input(FILE * stream) {
	fscanf(stream,"%d %d",&n,&m); 	//input number of vertex and edge
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			fscanf(stream,"%d", &a[i][j]);
		}
	}
}

void printgraph() {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d ",a[i][j] );
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	FILE * pfile = fopen("input.txt","r");
	input(pfile);
	fclose(pfile);

	printgraph();

	for (int i = 0; i < m; ++i)
	{
		int h = -1;
		int t = -1;
		for (int j = 0; j < n; ++j)
		{
			if (a[j][i] != 0)
			{
				h = j;
				break;
			}
		}
		for (int j = n-1; j >= 0; --j)
		{
			if (a[j][i] != 0)
			{
				t = j;
				break;
			}
		}
		apr[h][t] += 1;
	}
	char direct =' ';
	printf("This is directed graph or not? (y/n)\n");
	scanf("%c", &direct);

	switch (direct) {
		case 'y': {
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (a[i][j]!=0)
					{
						printf("Edge %d %d appears %d times\n",i,j,a[i][j] );
					}
				}
			}
		}
		default: {
			for (int i = 0; i < n; ++i)
			{
				for (int j = i; j < n; ++j)
				{
					if ((a[i][j]!=0)||(a[j][i] != 0))
					{
						printf("Edge %d %d appears %d times\n",i,j,a[i][j] + a[j][i] );
					}
				}
			}
		}
	}
	return 0;
}