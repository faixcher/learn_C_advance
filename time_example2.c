#include <stdio.h>
#include <time.h>

void dump_time_struct_bytes(struct tm *time_ptr,int size){
	int i;
	unsigned char *raw_ptr;
	printf("bytes of struct located at 0x%016x\n",time_ptr);
	raw_ptr = (unsigned char *)time_ptr;
	for(i =0 ;i<size;i++){
		printf("%02x ", raw_ptr[i]);
		if(i%16 == 15)
			printf("\n");
	}
	printf("\n");
	
}
int main(){
	long int seconds_since_epoch;
	struct tm current_time, *time_ptr;
	int hour,minute,second, i , *int_ptr;

	seconds_since_epoch = time(0);
	printf("time() - seconds since epoch: %ld\n",seconds_since_epoch);

	time_ptr = &current_time;
	localtime_r(&seconds_since_epoch,time_ptr); // covert second_since_time(long int farmat to int format' realnumber) 
												//to struct tm save to time_ptr(or currnet_time)

	//Three differnt ways to access struct elements:
	hour = current_time.tm_hour;
	minute = time_ptr->tm_min;
	second = *((int *)time_ptr);

	printf("Current time is: %02d:%02d:%02d\n",hour,minute,second);

	dump_time_struct_bytes(time_ptr,sizeof(struct tm));

	minute = hour = 0; // Clear out minute and hour
	int_ptr = (int *) time_ptr;

	for(i=0;i<3;i++){ // 3 bacause just want minute hour and second 
		printf("int_ptr @ 0x%016x : %d\n",int_ptr,*int_ptr);
		int_ptr++; 
	}
 
}