#include <stdio.h>

int func_one(){
	printf("This is function one\n");
	return 1;

}
int func_two(){
	printf("This is function own\n");
	return 2;
}
int main(){
	int value;
	int (*function_ptr) ();//

	function_ptr = func_one;
	printf("funcion_ptr is 0x016%x\n",function_ptr);
	value = function_ptr(); // return1 
	printf("value reterned was %d\n",value);

	function_ptr = func_two;
	printf("funcion_ptr is 0x016%x\n",function_ptr);
	value = function_ptr(); // if put () behind function_ptr is gonna be return'value
	printf("value returned was %d\n",value);

}
