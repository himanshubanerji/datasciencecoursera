#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    int rank, size, err_code;
    int mat[4][4], fmat[4][4];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank == 0){
        printf("Enter the elements in 4x4 matrix:\n");
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                scanf("%d",&mat[i][j]);
        }
        printf("Matrix: \n");
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }
    }
    int mmat[4],smat[4];
    MPI_Scatter(mat, 4, MPI_INT, mmat, 4, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scan(mmat, smat, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Gather(smat, 4, MPI_INT, fmat, 4, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0){
        printf("Output Matrix: \n");
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++)
                printf("%d ", fmat[i][j]);
            printf("\n");
        }
    }
    MPI_Finalize();
    exit(0);
}
