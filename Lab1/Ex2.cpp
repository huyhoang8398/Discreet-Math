#include <stdio.h>

void input(FILE * stream,int a[], int *n, int bbs[], int ins[]) {
	fscanf(stream,"%d",n);
	for (int i = 0; i < *n; ++i)
	{
		fscanf(stream,"%d", &a[i]);
		bbs[i] = a[i];
		ins[i] = a[i];
	}
}

int bubblesort(int a[], int n) {
	int temp;
	int count = 0;
	for (int i=n; i>0; i--) {
    	for (int j=0; j<i-1; j++){
      		if(a[j]>a[j+1]) 
      		{
             	temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            count++; //after every comparison, increase count
        }
	}
	return count;
}

int insertsort(int a[], int n) {
	int count =0;
	int x,j;
	//checking every element from the first
    for(int i=1;i<n;i++)
    {
      	j=i-1;
      	x=a[i];
      	
      	while((j>=0)&&(a[j]>x))
      	{
      		count++; 
        	a[j+1]=a[j]; 
	        j--;
    	}
      	a[j+1]=x;
    }
	return count;
}

int main(int argc, char const *argv[])
{
	int a[1000],bbs[1000],ins[1000];
	int n,x;

	FILE * pfile = fopen("input.txt","r");
	input(pfile,a,&n,bbs,ins);
	fclose(pfile);

	int bbsCount = bubblesort(bbs,n);
	printf("Bubble sort: %d steps\n", bbsCount);

	int insCount = insertsort(ins,n);
	printf("Insertion sort: %d steps\n", insCount);
	return 0;
}