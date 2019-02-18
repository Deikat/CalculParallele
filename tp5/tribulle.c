#include <stdio.h>
  2 #include <stdlib.h>
  3 #include <string.h>
  4 #include <mpi.h>
  5 
  6 #define SIZE 10
  7 
  8 
  9 void CreateRandomTab(int * tab, int nbProcs){
 10          int i;
 11          srand(time(NULL));
 12 
 13          for(i=0; i<nbProcs; i++){
 14                  tab[i] = rand()%101;
 15          }
 16 }
 17 
 18 void DisplayTab(int * tab, int nbProcs){
 19          int i;
 20          printf("\n---- TABLEAU -----\n");
 21          for(i=0; i<nbProcs; i++){
 22                  printf("%3d ",tab[i]);
 23          }
 24          printf("\n");
 25 }
 26 
 27 int main(int argc, char  ** argv){
 28         int rang = -1, nbProcs = 10;
 29         int tag1 = 50, tag2 = 150;
 30         int val = -1, recvVal = -1;
 31         int k = 0;
 32         MPI_Status status;
 33 
 34         int * tab = NULL;
 35         MPI_Init(&argc, &argv);
 36         MPI_Comm_rank(MPI_COMM_WORLD, &rang);
 37         MPI_Comm_size(MPI_COMM_WORLD, &nbProcs);
 38 
 39         if(!rang){
 40                 tab = (int *) malloc(nbProcs * sizeof(int));
 41 
 42                 /*if(!tab){
 43                         fprintf(stderr, "Erreur, rang :%d",rang);
 44                         MPI_Abort(MPI_COMM_WORLD,1);
 45                 }*/     
 46                 CreateRandomTab(tab,nbProcs);
 47                 DisplayTab(tab, nbProcs);
 48         }
 50         MPI_Scatter(&tab[0],1,MPI_INT, &val, 1, MPI_INT, 0, MPI_COMM_WORLD);
 51 
 52         for(k=0;k<=nbProcs/2;k++){
 53                 if(rang % 2 ==0){
 54 
 55                         MPI_Send(&val,1,MPI_INT,rang + 1,tag1 + k,MPI_COMM_WORLD);
 56                         MPI_Recv(&recvVal, 1, MPI_INT, rang +1, tag2 + k, MPI_COMM_WORLD, &status);
 57                         if(val< recvVal) val = recvVal;
 58                 }else{
 59                         if(rang % 2){
 60                                 if(rang + 1 != nbProcs){
 61                                         MPI_Send(&val, 1, MPI_INT, rang + 1, tag1 + k, MPI_COMM_WORLD);
 62                                         MPI_Recv(&recvVal, 1, MPI_INT, rang +1, tag2 + k, MPI_COMM_WORLD, &status);
 63                                         if(recvVal < val) val = recvVal;
 64                                 }
 65                         }else{
 66                                 if(rang != 0){
 67                                         MPI_Recv(&recvVal, 1, MPI_INT, rang - 1, tag1 + k, MPI_COMM_WORLD, &status);
 68                                         MPI_Send(&val, 1, MPI_INT, rang - 1 , tag2 + k, MPI_COMM_WORLD);
 69                                         if(recvVal > val) val = recvVal;
 70                                 }
 71                         }
 72                 }
 73         }
 74         MPI_Gather(&val, 1, MPI_INT, tab, 1, MPI_INT, 0, MPI_COMM_WORLD);
 75         if(!rang){
 76                 DisplayTab(tab,nbProcs);
 77                 free(tab);
 78         }
 79         MPI_Finalize();
 80         return EXIT_SUCCESS;
 81 }
