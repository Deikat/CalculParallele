#include <stdio.h>
  2 #include <stdlib.h>
  3 #include <string.h>
  4 #include "mpi.h"
  5 
  6 int main(int argc, char **argv)
  7 {
  8         int rang, nbprocs, dest=0, source, etiquette = 50;
  9         MPI_Status statut;
 10         char message[500];
 11         char message_actuel[500];
 12         MPI_Init( &argc, &argv );
 13         MPI_Comm_rank( MPI_COMM_WORLD, &rang );
 14         MPI_Comm_size( MPI_COMM_WORLD, &nbprocs );
 15         if ( rang != 0 ) {
 16              if(rang != nbprocs-1){
 17                      MPI_Recv(message, 500, MPI_CHAR,rang+1, etiquette, MPI_COMM_WORLD, &stat    ut);
 18                      sprintf(message_actuel,"");
 19              }
 20              if(rang == 1){
 21                      sprintf(message_actuel," P%d",rang);
 22              }else
 23                      sprintf(message_actuel,", P%d",rang);
 24              strcat(message_actuel,message);
 25              MPI_Send( message_actuel, strlen(message_actuel)+1, MPI_CHAR,rang-1, etiquette,     MPI_COMM_WORLD );
 26         }
 27         else
 28         {
 29 //                    MPI_Recv( message, 100, MPI_CHAR, source, etiquette, MPI_COMM_WORLD, &s    tatut );
 30               MPI_Recv( message, 500, MPI_CHAR, 1,etiquette, MPI_COMM_WORLD, &statut);
 31               printf( "Bonjour de la part de %s", message,rang );
 32         }
 33                 MPI_Finalize();
 34         return EXIT_SUCCESS ;
 35 }

