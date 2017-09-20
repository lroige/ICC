/* Calcul del producte escalar de dos vectors usant memòria dinàmica'*/
#include <stdio.h>

int main (void){
    int n , i;
    float *x , *y , prod ;
    
    printf ("Doneu la dimensi´o dels vectors , n = \n" );
    scanf ("%d" , &n );
    
    x = (float*) malloc(n*sizeof(float) );
    y = (float*) malloc(n*sizeof(float) );

    if ( x == NULL || y == NULL ){
        printf (" No hi ha prou memoria " );
        return 1;
    }
    
    printf (" Doneu els %d elements del vector x \n" , n );
    
    for (i = 0; i < n; i++){
        scanf ("%f" , &x[i]);
    }
    
    printf (" Doneu els %d elements del vector y \n" , n );
    
    for (i = 0; i < n; i++){
        scanf ("%f" , &y[i]);
    }
    
    prod = prod_esc(n, x, y);
    
    printf (" El producte escalar val : %16.7e \n" , prod );
    
    free(x);
    free(y);
    
    return 0;
}
