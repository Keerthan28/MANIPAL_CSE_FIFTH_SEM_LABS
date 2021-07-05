#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

void* thread_code(void* n)
{
	int sum = 0,k=0;
	int limit = *((int*)n);
	srand(time(0));
	for (int i = 1; i <= limit; i++){
		k = rand()%100;
		//printf("%d\n",k);
		sum += k;
	}
	*((int*)n) = sum;
}

void main()
{
	int n, num;
	printf("Enter no. of elements: ");
	scanf("%d", &n);
	num = n;
	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void*)&n);
	pthread_join(thread, NULL);
	printf("Sum of all non-negetive numbers generated randomly is: %d\n", n);
}