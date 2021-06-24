#include<stdio.h>
#include<stdlib.h>


int main(){
	int p;
	printf("Enter the length of the array: ");
	scanf("%d",&p);
	int i = 0,j=0;
	int size1 = p*sizeof(int);
	int *arr = (int*)malloc(size1);
	printf("Enter the elements of the array");
	for(i=0;i<p;i++){
		scanf("%d",arr+i);
	}
	int smallest = 32000;
	for(i=0;i<p;i++){
		if( smallest > *(arr+i))
			smallest = *(arr+i);
	}
	printf("smallest element in the array is %d",smallest);
	return 0;
}