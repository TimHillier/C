#include <stdio.h>

 int main(void){
int c; 
int values[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,12,2,3,4,5,6,7,8,9,0,11};

int i = 0; 
int k = 0; 
int other[sizeof(values)/sizeof(values[0])]; 



while (values[i] != 0){
	printf("no\n"); 
	if(values[i]==11){
		other[k]= values[i]; 
		printf("%d added to other\n",other[k]);
		k++;
	}
	i++; 
	}

	printf("complete\n");
}