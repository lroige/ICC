/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void resTinf (int n, double **L, double *x, double *b);
void resTsup (int n, double **U, double *x, double *b);
int normaVec (int n, double *vec);//PREGUNTA: ES PODEN POSAR MÉS FUNCIONS A LA LLIBRERIA?????
void prodMatVec (int n, int m, double **A, double *b);
void prodMatMat (int n, int m, double **A, double **B);


/*Aquesta funcio resol un sistema en una matriu triangular inferior i guarda la solucio al vector x*/
void resTinf (int n, double **L, double *x, double *b){
    int i, j, sum;
    
    x[0] = b[0];
    for (i = 1; i < n; i++){
        sum = 0;
        for (j = 0; j < i; j++){
            sum += L[i][j] * x[k];
        }
        x[i] = b[i] - sum;
    }
    
    return 0;
}

/*Aquesta funcio resol un sistema en una matriu triangular superior i guarda la solucio al vector x*/
void resTinf (int n, double **L, double *x, double *b){
    int i, j, sum;
    
    x[n - 1] = b[n - 1];
    for (i = 1; i < n; i++){
        sum = 0;
        for (j = 0; j < i; j++){
            sum += L[i][j] * x[k];
        }
        x[i] = b[i] - sum;
    }
    
    return 0;
}

/*Aquesta funcio calcula la norma euclidiana d'un vector i retorna el resultat*/
int normaVec (int n, double *vec){
    int sum = 0
    for (i = 0; i < n; i++){
        sum += (y[i] - b[i])²;
    }
    return sqrt(sum);
}

/*Aquesta funcio calcula el producte d'una matriu per un vector*/
//REVISAR I AFEGIR LES CONSIDERACIONS DE M
void prodMatVec (int n, int m, double **A, double *b){
    int i, j;
    
    for(i = 0; i < n; i++){
        resultat[i] = 0;
    }
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            resultat[i] += A[i][j] * b[j];
        }
    }
    return 1;
}
