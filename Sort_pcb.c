#include <stdio.h>
#include <stdbool.h> 
#define ARRAYSIZE 100 
int Input_Values(int* A, int* n, int* maxi){

  printf("Code to sort integer array\n");
  printf("Input size of array\n");
  scanf(" %d",n);
  printf("You input array size %d\n",*n);
  printf("Input %d numbers > 0 \n",*n);
  int i,j =1;
  for (i = 0;i<*n;i++){
    scanf("%d",&A[i]);
    if(A[i] > (1<<24))return 1;
    if(A[i] < 0)return 1;
    while(A[i]+1>j){
      j = (j<<1);
      (*maxi)++;
    }
  }

  /*
  printf("The %d numbers are:\n",n);
  for ( i = 0;i<n;i++){
    printf("%d ",A[i]);
  }
  printf("\n");
  */
  return 0;
}
/**
 * @brief Sorts positve integers into ascending order
 * @param int* A Array of positive integers
 * @param int n Size of A
 * @param int k index of current bit
 * @return maybe at later date (not used)  
 */
int OneZeroSort(int* A, int n, int k){
  int i;
  int One[ARRAYSIZE] = {0},Zero[ARRAYSIZE]={0};
  int OneCounter = 0,ZeroCounter = 0;
  for(i=0;i<n;i++){
    if((A[i] & (1<<k))==0){
      Zero[ZeroCounter] = A[i];
      ZeroCounter++;
    }
    else{
      One[OneCounter] = A[i];
      OneCounter++;
    }
  }
  for(i=0;i<ZeroCounter;i++){
    A[i] = Zero[i];
  }
  for(i=ZeroCounter;i<n;i++){
    A[i] = One[i-ZeroCounter];
  }
  return 0;
}

int Output_Values(int *A,int n){
  
  int i; 
  printf("The ordered  %d numbers are now:\n",n);
  for ( i = 0;i<n;i++){
    printf("%d ",A[i]);
  }
  printf("\n");
  return 0;
}


  int main() {
  int A[ARRAYSIZE]={0};
  int n = 0,i,maxi=0,error=1;
  
  //input the array 
  error =   Input_Values(A,&n,&maxi);
  if(error == 1){
     printf("Integer > 0 and not too large \n");
     return 1;
  }

  //Sort the data
  for(i=0;i<maxi;i++){
    OneZeroSort(A,n,i);
  }

//output the sorted array
  Output_Values(A,n);



  return 0;
}
