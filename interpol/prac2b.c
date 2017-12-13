/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "prac2funs.h"

//posar n = 20, per exemple

int main(){
    double a, b, c, tol;
    int nmax, m, i, sol;
    
    printf("Introduir els limits de l'interval [a, b]:\n");
    scanf("%le %le", &a, &b);
    printf("Introduir el nombre maxim de solucions a calcular:\n");
    scanf("%d", &m);
    printf("Introduir l'ordenada c on F(x) = c:\n");
    scanf("%le", &c);
    
    printf("Introduir el nombre de subdivisions de l'interval [%le, %le]:\n", a, b);
    scanf("%d", &nmax);
    
    tol = 1.e-12;
    sol = 0; /* Solucions que hom trobat fins ara */
    
    while (i < nmax && sol < m){
        
    }
    

    return 0;
}


double F (double x){
    x = pow(x, 3) - 3 * pow(x, 2) + x + 1;
    return x;
}

double dF (double x){
    x = 3 * pow(x, 2) - 6 * x + 1;
    return x;
}
