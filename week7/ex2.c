#include <stdio.h>
#include <malloc.h>

int main() {
	int N = 0;
	scanf("%d", &N);
	int *arr = malloc(N * sizeof(int));
	for(int i = 0; i< N;i++) {
		arr[i] = i;
	}
	printf("%d", arr[0]);
	for(int i = 1; i< N; i++) {
		printf(" %d", arr[i]);
	}
	return 0;
}
