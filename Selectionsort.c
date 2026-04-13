#include<stdio.h>
int main(){
   int n,i,j,min,temp;
   printf("Enter no of elements:");
   scanf("%d",&n);
   int a[n];
   printf("Enter the elements:\n");
   for(i=0;i<n;i++){
      scanf("%d",&a[i]);
   }
   for(i=0;i<n-1;i++){
      min=i;
      for(j=i+1;j<n;j++){
         if(a[j]<a[min]){
            min=j;
         }
      }
      if(min!=i){
         a[i]=a[i]+a[min];
         a[min]=a[i]-a[min];
         a[i]=a[i]-a[min];
      }
   }
   printf("Sorted array:\n");
   for(i=0;i<n;i++){
      printf("%d ",a[i]);
   }
   printf("\n");
   return 0;
}
