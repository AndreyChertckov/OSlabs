#include <stdio.h>

void bubble_sort(int a[], int size) {
	for(int i =0; i < size; i++) {
		for(int j=0; j < size - i-1; j++) {
			if(a[j] > a[j+1]) {
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

int main() {
	int a[6] = {1,5,4,3,2,0};
	bubble_sort(a,6);
	printf("%d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
	return 0;
}
