#ifndef SHOP_H
#define SHOP_H

#include "jogofut.h"

void loja1_comidas(Jogador *p);
void loja2_remedios(Jogador *p);
void loja3_coisas_ruins(Jogador *p);
void loja4_equipamentos(Jogador *p);
void loja5_luxo(Jogador *p);
void loja6_treino_avancado(Jogador *p);

void mostrar_dinheiro(Jogador *j){
    clrscr();
    gotoxy(5,1); textcolor(14); cprintf("SALDO DO JOGADOR: %d", j->dinheiro);

}

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
    mostrar_status(j);
    Sleep (2000);
    system ("cls");
}


void loja1_comidas(Jogador *j) {
    int op = -1;
    while (op != 0) {
        textcolor(10);
        printf("\n LOJA 1: Comidas/Bebidas \n");
        textcolor(15);
        printf("1) Sanduiche Natural ($20)   [+10 saude, +10 energia]\n");
        printf("2) Suco de Laranja 500ml ($10) [+5 saude, +10 energia]\n");
        printf("3) Prato Fit ($40)           [+20 saude, +5 desempenho]\n");
        printf("0) Voltar\n> ");
        if (scanf("%d", &op) != 1) { while (getchar()!='\n'); op=-1; continue; }

        if (op == 1 && j->dinheiro >= 20) {
            if (confirmar_compra("Sanduiche Natural", 20))
                aplicarEfeito(j, 20, +10);
        } else if (op == 2 && j->dinheiro >= 10) {
            if (confirmar_compra("Suco de Laranja", 10))
                aplicarEfeito(j, 10, +5);
        } else if (op == 3 && j->dinheiro >= 40) {
            if (confirmar_compra("Prato Fit", 40))
                aplicarEfeito(j, 40, +20);
        } else if (op == 0) {
            textcolor(14); puts("Voltando..."); textcolor(15);
        } else if (op >= 1 && op <= 3) {
            textcolor(12); puts("Dinheiro insuficiente."); textcolor(15);
        }
    }Sleep (2000);
    system ("cls");
}

void loja2_remedios(Jogador *j) {
    int op = -1;
    while (op != 0) {
        textcolor(10);
        printf("\n LOJA 2: Remedios/Descanso \n");
        textcolor(15);
        printf("1) Vitamina   ($25)  [+15 saude]\n");
        printf("2) Analgesico ($15)          [+10 saude]\n");
        printf("3) Capsula ($30)  [+25 energia]\n");
        printf("0) Voltar\n> ");
        if (scanf("%d", &op) != 1) { while (getchar()!='\n'); op=-1; continue; }

        if (op == 1 && j->dinheiro >= 25) {
            if (confirmar_compra("Vitamina Complexa", 25))
                aplicarEfeito(j, 25, +15);
        } else if (op == 2 && j->dinheiro >= 15) {
            if (confirmar_compra("Analgesico", 15))
                aplicarEfeito(j, 15, +10);
        } else if (op == 3 && j->dinheiro >= 30) {
            if (confirmar_compra("Capsula", 30))
                aplicarEfeito(j, 30, 0);
        } else if (op == 0) {
            textcolor(14); puts("Voltando..."); textcolor(15);
        } else if (op >= 1 && op <= 3) {
            textcolor(12); puts("Dinheiro insuficiente."); textcolor(15);
        }
    }Sleep (2000);
    system ("cls");
}

void loja3_coisas_ruins(Jogador *j) {
    int op = -1;
    while (op != 0) {
        textcolor(10);
        printf("\n LOJA 3: Coisas 'Ruins' \n");
        textcolor(15);
        printf("1) Cigarro ($12)          [-15 saude, +5 energia]\n");
        printf("2) Bebida Alcoolica ($18)  [-10 saude, +15 energia]\n");
        printf("3) Fast Food ($22)  [-10 saude, +20 energia]\n");
        printf("0) Voltar\n> ");
        if (scanf("%d", &op) != 1) { while (getchar()!='\n'); op=-1; continue; }

        if (op == 1 && j->dinheiro >= 12) {
            if (confirmar_compra("Cigarro", 12))
                aplicarEfeito(j, 12, -15);
        } else if (op == 2 && j->dinheiro >= 18) {
            if (confirmar_compra("Bebida Alcoolica", 18))
                aplicarEfeito(j, 18, -10);
        } else if (op == 3 && j->dinheiro >= 22) {
            if (confirmar_compra("Fest Food", 22))
                aplicarEfeito(j, 22, -10);
        } else if (op == 0) {
            textcolor(14); puts("Voltando..."); textcolor(15);
        } else if (op >= 1 && op <= 3) {
            textcolor(12); puts("Dinheiro insuficiente."); textcolor(15);
        }
    }Sleep (2000);
    system ("cls");
}

