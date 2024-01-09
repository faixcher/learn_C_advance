#include <stdio.h>
#include <string.h>

int main(){
	char message[10];
	int count, i;

	strcpy(message,"Hello ,World!\n");

	printf("Repeat how many time? ");
	scanf("%d",&count);

	for(i=0; i<count; i++){
		printf("%3d - %s\n",i,message);
	}
}
