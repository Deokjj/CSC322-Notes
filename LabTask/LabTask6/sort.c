#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

//getpid returns the process ID of the current process
//pid_t data type is a signed integer capable of representing a processID
pid_t getpid();

typedef int *  Intptr;
typedef int    ArrOfFiveInts[LENGTH];
typedef Intptr ArrOfFiveIntptrs[LENGTH];

void init (ArrOfFiveInts fiveInts, ArrOfFiveIntptrs fiveIntptrs);
void printInts (int * arr);
void printIntsByPointer (int ** arr);
void bubbleSort(int * arr);
void bubbleSortPointers(int ** arr);

int main() {
	//declaration
	ArrOfFiveInts    fiveInts;
	ArrOfFiveIntptrs fiveIntptrs;
	
	int pid = getpid(); 
	//seeds the pseudo-random number generator used by rand() with getpid value seed.
	srand(pid);
	//initialize the arrays
	init(fiveInts, fiveIntptrs);
	
	printf("---- Initialized array of integers ----\n");
	printInts(fiveInts);

	bubbleSortPointers(fiveIntptrs);
	printf("---- Sorted array of pointers ----\n");
	printIntsByPointer(fiveIntptrs);
	
	bubbleSort(fiveInts);
	printf("---- Sorted array of integers ----\n");
	printInts(fiveInts);	

	printf("---- Array of pointers ----\n");
	printIntsByPointer(fiveIntptrs);

	return 1;
}

void init (ArrOfFiveInts fiveInts, ArrOfFiveIntptrs fiveIntptrs){
	int i;
	for(i=0; i<LENGTH; i++){
		fiveInts[i] = rand();
		fiveIntptrs[i] = &(fiveInts[i]);
	}
}

void printInts (int * arr) {
   	 int i;
    	for (i = 0; i < LENGTH; i++) {
        	printf("  %d : %d\n", i, *(arr + i));
    	}
}

void printIntsByPointer (int ** arr) {
 	int i;
    	for (i = 0; i < LENGTH; i++) {
        	printf("  %d : %d\n", i, **(arr + i));
    	}
}

void bubbleSortPointers (int ** arr) {
    	int i, j;
	for(i = 0; i < LENGTH; i++) {
		for(j=0; j < LENGTH -i -1; j++) {
			if(**(arr + j) > **(arr + j + 1)){
				int * temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}

void bubbleSort (int * arr) {
    	int i, j;
	for(i = 0; i < LENGTH; i++) {
		for(j=0; j < LENGTH -i -1; j++) {
			if(*(arr + j) > *(arr + j + 1)){
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}
