#include <stdio.h>
#include<time.h>
#include<stdlib.h>
void insertion(int a[], int n)
{
 int j,temp;
 for(int i =1;i<n;i++)
 {
 temp = a[i];
 j=i-1;
 while(a[j]> temp && j>=0)
 {
 a[j+1]=a[j];
 j--;
 }
 a[j+1]= temp;
 }
}
void main() {
 int a[100000],n,i,j;
 double avgt,bstt,wstt;
 clock_t t;
 printf("Enter the size : ");
 scanf("%d",&n);
 //avg
 for(i=0;i<n;i++)
 a[i]=rand();
 t = clock();
 insertion(a, n);
 t = clock()-t;
 avgt = ((double)t);
 printf(" Average case: %f",avgt);
 //best
 for(i=0;i<n;i++)
 a[i]=i;
 t = clock();
 insertion(a, n);
 t = clock()-t;
 bstt = ((double)t);
 printf("\nBest case : %f",bstt);
 //worst
 for(i=0,j=n-1;i<n;i++,j--)
 a[i]=j;
 t = clock();
 insertion(a, n);
 wstt = clock()-t;
 double t3 = ((double)t);
 printf("\nWorst case : %f",wstt);
}
