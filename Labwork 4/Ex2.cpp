#include <stdio.h>
#include <string.h>

int n,m;
int a[100][100];
char sop[1000]="";

void input(FILE * stream) {
	fscanf(stream,"%d",&n);
	m = 0;
	while (!(feof(stream))){
		for (int i = 0; i < n+1; ++i)
		{
			fscanf(stream,"%d", &a[m][i]);	
			
		}	
		m++;
	}
}

void sum() {
	for (int i = 0; i < m; ++i)
	{
		if (a[i][n] == 1)
		{
			char product[100] = "";	
			for (int j = 0; j < n; ++j)
			{
				if (a[i][j] == 1) {
					char temp[10] = {'(','x',char (j+49),')','.'};
					strcat(product,temp);
				}
				else {
					char temp[10] = {'(','!','x',char (j+49),')','.'};
					strcat(product,temp);
				}
			}
			int len = strlen(product);
			product[len-1] = product[len];
			strcat(sop,product);
			strcat(sop,"+");
		}
	}
	int len = strlen(sop);
	sop[len-1] = sop[len];
	printf("%s\n",sop );
}


int main(int argc, char const *argv[])
{
	FILE * pfile = fopen("input.txt","r");
	input(pfile);
	fclose(pfile);

	sum();
	return 0;
}