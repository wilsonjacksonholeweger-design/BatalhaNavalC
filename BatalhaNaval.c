#include <stdio.h>

#define TAM 10
#define TAM_HAB 5           // Tamanho da Habilidade
#define NAVIO 3             // representa parte de um navio
#define TAM_NAVIO 3         // cada navio ocupa 3 posições
#define AGUA 0              // representa água
#define HABILIDADE 5        //representa a área afetdada pela habilidade


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


     // MATRIZES DE HABILIDADE
    
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // CONE (em forma de triângulo)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB/2 - i && j <= TAM_HAB/2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // CRUZ (linha e coluna centrais)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB/2 || j == TAM_HAB/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // OCTAEDRO (losango)
for (int i = 0; i < TAM_HAB; i++) {
    for (int j = 0; j < TAM_HAB; j++) {
        octaedro[i][j] = 0;
    }
}

// Cria o formato do losango manualmente
for (int i = 0; i < TAM_HAB; i++) {
    for (int j = 0; j < TAM_HAB; j++) {

        // distância vertical até o centro
        int dist = i <= TAM_HAB/2 ? i : (TAM_HAB - 1 - i);

        // define a área do losango
        if (j >= (TAM_HAB/2 - dist) && j <= (TAM_HAB/2 + dist)) {
            octaedro[i][j] = 1;
        }
    }
}

  
    // APLICAR HABILIDADES NO TABULEIRO
  
    int origemConeLinha = 1, origemConeColuna = 7;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaLinha = 7, origemOctaColuna = 3;

    // Função para sobrepor matriz de habilidade
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origemConeLinha + i - TAM_HAB/2;
            int colunaTab = origemConeColuna + j - TAM_HAB/2;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (cone[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == AGUA)
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
            }
        }
    }

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origemCruzLinha + i - TAM_HAB/2;
            int colunaTab = origemCruzColuna + j - TAM_HAB/2;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (cruz[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == AGUA)
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
            }
        }
    }

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origemOctaLinha + i - TAM_HAB/2;
            int colunaTab = origemOctaColuna + j - TAM_HAB/2;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == AGUA)
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
            }
        }
    }

    // Exibe o tabuleiro na tela
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: %d = água | %d = navio | %d = habilidade\n", AGUA, NAVIO, HABILIDADE);

    return 0;
}