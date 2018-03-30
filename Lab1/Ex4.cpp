#include <stdio.h>

void input(FILE * stream,int *n, int s[], int e[]) {
	fscanf(stream,"%d",n);
	for (int i = 0; i < *n; ++i)
	{
		fscanf(stream, "%d", &s[i]);
		fscanf(stream, "%d", &e[i]);
	}
}

int fswap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//sort
int sort(int n, int s[], int e[]) {
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (e[i] > e[j])
			{
				fswap(&e[i],&e[j]);
				fswap(&s[i],&s[j]);
			}
			if ((e[i] == e[j])&&(s[i]>s[j]))
			{
				fswap(&e[i],&e[j]);
				fswap(&s[i],&s[j]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	int s[1000],e[1000];

	FILE * pfile = fopen("input.txt","r");
	input(pfile,&n,s,e);
	fclose(pfile);

	sort(n,s,e);
	
	//choose soonest ending time
	printf("%d %d\n", s[0],e[0]);
	int next = e[0]; 
	for (int i = 0; i < n; ++i)
	{
		if (s[i] > next) 
		{
			printf("%d %d\n", s[i],e[i]);
			next = e[i];
		}
	}

	return 0;
}