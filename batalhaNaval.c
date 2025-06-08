#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    // Declaração do tabuleiro e inicialização com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios
    int linha_navio_horizontal = 2;  // Linha onde o navio horizontal começa
    int coluna_navio_horizontal = 4; // Coluna onde ele começa (vai até +2 colunas)

    int linha_navio_vertical = 5;    // Linha onde o navio vertical começa (vai até +2 linhas)
    int coluna_navio_vertical = 1;   // Coluna onde o navio vertical está fixo

    // Validação para garantir que os navios não saem do tabuleiro
    if (coluna_navio_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linha_navio_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Validação para garantir que os navios não se sobrepõem
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (linha_navio_horizontal == linha_navio_vertical + i &&
                coluna_navio_horizontal + i == coluna_navio_vertical) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = NAVIO;
            }

            // Posiciona o navio vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = NAVIO;
            }

            // Exibe o tabuleiro
            printf("Tabuleiro com navios posicionados:\n");
            for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
                for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Erro: Os navios se sobrepõem!\n");
        }

    } else {
        printf("Erro: As coordenadas dos navios excedem os limites do tabuleiro.\n");
    }

    return 0;
}
