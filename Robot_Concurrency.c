#include <stdio.h>
#include <stdbool.h>	
#include <pthread.h>


  int main(){
//int values to go through the arrays. 
int b,c,d,q = 0; 

//test value to go through array right and left; 
int right[]={1,2,3,4,5};
int left[]={1,2,2,4,5};


//test Bool for reject
bool REJECT = false; 

int rright[]={-1}; 
int lleft[]={-1}; 


//reject is an array of values that are not equal from left and right
int reject[sizeof(right)/sizeof(right[0])]; 
//good is an array of values that are equal from left and right
int good[2*sizeof(right)/sizeof(right[0])]; 
//boolean to see if you took from right & left
bool R = false; 
bool L = false; 
//booleans for the outter while loop
bool FLAG = true;
bool flagr = true; 
bool flagl = true; 





while(FLAG){



	//take input from right
	while(flagr){

	if(rright[0] < 0 && R == false){
		//take input from right motor and set it into the right array
		rright[0]=right[q];
		flagr = false; 
		R=true;
	}else{

		flagr = true; 
	}
}

	while(flagl){

		if(lleft[0] < 0 && L == false){
			//take input from the left motor and set it into the left array
			lleft[0]=left[q];
			flagl = false; 
			L=true; 
		}else{
			flagl = true; 
		}
}
		//Checks if the two values are equal. 
		if(rright[0]==lleft[0]){
			good[c]=rright[0]; 
			c++; 
			good[c]=lleft[0]; 
			c++; 
		}else{
			//The right and left are not equal, so add them to the reject array. 
			reject[d]=rright[0]; 
			d++; 
			reject[d]=lleft[0]; 
			d++; 
			//test bool
			REJECT = true; 
		}
//reset the flags for left and right, so it continues
flagr=true; 
flagl=true; 
rright[0]=-1; 
R=false; 
lleft[0]=-1; 
L=false; 
q++; 
b++;

//This literally goes on forever, so only goes for as long as the arrays are
//debug
if(b >= sizeof(right)/sizeof(right[0])){
FLAG = false; 

}
}
}







