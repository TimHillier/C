#include <stdio.h>

 int main(void){
int c; 
int right[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,12,2,3,4,5,6,7,8,9,0,11};
int left[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,12,2,3,4,5,6,7,8,9,0,11};
int i = 0; 
int k = 0; 
int other[sizeof(right)/sizeof(right[0])]; 



	
// read from left and right, and only continue once it gets both values. 
//cannot take 2 from left or right. has to be one from each side
//set values to -1
//





while (right[i] != 0){
	printf("no\n"); 
	if(right[i]==11){
		other[k]= right[i]; 
		printf("%d added to other\n",other[k]);
		k++;
	}
	i++; 
	}

	printf("complete\n");
}