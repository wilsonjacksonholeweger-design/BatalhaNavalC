#include <stdio.h>

int main(){

    int tabuleiro[10][10];   // matriz do tabuleiro
    int tamanhoNavio = 3;    // cada navio ocupa 3 posições
    int agua = 0;            // representa água
    int navio = 3;           // representa parte de um navio

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = agua;
        }
    }

    // Coordenadas iniciais dos navios
    // Navio 1: horizontal
    int linhaH = 2;
    int colunaH = 4;

    // Navio 2: vertical
    int linhaV = 5;
    int colunaV = 1;


    // Posiciona o navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = navio;
    }

    // Posiciona o navio vertical
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = navio;
    }

    // Exibe o tabuleiro na tela
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = água | 3 = navio\n");

    return 0;
}