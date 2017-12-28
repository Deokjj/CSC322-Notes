#include <stdio.h>
#include <stdlib.h>

typedef char String[256];
typedef enum { false, true } boolean; // data type that returns either false or true

double * input_matrix   (int * rows, int * columns, char * key);
void output_matrix      (double * matrix, int rows, int columns);
boolean matrix_multiply    (double * m1, int m1_rows, int m1_cols, double * m2, int m2_rows, int m2_cols, double * m3);

int main(void) {

    double *m1,*m2,*m3;
    int m1_rows,m1_cols,m2_rows,m2_cols;

    if (((m1 = input_matrix(&m1_rows,&m1_cols,"Matrix 1")) != NULL) &&
((m2 = input_matrix(&m2_rows,&m2_cols,"Matrix 2")) != NULL) &&
((m3 = malloc(m1_rows*m2_cols*sizeof(double))) != NULL)) {
        printf("Matrix 1\n");
        output_matrix(m1,m1_rows,m1_cols);
        printf("Matrix 2\n");
        output_matrix(m2,m2_rows,m2_cols);
        if (matrix_multiply(m1,m1_rows,m1_cols,m2,m2_rows,m2_cols,m3)) {
            printf("Product\n");
            output_matrix(m3,m1_rows,m2_cols);
            free(m1);
            free(m2);
            free(m3);
            return(0);
        } else {
            printf("Error in dimensions\n");
            free(m1);
            free(m2);
            free(m3);
            return(-1);
        }
    } else {
        free(m1);
        free(m2);
        free(m3);
        printf("Error allocating memory\n");
        return(-2);
    }
}

double * input_matrix (int * rows, int * columns, char * key) {
    double * matrix;
    int i, j;

    printf("Number of rows in %s?:\t\t", key);
    scanf("%d", rows);
    printf("Number of cols in %s?:\t\t", key);
    scanf("%d", columns);

    matrix = (double *)(malloc((*rows * *columns) * sizeof(double)));

    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *columns; j++) {
            printf("Enter value of row %d col %d of %s:\t", i+1, j+1, key);
            scanf("%lf", matrix + (i * *columns) + j);
        }
    }

    return matrix;
}

void output_matrix (double * matrix, int rows, int columns) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%4.2f\t", *(matrix + (i * columns) + j));
        }
        printf("\n");
    }
}

boolean matrix_multiply (double * m1, int m1_rows, int m1_cols, double * m2, int m2_rows, int m2_cols, double * m3) {
    int i, j, k;
    double n, m, sum;
    if (m1_cols != m2_rows) {
        return false;
    }
    for (i = 0; i < m1_rows; i++) {
        for (j = 0; j < m2_cols; j++) {
            sum = 0;
            for (k = 0; k < m1_cols; k++) {
  		m = *(m1 + (i*m1_cols) + k);
		n = *(m2 + (k*m2_cols) + j);
                sum += (n * m);
            }
	    *(m3 + i*m2_cols + j) = sum;
        }
    }
    return true;
}
