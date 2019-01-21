#include <stdio.h>
  2 #include <stdlib.h>
  3 #include <string.h>
  4 #include "mpi.h"
  5 
  6 int main(int argc, char **argv)
  7 {
  8         int rang, nbprocs, dest=0, source, etiquette = 50;
  9         MPI_Status statut;
 10         char message[100];
 11         MPI_Init( &argc, &argv );
 12         MPI_Comm_rank( MPI_COMM_WORLD, &rang );
 13         MPI_Comm_size( MPI_COMM_WORLD, &nbprocs );
 14         if ( rang != 0 ) {
 15              sprintf( message, "Bonjour de la part de P%d!\n" , rang
 16         );
 17          MPI_Send( message, strlen(message)+1, MPI_CHAR, dest, etiquette, MPI_COMM_WORLD );
 18 
 19         }
 20         else
 21 
 22         for ( source=1; source<nbprocs; source++ ) {
 23 //            MPI_Recv( message, 100, MPI_CHAR, source, etiquette, MPI_COMM_WORLD, &statut );
 24               MPI_Recv( message, 100, MPI_CHAR, MPI_ANY_SOURCE,etiquette, MPI_COMM_WORLD, &st    atut);
 25             printf( "%s", message );
 26         }
 27         MPI_Finalize();
 28         return EXIT_SUCCESS ;
 29 }

