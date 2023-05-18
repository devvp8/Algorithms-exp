#include<stdio.h>
#include <time.h>
#include <stdlib.h>
int min(int a[],int p, int n)
{
 int small = a[p],pos=p;
 for(int i = p+1 ;i<n;i++)
 {
 if(a[i]<small)
 {
 small=a[i];
 pos=i;
 }
 }
 return pos;
}
void selection(int a[],int n)
{
 int pos,temp;
 for(int i=0;i<n;i++)
 {
 pos = min(a,i,n);
 temp = a[i];
 a[i] = a[pos];
 a[pos] = temp;
 }
}
void main()
{
 clock_t t;
 int n,a[150000],b;
 double avgt,bstt,wstt;
 printf("Enter size : ");
 scanf("%d",&n);
 //Average case
 for(int i=0;i<n;i++)
 a[i]=rand();
 t = clock();
 selection(a, n);
 t = clock()-t;
 avgt = ((double)t);
 printf("Average case: %f",avgt);
 //Best case
 for(int i=0;i<n;i++)
 a[i]=i;
 t = clock();
 selection(a, n);
 t = clock()-t;
 bstt = ((double)t);
 printf("\nBest case : %f",bstt);
 //worst
 for(int i=0,j=n;i<n;i++,j--)
 a[i]=j;
 t = clock();
 selection(a, n);
 t = clock()-t;
 wstt = ((double)t);
 printf("\nWorst case : %f",wstt);
} 
