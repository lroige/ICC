/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "prac2funs.h"

//posar n = 20, per exemple

int main(){
    double a, c, tol, aj, prev, g, h, sols, x;
    int sol, itmax, err;
    
    printf("Introduir l'ordenada c on F(x) = c:\n");
    scanf("%le", &c);
    
    tol = 1.e-12;
    itmax = 20;
    sol = 0; /* Solucions que hom trobat fins ara */
    h = 1;
    a = 0;
    aj = a + h;
    prev = F(a) - c;
    
    if (prev == 0){
        sols = prev;
        sol++;
    }
    
    while (!sol){
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
                sols = x;
                sol++;
            }
        }
        
        /* Fem la seguent iteracio */
        prev = g;
        a = aj;
        aj = aj + h;
    }
    
    printf("La solucio trobada es x = %le\n", sols);

    return 0;
}


/* Aquesta funcio avalua una funcio en un valor donat (en aquest cas sinus) */
double f(double x){
    return pow(sin(x), 2);
}

double F (double x){
    double tol, tn, prev;
    int nmax, n;
    
    tol = 1.e-8;
    n = 4;
    nmax = pow(2, 30);
    
    tn = trapezis(2, -x, x);
    prev = x;
    
    while (n <= nmax && fabs(tn - prev) >= tol){
        prev = tn;
        tn = trapezis(n, -x, x);
        n = n * 2;
    }
    
    if (n > nmax){
        printf("La integral no s'ha pogut calcular amb prou precisio.\n");
        exit(0);
    }
    
    return tn;
}

double dF (double x){
    return f(x) + f(-x);
}
