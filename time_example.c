#include <stdio.h>
#include <time.h>

int main(){
	long int seconds_since_epoch;
	struct tm current_time,*time_ptr;
	int hour, minute, second, day, month,year;

	seconds_since_epoch = time(0); // pass null to argument
	printf("time() -seconds since epoch: %ld\n",seconds_since_epoch);

	time_ptr = &current_time;
	localtime_r(&seconds_since_epoch,&current_time); // covert formant 
							// use time_ptr or &current_time

	// three way to access time 	
	hour = current_time.tm_hour;
	minute = time_ptr->tm_min; // access time in struct with pointer
	second = *((int *) time_ptr);// the first varaible is tm struct is tm_second	

	printf("Current time is: %02d:%02d:%02d\n",hour,minute,second);




}
