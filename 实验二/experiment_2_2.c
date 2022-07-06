#include <stdio.h>
#include <stdlib.h>
int count1=0;
int count2=0;
int  DAC_f(int n) {
if(n==1||n==2)
 return 1 ;
else{
count1++;
return DAC_f(n-1)+DAC_f(n-2) ;
}
}

int DP_f(int n) {
int  *f=(int*)malloc(sizeof(int)*(n+1));
for (int i=1;i<n+1;i++){
if(i==1||i==2)
 f[i]=1 ;
else {
        count2++;
f[i]=f[i-1]+f[i-2] ;
}
}
return f[n];
}

int main()
{int result1,result2;
    int N[]={5, 10, 15, 20, 25, 30};
for(int i=0;i<6;i++){
printf("n=%d时，两者比较：\n",N[i]);
result1=DAC_f(N[i]);
result2=DP_f(N[i]);
printf("分治算法结果：%d,，相加次数：%d\n",    result1,count1);
printf("动态规划结果：%d,，相加次数：%d\n\n",    result2,count2);
count1=0;
count2=0;
}

    return 0;
}
