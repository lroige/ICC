/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "prac1funs.h"

int ldlt(int n, double **A, double tol);
void transposar_matriu(int n, double** A);

int main(){
    int n, m, i, j, error;
    double **A, **At, **M, *b, *x, *y, *z, *prod, norma, sum, tol;

    printf("Introdueix les dimensions de la matriu (m i n amb m < n i m, n >= 2): \n");
    scanf("%d %d", &m, &n);
    
    if (n < 2 || m < 2 || n < m){
        printf("Les dimensions de la matriu no serveixen per aquest programa\n");
        return -1;
    }

    tol = 1.e-12;
    
    /*Inicialitzem matriu A i vectors b, x i y */
    
    x = (double*)malloc(n*sizeof(double));

    y = (double*)malloc(n*sizeof(double));
    
    z = (double*)malloc(n*sizeof(double));
    
    prod = (double*)malloc(n*sizeof(double));
    
    A = (double**)malloc(m*sizeof(double*));
    for (i = 0; i < m; i++){
        A[i]= (double*)malloc(n*sizeof(double));
    }
    
    At = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        At[i]= (double*)malloc(m*sizeof(double));
    }
    
    M = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        M[i]= (double*)malloc(n*sizeof(double));
    }
    
    /* Llegim la matriu */
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf("Introduir l'element de la fila %d, columna %d de la matriu:\n", i+1, j+1);
            scanf("%le", &A[i][j]);
            At[j][i] = A[i][j];
        }
    }
    
    
    b = (double*)malloc(n*sizeof(double));
    for (i = 0; i < n; i++){
        printf("Introduir l'element %d del vector:\n", i+1);
        scanf("%le", &b[i]);
    }

    /* Comencem la resolucio, primer de tot calculem M = At*A i At*b*/
    
    prodMatMat(m, n, m, A, At, M);
    
    
    error = ldlt(n, M, tol);
    
    if (error == 1){
        printf("No s'ha pogut descomposar la matriu\n");
        return 1;
    }

    /* Ara que tenim la matriu LD resolem el sistema de la seguent manera:
     * Lz = b (passant M com a matriu triangular inferior al mètode resTinf)
     * Dy = z
     * Ltx = y (passant M transposada com a matriu triangular superior al mètode resTsup)
     */
    
    resTinf(n, M, z, b);
    
    resTsup(n, M, y, z);
        
    resTsup(n, M, x, y);
    
    /* Ara que tenim el resultat construim la matriu LDLt (posant Lt a la triangular superior d'M) per
     * calcular-ne la norma
     */
    
    prodMatVec(n, n, M, x, prod);
    
    sum = 0.;
    for (i = 0; i < n; i++){
        sum += pow((prod[i] - b[i]), 2);
    }
    norma = sqrt(sum);
   
    /*Imprimim el vector solucio i la norma |Lx-b|2*/
    printf("El vector solucio es:\n");
    for(i = 0; i < n; i++){
        printf("%e    ", x[i]);
    }
    printf("\n");
    
    printf("La norma |Mx - b|2 es: %e\n", norma);

    
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
        for (i = 0; i < n; i++){
            A[i][k] = A[i][k] * 1 / A[k][k];
        }
    }
    
    return 0;
}

int print_matrix(int n, double **A){
    int a;
    int b;
    for(a = 0; a<n; a++){
        for (b = 0; b<n; b++){
            printf("%f    ", A[a][b]);
        }
        printf("\n");
    }
    printf("\n");
    return 1;
}
