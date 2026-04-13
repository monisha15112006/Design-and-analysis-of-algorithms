#include<stdio.h>
void swap(int* a,int* b){
   int temp=*a;
   *a=*b;
   *b=temp;
}
int partition(int A[],int left,int right){
   int pivot=A[left];
   int i=left+1;
   int j=right;
   while(1){
      while(i<=right && A[i]<=pivot)
         i++;
      while(A[j]>pivot)
         j--;
      if(i<j)
         swap(&A[i],&A[j]);
      else{
         swap(&A[left],&A[j]);
         return j;
      }
   }
}
void quickSort(int A[],int left,int right){
   int s;
   if(left<right){
      s=partition(A,left,right);
      quickSort(A,left,s-1);
      quickSort(A,s+1,right);
   }
}
int main(){
   int A[100],n,i;
   printf("Enter no of elements:");
   scanf("%d",&n);
   printf("Enter elements:\n");
   for(i=0;i<n;i++)
      scanf("%d",&A[i]);
   quickSort(A,0,n-1);
   printf("Sorted array:\n");
   for(i=0;i<n;i++)
      printf("%d ",A[i]);
   printf("\n");
   return 0;
}
