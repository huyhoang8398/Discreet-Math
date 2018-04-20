#include <stdio.h>
int G[100][100];
int n,a,b,m,sum,i;
int Len[100], S[100], P[100];

void input(FILE * stream) {
	fscanf(stream,"%d",&m); 	
	sum = 0;
	for (int i = 0; i < m; ++i)
	{
		int h,t,w;
		fscanf(stream, "%d %d %d", &h,&t,&w);
		G[h-1][t-1] = w;
		sum += w;
		if (h>n) n=h;
		if (t>n) n=t;
	}
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && G[i][j] == 0)
                G[i][j] = sum;
        }
    }
    fscanf(stream, "%d %d", &a, &b);
    a--;
    b--;
    for (int i = 0; i < n; i++) {
        Len[i] = sum;                   
        S[i] = 0;                       
        P[i] = a;                       
    }
	Len[a] = 0;                         
    
}

int main(int argc, char const *argv[])
{
	FILE * pfile = fopen("input.txt","r");
	input(pfile);
	fclose(pfile);

	while (S[b] == 0) {                 
        for (i = 0; i < n; i++)         
            if (!S[i] && Len[i] < sum)
                break;
  
        
        if (i >= n) {
            break;
        }
  
        for (int j = 0; j < n; j++) {    // tim diem co vi tri ma do dai la min
            if (!S[j] && Len[i] > Len[j]) {
                i = j;
            }
        }
  
        S[i] = 1;                       
  
        for (int j = 0; j < n; j++) {   
            if (!S[j] && Len[i] + G[i][j] < Len[j]) {
                Len[j] = Len[i] + G[i][j];      // thay doi len
                P[j] = i;                       // danh dau diem truoc no
            }
        }
    }

    if (Len[b] > 0 && Len[b] < sum) {
        printf("Length of %d to %d is %d\n", a + 1, b + 1, Len[b]);
  
        // truy vet
        while (i != a) {
            printf("%d <-- ", i + 1);
            i = P[i];
        }
        printf( "%d", a + 1);
    } else {
        printf("No way from %d to %d\n", a + 1, b + 1);
    }

	return 0;
}