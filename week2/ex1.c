#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	printf("INT size: %d; max value: %d\n", sizeof(int), i);
	printf("FLOAT size: %d; max value: %f\n", sizeof(float), f);
	printf("DOUBLE size: %d; max value: %f\n", sizeof(double), d);
	return 0;
}
