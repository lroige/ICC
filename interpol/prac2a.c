/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "prac2funs.h"

//posar n = 20, per exemple

int main(){
    double a, b, tol, tn, prev;
    int nmax, n;
    
    printf("Introduir els limits de l'interval [a, b]:\n");
    scanf("%le %le", &a, &b);
    printf("Introduir la tolerancia:\n");
    scanf("%le", &tol);
    printf("Introduir el nombre maxim de subdivisions de l'interval [%le, %le]:\n", a, b);
    scanf("%d", &nmax);
    
    n = 4;
    nmax = pow(2, nmax);
    
    tn = trapezis(2, a, b);
    
    do{
        prev = tn;
        tn = trapezis(n, a, b);
        
        n = n * 2;
    } while (n <= nmax || abs(tn - prev) >= tol);
    
    if (n > nmax){
        printf("La integral no s'ha pogut calcular amb prou precisio.\n");
        return 0;
    }
    
    printf("El valor aproximat de la integral es %le\n", tn);

    return 0;
}
