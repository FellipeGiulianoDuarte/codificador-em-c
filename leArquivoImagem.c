#include "mylib.h"
/*
 * Lê nomeImagem como argumento da main e retorna ponteiro de ponteiro.
 */
int **leArquivoImagem(char *nomeImagem, char *tipo, int *lin, int *col) {
    FILE *arq = fopen(nomeImagem, "r");
    if (arq == NULL) {
        printf("\nErro ao abrir arquivo - leArquivoImagem.\n");
        return NULL;
    }

    char buffer[2048];
    while (fgets(buffer, sizeof(buffer), arq) != NULL) {

        sscanf(buffer, "%s", tipo);
        printf("%s\n", tipo);

        while (fgets(buffer, sizeof(buffer), arq) != NULL) {
            if (buffer[0] != '#') {
                sscanf(buffer, "%d %d", col, lin);
                printf("%d %d\n", *lin, *col);
                break;
            }
        }

        int **mat = alocaMatrizImagem(*lin, *col);
        if (mat == NULL) {
            printf("\nErro ao alocar mat imagem - leArquivoImagem.\n");
            fclose(arq);
            return NULL;
        }

        int count = 0;
        for (int i = 0; i < *lin; i++) {
            fgets(buffer, sizeof(buffer), arq);
            char *ptr = buffer;
            for (int j = 0; j < *col; j++) {
                while (*ptr == ' ') ptr++;
                if (*ptr == '\n' || *ptr == '\0') {
                    j--;
                    continue;
                }
                mat[i][j] = strtol(ptr, &ptr, 10);
            }
        }

        fclose(arq);
        return mat;
    }

    fclose(arq);
    return NULL;
}





