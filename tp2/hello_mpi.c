#include <stdio.h>
  2 #include <stdlib.h>
  3 #include <sched.h>
  4 #include "mpi.h"
  5 
  6 int main(int argc, char **argv)
  7 {
  8 
  9           int rang=-1, nbprocs=0;
 10           char processor_name[MPI_MAX_PROCESSOR_NAME];
 11           int namelen;
 12           int cpu_id;
 13 
 14           MPI_Init( &argc, &argv );
 15           MPI_Comm_rank( MPI_COMM_WORLD, &rang );
 16           MPI_Comm_size( MPI_COMM_WORLD, &nbprocs );
 17           MPI_Get_processor_name(processor_name,& namelen);
 18           cpu_id=sched_getcpu();
 19 
 20           printf( " Hello from process %d of %d\n ",
 21                      rang, nbprocs);
 22 
 23           MPI_Finalize();
 24           return EXIT_SUCCESS;
 25 }

