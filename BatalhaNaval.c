#include <stdio.h>

#define TAM 10
#define NAVIO 3             // representa parte de um navio
#define TAM_NAVIO 3         // cada navio ocupa 3 posições
#define AGUA 0              // representa água

int main(){

    int tabuleiro[TAM][TAM];   // matriz do tabuleiro
               

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios
    // Navio 1: horizontal
    int linhaH = 4;
    int colunaH = 4;

    // Navio 2: vertical
    int linhaV = 5;
    int colunaV = 1;

    // Navios 3 e 4: diagonais
    int linhaD1 = 0, colunaD1 = 0; // diagonal principal (↘)
    int linhaD2 = 6, colunaD2 = 9; // diagonal secundária (↙)


    // Posiciona o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // Posiciona o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }



    // Navio 3: diagonal principal (↘)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] == NAVIO) {
            
        }
        tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
    }

    // Navio 4: diagonal secundária (↙)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] == NAVIO) {
            
        }
        tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
    }

    // Exibe o tabuleiro na tela
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: %d = água | %d = navio\n", AGUA, NAVIO);

    return 0;
}