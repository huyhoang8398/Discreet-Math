#include <stdio.h>
int a[100][100];
int n;

void input(FILE * stream) {
	fscanf(stream,"%d",&n); 	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
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

	char direct =' ';
	printf("This is directed graph or not? (y/n)\n");
	scanf("%c", &direct);

	switch (direct) {
		case 'y': {
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (a[i][j] != 0)
					{
						printf("Edge %d %d appear 1 time\n",i+1,j+1 );
					}
				}
			}
			break;
		}
		default: {
			for (int i = 0; i < n; ++i)
			{
				for (int j = i; j < n; ++j)
				{
					if (a[i][j] != 0)
					{
						if(i==j) {
							printf("Edge %d %d appear 1 time\n",i+1,i+1);
						}
						else {
							if (a[j][i] != 0)
							{
								printf("Edge %d %d appear 2 time\n",i+1,j+1);
							}
							else {
								printf("Edge %d %d appear 1 time\n",i+1,j+1);
							}
							
						}
					}
				}
			}
		}
	}
	return 0;
}