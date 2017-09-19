/*  Calcul d'una successio en precisio simple  fixats a , b , x0  */

#include <stdio.h>
#include <math.h>

int main ( void ) {
	int n, k ;
	float a, b, x0, y0, x1, y1, t, aux0, aux1 ;
    
    /*Llegim les dades de teclat (nomes a, b, x0)*/
        k = scanf ("%f %f %f" ,&a ,&b ,&x0);
        aux0 = x0 / a;
        if ( fabs ( aux0 ) > 1.){
            printf (" No es pot fer l’arrel quadrada \n" );
            return 1;
        }
    
    /* Per indicar que s'acaba l'entrada posem a = 0
     */
    while (a != 0){ 
        
        aux0 = x0 / a;
        y0 = b * sqrt (1.f - aux0 * aux0);
        
        aux1 = y0 / b ;
        printf ("%3s %18s\n", "#n", "t");
        /* Notem que ha fet servir %3s, s es per string i 3 es per reservar
        * l'espai de linia. Fent-ho aixi es mes facil alinear amb els index
        * mes tard.
        */
        
        t = aux0 * aux0 + aux1 * aux1;
        printf ("%3d %18.6e\n", 0, t);
        /* Aqui fem servir %18.6, on 18 es l'espai reservat de linia i 6 el 
        * nombre de decimals que volem (notem que abans per la t hem reservat
        * 18 espais de linies).
        */
        
        for (n = 1; n <= 30; n++) {
            aux0 = x0 / a;
            aux1 = y0 / b;
            
            x1 = 2.f * x0 * y0 / b ;
            y1 = b * (aux0 * aux0 - aux1 * aux1);
            
            aux0 = x1 / a ;
            aux1 = y1 / b ;
            t = aux0 * aux0 + aux1 * aux1 ;
            printf ("%3d %18.6e\n", n, t);
            
            x0 = x1 ;
            y0 = y1 ;
        }
        
        /*Llegim les dades per la seguent execucio*/
        k = scanf ("%f %f %f" ,&a ,&b ,&x0);
        aux0 = x0 / a;
        if (a == 0){continue;}
        else if ( fabs ( aux0 ) > 1.){
            printf (" No es pot fer l’arrel quadrada \n" );
            return 1;
        }
    }
	
	return 0;
}
