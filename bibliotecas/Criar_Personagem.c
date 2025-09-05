#ifndef CRIACAO_PERSONAGEM
#define CRIACAO_PERSONAGEM

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

void create_person(int *genero, int cores_personagem[]) {
	int i;
    *genero = -1;
    
    gotoxy(70, 5);
    printf("%s", name);

    // 1. TELA DE SELEÇÃO DE GÊNERO
    while (*genero == -1) {
        system("cls");
        textcolor(15);
        gotoxy(45, 10); printf("SELECIONE O GENERO DO PERSONAGEM");
        gotoxy(45, 11); printf("---------------------------------");
        gotoxy(50, 13); printf("1. Masculino");
        gotoxy(50, 14); printf("2. Feminino");
        gotoxy(45, 16); printf("Digite sua opcao: ");
        scanf("%d", genero);

        if (*genero == 1) {
            *genero = 0;
        } else if (*genero == 2) {
            *genero = 1;
        } else {
            gotoxy(45, 19); textcolor(12);
            printf("Opcao invalida! Pressione qualquer tecla para tentar novamente.");
            *genero = -1;
            getch();
        }
    }

    // 2. TELA DE CUSTOMIZAÇÃO
    const char *partes_masculino[] = {"Pele", "Olho", "Cabelo", "Camiseta", "Manga", "Shorts", "Sapato"};
    const char *partes_feminino[] = {"Pele", "Olho", "Cabelo", "Camiseta", "Manga", "Shorts", "Sapato"};
    int num_partes = (*genero == 0) ? 7 : 7;

    int cores_masculino[] = {6, 9, 14, 14, 10, 1, 8	};
    int cores_feminino[] = {6, 9, 14, 14, 10, 1, 8 };

    int opcao_parte = 0;

    while (opcao_parte != num_partes + 1) {
    	system("cls");
    	
    	gotoxy(55, 15); textcolor(15); printf("---- PALETA DE CORES (0-15) ----");
	    for(i = 0; i < 8; i++) {
	        gotoxy(54, 17+i); textcolor(i);
			if (i == 0){
            	textcolor(8);
			}
			printf("%2d: %-13s", i, obterNomeCor(i));
	        gotoxy(70, 17+i); textcolor(i+8); printf("%2d: %-13s", i+8, obterNomeCor(i+8));
	    }
    	
        // --- PAINEL DE OPÇÕES (ESQUERDA) - Redesenhado a cada loop
        gotoxy(55, 2); textcolor(15); printf("PAINEL DE CRIACAO DE PERSONAGEM");
        gotoxy(55, 3); printf("---------------------------------");
        for (i = 0; i < num_partes; i++) {
            gotoxy(55, 5 + i);
            int cor_atual = (*genero == 0) ? cores_masculino[i] : cores_feminino[i];
            textcolor(7);
            printf("%d. %-10s:  ", i + 1, (*genero == 0) ? partes_masculino[i] : partes_feminino[i]);
            textcolor(cor_atual);
			if (cor_atual == 0){
            	textcolor(8);
			}
            printf(" %s          ", obterNomeCor(cor_atual));
        }
        textcolor(10);
        gotoxy(55, 5 + num_partes); printf("%d. Finalizar e Salvar", num_partes + 1);

        // --- VISUALIZAÇÃO DO PERSONAGEM (DIREITA) ---
        if (*genero == 0) {
            personagem_masculino(cores_masculino[0], cores_masculino[1], cores_masculino[2], cores_masculino[3], cores_masculino[4], cores_masculino[5], cores_masculino[6]);
        } else {
            personagem_feminino(cores_feminino[0], cores_feminino[1], cores_feminino[2], cores_feminino[3], cores_feminino[4], cores_feminino[5], cores_feminino[6]);
        }

        // --- INPUT DO USUÁRIO ---
        textcolor(15);
        gotoxy(55, 27); printf("Escolha uma opcao para alterar: ");
        scanf("%d", &opcao_parte);

        if (opcao_parte > 0 && opcao_parte <= num_partes) {
            int nova_cor = -1;	
            gotoxy(55, 28); printf("Digite o novo codigo da cor (0-15): ");
            scanf("%d", &nova_cor);

            if (nova_cor >= 0 && nova_cor <= 15) {
                if (genero == 0) {
                    cores_masculino[opcao_parte - 1] = nova_cor;
                } else {
                    cores_feminino[opcao_parte - 1] = nova_cor;
                }
                 gotoxy(5, 26); printf("                                                         "); // Limpa linha
            } else {
                gotoxy(65, 19); textcolor(12);
                printf("Codigo de cor invalido! Pressione qualquer tecla para continuar.");
                getch();
                gotoxy(55, 27); printf("                                                                 ");
            }
        } else if (opcao_parte != num_partes + 1) {
             gotoxy(55, 26); textcolor(12);
             printf("Opcao invalida! Pressione qualquer tecla para continuar.");
             getch();
             gotoxy(55, 26); printf("                                                                 ");
        }
    }

	cores_personagem = (*genero == 0) ? cores_masculino : cores_feminino;
    system("cls");
}

#endif