void loja4_equipamentos(Jogador *j) {
    int op = -1;
    while (op != 0) {
        textcolor(10);
        printf("\n LOJA 4: Equipamentos de Treino \n");
        textcolor(15);
        printf("1) Meiao ($60)           [+10 desempenho]\n");
        printf("2) Caneleira ($80)  [+10 desempenho, +10 energia]\n");
        printf("3) Chuteira ($120)          [+15 desempenho]\n");
        printf("0) Voltar\n> ");
        if (scanf("%d", &op) != 1) { while (getchar()!='\n'); op=-1; continue; }

        if (op == 1 && j->dinheiro >= 60) {
            if (confirmar_compra("Meiao", 60))
                aplicarEfeito(j, 60, 0);
        } else if (op == 2 && j->dinheiro >= 80) {
            if (confirmar_compra("Caneleira", 80))
                aplicarEfeito(j, 80, 0);
        } else if (op == 3 && j->dinheiro >= 120) {
            if (confirmar_compra("Chuteira", 120))
                aplicarEfeito(j, 120, 0);
        } else if (op == 0) {
            textcolor(14); puts("Voltando..."); textcolor(15);
        } else if (op >= 1 && op <= 3) {
            textcolor(12); puts("Dinheiro insuficiente."); textcolor(15);
        }
    }Sleep (2000);
    system ("cls");
}

void loja5_luxo(Jogador *j) {
    int op = -1;
    while (op != 0) {
        textcolor(10);
        printf("\n LOJA 5: Itens de Luxo \n");
        textcolor(15);
        printf("1) Carro Esportivo ($500)   [+5 desempenho]\n");
        printf("2) Moto ($300)            [+3 desempenho]\n");
        printf("3) Lancha ($800)          [+10 energia]\n");
        printf("4) Mansao ($1500)          [+20 energia, +10 desempenho]\n");
        printf("0) Voltar\n> ");
        if (scanf("%d", &op) != 1) { while (getchar()!='\n'); op=-1; continue; }

        if (op == 1 && j->dinheiro >= 500) {
            if (confirmar_compra("Carro Esportivo", 500))
                aplicarEfeito(j, 500, 0);
        } else if (op == 2 && j->dinheiro >= 300) {
            if (confirmar_compra("Moto", 300))
                aplicarEfeito(j, 300, 0);
        } else if (op == 3 && j->dinheiro >= 800) {
            if (confirmar_compra("Lancha", 800))
                aplicarEfeito(j, 800, 0);
        } else if (op == 4 && j->dinheiro >= 1500) {
            if (confirmar_compra("Mansao", 1500))
                aplicarEfeito(j, 1500, 0);
        } else if (op == 0) {
            textcolor(14); puts("Voltando..."); textcolor(15);
        } else if (op >= 1 && op <= 4) {
            textcolor(12); puts("Dinheiro insuficiente."); textcolor(15);
        }
    }Sleep (2000);
    system ("cls");
}

void loja6_treino_avancado(Jogador *j) {
    int op = -1;
    while (op != 0) {
        textcolor(10);
        printf("\n LOJA 6: Treino Avancado \n");
        textcolor(15);
        printf("1) Personal Trainer ($200)   [+25 desempenho, +10 energia]\n");
        printf("2) Suplemento Proteico ($90) [+10 desempenho, +15 saude]\n");
        printf("3) Equipamento Premium ($350) [+40 desempenho]\n");
        printf("0) Voltar\n> ");
        if (scanf("%d", &op) != 1) { while (getchar()!='\n'); op=-1; continue; }

        if (op == 1 && j->dinheiro >= 200) {
            if (confirmar_compra("Personal Trainer", 200))
                aplicarEfeito(j, 200, 0);
        } else if (op == 2 && j->dinheiro >= 90) {
            if (confirmar_compra("Suplemento Proteico", 90))
                aplicarEfeito(j, 90, +15);
        } else if (op == 3 && j->dinheiro >= 350) {
            if (confirmar_compra("Equipamento Premium", 350))
                aplicarEfeito(j, 350, 0);
        } else if (op == 0) {
            textcolor(14); puts("Voltando..."); textcolor(15);
        } else if (op >= 1 && op <= 3) {
            textcolor(12); puts("Dinheiro insuficiente."); textcolor(15);
        }
    }Sleep (2000);
    system ("cls");
}


void open_shop(Jogador *j) {
	system("cls");
    int op = -1;
    while (op != 0) {
        textcolor(11);
        printf("\t\n         * PAGINA PRINCIPAL * \t\n");
        textcolor(15);
        mostrar_dinheiro(j);
        printf("\n\nPara onde deseja ir?\n\n");
        textcolor(10);
        printf("1) Loja 1 - Comidas/Bebidas\n");
        printf("2) Loja 2 - Remedios/Descanso\n");
        printf("3) Loja 3 - Coisas 'Ruins'\n");
        printf("4) Loja 4 - Equipamentos\n");
        printf("5) Loja 5 - Luxo\n");
        printf("6) Loja 6 - Treino Avancado\n");
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
            case 4: loja4_equipamentos(j); break;
            case 5: loja5_luxo(j); break;
            case 6: loja6_treino_avancado(j); break;
            default:
                textcolor(12); puts("Opcao invalida."); textcolor(15);
        }
    }
}

#endif
