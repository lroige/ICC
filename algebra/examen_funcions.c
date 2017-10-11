#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int reset_matrix(int n, double **A); /*posa la matriu a zero*/
int print_matrix(int n, double **A); /*imprimeix una matriu*/
int print_vector(int n, double *b); /*imprimeix un vector*/
int multmatrius(int n, double **A, double **B, double **C); /*multiplica A i B  i ho guarda a C*/
int resoltrisup(int n, double **A, double *b, double tol); /*resol una matriu superior A sobre el vector b*/
int resoltriinf(int n, double **A, double *b, double tol);
int mult_vector_matrix(int n, double** A, double* b, double* resultat); /*multiplica un vector b*A matriu*/
int mult_matrix_vector(int n, double** A, double* b, double* resultat); /* multiplica una matriu A*b vector*/
int gauss_i_vector(int n, double **A, double *b, double tol); /*aplica gauss a matriu i vector*/
int gauss(int n, double **A, double tol); /*fa L U a  una matriu*/
int AtoLU (int n, double** A, double** L, double** U); /*transforma una matriu A ja transformada en dues L i U*/
int palu (int n, double** A, double *p, double tol);
int canvi_files(int n, double **A, int k, int maxvalor);
int palu_vector (int n, double** A, double *p, double *b, double tol);
int transposar_matriu(int n, double** A);

/***********************/
/* compilacio
   gcc -c examen.c -Wall -O
   gcc examen.o -o examen.exe -lm
   ./examen.exe

   gcc provafile.c -o 1.x -Wall -lm
*/




int main(void){
 return 1;
}

/*********************/
/* tolerancia
   double tol;
   tol = 1.e-12;
*/

/************************/
/* create_vector_zero
   int n = 3;
   double *b;
   b = (double*)malloc(n*sizeof(double));
   int counter;
   for (counter = 0; counter < n; counter++){
    b[counter] = 0;
  }
*/

/************************/
/* open file
    FILE *in, *out;
    in = fopen("document d'entrada", "r");
    out = fopen("document de sortida", "a");
    if(in==NULL){
		printf("Error entrada\n");
		exit(1);
	}
	if(out == NULL){
        printf("error de sortida\n");
        exit(1);
	}
*/

/************************/
/* introduir matriu des de document
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			fscanf(in,"%lf",&A[i][j]);
		}
	}
*/

/************************/
/* guardar matriu a document
    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fprintf(out,"%lf ",A[i][j]);
		}
		fprintf(out,"\n");
	}
*/

/************************/
/* tancar documents
    fclose(in);
	fclose(out);
*/

/************************/
/* create_vector_random
   int n = 3;
   double *b;
   b = (double*)malloc(n*sizeof(double));
   int counter;
   for (counter = 0; counter < n; counter++){
    b[counter] = 10*(double)rand()/(double)RAND_MAX;
  }
*/


/***********************/
/* create_perm_vector
  int n = 3;
   double *b;
   b = (double*)malloc(n*sizeof(double));
   int counter;
   for (counter = 0; counter < n; counter++){
    b[counter] = counter;
  }
*/

/************************/
/* create_vector_fill-in
   int n = 3;
   double *b;
   b = (double*)malloc(n*sizeof(double));
   int counter;
   for (counter = 0; counter < n; counter++){
     printf("Introduir l'element de la fila %d\n", counter+1);
     scanf("%le", &b[counter]);
   }
*/


/************************/
/*create_matrix_zero
  int n = 3;
  double **A;
  A = (double**)malloc(n*sizeof(double*));
  int counter;
  for (counter = 0; counter < n; counter++){
    A[counter]= (double*)malloc(n*sizeof(double));
  }
  int a;
  int b;
  for (a = 0; a < n; a++){
    for (b = 0; b< n; b++){
	A[a][b]= 0;
    }
  }
*/


/************************/
/* create_matrix_random
  int n = 3;
  int counter = 0;
  double **A;
  A = (double**)malloc(n*sizeof(double*));
  for (counter = 0; counter < n; counter++){
    A[counter]= (double*)malloc(n*sizeof(double));
  }
  int a = 0;
  int b= 0;
  for (a = 0; a < n; a++){
    for (b = 0; b< n; b++){
	A[a][b]= 10*(double)rand()/(double)RAND_MAX;
    }
  }
*/




/***********************triangular inferior amb diagonal i la resta d'uns*/
/* create_matrix_L
  int n = 3;
  int counter = 0;
  double **A;
  A = (double**)malloc(n*sizeof(double*));
  for (counter = 0; counter < n; counter++){
    A[counter]= (double*)malloc(n*sizeof(double));
  }
  int a = 0;
  int b= 0;
  for (a = 0; a < n; a++){
    for (b = 0; b< n; b++){
      if(a==b){
	A[a][b] = 1;
      }
      if(a > b){
	A[a][b] = 10*(double)rand()/(double)RAND_MAX;
      }
    }
  }
*/


