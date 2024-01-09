#include <stdio.h>
#include <string.h>

int main(){
	char str_a[20];
	char *pointer;
	char *pointer2;
	
	strcpy(str_a,"Fais love Allah\n");
	pointer = str_a;
	printf(pointer);

	pointer2 = pointer + 10;
	printf(pointer2);
	strcpy(pointer2,"Hannan");
	printf(pointer);
	

}
