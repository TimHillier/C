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






bool flagr = true; 
int rright[]={-1}; 
bool R = false; 
int right[]={1,2,2,4,5};
int left[]={1,2,2,4,5};
int lleft[]={-1}; 
bool L = false; 
bool FLAG = true;
bool flagl = true;
int q = 0; 





  int main()
  {
  	//create threads
  	pthread_t thread1, thread2; 
  	int rc1, rc2; 

  	int counter =0; 


 	//C counts for equal values, D counts for not equal values. 
int b = 0; 
int c=0; 
int d=0; 
//test value to go through array right and left; 

//storage arrays to keep the element seperate

//test Bool for reject
bool REJECT = false; 

// both is array to hold both values if i need to
//int both[]={-1,-1};
//reject is an array of values that are not equal from left and right
int reject[sizeof(right)/sizeof(right[0])]; 
//good is an array of values that are equal from left and right
int good[2*sizeof(right)/sizeof(right[0])]; 
//boolean to see if you took from right & left
 
//lleft and rright can act as buffers maybe	
// read from left and right, and only continue once it gets both values. 
//cannot take 2 from left or right. has to be one from each side
//set values to -1


printf("size of good %lu\n",sizeof(good)/sizeof(good[0]));


while(FLAG){

if((rc1=pthread_create(&thread1, NULL, &rightCounter, NULL)))
{
	printf("Thread creation failed: %d\n", rc1);
}
if((rc2 = pthread_create(&thread2, NULL, &leftCounter,NULL)))
{
	printf("Thread creation failed: %d\n",rc2); 
}





//if(rright[0]>=0 && lleft[0]>=0 ){
	printf("in comparision\n");
	//combine into one array? 
	//Do I compare here? 
	//push to thing. 
	//if the 2 are equal, add them to array, and say they where added. 
	//if they are not equal, add them to reject array and say they where added. 


	//Should this be in a thread/ 
	//maybe. 

pthread_join(thread1, NULL); 
pthread_join(thread2, NULL); 
	
	if(rright[0]==lleft[0]){

		good[c]=rright[0]; 
		printf("%d added to good from right\n",rright[0]); 
		c++; 
		good[c]=lleft[0]; 
		printf("%d added to good from left\n",lleft[0]); 
		c++; 
}else{

	printf("%d from right is not equal to %d from left\n",rright[0],lleft[0]); 
	reject[d]=rright[0]; 
	printf("%d added to reject from right\n",rright[0]); 
	d++; 
	reject[d]=lleft[0]; 
	printf("%d added to rejct from left\n",lleft[0]); 
	d++; 
	//test bool
	REJECT = true; 
}


flagr=true; 
flagl=true; 
//
rright[0]=-1; 
R=false; 
lleft[0]=-1; 
L=false; 
q++; 
b++;
//This literally goes on forever
if(b >= sizeof(right)/sizeof(right[0])){
FLAG = false; 
printf("COMPLETE\n"); 
printf("Reject = %s\n",REJECT ? "true" : "false"); 

//}
}
}
}

//function
void*rightCounter()
{
	pthread_mutex_lock(&mutex1); 
	//rightcounter++;
	//printf("rightcounter\n");
		while(flagr){
	if(rright[0] < 0 && R == false){
		//take input from right motor and set it into the right array
		rright[0]=right[q];
		flagr = false; 
		R=true;
	}else{
		flagr = true; 
		//wait
}
} 
 
	pthread_mutex_unlock(&mutex1); 
	return 0; 
}



void*leftCounter()
{
	pthread_mutex_lock(&mutex2); 
	//leftcounter++; 
	//printf("leftcounter\n");
	while(flagl){
		if(lleft[0] < 0 && L == false){
		//take input from the left motor and set it into the left array
		lleft[0]=left[q];
		flagl = false; 
		L=true; 
	}else{
		flagl = true; 
		//wait?
}
}

	pthread_mutex_unlock(&mutex2); 
	return 0; 
}














//If This needs to check if they are equal then you would check here, 
// and push to error correction if it is false, or the other place if it
//is true; 
//still need to figure out what to do if it gets 2 of one side
//Like what happens if this happens? 
//I dont think this will loop forever, once it gets past the if else x2 then it just stops if its
//false. Need a way to check again. Maybe a do while? Should I make left and right seperate? 
//Does it matter? yes it does, if it takes 2r, and assigns one of them left, then its no good. 
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
	flag = false; //Breaks out of the while loop for checking the side
}else{
	flag = true; 
	//and it continues to loop, checking for right input. 
	//but then what if it gets Left first? 
	//need to figure that out
	//but this should work. I like this actually
	//yes
	}
}
*/
//---------------------------------------
//If i can make both left and right run at the same time that would be good. 
//But again, what do i do if I get 2r? 
//Do i need to count, if I need to count than thats different. 
//that would change everything. 
//Would it though? 
//Just keep count. lol
//shoudl the last if(61) havve a loop, or will it work not having a loop? 









