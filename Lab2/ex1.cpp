#include <stdio.h>
int a[100][100];
int n,m;
bool bipartite = true;
int cl[100], check[100];

void input(FILE * stream) {
	fscanf(stream,"%d",&m); 	//input number of edges
	for (int i = 0; i < m; ++i)
	{
		int j,k;	//input i,j as 2 vertices of the edge.
		fscanf(stream,"%d", &j);
		fscanf(stream,"%d", &k);
		a[j-1][k-1] = 1;
		a[k-1][j-1] = 1;
		if (j>n) n=j;				
		if (k>n) n=k;
	}
	for (int i = 0; i < n; ++i)
	{
		cl[i] = -1;
	}
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

bool isColor () {
	for (int i = 0; i < n; ++i)
	{
		if (cl[i] == -1)
		{
			return false;
		}
	}
	return true;
}
//use BFS to coloring the graph with 2 color
void bipartite_check(int x) {
	if (isColor())
	{
		return; //if all the graph is colored then out.
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[x][i] == 1)
		{
			if (cl[i] == -1)
			{
				cl[i] = 1-cl[x]; 
			}
			else {
				if (cl[i] == cl[x])
				{
					bipartite = false; 
									   
					return;
				}
			}
		}
	}
	check[x] = 1; 
	for (int i = 0; i < n; ++i)
	{
		if ((a[x][i] == 1)&&(check[i]==0))
		{
			bipartite_check(i); 
		}
	}
}


int main(){
	
	FILE * pfile = fopen("input.txt","r");
	input(pfile);
	fclose(pfile);

	cl[0] = 0;
	bipartite_check(0);
	if (bipartite)
	{
		printf("The graph is bipartite\n");
	}
	else {
		printf("The graph is not bipartite\n");
	}

	return 0;

}