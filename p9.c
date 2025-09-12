#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
    int rank, size;
    int value, sum, max;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    value = rank + 1; // Each process has a value

    // Reduce: sum values at root (rank 0)
    MPI_Reduce(&value, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Sum using Reduce: %d\n", sum);
    }

    // Allreduce: find maximum across all processes
    MPI_Allreduce(&value, &max, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
    printf("Max using Allreduce (rank %d): %d\n", rank, max);

    MPI_Finalize();
    return 0;
}


/*
sinchana@sinchana-VirtualBox:~/Desktop/parallel computing$ gedit p9.c
sinchana@sinchana-VirtualBox:~/Desktop/parallel computing$ mpicc p9.c -o p9
sinchana@sinchana-VirtualBox:~/Desktop/parallel computing$ mpirun -np 4 ./p9
Sum using Reduce: 10
Max using Allreduce (rank 0): 4
Max using Allreduce (rank 2): 4
Max using Allreduce (rank 3): 4
Max using Allreduce (rank 1): 4
*/
