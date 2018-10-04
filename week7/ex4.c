#include <string.h>
#include <stdlib.h>
#include <stddef.h> 
#include <stdio.h>

void * my_realloc(void * ptr, size_t size) {
	if(size <=0) {
		free(ptr);
	}else if(ptr == NULL){
		return malloc(size);
	}else {
		void * new_ptr = malloc(size);
		memcpy(new_ptr, ptr, size);
		free(ptr);
		return new_ptr;
	}
}

int main() {
	int * ptr = malloc(3 * sizeof(int));
	for(int i= 0; i < 3; i++) {
		ptr[i] = i;
		printf("%d ", ptr[i]);
	}
	printf("\n");
	ptr = my_realloc(ptr, 8* sizeof(int));
	for(int i=0; i < 8; i++) {
		printf("%d ", ptr[i]);
	}
	return 0;
}
