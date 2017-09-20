/* Avaluacio d’un polinomi en m punts equiespaiats a l’interval [a,b]
* usant dos algorismes
*/

#include <stdio.h>
#include <math.h>
double poli (double, double[]);
double horner (double, double[]);

int main (void) {
    int i , m , k;
    double a , b , x , aval1 , aval2 , h;
    double coef[8];

    FILE * entrada ;
    entrada = fopen ("coeficients.dad", "r"); /* (1) */

    if ( entrada == NULL ){
        printf (" Error en obrir el fitxer %s\n" , "coeficients.dad" ); /* (2) */
        return 1;
    }

    for (i = 0; i < 8; i ++){
        k = fscanf ( entrada , "%f" , & coef [i ]);
    }
    fclose ( entrada );

    printf ("# doneu a, b, m = \n" );

    k = scanf (" %f %f %d" , &a , &b , &m );
    h = (b -a )/ m;
    printf ("# %8s %17s %17s %17s\n", "x", "poli", "horner", "diferencia");

    for (i = 0; i <= m; i++){
        x = a + i * h;
        aval1 = poli(x, coef );
        aval2 = horner(x, coef );
        printf (" %15.6e %15.6e %15.6e %15.6e\n" , x , aval1 , aval2 , fabs (aval1 - aval2));
    }

    return 0;
}

double poli (double z, double a[]){
    int i;
    double sum;
    sum = a[0];

    for (i = 1; i <= 7; i++){
        sum = sum +a[i]* pow (z, i);
    }

    return sum;
}

double horner (double z, double a[]){
    int i;
    double sum;
    sum = a[7];

    for (i = 6; i >= 0; i--){
        sum = sum * z + a[i];
    }

    return sum;
}
