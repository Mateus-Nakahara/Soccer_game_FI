#include <stdio.h>
#include <conio.c>
#include <string.h>

// Estrutura para armazenar os atributos do jogador
struct Jogador {
    char nome[50];
    int nivel;
    int hp;
    int mp;
    char classe[50];
};

// Função para desenhar o painel de atributos do jogador
void desenharPainel(struct Jogador jogador) {
    // Limpa a tela
    clrscr();

    // Define a cor do texto para o painel
    textcolor(WHITE);
    textbackground(BLACK);

    // Desenha a borda superior
    gotoxy(1, 1);
    printf("%c", 201); // Canto superior esquerdo
    for (int i = 0; i < 118; i++) {
        printf("%c", 205); // Linha horizontal
    }
    printf("%c", 187); // Canto superior direito

    // Desenha as bordas laterais
    for (int i = 2; i < 30; i++) {
        gotoxy(1, i);
        printf("%c", 186); // Linha vertical
        gotoxy(120, i);
        printf("%c", 186); // Linha vertical
    }

    // Desenha a borda inferior
    gotoxy(1, 30);
    printf("%c", 200); // Canto inferior esquerdo
    for (int i = 0; i < 118; i++) {
        printf("%c", 205); // Linha horizontal
    }
    printf("%c", 188); // Canto inferior direito

    // Exibe o título do painel
    textcolor(YELLOW);
    gotoxy(12, 2);
    cprintf("CARACTERISTICAS DO JOGADOR");
    gotoxy(80, 2);
    cprintf("ATRIBUTOS DO JOGADOR");

    // Exibe os atributos do jogador
    textcolor(WHITE);
    gotoxy(3, 4);
    cprintf("Nome: ");
    textcolor(GREEN);
    cprintf("%s", jogador.nome);

    textcolor(WHITE);
    gotoxy(3, 5);
    cprintf("Nivel: ");
    textcolor(GREEN);
    cprintf("%d", jogador.nivel);

    textcolor(WHITE);
    gotoxy(3, 6);
    cprintf("HP: ");
    textcolor(GREEN);
    cprintf("%d", jogador.hp);

    textcolor(WHITE);
    gotoxy(3, 7);
    cprintf("MP: ");
    textcolor(GREEN);
    cprintf("%d", jogador.mp);

    textcolor(WHITE);
    gotoxy(3, 8);
    cprintf("Classe: ");
    textcolor(GREEN);
    cprintf("%s", jogador.classe);

    // Posiciona o cursor fora do painel
    
    char *text = "Presione qualquer tecla para voltar ao inicio...";
    
    textcolor(14);
    gotoxy((120 - strlen(text)) / 2, 28);
    printf("Presione qualquer tecla para voltar ao inicio...");
}

int main() {
	window(1, 1, 120, 30);
    struct Jogador jogador1 = {"Aragorn", 10, 100, 50, "Guerreiro"};

    desenharPainel(jogador1);

    // Aguarda o usuário pressionar uma tecla para sair
    getch();

    return 0;
}
