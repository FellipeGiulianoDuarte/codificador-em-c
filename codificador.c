#include "mylib.h"

/*
 * Função recursiva para codificar uma imagem binária com base em um sistema de codificação específico,
 * dividindo a imagem em sub-imagens e atribuindo códigos de acordo com a presença de pixels de cores
 * diferentes ou não.
 */
void codificarImagem(int **imagem, int linhaInicial, int linhaFinal, int colunaInicial, int colunaFinal)
{
    // Verifica se as coordenadas de entrada são válidas
    if (linhaInicial > linhaFinal || colunaInicial > colunaFinal)
    {
        return; // Retorna se as coordenadas forem inválidas
    }

    // Verifica se é um único pixel e imprime 'P' se for preto (1) e 'B' se for branco (0)
    if (linhaInicial == linhaFinal && colunaInicial == colunaFinal)
    {
        if (imagem[linhaInicial][colunaInicial] == 1)
        {
            printf("P");
        }
        else
        {
            printf("B");
        }
        return;
    }

    // Verifica se a região é homogênea e imprime 'P' se for preto (1) e 'B' se for branco (0)
    int valor = imagem[linhaInicial][colunaInicial];
    int homogenea = 1;
    for (int i = linhaInicial; i <= linhaFinal && homogenea; i++)
    {
        for (int j = colunaInicial; j <= colunaFinal; j++)
        {
            if (imagem[i][j] != valor)
            {
                homogenea = 0;
                break;
            }
        }
    }

    if (homogenea)
    {
        if (valor == 1)
        {
            printf("P");
        }
        else
        {
            printf("B");
        }
        return;
    }
    else // Se a região não é homogênea, divide-a em sub-regiões e chama a função recursivamente
    {
        printf("X");                                        // Marca o início de uma região não homogênea
        int linhaMeio = (linhaInicial + linhaFinal) / 2;    // Encontra a coordenada da linha do meio
        int colunaMeio = (colunaInicial + colunaFinal) / 2; // Encontra a coordenada da coluna do meio
        // Chama a função para as quatro sub-regiões
        codificarImagem(imagem, linhaInicial, linhaMeio, colunaInicial, colunaMeio);
        codificarImagem(imagem, linhaInicial, linhaMeio, colunaMeio + 1, colunaFinal);
        codificarImagem(imagem, linhaMeio + 1, linhaFinal, colunaInicial, colunaMeio);
        codificarImagem(imagem, linhaMeio + 1, linhaFinal, colunaMeio + 1, colunaFinal);
    }
}