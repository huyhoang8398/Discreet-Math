#include <stdio.h>

int a[100][100];
int n,m;
int check[100];

void input(FILE * stream) {
	fscanf(stream,"%d",&m); 	//input number of edge
	for (int i = 0; i < m; ++i)
	{
		int h,t;
		fscanf(stream, "%d %d", &h,&t);
		a[h-1][t-1] = 1;
		a[t-1][h-1] = 1;
		if (h>n) n=h;
		if (t>n) n=t;
	}
}

void mapCheck(int x,int t) {
	for (int i = 0; i < n; ++i)
	{
		if (a[x][i] == 1 && check[i] == 0) {
			check[i] = t;
			mapCheck(i,t);
		}
	}
}

int Checked() {
	for (int i = 0; i < n; ++i)
	{
		if (check[i]== 0)
		{
			return i;
		}	
	}
	return -1;
}


void printGraph() {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
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
	int t = 0;
	while (Checked() != -1) {
		int start = Checked();
		t += 1;
		mapCheck(start,t);
	}
	if (t == 1)
	{
		printf("The graph is connected\n");
	}
	else {
		printf("The graph is not connected\n");
	}

	for (int i = 0; i < t; ++i)
	{
		printf("component connected %d :",i+1 );
		for (int j = 0; j < n; ++j)
		{
			if (check[j] == i+1)	
			{
				printf("%d ", j+1);
			}
		}
		printf("\n");
	}
	return 0;
}