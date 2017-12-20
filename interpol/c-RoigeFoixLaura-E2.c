/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "prac2funs.h"


int main(){
    double c, tol, tol1, prev, x, pi, tn;
    int itmax, err, n, nmax;
    
    /* c = 332/1000, el meu NIUB es 16648332 */
    c = 332. / 1000;
    pi = 3.14159265358979323846;
    x = 1.;
    tol = 1.e-11;
    tol1 = 1.e-8;
    itmax = 10;
    n = 4;
    nmax = pow(2, 30);
    
    printf("c = %le\n", c);
    
    err = Newton (&x, tol, itmax, c);
    if(err){
        printf("No s'ha pogut trobar la solucio amb prou precisio.\n");
        return 1;
    }
    
    printf("x1 = %le\n", x);
    
    tn = trapezis(2, x, pi);
    prev = pi;
    
    while (n < nmax && fabs(tn - prev) >= tol1){
        prev = tn;
        tn = trapezis(n, x, pi);
        
        n = n * 2;
    }
    
    if (n >= nmax){
        printf("La integral no s'ha pogut calcular amb prou precisio.\n");
        return 0;
    }
    printf("n = %d\n", n);
    printf("El valor aproximat de la integral es %le\n", tn);

    return 0;
}


/* Aquesta funcio avalua una funcio en un valor donat (en aquest cas sinus) */
double f(double x){
    return -cos(x) - cos(2 * x);
}

double F (double x){
    return -cos(x) - cos(2 * x);
}

double dF (double x){
    return sin(x) + 2 * sin(2 * x);
}
