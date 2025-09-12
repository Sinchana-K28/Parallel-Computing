//Program 5: Write an MPI program demonstrating MPI_Send and MPI_Recv.
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int number;

    MPI_Init(&argc, &argv); // Initialize the MPI environment
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Get the number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get the rank of the process

    if (size < 2) {
        if (rank == 0) {
            printf("This program requires at least 2 processes.\n");
        }
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        number = 42;
        printf("Process 0 is sending number %d to Process 1\n", number);
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received number %d from Process 0\n", number);
    }

    MPI_Finalize();
    return 0;
}
/*
sudo apt update
sudo apt install libopenmpi-dev openmpi-bin
*/
 //mpicc p5.c -o p5      : to compile
 //mpirun -np 2 ./p5    : to run the program

/*output
Process 0 is sending number 42 to Process 1
Process 1 received number 42 from Process 0
*/
