#include <stdio.h>
  2 #include "mpi.h"
  3 
  4 int main(int argc, char ** argv)
  5 {
  6         int rang, nbprocs;
  7         MPI_Status status;
  8         MPI_Init(&argc, &argv);
  9         MPI_Comm_rank(MPI_COMM_WORLD,&rang);
 10         MPI_Comm_size(MPI_COMM_WORLD,&nbprocs);
 11         double *A,*X,lA;
 12         int SIZE = 16;
 13 
 14         int i,j;
 15 
 16         if(rang ==0)
 17         {
 18                 MPI_Type_contignous(sizeof(double)*SIZE,MPI_DOUBLE, &type_line_    A); //Mat A
 19                 MPI_Type_commit(&type_line_A);
 20 
 21                 A = (double *) malloc(SIZE * SIZE * sizeof(double)); // allocat    ion d'un grand vecteur contenant toutes les lignes de la matrice pour avoir un     mémoire continue
 22 
 23                 for(i=0; i<SIZE*SIZE; i++){
 24                         A[i][j] = i*SIZE+j;
 25                 }
 26 
 27                 MPI_Scatter(A,1,type_line, A, SIZE*SIZE, MPI_DOUBLE,0, MPIS_COM    M_WOLRD); //Distribution des lignes de A
 28 
 29                 MPI_Type_contignous(sizeof(double)*SIZE,MPI_DOUBLE, &type_line_    X); //Vect X
 30                 MPI_TYPE_commit(&type_line_X);
 31                 X = (double*)malloc(SIZE * sizeof(double));
 32                 for(i=0;i<SIZE;i++){
 33                         X[i] = i*SIZE + i*i;
 34                 }
 35 
 36                 MPI_Bcast(type_line_X, SIZE, MPI_DOUBLE,0,MPI_COMM_WOLRD); //Di    ffusion du vecteur X
 37         }
 38 
 39         //Diffusion du vecteur X
 40 
 41         //Distribution des lignes de A
 42         lA = (double *) malloc(SIZE * SIZE * sizeof(double));
 43         MPI_Scatter(A,SIZE,MPI_DOUBLE,lA,SIZE, MPI_DOUBLE,
 45         //Calcul des composants de Y
 46 
 47         //Fusion des composants de Y
 48 
 49         if(rang ==0){
 50 
 51                 //Affichage de Y
 52         }
 53 
 54 
 55 
 56 
 57         MPI_Finalize();
 58         return EXIT_SUCCESS;
 59 }

