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
    free(a);
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
    free(list);
}
void quick_sort(int* num, int low, int high ) {
    int i,j,temp;
    int tmp;

    i = low;
    j = high;
    tmp = num[low];

    if(i > j) {
        return;
    }

    while(i != j) {
        while(num[j] >= tmp && j > i) {
            j--;
        }

        while(num[i] <= tmp && j > i) {
            i++;
        }

        if(j > i) {
            temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
        count3++;
    }

    num[low] = num[i];
    num[i] = tmp;

    quick_sort(num,low,i-1);
    quick_sort(num,i+1,high);
}
void QuickSort_t(int* array,int n) {
    int *list=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        list[i]=array[i];
    quick_sort(list,0,n-1);
    free(list);
}
int main() {
    int *array;
    int n;
    printf("请输入排序元素个数：");
    scanf("%d",&n);
    array=(int*)malloc(n*sizeof(int));

    rand_array(array,n);
/*printf("测试数组：\n");
for(int i=0;i<n;i++){
    printf("%d  ",array[i]);
if(i%15==0&&i!=0)
        printf("\n");
}
    printf("\n\n");*/
    BubbleSort(array,n);

    MergeSort_t(array, n);

    QuickSort_t(array, n);

    printf("冒泡排序比较次数%d\n",count1);
    printf("合并排序比较次数%d\n",count2);
    printf("快速排序比较次数%d\n",count3);
    free(array);
}

