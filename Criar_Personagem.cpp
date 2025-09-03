#include <stdio.h>
#include <stdlib.h>  // Para system("cls")
#include <conio.c>   // Para getch(), textcolor(), textbackground()
#include <windows.h> // Para a função gotoxy() e configuração da janela

#include "bibliotecas/personagens.c"

// --- FUNÇÕES AUXILIARES DE INTERFACE ---

void gotoxy(int x, int y);
void configurarJanela();
const char* obterNomeCor(int cor);

// =======================================================================
// === SEU CÓDIGO DE DESENHO DO PERSONAGEM INTEGRADO ABAIXO ===
// =======================================================================

#ifndef PERSONAGENS_C
#define PERSONAGENS_C

int inicioX = 72; // Posição X inicial para o desenho na tela
int inicioY = 5;  // Posição Y inicial para o desenho na tela (ajustado)

// Função auxiliar do seu código para desenhar com cor
void print_color(int x, int y, int color, const char *text) {
    textbackground(color);
    gotoxy(inicioX + x, inicioY + y);
    printf("%s", text);
}

#endif

// =======================================================================
// === PAINEL DE CRIAÇÃO (CONTROLADOR) ===
// =======================================================================

void painelDeCriacao() {
    int genero = -1;
    int opcao = 0;

    // 1. TELA DE SELEÇÃO DE GÊNERO
    while (genero == -1) {
        system("cls");
        textcolor(15);
        gotoxy(45, 10); printf("SELECIONE O GENERO DO PERSONAGEM");
        gotoxy(45, 11); printf("---------------------------------");
        gotoxy(50, 13); printf("1. Masculino");
        gotoxy(50, 14); printf("2. Feminino");
        gotoxy(45, 16); printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            genero = 0;
        } else if (opcao == 2) {
            genero = 1;
        } else {
            gotoxy(45, 18); textcolor(12);
            printf("Opcao invalida! Pressione qualquer tecla para tentar novamente.");
            getch();
        }
    }

    // 2. TELA DE CUSTOMIZAÇÃO
    const char *partes_masculino[] = {"Pele", "Olho", "Cabelo", "Camiseta", "Manga", "Shorts", "Sapato"};
    const char *partes_feminino[] = {"Pele", "Olho", "Cabelo", "Camiseta", "Manga", "Shorts", "Sapato", "Boca"};
    int num_partes = (genero == 0) ? 7 : 8;

    int cores_masculino[] = {6, 9, 14, 14, 10, 1, 8	};
    int cores_feminino[] = {6, 9, 14, 14, 10, 1, 8, 13};

    int opcao_parte = 0;

    // DESENHO INICIAL E ESTÁTICO DA TELA
    system("cls");
    
    gotoxy(8, 15); textcolor(15); printf("--- PALETA DE CORES (0-15) ---");
    for(int i = 0; i < 8; i++) {
        gotoxy(4, 17+i); textcolor(i); printf("%2d: %-13s", i, obterNomeCor(i));
        gotoxy(26, 17+i); textcolor(i+8); printf("%2d: %-13s", i+8, obterNomeCor(i+8));
    }

    while (opcao_parte != num_partes + 1) {
        // --- PAINEL DE OPÇÕES (ESQUERDA) - Redesenhado a cada loop
        gotoxy(5, 2); textcolor(15); printf("PAINEL DE CRIACAO DE PERSONAGEM");
        gotoxy(5, 3); printf("---------------------------------");
        for (int i = 0; i < num_partes; i++) {
            gotoxy(5, 5 + i);
            int cor_atual = (genero == 0) ? cores_masculino[i] : cores_feminino[i];
            textcolor(7);
            printf("%d. %-10s:", i + 1, (genero == 0) ? partes_masculino[i] : partes_feminino[i]);
            textcolor(cor_atual);
            printf(" %s          ", obterNomeCor(cor_atual));
        }
        textcolor(10);
        gotoxy(5, 5 + num_partes); printf("%d. Finalizar e Salvar", num_partes + 1);

        // --- VISUALIZAÇÃO DO PERSONAGEM (DIREITA) ---
        if (genero == 0) {
            personagem_masculino(cores_masculino[0], cores_masculino[1], cores_masculino[2], cores_masculino[3], cores_masculino[4], cores_masculino[5], cores_masculino[6]);
        } else {
            personagem_feminino(cores_feminino[0], cores_feminino[1], cores_feminino[2], cores_feminino[3], cores_feminino[4], cores_feminino[5], cores_feminino[6], cores_feminino[7]);
        }

        // --- INPUT DO USUÁRIO ---
        textcolor(15);
        gotoxy(5, 27); printf("Escolha uma opcao para alterar: ");
        scanf("%d", &opcao_parte);

        if (opcao_parte > 0 && opcao_parte <= num_partes) {
            int nova_cor = -1;	
            gotoxy(5, 28); printf("Digite o novo codigo da cor (0-15): ");
            scanf("%d", &nova_cor);

            if (nova_cor >= 0 && nova_cor <= 15) {
                if (genero == 0) {
                    cores_masculino[opcao_parte - 1] = nova_cor;
                } else {
                    cores_feminino[opcao_parte - 1] = nova_cor;
                }
                 gotoxy(5, 26); printf("                                                         "); // Limpa linha
            } else {
                gotoxy(5, 27); textcolor(12);
                printf("Codigo de cor invalido! Pressione qualquer tecla para continuar.");
                getch();
                gotoxy(5, 27); printf("                                                                 ");
            }
        } else if (opcao_parte != num_partes + 1) {
             gotoxy(5, 26); textcolor(12);
             printf("Opcao invalida! Pressione qualquer tecla para continuar.");
             getch();
             gotoxy(5, 26); printf("                                                                 ");
        }
    }

    // 3. FINALIZAÇÃO
    system("cls");
    gotoxy(48, 14); textcolor(10);
    printf("Personagem criado com sucesso!");
    gotoxy(45, 16); textcolor(7);
    printf("Pressione qualquer tecla para iniciar o jogo...");
    getch();
}

// --- FUNÇÃO PRINCIPAL PARA INICIAR O PROGRAMA ---
int main() {
	window(1, 1, 120, 30);
    configurarJanela();
    painelDeCriacao();
    return 0;
}

void configurarJanela() {
    system("mode con: cols=120 lines=30");
    system("title Criacao de Personagem");
}

const char* obterNomeCor(int cor) {
    const char* nomes[] = {
        "Preto", "Azul", "Verde", "Ciano", "Vermelho", "Magenta", "Marrom", "Cinza Claro",
        "Cinza Escuro", "Azul Claro", "Verde Claro", "Ciano Claro", "Vermelho Claro",
        "Magenta Claro", "Amarelo", "Branco"
    };
    if (cor >= 0 && cor <= 15) {
        return nomes[cor];
    }
    return "Invalido";
}
