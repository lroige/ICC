/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <"prac1funs.h">

int ldlt(int n, double **A, double tol);

int main(){
    int n, i, j;
    double **L, *b, *x, *y, tol;

    printf("Introdueix la dimensio de la matriu: ");
    scanf("%d", &n);

    tol = 1.e-12;
    
    /*Inicialitzem matriu L i vectors b, x i y */
    
    x = (double*)malloc(n*sizeof(double*));

    y = (double*)malloc(n*sizeof(double*));
    
    L = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        L[i]= (double*)malloc(n*sizeof(double));
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("Introduir l'element de la fila %d, columna %d de la matriu:\n", i+1, j+1);
            scanf("%le", &L[i][j]);
        }
    }
    
    b = (double*)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        printf("Introduir l'element %d del vector:\n", i+1);
        scanf("%le", &b[i]);
    }

    
    
    
    
    /*Alliberar matriu*/
    for(i = 0; i < n; i++){
        free(L[i]);
    }
    free(L);
    free(b);
    free(x);
    free(y)
    
    return 0;
}

int ldlt (int n, double **A, double tol){
    
    if A[k][k] < tol{
        un cop descomposat
        return 1;
    }
    
    return 0;
}
