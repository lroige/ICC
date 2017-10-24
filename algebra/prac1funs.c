/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*Aquesta funcio resol un sistema en una matriu triangular inferior i guarda la solucio al vector x*/
void resTinf (int n, double **L, double *x, double *b){
    int i, j;
    double sum;
    
    x[0] = b[0];
    for (i = 1; i < n; i++){
        sum = 0;
        for (j = 0; j < i; j++){
            sum += L[i][j] * x[j];
        }
        x[i] = b[i] - sum;
    }
}

/*Aquesta funcio resol un sistema en una matriu triangular superior i guarda la solucio al vector x*/
void resTsup (int n, double **U, double *x, double *b){
    int i, j;
    double sum;
    
    x[n - 1] = b[n - 1];
    for (i = n - 1; i > 0; i++){
        sum = 0;
        for (j = i + 1; j < n; j++){
            sum += U[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / U[i][i];
    }
}

/* Aquesta funcio calcula el producte d'una matriu per un vector
 * multiplica A*x i guarda el resultat en y
 * A=mxn x=n y=m
 */
void prodMatVec (int m, int n, double **A, double *x, double *y){
    int i, j;

    for (i = 0; i < m; i++){
        y[i] = 0;
        for (j = 0; j < n; j++){
            y[i] += A[i][j] * x[j];
        }
    }
}

/* Aquesta funcio calcula el producte d'una matriu per una altra
 * multiplica A*B i guarda el resultat en C
 * A=mxn B=nxp C=mxp
 */
void prodMatMat (int m, int n, int p, double **A, double **B, double **C){
    int i, j, k;

    for (i = 0; i < m; i++){
        for (j = 0; j < p; j++){
            C[i][j] = 0;
            for (k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[j][k];
            }
        }
    }
}
