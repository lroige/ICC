/* Calcul del producte d’una matriu per un vector usant memoria dinamica*/
#include <stdio.h>
#include <stdlib.h>

int main (void){
	int n, m, p, i, j;
	double **a, **b, **c;
	
    /*Demanem les dimensions de les matrius i les inicialitzem*/
	printf("Doneu les dimensions de la matriu A, (n, m) = \n");
	scanf("%d %d", &n, &m);
	
    printf("Doneu les dimensions de la matriu B, (%d, p) = \n", m);
	scanf("%d", &p);
    
	a = (double **) malloc(n*sizeof(double*));
	
	if (a == NULL){
		printf("No hi ha prou memoria");
		return 1;
	}

	for (i = 0; i < n; i++){
		a[i] = (double *) malloc(m*sizeof(double));
		if (a[i] == NULL){
			printf("No hi ha prou memoria");
			return 2;
		}
	}
	
	b = (double **) malloc(m*sizeof(double*));
	
	if (b == NULL){
		printf("No hi ha prou memoria");
		return 1;
	}

	for (i = 0; i < m; i++){
		b[i] = (double *) malloc(p*sizeof(double));
		if (b[i] == NULL){
			printf("No hi ha prou memoria");
			return 2;
		}
	}
	
	c = (double **) malloc(n*sizeof(double*));
	
	if (c == NULL){
		printf("No hi ha prou memoria");
		return 1;
	}

	for (i = 0; i < n; i++){
		c[i] = (double *) malloc(p*sizeof(double));
		if (c[i] == NULL){
			printf("No hi ha prou memoria");
			return 2;
		}
	}
	
	/*inicialitzem C a zero*/
    for (i = 0; i < n; i++){
        for (j = 0; j < p; j++){
            c[i][j]= 0.;
        }
    }
	
	/*Demanem les dades de les matrius i les omplim*/
	printf("Doneu els (%d x %d) elements de la matriu A \n", n, m);
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			scanf ("%le", &a[i][j]);
		}
	}

	printf("Doneu els (%d x %d) elements de la matriu B \n", m, p);
	for (i = 0; i < m; i++){
		for (j = 0; j < p; j++){
			scanf ("%le", &b[i][j]);
		}
	}
	
	/*Fem el producte de les matrius*/
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			v[i] += a[i][j] * u[j];
		}
	}

	/*Imprimim el resultat*/
	printf("El producte de la matriu A = \n");

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			printf(" %16.7e ", a[i][j]);
		}
		printf("\n");
	}

	printf ("per la matriu B = \n");

	for (i = 0; i < m; i++){
		for (j = 0; j < p; j++){
			printf(" %16.7e ", b[i][j]);
		}
		printf("\n");
	}
	
	printf ("ens dona C = \n");
	
	for (i = 0; i < n; i++){
		for (j = 0; j < p; j++){
			printf(" %16.7e ", c[i][j]);
		}
		printf("\n");
	}

	/*Alliberem memoria*/
	for (i = 0; i < n; i++){
		free(a[i]);
	}
	
	for (i = 0; i < m; i++){
        free(b[i]);
    }

	free(a);
    free(b);
	free(u);
	free(v);
	
	return 0;
}
