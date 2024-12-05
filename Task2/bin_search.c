#include <stdio.h>
#include <stdlib.h>
int binary_search(int arr[], int size ,int num){ 
	 int left = 0, right = size -1;
	  while(left<=right){ 
	  	int mid = left+(right-left)/2; 
	  	if(arr[mid]==num){ return mid; }
	  	else if(arr[mid]<num){ left=mid+1;}
	  	else{ right = mid-1;  } 
	  } 
	 return -1; 
 } 
 int main(int argc , char*argv[]){
 int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
 int size= 12;
 int num = atoi(argv[1]);
 int result = binary_search(arr, size, num);
 if(result == -1 ){
 	printf("Element is not found\n");
 }else{
 	printf("Element is found in index : %d\n",result);
 }
 
 return 0;
 }