/***********************triangular superior amb la resta d'uns*/
/* create_matrix_U
  int n = 3;
  int counter = 0;
  double **A;
  A = (double**)malloc(n*sizeof(double*));
  for (counter = 0; counter < n; counter++){
    A[counter]= (double*)malloc(n*sizeof(double));
  }
  int a = 0;
  int b= 0;
  for (a = 0; a < n; a++){
    for (b = 0; b< n; b++){
      if(a<=b){
	A[a][b]= 10*(double)rand()/(double)RAND_MAX;
      }
    }
  }
*/



/*Crear matriu i omplir-la per pantalla*/
/* create_matrix_fill-in
  int n = 3;
  int counter = 0;
  double **A;
  A = (double**)malloc(n*sizeof(double*));
  for (counter = 0; counter < n; counter++){
    A[counter]= (double*)malloc(n*sizeof(double));
  }
  int a = 0;
  int b= 0;
  for (a = 0; a < n; a++){
    for (b = 0; b< n; b++){
      printf("Introduir l'element de la fila %d, columna %d:\n", i+1, j+1);
      scanf("%le", &matriu[a][b]);
    }
  }
*/


/*Alliberar matriu*/
/* free_matrix
   int p;
   for(p = 0; p < n; p++){
     free(A[p]);
   }
   free(A);
*/


/*Alliberar vector*/
/* free_vector
   free(c);
*/


/*Demanar dimensio*/
/* demanar_dimensio
   int dimensio;
   printf("Entra el valor de la dimensio");
   scanf("%d", &dimensio);
*/

/*Aquesta funcio posa una matriu a zero*/
int reset_matrix(int n, double **A){
    int a = 0;
    int b= 0;
    
    for (a = 0; a < n; a++){
        for (b = 0; b< n; b++){
            A[a][b] = 0;
        }
    }
    return 1;
}

/*Aquesta funcio imprimeix una matriu quadrada de dim n*/
int print_matrix(int n, double **A){/*funciona*/
    int a;
    int b;
    for(a = 0; a<n; a++){
        for (b = 0; b<n; b++){
            printf("%f    ", A[a][b]);
        }
        printf("\n");
    }
    printf("\n");
    return 1;
}

/*Aquesta funcio imprimeix un vector b de dim n */
int print_vector(int n, double *b){/*funciona*/
    int a;
    
    for(a = 0; a < n; a++){
        printf("%f    ", b[a]);
    }
    printf("\n");
    return 1;
}

/*Aquesta funcio calcula el producte de dues matrius */
int multmatrius(int n, double **A, double **B, double **C){/*funciona*/
    int i = 0;
    int j = 0;
    int k = 0;
    double suma = 0;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            suma = 0;
            for(k = 0; k < n; k++){
                suma += A[i][k] * B[k][j];
            }
        C[i][j] = suma;
        }
    }
    return 1;
}


/*Aquesta funcio resol un sistema en una matriu triangular superior I IMPRIMEIX EL RESULTAT*/
int resoltrisup(int n, double **A, double *b, double tol){/*funciona*/
    int i = 0;
    int continuar = 1;
    
    for (i = 0; i < n; i++){
        if (abs(A[i][i]) < tol){
            continuar = 0;
            i = n;
        }
    }
    
    if (continuar == 1) {
        int j;
        for (j = n-1; j>= 0; j-- ){
            b[j]= b[j]/A[j][j];
            for (i = 0; i < j; i++){
                b[i]= b[i]- b[j]*A[i][j];
            }
        }
        int counter = 0;
        for (counter = 0; counter < n; counter++){
            printf("%f\n", b[counter]);
        }
    }
    return 1;
}

/*Aquesta funcio resol un sistema en una matriu triangular inferior I IMPRIMEIX EL RESULTAT*/
int resoltriinf(int n, double **A, double *b, double tol){/*per mirar*/
    int i = 0;
    int continuar = 1;
    
    for (i = 0; i <n; i++){
        if (abs(A[i][i]) < tol){
            continuar = 0;
            i = n;
        }
    }
    
    if (continuar == 1) {
        int j;
        for (j = n-1; j>= 0; j-- ){
            b[j]= b[j]/A[j][j];
            for (i = 0; i < j; i++){
                b[i]= b[i]- b[j]*A[i][j];
            }
        }
        int counter = 0;
        for (counter = 0; counter < n; counter++){
            printf("%f\n", b[counter]);
        }
    }
    return 1;
}


/*Aquesta funcio calcula el producte d'un vector per una matriu */
int mult_vector_matrix(int n, double** A, double* b, double *resultat){/*funciona*/
    int i;
    int j;
    for(i = 0; i < n; i++){
        resultat[i] = 0;
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            resultat[i] += A[j][i] * b[j];
        }
    }
    return 1;
}

/*Aquesta funcio calcula el producte d'una matriu per un vector*/
int mult_matrix_vector(int n, double** A, double* b, double *resultat){/*funciona*/
    int i;
    int j;
    
    for(i = 0; i < n; i++){
        resultat[i] = 0;
    }
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            resultat[i] += A[i][j] * b[j];
        }
    }
    return 1;
}

