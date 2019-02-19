  1 #include <stdio.h>
  2 #include <time.h>
  3 #include <stdlib.h>
  4 #include "mpi.h"
  5 
  6 #define NBLIGNES 2
  7 #define NBCOLS 3
  8 
  9 void DisplayMat(char * nom, double * Y, int nblignes, int nbcols){
 10         int i,j;
 11         printf("---- matrice %s ----\n",nom);
 12         for(i=0; i<nblignes;i++){
 13                 for(j=0;j<nbcols;j++){
 14                         printf("%3f ", Y[i*nbcols+j]);
 15                 }
 16                 printf("\n");
 17         }
 18 }
 19 
 20 void InitMat(double * Y, int taille){
 21         int i,j;
 22         srand(time(NULL));
 23 
 24         for(i=0; i<taille; i++){
 25                 Y[i] = rand()%10;
 26         }
 27 }
 28 
 29 void ProdMat(double * result, int rang, int nbcol, double * lignes, double * vect){
 30         /*int i;
 31         for(i=rang * NBCOLS+1; i<*/
 32 }
 33 
 34 int main(int argc, char ** argv){
 35         int rang, nbProcs, nbCol;
 36         double * A, *col, * X, * lignes, * res;
 37 
 38         MPI_Init(&argc,&argv);
 39         MPI_Comm_rank(MPI_COMM_WORLD,& rang);
 40         MPI_Comm_size(MPI_COMM_WORLD, &nbProcs);
 41 
 42         printf("nb proc %d\n",nbProcs);
 43         nbCol = NBCOLS / nbProcs;
 44         lignes = (double*) malloc(nbCol * NBLIGNES * sizeof(double));
 45         res = (double *) malloc(NBCOLS * NBLIGNES * sizeof(double));
 46 
 47         if(rang == 0){
 48                 // Init matrice A et vecteur X
 49                 A = (double *) malloc(NBCOLS * NBLIGNES * sizeof(double));
"prodMat.c" 107L, 2817C                                                                      43,2-9       Haut
