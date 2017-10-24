/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "prac1funs.h"

int ldlt(int n, double **A, double tol);
void transposar_matriu(int n, double** A);

int main(){
    int n, i, j, error;
    double **A, *b, *x, *y, *z, *prod, norma, sum, tol;

    printf("Introdueix la dimensio de la matriu: ");
    scanf("%d", &n);

    tol = 1.e-12;
    
    /*Inicialitzem matriu A i vectors b, x i y */
    
    x = (double*)malloc(n*sizeof(double*));

    y = (double*)malloc(n*sizeof(double*));
    
    z = (double*)malloc(n*sizeof(double*));
    
    prod = (double*)malloc(n*sizeof(double*));
    
    A = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        A[i]= (double*)malloc(n*sizeof(double));
    }

    /*----------------------------------------FALLA SQRT-------------------------------------------------/*
    
    /* Llegim la matriu i en comprovem la simetria */
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("Introduir l'element de la fila %d, columna %d de la matriu:\n", i+1, j+1);
            scanf("%le", &A[i][j]);
            if (i > j && A[i][j] != A[j][i]){
                printf("La matriu no es simetrica");
                return 1;
            }
        }
    }
    
    
    b = (double*)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        printf("Introduir l'element %d del vector:\n", i+1);
        scanf("%le", &b[i]);
    }

    error = ldlt(n, A, tol);
    
    if (error == 1){
        printf("No s'ha pogut descomposar la matriu");
        return 1;
    }
    
    /* Posem zeros sobre la diagonal de A per facilitar els calculs posteriors */
    
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            A[i][j] = 0.0;
        }
    }
    
    /* Ara que tenim la matriu LD resolem el sistema de la seguent manera:
     * Lz = b (passant A com a matriu triangular inferior al mètode resTinf)
     * Dy = z (passant A com a matriu triangular superior al mètode resTsup)
     * (Transposem la matriu A)
     * Ltx = y (passant A transposada com a matriu triangular superior al mètode resTsup)
     */
    
    resTinf(n, A, z, b);
    
    resTsup(n, A, y, z);
    
    transposar_matriu(n, A);
    
    resTsup(n, A, x, y);
    
    /* Ara que tenim el resultat construim la matriu LDLt (posant Lt a la triangular superior d'A) per
     * calcular-ne la norma
     */
    
    /* Posem zeros sobre la diagonal de A per facilitar els calculs posteriors */
    
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            A[j][i] = A[i][j];
        }
    }
    
    prodMatVec(n, n, A, x, prod);
    
    sum = 0;
    for (i = 0; i < n; i++){
        sum += pow((prod[i] - b[i]), 2);
    }
    norma = sqrt(sum);
   
    /*Imprimim el vector solucio i la norma |Lx-b|2*/
    printf("El vector solucio es:\n");
    for(i = 0; i < n; i++){
        printf("%f    ", x[i]);
    }
    printf("\n");
    
    printf("La norma |Ax - b|2 es: %le", norma);

    
    /*Alliberar matriu*/
    for(i = 0; i < n; i++){
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);
    free(y);
    
    return 0;
}

int ldlt (int n, double **A, double tol){
    int i, j, k;
    
    for (k = 0; k < n; k++){
        for (j = 0; j < k; j++){
            A[k][k] -= pow(A[k][j], 2) * A[j][j];
        }
    }
    
    for (k = 0; k < n; k++){
        for (i = k + 1; i < n; i++){
            for (j = 0; j < k; j++){
                A[i][k] -= A[i][j] * A[k][j] * A[j][j];
            }
        }
        if (fabs(A[k][k]) < tol){
            return 1;
        }
        A[i][k] /= 1 / A[k][k];
    }
    
    return 0;
}

/*Aquesta funcio transposa una matriu de dimensio n*/
void transposar_matriu(int n, double** A){
    double aux;
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i > j){
                aux = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = aux;
            }
        }
    }
}
