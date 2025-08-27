#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <conio.c>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "menu.c"
#include "personagens.c"
#include "jogofut.cpp"

main(){
	setlocale(LC_ALL, "Portuguese");
	window(1, 1, 120, 30);
	system("cls");
	
	initialing();
	
	while (1){
		int tecla;
		
		first_screen();
		text(35, 7, 14);
		
		tecla = getch();
		textbackground(0);
		
		switch(tecla){
			case 49:
				start_game();
				break;
			case 50:
				instructions();
				break;
			case 51:
				credits();
				break;
			case 52:
				system("cls");
				return 0;
		}
	}
	textcolor(15);
}
