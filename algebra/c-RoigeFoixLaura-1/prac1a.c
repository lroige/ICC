/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "prac1funs.h"

void transposar_matriu(int n, double** A);

int main(){
    int n, i, j;
    double **L, *b, *x, *y, sum, norma;

    printf("Introdueix la dimensio de la matriu: ");
    scanf("%d", &n);

    
    /*Inicialitzem matriu L i vectors b, x i y */
    
    x = (double*)malloc(n*sizeof(double));

    y = (double*)malloc(n*sizeof(double));
    
    L = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        L[i]= (double*)malloc(n*sizeof(double));
    }
    
    /* Llegim la matriu i comprovem que sigui triangular inferior amb uns a la diagonal */
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("Introduir l'element de la fila %d, columna %d de la matriu:\n", i+1, j+1);
            scanf("%le", &L[i][j]);
            /* Comprovem que l matriu es triangular inferior */    
            if (i < j && L[i][j] != 0.0){
                printf("La matriu no es triangular inferior");
                return 1;
            }
        }
        if (L[i][i] != 1.){
            printf("L'element %d de la diagonal no es 1!", i+1);
            return 1;
        }
    }
    
    b = (double*)malloc(n*sizeof(double));
    for (i = 0; i < n; i++){
        printf("Introduir l'element %d del vector:\n", i+1);
        scanf("%le", &b[i]);
    }

    resTinf(n, L, x, b);
    
    prodMatVec(n, n, L, x, y);
    
    sum = 0;
    for (i = 0; i < n; i++){
        sum += pow((y[i] - b[i]), 2);
    }
    norma = sqrt(sum);
   
    /*Imprimim el vector solucio i la norma |Lx-b|2*/
    printf("\nEl vector solucio es:\n");
    for(i = 0; i < n; i++){
        printf("%f    ", x[i]);
    }
    printf("\n");
    
    printf("\nLa norma |Lx - b|2 es: %le\n", norma);
    
    /* Transposem la matriu L i calculem la solució del sistema triangular superior resultant
     */
    transposar_matriu(n, L);
    
    resTsup(n, L, x, b);
    
    /*Imprimim el vector solucio del sistema triangular superior*/
    printf("\nEl vector solucio del sistema triangular superior es:\n");
    for(i = 0; i < n; i++){
        printf("%f    ", x[i]);
    }
    printf("\n");
    
    
    /*Alliberar matriu*/
    for(i = 0; i < n; i++){
        free(L[i]);
    }
    free(L);
    free(b);
    free(x);
    free(y);
    
    return 0;
}

/*Aquesta funcio transposa una matriu quadrada de dimensio n*/
void transposar_matriu(int n, double** A){
    double aux;
    int i, j;
    for(i = 0; i<n; i++){
        for(j = 0; j < n; j++){
            if(i > j){
                aux = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = aux;
            }
        }
    }
}
