/*
 ________  ___  ___  ________  ________  _________  _______
|\   ___ \|\  \|\  \|\   __  \|\   __  \|\___   ___\\  ___ \
\ \  \_|\ \ \  \\\  \ \  \|\  \ \  \|\  \|___ \  \_\ \   __/|
 \ \  \ \\ \ \  \\\  \ \   __  \ \   _  _\   \ \  \ \ \  \_|/__
  \ \  \_\\ \ \  \\\  \ \  \ \  \ \  \\  \|   \ \  \ \ \  \_|\ \
   \ \_______\ \_______\ \__\ \__\ \__\\ _\    \ \__\ \ \_______\
    \|_______|\|_______|\|__|\|__|\|__|\|__|    \|__|  \|_______|
*/

#include "mylib.h"

int main(int argc, char *argv[])
{
    if (argc == 1 || (argc == 2 && (strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "--help") == 0)))
    {
        printf("Uso: ImageEncoder [-? | -m | -f ARQ]\n");
        printf("Codifica imagens binárias dadas em arquivos PBM ou por dados informados manualmente.\n");
        printf("Argumentos:\n");
        printf("-?, --help  : apresenta essa orientação na tela.\n");
        printf("-m, --manual: ativa o modo de entrada manual, em que o usuário fornece todos os dados da imagem informando-os através do teclado.\n");
        printf("-f, --file: considera a imagem representada no arquivo PBM (Portable bitmap).\n");
        return 0;
    }

    if (argc >= 2)
    {
        if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "--manual") == 0)
        {
            int lin, col;
            do
            {
                printf("Digite o número de linhas e colunas:\n");
                scanf("%d %d", &lin, &col);
                if (lin >= MAX_HT || col >= MAX_LEN)
                {
                    printf("tamanho máximo de dimensão: %dx%d.\n", MAX_LEN, MAX_HT);
                }
            } while (lin >= MAX_HT || col >= MAX_LEN);

            // Aloca a matriz de imagem manualmente
            int **matImagem = alocaMatrizImagem(lin, col);

            // Preencha a matriz de imagem com os valores digitados manualmente
            for (int i = 0; i < lin; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    scanf("%d", &matImagem[i][j]);
                }
            }

            codificarImagem(matImagem, 0, lin - 1, 0, col - 1);

            // Libere a memória alocada para a matriz da imagem
            desalocaMatrizImagem(matImagem, lin);

            return 0;
        }
        else if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--file") == 0)
        {
            char *nomeImagem = argv[2], tipo[2];
            int lin, col, **matImagem;
            matImagem = leArquivoImagem(nomeImagem, tipo, &lin, &col);

            codificarImagem(matImagem, 0, lin - 1, 0, col - 1);

            desalocaMatrizImagem(matImagem, lin);
        }
        else
        {
            printf("Opção inválida.\n");
            return 1;
        }
    }

    return 0;
}