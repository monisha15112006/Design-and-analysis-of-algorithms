#include<stdio.h>
void merge(int A[],int l,int m,int r){
   int i=l,j=m+1,k=l;
   int B[100];
   while(i<=m && j<=r){
      if(A[i]<A[j])
         B[k++]=A[i++];
      else
         B[k++]=A[j++];
   }
   while(i<=m)
      B[k++]=A[i++];
   while(j<=r)
      B[k++]=A[j++];
   for(i=l;i<=r;i++)
      A[i]=B[i];
}
void mergeSort(int A[],int l,int r){
   int m;
   if(l<r)
   {
      m=(l+r)/2;
      mergeSort(A,l,m);
      mergeSort(A,m+1,r);
      merge(A,l,m,r);
   }
}
int main(){
   int A[100],n,i;
   printf("Enter number of elements:");
   scanf("%d",&n);
   printf("Enter elements:\n");
   for(i=0;i<n;i++)
      scanf("%d",&A[i]);
   mergeSort(A,0,n-1);
   printf("Sorted Array:\n");
   for(i=0;i<n;i++){
      printf("%d ",A[i]);
   }
   printf("\n");
   return 0;
}
