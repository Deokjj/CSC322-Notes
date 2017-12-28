#include <stdio.h>
#include <stdlib.h>

#define LENGTH 3

typedef int matrix[3][3];

void inputMatrix(int ** m, char name);
void multiplyMatrices (int ** a, int ** b, int ** result);
void printMatrix (int ** m, char name);

int main (void) {
    	matrix a;
    	matrix b;
    	matrix c;

    	printf("When entering rows, delimit numbers with spaces.\n");
    
    	inputMatrix((int **)a, 'A');
    	inputMatrix((int **)b, 'B');

    	printMatrix((int **)a, 'A');
    	printMatrix((int **)b, 'B');
    	printf("If C = AB, then ");
    	multiplyMatrices((int **)a, (int **)b, (int **)c);
    	printMatrix((int **)c, 'C');

    	return 1;
}

void inputMatrix(int ** m, char name) {
    	int i;
    	for (i = 0; i < 3; i++) {
        	*(m + i) = (int *)malloc(3 * sizeof(int));
        	printf("Enter row %d of matrix %c: ", i + 1, name);
        	scanf("%d %d %d", (*(m+i)), (*(m+i)+1), (*(m+i)+2));
    	}
    	printf("\n");
}

void multiplyMatrices (int ** a, int ** b, int ** result) {
    	int i, j, k, sum;
    	int m, n;
    	for (i = 0; i < 3; i++) {
        	*(result + i) = (int *)malloc(3 * sizeof(int));
        	for (j = 0; j < 3; j++) {
	 		sum = 0;
			for (k = 0; k < 3; k++) {
                		m = *(*(a+i)+k);
                		n = *(*(b+k)+j);
                		sum += (n * m);
            		}
            		*(*(result + i) + j) = sum;
        	}
    	}
}

void printMatrix (int ** m, char name) {
    	int i, j;
    	printf("matrix %c is:\n", name);
    	for (i = 0; i < 3; i++) {
        	for (j = 0; j < 3; j++) {
            		printf("%d\t", *(*(m+i)+j));
        	}
        	printf("\n");
    	}
}
