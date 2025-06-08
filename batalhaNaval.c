#include <stdio.h>

#define TAM 10
#define TAM_HABIL 7
#define ORIGEM 3  // Centro da matriz 7x7

#define AGUA 0
#define NAVIO 3
#define AREA_HABILIDADE 5

// Inicializa o tabuleiro com água
void inicializar_tabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;
}

// Imprime o tabuleiro com representação clara
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n   ");
    for (int i = 0; i < TAM; i++)
        printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf(" . ");
            else if (tabuleiro[i][j] == NAVIO)
                printf(" N ");
            else if (tabuleiro[i][j] == AREA_HABILIDADE)
                printf(" * ");
            else
                printf(" ? ");
        }
        printf("\n");
    }
}

// Cria a matriz de habilidade Cone (forma triangular)
void criar_matriz_cone(int habilidade[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (i >= ORIGEM && j >= ORIGEM - (i - ORIGEM) && j <= ORIGEM + (i - ORIGEM))
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria a matriz de habilidade Cruz
void criar_matriz_cruz(int habilidade[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (i == ORIGEM || j == ORIGEM)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria a matriz de habilidade Octaedro (losango)
void criar_matriz_octaedro(int habilidade[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (abs(i - ORIGEM) + abs(j - ORIGEM) <= 3)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Aplica a matriz de habilidade no tabuleiro na coordenada (linha, coluna)
void aplicar_habilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABIL][TAM_HABIL], int linha, int coluna) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            int linha_tab = linha + (i - ORIGEM);
            int coluna_tab = coluna + (j - ORIGEM);
            // Verifica se está dentro dos limites
            if (linha_tab >= 0 && linha_tab < TAM && coluna_tab >= 0 && coluna_tab < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] == AGUA) {
                    tabuleiro[linha_tab][coluna_tab] = AREA_HABILIDADE;
                }
            }
        }
    }
}

// Posiciona navios no tabuleiro para exemplo
void posicionar_navios_exemplo(int tabuleiro[TAM][TAM]) {
    // Horizontal
    for (int j = 1; j <= 3; j++)
        tabuleiro[2][j] = NAVIO;

    // Vertical
    for (int i = 4; i <= 6; i++)
        tabuleiro[i][7] = NAVIO;

    // Diagonal ↘
    for (int i = 0; i < 3; i++)
        tabuleiro[i][i] = NAVIO;

    // Diagonal ↗
    for (int i = 0; i < 3; i++)
        tabuleiro[6 - i][i + 3] = NAVIO;
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HABIL][TAM_HABIL];
    int cruz[TAM_HABIL][TAM_HABIL];
    int octaedro[TAM_HABIL][TAM_HABIL];

    inicializar_tabuleiro(tabuleiro);
    posicionar_navios_exemplo(tabuleiro);

    // Criação das áreas de efeito
    criar_matriz_cone(cone);
    criar_matriz_cruz(cruz);
    criar_matriz_octaedro(octaedro);

    // Aplicação das habilidades no tabuleiro
    aplicar_habilidade(tabuleiro, cone, 1, 2);       // Exemplo: cone centrado em (1,2)
    aplicar_habilidade(tabuleiro, cruz, 5, 5);       // Cruz centrada em (5,5)
    aplicar_habilidade(tabuleiro, octaedro, 8, 8);   // Octaedro centrado em (8,8)

    exibir_tabuleiro(tabuleiro);

    return 0;
}
