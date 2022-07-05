#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count1=0;
int count2=0;
int count3=0;
void rand_array(int *array,int n) {
    srand((unsigned int)time(NULL));
    for(int i=0; i<n; i++) {
        array[i]=rand()%10000+1;
    }
}
void BubbleSort (int* array,int n ) {
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        a[i]=array[i];
    int temp;
    int numberOfPairs=n;
    int swappedElements=1;
    while (swappedElements==1) {
        numberOfPairs=numberOfPairs-1;
        swappedElements=0;
        for(int i=0; i<numberOfPairs; i++) {
            if (a[i]>a[i+1] ) {

                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swappedElements=1;
            }
            count1++;
        }
    }
}
void MergeLists(int* list, int start1, int end1, int start2, int end2) {
    int indexC=0;
    int n=end1-start1+end2-start2+2;
    int *result=(int*)malloc(n*sizeof(int));
    int finalstart,finalend;
    finalstart=start1;
    finalend=end2;
    while (start1<=end1&&start2<=end2) {
        if (list[start1] < list[start2]) {
            result[indexC]=list[start1];
            start1=start1+1;
        } else {
            result[indexC]=list[start2];
            start2=start2+1;
        }
count2++;
        indexC=indexC+1;
    }
    if (start1<=end1) {
        for (int i=start1; i<=end1; i++) {
            result[indexC]=list[i];
            indexC=indexC+1;
        }
    } else {
        for (int i=start2; i<=end2; i++) {
            result[indexC]=list[i];
            indexC=indexC+1;
        }
    }
    indexC=0;
    for (int i=finalstart; i<=finalend; i++) {
        list[i]=result[indexC];
        indexC=indexC+1;

    }
}
void MergeSort(int* list,int first, int last) {
    if (first<last) {
        int middle=(first+last)/2;
        MergeSort(list, first, middle) ;
        MergeSort(list, middle+1, last) ;
        MergeLists(list, first, middle, middle+1, last) ;
    }
}
void MergeSort_t(int* array,int n) {
    int *list=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        list[i]=array[i];

    MergeSort(list,0,n-1);
}
void QuickSort(int* a,int start,int end)    {
    int i,j,temp,x;
    i=start;
    j=end;
    x=a[start];
    while(i<j) {
        while(i<j && x<a[j])
            j--;
        while(i<j && x>a[i])
            i++;
        if(i<j) {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
        count3++;
    }
    temp=x;
    x=a[i];
    a[i]=temp;
    if(start<j)
        QuickSort(a,start,j-1);
    if(i<end)
        QuickSort(a,j+1,end);
}
void QuickSort_t(int* array,int n) {
    int *list=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        list[i]=array[i];
    QuickSort(list,0,n-1);
}

int main() {
    int *array;
    int n;
    printf("请输入排序元素个数：");
    scanf("%d",&n);
    array=(int*)malloc(n*sizeof(int));
    rand_array(array,n);
    BubbleSort(array,n);
    MergeSort_t(array, n);
    QuickSort_t(array, n);
    printf("冒泡排序比较次数%d\n",count1);
     printf("合并排序比较次数%d\n",count2);
   printf("快速排序比较次数%d\n",count3);
}








