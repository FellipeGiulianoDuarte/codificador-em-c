#include "mylib.h"
/*
 * desaloca em i linhas, todos os elementos alocados, depois desaloca mat
 */
void desalocaMatrizImagem(int **matriz, int lin) {
    for (int i = 0; i < lin; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

/*
 * Função para alocar memória para uma matriz com um determinado número de linhas (int lin) e colunas (int col).
 * Lembre-se de desalocar a memória alocada quando não for mais necessária.
 */
int **alocaMatrizImagem(int lin, int col) {
    int **matriz = (int **)malloc(lin * sizeof(int *));
    if (matriz == NULL) {
        printf("Memória insuficiente.\n");
        exit(EXIT_FAILURE); // ou trate o erro adequadamente
    }

    for (int i = 0; i < lin; i++) {
        matriz[i] = (int *)malloc(col * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Memória insuficiente.\n");
            exit(EXIT_FAILURE); // ou trate o erro adequadamente
        }
    }

    return matriz;
}