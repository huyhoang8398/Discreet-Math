#include <stdio.h>

void input(FILE * stream,int a[], int *n, int *x) {
	fscanf(stream,"%d",n);
	for (int i = 0; i < *n; ++i)
	{
		fscanf(stream,"%d", &a[i]);
	}
	fscanf(stream,"%d", x);
}

int fposlinear(int a[],int n,int x,int *count) {
	*count = 0;
	for (int i = 0; i < n; ++i)
	{
		*count += 1;
		if (a[i]==x) 
		{
			return i;
		}
	}
}

//binary search 
int fposbinary(int a[],int n, int x, int *count) {
	int l=0;
	int r=n-1;
	int mid;
	int pos = -1;
	*count =0;
	while (l!=r) {
		mid = (l+r)/2;
		*count +=1;
		if (x > a[mid]) l = mid+1;
		if (x < a[mid]) r = mid-1;
		if (x == a[mid]) {
			pos = mid;
			break;
		}
	}
	if (x == a[l]) pos = l;
	return pos;
}

int sort(int n, int a[]) {
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[100];
	int n,x;
	
	//input from file
	FILE * pfile = fopen("input.txt","r");
	input(pfile,a,&n,&x);
	fclose(pfile);

	int binaryCount;
	int linearCount;
	sort(n,a); //sort the input before test
	int linearPos = fposlinear(a,n,x,&linearCount) +1;
	int binaryPos = fposbinary(a,n,x,&binaryCount) +1;

	printf("Linear find:\nPosition:%d\nNumber of comparisons:%d\n", linearPos,linearCount);
	printf("Binary find:\nPosition:%d\nNumber of comparisons:%d\n", binaryPos,binaryCount);

	return 0;
}