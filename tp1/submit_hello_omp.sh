#!/bin/bash

# submit_hello_omp.sh fichier pour l'execution de hello avec sbatch

# Options de sbatch
#SBATCH --account=tp-etud
#SBATCH --partition=part-etud	# partition pour tps etudiants
#SBATCH --ntasks=1				# 1 task / processus
#SBATCH --cpus-per-task=8		# de 8 threads
#SBATCH job-name=testOpenMP

# Execution du programme
./prodMatriciel_dynamic_seq
