#!/bin/bash
  2 
  3 # submit.sh fichier pour l'execution de hello_mpi
  4 # Options de sbatch
  5 #SBATCH --partition=part-etud # partition pour tps etudiants
  6 #SBATCH --ntasks=8
  7 # 8 tasks / processus
  8 #SBATCH --cpus-per-task=1
  9 # de 1 thread
 10 #SBATCH --job-name=testMPI
 11 #SBATCH --nodelist=node27,node29
 12 # Execution du programme
 13 .mpiexec /hello

