#include <stdio.h>
int n, threshhold;
int a[100];
char gate;

void input(FILE * stream) {  	
	fscanf(stream,"%d",&threshhold);
	fscanf(stream,"%d",&n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(stream,"%d\n", &a[i]);
	}
	fscanf(stream,"%c",&gate);
}


int main(int argc, char const *argv[])
{
	FILE * pfile = fopen("input.txt","r");
	input(pfile);	
	fclose(pfile);
	
	int x = a[0];
	for (int i = 1; i < n; ++i)
	{
		x = x + a[i];
	}
	if (x> threshhold) printf("1\n");
	else printf("0\n");
	
	return 0;
}