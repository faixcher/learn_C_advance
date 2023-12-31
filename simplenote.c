#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void usage(char *prog_name,char *filename){
	printf("Usage: %s <data to add to %s>\n",prog_name,filename);
	exit(0);	
}
void fatal(char *); // function for fatal errrors
void *ec_malloc(unsigned int); // An error-checked malloc() wrapper

int main(int argc,char *argv[]){
	int fd ; // file descriptor
	char *buffer, *datafile;
	
	buffer = (char *) ec_malloc(100);
	datafile = (char *) ec_malloc(20); // filename still save with strings 
	strcpy(datafile,"/tmp/notes");

	if(argc < 2)
		usage(argv[0], datafile); 
	strcpy(buffer, argv[1]);

	printf("[DEBUG] buffer   @ %p: \'%s\'\n",buffer,buffer);
	printf("[DEBUG] datafile @ %p: \'%s\'\n",datafile,datafile);

	strncat(buffer,"\n",1); // add \n to end of buffer 

	//Opening file 
	fd = open(datafile,O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
	if(fd == -1)
		fatal("in main() while opening file");
	printf("[DEGUB] file descriptor is %d\n", fd);
	//Writing file
	if(write(fd,buffer,strlen(buffer)) == -1)
		fatal("in main() whiel writing buffer to file");
	//Closing file 
	if(close(fd) == -1 )
		fatal("in main() while closing file");

	printf("Note has been saved.\n");
	free(buffer);
	free(datafile);
	


}
void fatal(char *message){
	char error_message[100];
	strcpy(error_message,"[!!] Fatal Error "); // len 17
	strncat(error_message,message,83); 
	perror(error_message); // print error (if have) before end program 
	exit(-1);
}

void *ec_malloc(unsigned int size){
	void *ptr;
	ptr = malloc(size);
	if(ptr == NULL)
		fatal("in ec_malloc() on memory allocation");
	return ptr;
	
}

