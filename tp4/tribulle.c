#include <stdio.h>
  2 #include <stdlib.h>
  3 /*#include "mpi.h"*/
  4 #include <time.h>
  5
  6 #define SIZE 10
  7
  8 int * CreateRandomTab(){
  9         static int tab[SIZE];
 10         int i;
 11         srand(time(NULL));
 12
 13         for(i=0; i<SIZE; i++){
 14                 tab[i] = rand()%101;
 15         }
 16         return tab;
 17 }
 18
 19 int CheckOrder(int * tab){
 20         int i=0;
 21         int result = 1;
 22         while(i+1<SIZE){
 23                 if(tab[i]>tab[i+1]){
 24                         result = 0;
 25                 }
 26                 i++;
 27         }
 28         return result;
 29 }
 30
 31 void DisplayTab(int * tab){
 32         int i;
 33         printf("\n---- TABLEAU -----\n");
 34         for(i=0; i<SIZE; i++){
 35                 printf("%3d ",tab[i]);
 36         }
 37         printf("\n");
 38 }
 39
 40 int main(int argc, char ** argv){
 41         /*int * tab;
 42         tab = CreateRandomTab();
 43         DisplayTab(tab);
 44         printf("Trie ? %d\n",CheckOrder(tab));*/
 45
 46         int rang, nbprocs;
 47         int * tab, * local_tab;
 48         MPI_Comm_rank(MPI_COMM_WORLD, &rang);
 49         MPI_Comm_size(MPI_COMM_WORLD, &nbprocs);
 50
 51         tab = CreateRandomTab();
 52         local_tab = (int *) malloc(
 53
 54         MPI_Scatter(local_tab
 55
 56
 57
 58
 59         return EXIT_SUCCESS;
 60
 61 }

