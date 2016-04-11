#include <stdio.h>

 int main(void){

 	FILE *fp; 
 	//char buff[255]; 
 	FILE *fopen()
	fp = fopen("/C/Values.rtf","r"); 
	fscanf(fp, "%s",buff);
	printf("1 : %s\n", buff); 
	fclose(fp); 

	//fgets(buff, 255, (FILE*)fp); 







/*
int c; 

while (c != 1){
scanf("%d",&c);
	printf("no\n"); 
	}

	printf("complete\n");
}
*/
}