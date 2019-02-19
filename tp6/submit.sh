#!/bin/bash
 
#SBATCH --account=tp-etud
#SBATCH --partition=part-etud
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH job-name=testProdMat
 
mpiexec ./exe
