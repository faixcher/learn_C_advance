#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h" // this will find hakcing.h'file in current directory

void usage(char *program_name,char *filename){
	printf("Usage: %s <data to add to %s>\n",program_name,filename);
	exit(0);
}

void fatal(char *); // still need to declare ,whenever include "hacking.h"
void *ec_malloc(unsigned int); // tooo 

int main(int argc,char *argv[]){
	int userid, fd;
	char *buffer, *datafile;

	buffer = (char *) ec_malloc(100);
	datafile = (char *) ec_malloc(20);
	strcpy(datafile,"/var/notes");

	if(argc<2)
		usage(argv[0],datafile);
	strcpy(buffer,argv[1]);

	printf("[DEBUG] buffer   @ %p: \'%s\'\n",buffer,buffer);
	printf("[DEBUG] datafile @ %p: \'%s\'\n",datafile,datafile);

	fd = open(datafile,O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
	if(fd == -1)
		fatal("in main() while opening file");
	printf("[DEGUB] file descriptor is %d\n", fd);

	userid = getuid(); // get real user ID

	//Writing data 
	if(write(fd,&userid,4) == -1) // point to address save userid 
		fatal("in main() while writing userid to file");
	write(fd,"\n",1);

	if(write(fd,buffer,strlen(buffer)) == -1) //NOTE !! parametor of 2 , need to send pointer 
		fatal("in main() while writing buffer to file");
	write(fd,"\n",1);

	//Closing file
	if(close(fd) == -1)
		fatal("in main() while closing file");
	printf("Note has been saved.\n");
	free(buffer);
	free(datafile);



}


