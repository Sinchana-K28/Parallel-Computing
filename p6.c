#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, data_send, data_recv;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0)
            printf("This program requires at least 2 processes.\n");
        MPI_Finalize();
        return 0;
    }

    data_send = rank;

    if (rank == 0) {
        MPI_Send(&data_send, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&data_recv, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received %d\n", rank, data_recv);
    }
    else if (rank == 1) {
        MPI_Recv(&data_recv, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&data_send, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process %d received %d\n", rank, data_recv);
    }

    MPI_Finalize();
    return 0;
}

/*mpicc p6.c -o p6 :to compile
mpirun -np 2 ./p6  : to run
*/

/*output
Process 0 received 1
Process 1 received 0
*/ 
