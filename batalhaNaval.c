#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa a matriz do tabuleiro com 0 (representa água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho fixo dos navios
    int tamanhoNavio = 3;

    // Coordenadas para o navio horizontal
    int linhaH = 2;
    int colunaH = 4;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + tamanhoNavio <= 10) {
        // Preenche a matriz com o valor 3 para representar o navio
        for (j = 0; j < tamanhoNavio; j++) {
            tabuleiro[linhaH][colunaH + j] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora do limite do tabuleiro.\n");
        return 1;
    }

    // Coordenadas para o navio vertical
    int linhaV = 5;
    int colunaV = 6;

    // Verifica se o navio vertical cabe no tabuleiro e não se sobrepõe
    int sobreposicao = 0;
    if (linhaV + tamanhoNavio <= 10) {
        for (i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
            }
        }

        if (sobreposicao == 0) {
            for (i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Erro: navio vertical sobreposto com outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical fora do limite do tabuleiro.\n");
        return 1;
    }

    // Exibe a matriz (tabuleiro)
    printf("\nTabuleiro final:\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}