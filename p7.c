#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
    int rank, data = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        data = 100; // Root process sets the data
    }

    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD); // Broadcast data to all

    printf("Process %d received data: %d\n", rank, data);

    MPI_Finalize();
    return 0;
}

/*sinchana@sinchana-VirtualBox:~/Desktop/parallel computing$ mpicc p7.c -o p7
sinchana@sinchana-VirtualBox:~/Desktop/parallel computing$ mpirun -np 4 ./p7
Process 0 received data: 100
Process 1 received data: 100
Process 2 received data: 100
Process 3 received data: 100
*/