/* Aquesta funcio calcula gauss d'una matriu amb el vector de coeficients */
int gauss_i_vector(int n, double **A, double *b, double tol){/*funciona*/
    int i, j, k;
    double mult;

    for(i = 0; i < n; i++){

    }
    
    for(k = 0; k < n - 1; k++){
        if (fabs(A[k][k]) <  tol){
            printf("Hi ha un zero a la diagonal\n");
            exit(1);
        }
        
        for(i=k+1;i<n;i++){
            mult = A[i][k]/A[k][k];
            A[i][k] = mult;

            for(j=k+1;j<n;j++){
                A[i][j] = A[i][j] - mult*A[k][j];
            }
            b[i] = b[i] - mult*b[k];
        }
    }
    return 0;
}


/*Aquesta funcio calcula gauss d'una matriu */
int gauss(int n, double **A, double tol){/*funciona*/
    int i, j, k;
    double mult;

    for(k=0;k<n-1;k++){
        if (fabs(A[k][k]) <  tol){
            printf("Hi ha un zero a la diagonal\n");
            exit(1);
        }
    
        for(i=k+1;i<n;i++){
            mult = A[i][k]/A[k][k];
            A[i][k] = mult;

            for(j=k+1;j<n;j++){
                A[i][j] = A[i][j] - mult*A[k][j];
            }
        }
    }
    return 0;
}

/*Aquesta funcio fa la factoritzacio A=LU d'una matriu (sense pivotatge) */
int AtoLU (int n, double** A, double** L, double** U){/*funciona*/
    int i;
    int j;
    
    for (i = 0; i < n; i++){
    
        for (j = 0; j < n; j++){
            if (i < j){
                U[i][j] = A[i][j];
                L[i][j] = 0;
            } else if(i == j){
                U[i][j] = A[i][j];
                L[i][j] = 1;
            } else {
                U[i][j] = 0;
                L[i][j] = A[i][j];
            }
        }
    }
    return 1;
}

/* Aquesta funcio fa la factoritzacio palu amb pivotatge */
int palu (int n, double** A, double *p, double tol){
    int i, j, k, aux;
    double mult;
    int resultat = 1;
    int maxvalor;
    
    for(k=0;k<n-1;k++){
        maxvalor = k;
        
        for(i = k+1; i<n; i++){
            if(fabs(A[i][k]) > fabs(A[maxvalor][k])){
                maxvalor = i;
            }
        }
        
        if(fabs(A[maxvalor][k]) < tol){
            printf("Problemes\n");
            return 0;
        }
        
        if(k != maxvalor){
            resultat *= -1;
            aux = p[k];
            p[k] = p[maxvalor];
            p[maxvalor] = aux;
            canvi_files(n, A, k, maxvalor);
    
        }
        
        for(i=k+1;i<n;i++){
            mult = A[i][k]/A[k][k];
            A[i][k] = mult;
    
            for(j=k+1;j<n;j++){
                A[i][j] = A[i][j] - mult*A[k][j];
            }
            
        }
        
    }
    
    return resultat;
}

/*Aquesta funcio canvia dues files d'una matriu (k i maxvalor) */
int canvi_files(int n, double **A, int k, int maxvalor){
   double *b;
   b = (double*)malloc(n*sizeof(double));
   int i = 0;
   for(i = 0; i < n; i++){
      b[i] = A[k][i];
   }
   for(i = 0; i < n; i++){
      A[k][i] = A[maxvalor][i];
   }
   for(i = 0; i < n; i++){
      A[maxvalor][i] = b[i];
   }
}

/*Aquesta funcio fa la factoritzacio palu amb pivotatge amb un vector(?) */
int palu_vector (int n, double** A, double *p, double *b, double tol){
    int i, j, k, aux;
    double mult;
    int maxvalor;

    for(k=0;k<n-1;k++){
        maxvalor = k;
        
    for(i = k+1; i<n; i++){
        if(fabs(A[i][k]) > fabs(A[maxvalor][k])){
            maxvalor = i;
        }
    }
    
    if(fabs(A[maxvalor][k]) < tol){
        printf("Problemes\n");
        exit(1);
    }
    
    if(k != maxvalor){
        aux = p[k];
        p[k] = p[maxvalor];
        p[maxvalor] = aux;
        canvi_files(n, A, k, maxvalor);
        aux = b[k];
        b[k] = b[maxvalor];
        b[maxvalor] = aux;
    }
    
    for(i=k+1;i<n;i++){
        mult = A[i][k]/A[k][k];
        A[i][k] = mult;

        for(j=k+1;j<n;j++){
            A[i][j] = A[i][j] - mult*A[k][j];
        }
            b[i] = b[i] - mult*b[k];

        }
    }
    
    return 1;
}

/*Aquesta funcio transposa una matriu*/
int transposar_matriu(int n, double** A){
    double aux;
    int i, j;
    for(i = 0; i<n; i++){
        for(j = 0; j < n; j++){
            if(i > j){
                aux = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = aux;
            }
        }
    }
}

