#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
    int rank, size;
    int send_data[4] = {10, 20, 30, 40};
    int recv_data;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Scatter values: each process receives one element
    MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received: %d\n", rank, recv_data);

    // Each process modifies its data
    recv_data += 1;

    // Gather back the modified values into root (rank 0)
    MPI_Gather(&recv_data, 1, MPI_INT, send_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Only root prints the gathered result
    if (rank == 0) {
        printf("Gathered data: ");
        for (int i = 0; i < size; i++)
            printf("%d ", send_data[i]);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}


/*
sinchana@sinchana-VirtualBox:~/Desktop/parallel computing$ gedit p8.c
sinchana@sinchana-VirtualBox:~/Desktop/parallel computing$ mpicc p8.c -o p8
sinchana@sinchana-VirtualBox:~/Desktop/parallel computing$ mpirun -np 4 ./p8
Process 1 received: 20
Process 2 received: 30
Process 3 received: 40
Process 0 received: 10
Gathered data: 11 21 31 41 
*/
