#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include <unistd.h>

int print_value(char str[]){
	int ret;
	ret = write(1,str,strlen(str));
	return ret;

} 

int main(void){

print_value("Hello world\n");
}
