#include <stdio.h>
#include <locale.h>
#include <conio.c>
#include <windows.h>

#include "bibliotecas/treinos.h"
#include "bibliotecas/criar_personagem.h"
#include "bibliotecas/personagens.h"
#include "bibliotecas/menu.h"
#include "bibliotecas/jogofut.h"
#include "bibliotecas/partida.h"
#include "bibliotecas/shop.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    window(1, 1, 120, 30);
    system("cls");

    initialing();

    while (1) {
        int tecla;

        first_screen();

        tecla = getch();
        textbackground(0);

        switch (tecla) {
            case '1':
                start_game();
                break;
            case '2':
                instructions();
                break;
            case '3':
                credits();
                break;
            case '4':
                system("cls");
                return 0;
        }
    }
    textcolor(15);
    return 0;
}
