#include <stdio.h>


void pointercopy(int **pointer_copied) {
	printf("Pointer in new function Memory Address Value: %p\n", pointer_copied);
}

int main(void){
	printf("Program to test pointer shit\n");

	int pointer = 0;
	pointer = 5;

	printf("Pointer Contains Value: %d\n", pointer);
	printf("Pointer Memory Address Value: %p\n", &pointer);

	printf("Calling Function\n");
	pointercopy(&pointer);
return 0;
}
