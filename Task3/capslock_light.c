#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char*argv[]){
int var ;
int value = atoi(argv[1]);
var = open("/sys/class/leds/input3::capslock/brightness", O_RDWR);
if(argv[1]!=NULL)
	dprintf(var,"%d",value);
return 0 ;
}
