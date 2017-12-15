/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "prac2funs.h"

/* Aquesta funcio calcula l'aproximacio d'una integral per trapezis */
double trapezis (int N, double a, double b){
    double tn, fa, fb, h;
    int i;
    
    fa = f(a);
    fb = f(b);
    h = (b - a) / N;
    tn = 0;
    
    for (i = 1; i < N; i++){
        tn = tn + f(a + i*h);
    }
    
    tn = h * (0.5 * fa + tn + 0.5 * fb);
    
    return tn;
}

int Newton (double *x, double tol, int itmax, double c){
    int i;
    double prev, f, df;
    
    i = 0;
    
    do {
        prev = *x;
        
        f = F(*x);
        df = dF(*x);
        
        *x = prev - (f - c) / df;
    } while (i < itmax && fabs(*x - prev) > tol && fabs(f - c) > tol);
    if (i > itmax){
        return 1;
    }
    return 0;
}
