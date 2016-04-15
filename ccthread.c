#include <stdio.h>
#include <stdbool.h>	
#include <stdlib.h>
#include <pthread.h>


//functions?

void*rightCounter(); 
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; 
int rightcounter = 0; 

void*leftCounter();
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
int leftcounter = 0 ; 






//Right and left are test arrays, and should be replaced with how we are keeping track of 
//the rotations, or movement. 
int right[]={1,2,2,4,5};
int left[]={1,2,2,4,5};

int rright[]={-1}; 
int lleft[]={-1}; 
bool L = false; 
bool R = false; 
bool flagr = true; 
bool flagl = true;
bool FLAG = true;

int q = 0; 


  int main()
  {
  	//create threads
pthread_t thread1, thread2; 
int rc1, rc2; 
int counter =0;  
int b = 0; 	int c=0; 
int d=0; 




//test Bool for reject
bool REJECT = false; 

int reject[sizeof(right)/sizeof(right[0])]; 

int good[2*sizeof(right)/sizeof(right[0])]; 
//Test

//debug
printf("size of good %lu\n",sizeof(good)/sizeof(good[0]));


while(FLAG){


//error checking for thread creation
	if((rc1=pthread_create(&thread1, NULL, &rightCounter, NULL)))
	{
		printf("Thread creation failed: %d\n", rc1);
	}
	if((rc2 = pthread_create(&thread2, NULL, &leftCounter,NULL)))
	{
		printf("Thread creation failed: %d\n",rc2); 
	}
		printf("in comparision\n");
	
//wait for both threads to be done before continuting. 
pthread_join(thread1, NULL); 
pthread_join(thread2, NULL); 

	if(rright[0]==lleft[0]){

			good[c]=rright[0]; 
			//debug
		printf("%d added to good from right\n",rright[0]); 
			c++; 
			good[c]=lleft[0];
			//debug 
		printf("%d added to good from left\n",lleft[0]); 
			c++; 
	}else{

			//debug
		printf("%d from right is not equal to %d from left\n",rright[0],lleft[0]); 
			reject[d]=rright[0]; 
			//debug
		printf("%d added to reject from right\n",rright[0]); 
			d++; 
			reject[d]=lleft[0]; 
			//debug
		printf("%d added to rejct from left\n",lleft[0]); 
	d++; 
	//test bool
	REJECT = true; 
}


flagr=true; 
flagl=true; 
rright[0]=-1; 
R=false; 
lleft[0]=-1; 
L=false; 
q++; 
b++;
//This literally goes on forever
//debug loop run only a set amount of times
if(b >= sizeof(right)/sizeof(right[0])){
FLAG = false; 
//debug
printf("COMPLETE\n"); 
printf("Reject = %s\n",REJECT ? "true" : "false"); 


}
}
}

//function
void*rightCounter()
{
	pthread_mutex_lock(&mutex1); 

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
 
	pthread_mutex_unlock(&mutex1); 
	return 0; 
}



void*leftCounter()
{
	pthread_mutex_lock(&mutex2); 
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

	pthread_mutex_unlock(&mutex2); 
	return 0; 
}
