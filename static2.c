#include <stdio.h>

void function(){
	int var = 5;
	static int static_var = 5; 

	printf("\t[in function] var @ %p = %d\n", &var, var);
	printf("\t[in function] static_var @ %p = %d\n", &static_var,static_var);
	var++;
	static_var++;
}
void function2(){
	int var2 = 5;
        static int static_var = 5;

        printf("\t[in function2] var2 @ %p = %d\n", &var2, var2);
        printf("\t[in function2] static_var @ %p = %d\n", &static_var,static_var);
        var2++;
        static_var++;

}
int main(){
	int i;
	static int static_var = 1337;

	for(i = 0;i<5;i++){
		printf("[in main] static_var @ %p = %d\n",&static_var,static_var);
		function();                                                               
		function2();
	}
}

