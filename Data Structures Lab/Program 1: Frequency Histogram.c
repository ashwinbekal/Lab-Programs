#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[100],frequency[10]={0},i,j,n;
void getdata(),printdata(),makefrequency(),makehistogram();
void main(){
    getdata();printdata();makefrequency();makehistogram();
}
void getdata(){
    printf("Enter the number of Array Elements:\n");
    scanf("%d",&n);
    printf("Enter %d Array Elements ranging from (0 to 9):\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void printdata(){
    if(n==0) {printf("Array is empty!\n"); exit(0);}
    printf("The Array Elements are:\n");
    for(int i=0;i<n;i++) printf("%d\t",a[i]);    
}
void makefrequency(){
    for(i=0;i<10;i++)
    for(j=0;j<n;j++){if(a[j]==i) frequency[i]++;}
}
void makehistogram(){
    printf("\nFrequency Histogram is:\n");
    printf("Histo--Frequency\n");
    for(i=0;i<10;i++){
        printf("\n[%d]",i);
        for(j=0;j<frequency[i];j++){
            printf("\t*");
        }printf("\n");
    }
}
