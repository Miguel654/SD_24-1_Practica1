#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double* wcTime){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (tp.tv_sec + tp.tv_usec / 1000000.0);
}

int main(int argc, char* argv[]){
    int i, j, k, n=10000;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;
    printf("==============={ Practica01 }=================\n");
    printf("===============[%i]===========================\n",n);
    //Inicializando matrices
    matrizA = (int **)malloc(n*sizeof(int *));
    matrizB = (int **)malloc(n*sizeof(int *));
    matrizC = (int **)malloc(n*sizeof(int *));

    for(i = 0; i < n; i++){
        *(matrizA + i) = (int *)malloc(n*sizeof(int));
        *(matrizB + i) = (int *)malloc(n*sizeof(int));
        *(matrizC + i) = (int *)malloc(n*sizeof(int));
        
    }

    //Llenando matrices
    get_walltime(&S1);
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
        }
    }
    get_walltime(&E1);
    
    printf("Llenado de Matrices: %lf s\n", (E1-S1));

    //1.- Metodo IJK
    get_walltime(&S1);

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            for(k = 0; k < n; ++k){
                matrizC[i][j] += matrizA[i][k] + matrizB[k][j];
            }
        }
    }

    get_walltime(&E1);
    
    printf("Tiempo metodo ijk: %lf s\n", (E1-S1));
    //printf("Tiempo metodo ijk: %lf s\n Inicio: %lf s\n Final: %lf s\n", (E1-S1), S1, E1);

    //2.- Metodo IKJ
    get_walltime(&S1);

    for(i = 0; i < n; ++i){
        for(k = 0; k < n; ++k){
            for(j = 0; j < n; ++j){
                matrizC[i][j] += matrizA[i][k] + matrizB[k][j];
            }
        }
    }

    get_walltime(&E1);
    
    printf("Tiempo metodo ikj: %lf s\n", (E1-S1));
    //printf("Tiempo metodo ijk: %lf s\n Inicio: %lf s\n Final: %lf s\n", (E1-S1), S1, E1);

    //3.- Metodo KIJ
    get_walltime(&S1);

    for(k = 0; k < n; ++k){
        for(i = 0; i < n; ++i){
            for(j = 0; j < n; ++j){
                matrizC[i][j] += matrizA[i][k] + matrizB[k][j];
            }
        }
    }

    get_walltime(&E1);
    
    printf("Tiempo metodo kij: %lf s\n", (E1-S1));
    //printf("Tiempo metodo ijk: %lf s\n Inicio: %lf s\n Final: %lf s\n", (E1-S1), S1, E1);

    //4.- Metodo JKI
    get_walltime(&S1);

    for(j = 0; j < n; ++j){
        for(k = 0; k < n; ++k){
            for(i = 0; i < n; ++i){
                matrizC[i][j] += matrizA[i][k] + matrizB[k][j];
            }
        }
    }

    get_walltime(&E1);
    
    printf("Tiempo metodo jki: %lf s\n", (E1-S1));
    //printf("Tiempo metodo ijk: %lf s\n Inicio: %lf s\n Final: %lf s\n", (E1-S1), S1, E1);

    //5.- Metodo KJI
    get_walltime(&S1);

    for(k = 0; k < n; ++k){
        for(j = 0; j < n; ++j){
            for(i = 0; i < n; ++i){
                matrizC[i][j] += matrizA[i][k] + matrizB[k][j];
            }
        }
    }

    get_walltime(&E1);
    
    printf("Tiempo metodo kji: %lf s\n", (E1-S1));
    //printf("Tiempo metodo ijk: %lf s\n Inicio: %lf s\n Final: %lf s\n", (E1-S1), S1, E1);

    //6.- Metodo jik
    get_walltime(&S1);

    for(j = 0; j < n; ++j){
        for(i = 0; i < n; ++i){
            for(k = 0; k < n; ++k){
                matrizC[i][j] += matrizA[i][k] + matrizB[k][j];
            }
        }
    }

    get_walltime(&E1);
    
    printf("Tiempo metodo jik: %lf s\n", (E1-S1));
    //printf("Tiempo metodo ijk: %lf s\n Inicio: %lf s\n Final: %lf s\n", (E1-S1), S1, E1);


    return 0;
}
