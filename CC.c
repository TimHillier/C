#include <stdio.h>
#include <stdbool.h>	
#include <stdlib.h>


 int main(void){
int c=0; 
int right[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,12,2,3,4,5,6,7,8,9,0,11};
int left[]={1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,11,12,2,3,4,5,6,7,8,9,0,11};
int rright[]={-1}; 
int lleft[]={-1}; 
int both[]={-1,-1};
int other[sizeof(right)/sizeof(right[0])]; 
int b = 0; 
//boolean to see if you took from right & left
bool R = false; 
bool L = false; 


//file input? 
//This isnt even relevant fuck this
/* 
char ch;
char *p; 
char file_name[25]="Right"; 


FILE *fp; 

fp= fopen(file_name,"r");

if(fp== NULL){
	perror("Error while opening the file.\n");
	exit(EXIT_FAILURE); 	
} 
printf("The contents of %s file are:\n",file_name);

while ( ( ch = fgetc(fp))!= EOF){
	printf("%c",ch); 
}
fclose(fp); 



//idk what im doing. 
*/



//lleft and rright can act as buffers maybe

	
// read from left and right, and only continue once it gets both values. 
//cannot take 2 from left or right. has to be one from each side
//set values to -1
//





while(true){


//maybe make these if statements do whiles? 
//take input from right

if(rright[0] < 0 && R == false){
	//take input from right motor and set it into the right array
	rright[0]=right[c];
	R=true;
}else{
	//wait?
}
if(lleft[0]<0 && L == false){
	//take input from the left motor and set it into the left array
	lleft[0]=left[c];
	L=true; 
}else{
	//wait?
}

if(rright[0]>=0 && lleft[0]>=0 ){
	//combine into one array? 
	//Do I compare here? 
	//push to thing. 
	rright[0]=other[b]; 
	rright[0]=-1; 
	R=false; 
	b++; 
	lleft[0]=other[b];
	lleft[0]=-1;  
	L=false; 
	b++; 
	c++; 
}

//If This needs to check if they are equal then you would check here, 
// and push to error correction if it is false, or the other place if it
//is true; 
//still need to figure out what to do if it gets 2 of one side
//Like what happens if this happens? 
//I dont think this will loop forever, once it gets past the if else x2 then it just stops if its
//false. Need a way to check again. Maybe a do while? Should I make left and right seperate? 
//Does it matter? yes it does, if it takes 2 from right, and assigns one of them left, then its no good. 
//Maybe put both if/else checks, into a while loop, and if its else, then set the thing to true, 
//and if it is true, then set it to false
//EXAMPLE
//---------------------------------------
/*

flag = true; 

while(flag){
	
f(rright[0] < 0 && R == false){
	//take input from right motor and set it into the right array
	rright[0]=right[c];
	R=true;
	flag = false; 
}else{
	flag = true; 
	//and it continues to loop, checking for right input. 
	//but then what if it gets Left first? 
	//need to figure that out
	//but this should work. I like this actually
	//Yes
	



	//wait?
}




}





*/






}
}


