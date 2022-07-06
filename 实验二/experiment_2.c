#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
void rand_w(int *w ,int n) {
    srand((unsigned int)time(NULL));
    for(int i=0; i<n; i++) {
        w[i]=rand()%40+1;
    }
}
void rand_v(int * v ,int n) {
    srand((unsigned int)time(NULL));
    for(int i=0; i<n; i++) {
        v[i]=rand()%50+1;
    }
}
int KnapsackDP (int *w, int* v,int n,int C) {
    	int **m = (int **)malloc(sizeof(int *) * (n+1));
    	int result;
	for (int i = 0; i < n+1; ++i)
	{
		m[i] = (int *)malloc(sizeof(int) * (C+1));
	}

    for (int i=0; i<n+1; i++) {
        m[i][0]=0;
    }
    for (int i=0; i<C+1; i++) {
        m[0][i]=0;
    }
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<C+1; j++) {
            m[i][j]=m[i-1][j] ;
            if (w[i-1]<=j )
            if(m[i][j]<m[i-1][j-w[i-1]]+v[i-1])
                m[i][j]=m[i-1][j-w[i-1]]+v[i-1];

            }
    }

    result=m[n][C];
    free(m);
        return result;
}

int main() {
    clock_t start,finish;
    int C[6]={200,400,800,2000,5000,10000};
    int N[10]={10,20,40,100,200,400,800,2000,5000,10000};
     int *w,*v;
     int result;
     for(int i=0;i<6;i++){
            printf("背包容量为%d\n",C[i]);
        for(int j=0;j<10;j++){
            w=(int*)malloc(N[j]*sizeof(int));
            v=(int*)malloc(N[j]*sizeof(int));
           rand_w(w,N[j]);
            rand_v(v,N[j]);
            start=clock();
            result=KnapsackDP(w,v,N[j],C[i]);
            finish=clock();
            printf("物品数量为%d,最终结果为：%d,用时%.3fms\n",N[j],result,(double)(finish-start)/CLOCKS_PER_SEC);
     free(w);
     free(v);
        }
                    printf("\n");
 }
    return 0;
}
