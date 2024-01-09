#include <stdio.h>

void function(){
	int var = 5;
	static int static_var = 5; //one run (if see that dont run) 
	printf("\t[in function] var = %d\n",var);
	printf("\t[in function] static_var = %d\n",static_var);
	var++;
	static_var++;

}
int main(){
	int i ; //nothing 
	static int static_var = 1337; //point

	for(i=0;i<5;i++){
		printf("[in main] static_var = %d\n",static_var);
		function();
	}
}
