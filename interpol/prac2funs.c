/* COGNOM1: ROIGÉ  COGNOM2: FOIX  NOM: LAURA  DNI: 47873311F */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Aquesta funcio avalua una funcio en un valor donat (en aquest cas sinus) */
double f(double x){
    return sin(x);
}

/* Aquesta funcio calcula l'aproximacio d'una integral per trapezis */
double trapezis (int N, double a, double b){
    double tn, fa, fb, h;
    int i;
    
    fa = f(a);
    fb = f(b);
    h = (b - a) / N;
    tn = fa;
    
    for (i = 0; i < N; i++){
        tn = tn + f(a + i*h);
    }
    
    tn = h * (0.5 * fa + tn + 0.5 * fb);
    
    return tn;
}
