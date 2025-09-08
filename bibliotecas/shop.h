#ifndef SHOP_H
#define SHOP_H

#include "jogofut.h"

void loja1_comidas(Jogador *p);
void loja2_remedios(Jogador *p);
void loja3_coisas_ruins(Jogador *p);
void loja4_equipamentos(Jogador *p);
void loja5_luxo(Jogador *p);
void loja6_treino_avancado(Jogador *p);

int clamp(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

int confirmar_compra(const char *nome, int preco) {
    int op;
    textcolor(14);
    printf("Confirmar compra de \"%s\" por $%d? (1=Sim, 0=Nao): ", nome, preco);
    textcolor(15);
    if (scanf("%d", &op) != 1) { while (getchar()!='\n'); return 0; }
    return op == 1;
    Sleep (2000);
    system ("cls");
}

void aplicarEfeito(Jogador *j, int preco, int dSaude) {
    j->dinheiro -= preco;
    textcolor(10);
    printf("Compra concluida!\n");
    textcolor(15);
    mostrar_status(j, 5, 3);
    Sleep (2000);
    system ("cls");
}

typedef struct {
    int indice;
    char nome[50];
    int valor;
    int energia;
    int moral;
    int saude;
    int fisico;
} Item;

Item menu_restaurante[25] = {
    // --- COMIDAS ---
    // {indice, "Nome", valor, energia, moral, saude, fisico}
    {1, "Pao com Manteiga", 5, 5, 0, 2, 0},
    {2, "Salada Simples", 8, 10, 0, 5, 1},
    {3, "Sanduiche de Frango", 12, 20, 0, 8, 2},
    {4, "Omelete com Queijo", 15, 18, 2, 10, 0},
    {5, "Macarronada a Bolonhesa", 22, 30, 0, 15, 0},
    {6, "Prato Feito", 25, 40, 0, 20, 0},
    {7, "Risoto de Cogumelos", 28, 25, 0, 10, 0},
    {8, "Lasanha de Carne", 30, 45, 4, 22, -1},
    {9, "Salmao Grelhado com Legumes", 35, 35, 0, 30, 0},
    {10, "Picanha com Batata Frita", 45, 50, 5, 25, -3},
    {11, "Feijoada Completa (Especial)", 50, 70, 0, 30, -2},
    {12, "Bife a Parmegiana", 38, 40, 0, 20, -1},
    {13, "Strogonoff de Frango", 32, 35, 0, 18, -1},
    {14, "Frango Assado com Polenta", 40, 60, 0, 25, 0},
    {15, "Torta de Frango (Fatia)", 10, 12, 0, 5, 0},

    // --- BEBIDAS ---
    {16, "Copo d'Agua", 2, 5, 0, 2, 0},
    {17, "Suco de Laranja (Copo)", 7, 10, 0, 8, 0},
    {18, "Refrigerante (Lata)", 8, 15, 0, -2, -1},
    {19, "Caldo de Cana", 10, 25, 0, 5, 0},
    {20, "Vitamina de Banana com Aveia", 14, 20, 0, 10, 2},
    {21, "Energetico (Lata)", 15, 40, 5, -5, -1},
    {22, "Suco Detox (Verde)", 18, 15, 0, 20, 3},
    {23, "Acai na Tigela (Pequeno)", 20, 30, 0, 10, -2},
    {24, "Cafe Expresso", 6, 10, 0, -1, 0},
    {25, "Milk-shake de Chocolate", 22, 25, 10, -3, -1}
};

Item menu_farmacia[15] = {
    {1, "Band-Aid (Caixa)", 10, 0, 0, 5, 0},
    {2, "Gaze e Antisseptico", 15, 0, 0, 10, 0},
    {3, "Analgesico Simples", 20, -2, 0, 15, 0},
    {4, "Relaxante Muscular", 25, 0, 0, 20, 0},
    {5, "Vitamina C (Frasco)", 30, 0, 0, 5, 0},
    {6, "Complexo Vitaminico", 45, 0, 0, 10, 0},
    {7, "Pomada para Contusoes", 35, 0, 0, 30, 0},
    {8, "Barra de Cereal Energetica", 12, 20, 0, 5, 0},
    {9, "Isotonico (Garrafa)", 15, 30, 0, 0, 0},
    {10, "Kit de Primeiros Socorros", 80, 0, 0, 70, 0},
    {11, "Anti-inflamatorio Forte", 60, -5, 0, 50, 0},
    {12, "Injecao de Adrenalina", 150, 100, 10, -20, 0},
    {13, "Suplemento de Proteina (Dose)", 50, 10, 0, 0, 0},
    {14, "Calmante Natural", 40, -10, 15, 5, 0},
    {15, "Tira para Dor de Cabeca", 18, 0, 2, 10, 0}
};

Item menu_bar[15] = {
    {1, "Agua com Gas", 5, 5, 2, 0, 0},
    {2, "Porcao de Amendoim", 8, 10, 5, 0, 0},
    {3, "Cerveja (Copo)", 10, 15, 10, 0, 0},
    {4, "Porcao de Batata Frita", 18, 25, 8, -3, 0},
    {5, "Caipirinha de Limao", 22, 20, 25, 0, 0},
    {6, "Porcao de Calabresa", 25, 30, 12, -4, 0},
    {7, "Refrigerante (Copo)", 7, 15, 0, -2, 0},
    {8, "Suco Natural (Copo)", 9, 12, 0, 5, 0},
    {9, "Whisky (Dose)", 30, 15, 30, 0, 0},
    {10, "Porcao de Frango a Passarinho", 35, 40, 15, -5, 0},
    {11, "Vinho (Taca)", 28, 10, 20, 0, 0},
    {12, "Cafe com Salgados", 15, 15, 5, 0, 0},
    {13, "Coquetel sem Alcool", 20, 20, 18, 5, 0},
    {14, "Porcao de Mandioca Frita", 22, 28, 10, -4, 0},
    {15, "Drink Especial da Casa", 40, 30, 40, 0, 0}
};

Item menu_luxo[10] = {
    {1, "Relogio de Grife", 1500, 5, 20, 0, 0},
    {2, "Perfume Importado", 800, 5, 15, 0, 0},
    {3, "Terno de Alfaiataria", 3000, 10, 30, 0, 0},
    {4, "Sapato Italiano de Couro", 2500, 8, 25, 0, 0},
    {5, "Oculos de Sol de Marca", 1200, 5, 18, 0, 0},
    {6, "Celular de Ultima Geracao", 7000, 15, 40, 0, 0},
    {7, "Fones de Ouvido Premium", 2000, 10, 22, 0, 0, 0},
    {8, "Joia (Corrente de Ouro)", 10000, 20, 60, 0, 0},
    {9, "Viagem de Fim de Semana", 15000, 50, 80, 0, 0},
    {10, "Carro Esportivo (Aluguel)", 25000, 30, 100, 0, 0}
};

Item menu_academia[15] = {
    {1, "Garrafa de Agua", 20, 10, 0, 0, 0},
    {2, "Toalha de Treino", 35, 0, 2, 0, 0},
    {3, "Barra de Proteina", 15, 25, 0, 0, 0},
    {4, "Luvas de Musculacao", 100, 0, 0, 0, 0},
    {5, "Shake Pos-Treino", 50, 40, 0, 10, 0},
    {6, "Corda de Pular Profissional", 120, 0, 0, 0, 1},
    {7, "Creatina (Pote Pequeno)", 200, 0, 0, 0, 0},
    {8, "Chuteira de Precisao", 500, 0, 0, 0, 1},
    {9, "Caneleiras de Carbono", 350, 0, 0, 5, 0},
    {10, "Camisa de Compressao Termica", 250, 2, 0, 0, 0},
    {11, "Plano de Nutricao Mensal", 1000, 0, 0, 10, 0},
    {12, "Treinamento Funcional (Sessao)", 300, 0, 0, 0, 1},
    {13, "BCAA (Suplemento)", 180, 5, 1, 0, 0},
    {14, "Bola Oficial de Jogo", 400, 0, 5, 0, 0},
    {15, "Assessoria com Personal Trainer", 2000, 0, 5, 0, 1}
};

void exibir_items(Jogador *j, Item Lista[], int tam_lista) {
    int i;
    for (i = 0; i < tam_lista; i++) { // Loop para as 15 comidas
        printf("[%d] %-30s | %sR$ %2d%s | %sEnergia: +%d%s, %sSaude: +%d%s, %sMoral: %d%s\n", 
            Lista[i].indice, 
            Lista[i].nome, 
            VERDE,
            Lista[i].valor, 
            RESET,
            AMARELO,
			Lista[i].energia,
			RESET,
            VERMELHO,
			Lista[i].saude,
			RESET,
			AZUL,
			Lista[i].moral,
			RESET
        );
    }
}

void loja1_comidas(Jogador *j) {
	int total_itens_restaurante = sizeof(menu_farmacia) / sizeof(menu_farmacia[0]);
    int escolha = -1;
    int i;

    while (escolha != 0) {
        system("cls");
        printf("Seu Dinheiro: R$ %s%d%s | Sua Energia: %s%d%s\n\n", VERDE, j->dinheiro, RESET, AMARELO, j->energia, RESET);
        
        exibir_items(j, menu_restaurante, total_itens_restaurante);

        printf("\nDigite o indice do item para comprar (ou 0 para sair): ");
        scanf("%d", &escolha);

        if (escolha > 0 && escolha <= total_itens_restaurante) {
            Item item_escolhido = menu_restaurante[escolha - 1]; // -1 porque o array começa em 0

            if (j->dinheiro >= item_escolhido.valor) {
                j->dinheiro -= item_escolhido.valor;
                
                // Aplica todos os efeitos (soma os status)
                j->energia += j->energia + item_escolhido.energia > 100 ? 100 - j->energia: item_escolhido.energia;
                j->moral += j->moral + item_escolhido.moral > 100 ? 100 - j->moral: item_escolhido.moral;
                j->saude += j->saude + item_escolhido.saude > 100 ? 100 - j->saude: item_escolhido.saude;
                j->fisico += j->fisico + item_escolhido.fisico > 100 ? 100 - j->fisico: item_escolhido.fisico;

                printf("Voce comprou %s! Seus status foram atualizados.", item_escolhido.nome);

            } else {
                printf("\nDinheiro insuficiente!\n");
            }
            sleep(2);
        }
    }
}

void loja2_remedios(Jogador *j) {
	int total_itens_farmacia = sizeof(menu_farmacia) / sizeof(menu_farmacia[0]);
    int escolha = -1;
    int i;

    while (escolha != 0) {
        system("cls");
        printf("Seu Dinheiro: R$ %s%d%s | Sua Energia: %s%d%s\n\n", VERDE, j->dinheiro, RESET, AMARELO, j->energia, RESET);
        
        exibir_items(j, menu_farmacia, total_itens_farmacia);

        printf("\nDigite o indice do item para comprar (ou 0 para sair): ");
        scanf("%d", &escolha);

        if (escolha > 0 && escolha <= total_itens_farmacia) {
            Item item_escolhido = menu_farmacia[escolha - 1]; // -1 porque o array começa em 0

            if (j->dinheiro >= item_escolhido.valor) {
                j->dinheiro -= item_escolhido.valor;
                
                // Aplica todos os efeitos (soma os status)
                j->energia += j->energia + item_escolhido.energia > 100 ? 100 - j->energia: item_escolhido.energia;
                j->moral += j->moral + item_escolhido.moral > 100 ? 100 - j->moral: item_escolhido.moral;
                j->saude += j->saude + item_escolhido.saude > 100 ? 100 - j->saude: item_escolhido.saude;
                j->fisico += j->fisico + item_escolhido.fisico > 100 ? 100 - j->fisico: item_escolhido.fisico;

                printf("Voce comprou %s! Seus status foram atualizados.", item_escolhido.nome);

            } else {
                printf("\nDinheiro insuficiente!\n");
            }
            sleep(2);
        }
    }
}

void loja3_coisas_ruins(Jogador *j) {
    int total_itens_bar = sizeof(menu_bar) / sizeof(menu_bar[0]);
    int escolha = -1;
    int i;

    while (escolha != 0) {
        system("cls");
        printf("Seu Dinheiro: R$ %s%d%s | Sua Energia: %s%d%s\n\n", VERDE, j->dinheiro, RESET, AMARELO, j->energia, RESET);
        
        exibir_items(j, menu_bar, total_itens_bar);

        printf("\nDigite o indice do item para comprar (ou 0 para sair): ");
        scanf("%d", &escolha);

        if (escolha > 0 && escolha <= total_itens_bar) {
            Item item_escolhido = menu_bar[escolha - 1]; // -1 porque o array começa em 0

            if (j->dinheiro >= item_escolhido.valor) {
                j->dinheiro -= item_escolhido.valor;
                
                // Aplica todos os efeitos (soma os status)
                j->energia += j->energia + item_escolhido.energia > 100 ? 100 - j->energia: item_escolhido.energia;
                j->moral += j->moral + item_escolhido.moral > 100 ? 100 - j->moral: item_escolhido.moral;
                j->saude += j->saude + item_escolhido.saude > 100 ? 100 - j->saude: item_escolhido.saude;
                j->fisico += j->fisico + item_escolhido.fisico > 100 ? 100 - j->fisico: item_escolhido.fisico;

                printf("Voce comprou %s! Seus status foram atualizados.", item_escolhido.nome);

            } else {
                printf("\nDinheiro insuficiente!\n");
            }
            sleep(2);
        }
    }
}

void loja4_luxo(Jogador *j) {
	int total_itens_luxo = sizeof(menu_luxo) / sizeof(menu_luxo[0]);
    int escolha = -1;
    int i;

    while (escolha != 0) {
        system("cls");
        printf("Seu Dinheiro: R$ %s%d%s | Sua Energia: %s%d%s\n\n", VERDE, j->dinheiro, RESET, AMARELO, j->energia, RESET);
        
        exibir_items(j, menu_luxo, total_itens_luxo);

        printf("\nDigite o indice do item para comprar (ou 0 para sair): ");
        scanf("%d", &escolha);

        if (escolha > 0 && escolha <= total_itens_luxo) {
            Item item_escolhido = menu_luxo[escolha - 1]; // -1 porque o array começa em 0

            if (j->dinheiro >= item_escolhido.valor) {
                j->dinheiro -= item_escolhido.valor;
                
                // Aplica todos os efeitos (soma os status)
                j->energia += j->energia + item_escolhido.energia > 100 ? 100 - j->energia: item_escolhido.energia;
                j->moral += j->moral + item_escolhido.moral > 100 ? 100 - j->moral: item_escolhido.moral;
                j->saude += j->saude + item_escolhido.saude > 100 ? 100 - j->saude: item_escolhido.saude;
                j->fisico += j->fisico + item_escolhido.fisico > 100 ? 100 - j->fisico: item_escolhido.fisico;

                printf("Voce comprou %s! Seus status foram atualizados.", item_escolhido.nome);

            } else {
                printf("\nDinheiro insuficiente!\n");
            }
            sleep(2);
        }
    }
}

void loja5_treino_avancado(Jogador *j) {
	int total_itens_treino = sizeof(menu_academia) / sizeof(menu_academia[0]);
    int escolha = -1;
    int i;

    while (escolha != 0) {
        system("cls");
        printf("Seu Dinheiro: R$ %s%d%s | Sua Energia: %s%d%s\n\n", VERDE, j->dinheiro, RESET, AMARELO, j->energia, RESET);
        
        exibir_items(j, menu_academia, total_itens_treino);

        printf("\nDigite o indice do item para comprar (ou 0 para sair): ");
        scanf("%d", &escolha);

        if (escolha > 0 && escolha <= total_itens_treino) {
            Item item_escolhido = menu_academia[escolha - 1]; // -1 porque o array começa em 0

            if (j->dinheiro >= item_escolhido.valor) {
                j->dinheiro -= item_escolhido.valor;
                
                // Aplica todos os efeitos (soma os status)
                j->energia += j->energia + item_escolhido.energia > 100 ? 100 - j->energia: item_escolhido.energia;
                j->moral += j->moral + item_escolhido.moral > 100 ? 100 - j->moral: item_escolhido.moral;
                j->saude += j->saude + item_escolhido.saude > 100 ? 100 - j->saude: item_escolhido.saude;
                j->fisico += j->fisico + item_escolhido.fisico > 100 ? 100 - j->fisico: item_escolhido.fisico;

                printf("Voce comprou %s! Seus status foram atualizados.", item_escolhido.nome);

            } else {
                printf("\nDinheiro insuficiente!\n");
            }
            sleep(2);
        }
    }
}


void open_shop(Jogador *j) {
	system("cls");
    int op = -1;
    while (op != 0) {
        textcolor(11);
        printf("\t\n         * PAGINA PRINCIPAL * \t\n");
        textcolor(15);
        mostrar_status(j, 5, 3);
        printf("\n\nPara onde deseja ir?\n\n");
        textcolor(10);
        printf("1) Restaurante\n");
        printf("2) Farmacia\n");
        printf("3) Bar\n");
        printf("4) Itens de Luxo\n");
        printf("5) Academia\n");
        textcolor(14);
        textcolor(15);
        printf("0) Sair\n> ");
        
        if (scanf("%d", &op) != 1) { 
			while (getchar()!='\n'); op=-1; continue; 
		}
		
		Sleep (1000);
	    system ("cls");
        switch (op) {
            case 1: loja1_comidas(j); break;
            case 2: loja2_remedios(j); break;
            case 3: loja3_coisas_ruins(j); break;
            case 4: loja4_luxo(j); break;
            case 5: loja5_treino_avancado(j); break;
            default:
                textcolor(12); puts("Opcao invalida."); textcolor(15);
        }
    }
}

#endif
