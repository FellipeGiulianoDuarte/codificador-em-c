#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=============== Constantes =======================
#define MAX_NAME 50 // número máximo de caracteres usado para nome do proprietario da imagem
#define MAX_LEN 1024
#define MAX_HT 768

//=== Protótipos das operações sobre as imagens ===
int **alocaMatrizImagem(int lin, int col);
void desalocaMatrizImagem(int **mat, int lin);

int **leArquivoImagem(char *nomeImagem, char *tipo, int *lin, int *col);

void codificarImagem(int **imagem, int linhaInicial, int linhaFinal, int colunaInicial, int colunaFinal);

#endif