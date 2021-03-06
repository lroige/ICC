/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "prac2funs.h"

//posar n = 20, per exemple

int main(){
    double a, b, c, tol, aj, prev, g, h, *sols, x;
    int nmax, m, j, sol, itmax, err;
    
    printf("Introduir els limits de l'interval [a, b]:\n");
    scanf("%le %le", &a, &b);
    printf("Introduir el nombre maxim de solucions a calcular:\n");
    scanf("%d", &m);
    printf("Introduir l'ordenada c on F(x) = c:\n");
    scanf("%le", &c);
    
    printf("Introduir el nombre de subdivisions de l'interval [%le, %le]:\n", a, b);
    scanf("%d", &nmax);
    
    sols = (double*) malloc(m * sizeof(double));
    
    tol = 1.e-12;
    itmax = 20;
    sol = 0; /* Solucions que hom trobat fins ara */
    m++;
    h = (b - a) / nmax;
    aj = a + h;
    prev = F(a) - c;
    
    if (prev == 0){
        sols[sol] = prev;
        sol++;
    }
    
    while (aj < b && sol < m){
        g = F(aj) - c;
        
        /* Comprovem si hi ha una solucio a l'interval */
        if (prev * g < 0){
            /* Calculem la solucio */
            x = 0.5 * (a + aj);
            err = Newton (&x, tol, itmax, c);
            if(err){
                printf("No s'ha pogut trobar la solucio amb prou precisio.\n");
                return 1;
            } else {
                sols[sol] = x;
                sol++;
            }
        }
        
        /* Fem la seguent iteracio */
        prev = g;
        a = aj;
        aj = aj + h;
    }
    
    printf("Les solucions trobades son: \n");
    
    for (j = 0; j < sol; j++){
        printf("%le\n", sols[j]);
    }
    
    free(sols);

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

double f(double x){
    return x;
}
