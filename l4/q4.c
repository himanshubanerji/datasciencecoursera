#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>
#define MCW MPI_COMM_WORLD
void ErrorHandler(int err_code){
    if (err_code != MPI_SUCCESS){
        char error_string[BUFSIZ];
        int length_err_string, err_class;
        MPI_Error_class(err_code, &err_class);
        MPI_Error_string(err_code, error_string, &length_err_string);
        fprintf(stderr, "Error: %d %s\n", err_class, error_string);
    }
}
int main(int argc, char *argv[]){
    int rank, size, err_code;
    int mat[4][4], fmat[4][4];
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MCW, MPI_ERRORS_RETURN);
    err_code = MPI_Comm_rank(MCW, &rank);
    err_code = MPI_Comm_size(MCW, &size);
    if (rank == 0)
        ErrorHandler(err_code);
    if (rank == 0){
        printf("Enter the elements in 4x4 matrix:\n");
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++)
                scanf("%d", &mat[i][j]);
        }
    }
    int mmat[4], smat[4];
    err_code = MPI_Scatter(mat, 4, MPI_INT, mmat, 4, MPI_INT, 0, MCW);
    err_code = MPI_Scan(mmat, smat, 4, MPI_INT, MPI_SUM, MCW);
    err_code = MPI_Gather(smat, 4, MPI_INT, fmat, 4, MPI_INT, 0, MCW);
    if (rank == 0){
        ErrorHandler(err_code);
        printf("The final result is : \n");
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++)
                printf("%d ", fmat[i][j]);
            printf("\n");
        }
    }
    MPI_Finalize();
    exit(0);
}
