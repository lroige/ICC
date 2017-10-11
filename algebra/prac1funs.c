#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void resTinf (int n, double **L, double *x, double *b);
void resTsup (int n, double **U, double *x, double *b);

int main(){
    int n, i, j, sum;
    double **L, *b, *x, *y;

    printf("Introdueix la dimensio de la matriu: ");
    scanf("%d", &n);

    
    /*Inicialitzem matriu L i vectors b i x*/
    
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
        if (L[i][i] != 1.){
            print("L'element %d de la diagonal no es 1!");
            return 1;
        }
    }
    
    b = (double*)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++){
        printf("Introduir l'element %d del vector:\n", i+1);
        scanf("%le", &b[i]);
    }

    resTinf(n, L, x, b);
    
    prodMatVec(n, n, L, x, y);
    
    sum = 0
    for (i = 0; i < n; i++){
        sum += (y[i] - b[i]);
    }
    
    /*Imprimim el vector solucio i la norma |Lx-b|2*/
    printf("El vector solucio es:\n");
    for(i = 0; i < n; i++){
        printf("%f    ", x[i]);
    }
    printf("\n");
    
    printf("La norma |Lx - b|2 es: %le", norma);

    /*Alliberar matriu*/
    for(i = 0; i < n; i++){
        free(L[i]);
    }
    free(L);
    free(b);
    free(x);
    
    return 0;
}

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
