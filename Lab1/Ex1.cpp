#include <stdio.h>

//input from file
void input(FILE * stream,int a[], int *n, int *x) {
	fscanf(stream,"%d",n);
	for (int i = 0; i < *n; ++i)
	{
		fscanf(stream,"%d", &a[i]);
	}
	fscanf(stream,"%d", x);
}

int fpos(int a[],int n, int x) {
	int left=0;
	int right=n-1;
	int mid;
	int pos = -1;
	while (left!=right) {
		mid = (left+right)/2;
		if (x > a[mid]) left = mid+1; 
		if (x < a[mid]) right = mid-1; 
		if (x == a[mid]) {
			pos = mid;
			break;
		}
	}
	if (x == a[left]) pos = left;
	return pos;
}

int main(int argc, char const *argv[])
{
	int a[100];
	int n,x;
	//input from file
	FILE * pfile = fopen("input.txt","r");
	input(pfile,a,&n,&x);
	fclose(pfile);

	int pos  = fpos(a,n,x);
	printf("%d\n", pos+1);
	return 0;
}