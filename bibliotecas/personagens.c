#ifndef PERSONAGENS_C
#define PERSONAGENS_C

int inicioX = 4;
int inicioY = 2;

void print_color(int x, int y, int color, const char *text) {
    textbackground(color);
    gotoxy(inicioX + x, inicioY + y);
    printf("%s", text);
}

void personagem_masculino(int pele, int olho, int cabelo, int camiseta, int manga_camiseta, int shorts, int sapato) {
	int i;
	
    textbackground(14);
    print_color(5, 2, cabelo, "      ");
    print_color(4, 3, cabelo, "       ");
	print_color(5, 4, cabelo, "  ");

    print_color(6, 4, pele, "     ");
    print_color(5, 5, pele, "   ");
    textbackground(olho); 
	printf(" ");
	
    textbackground(pele); 
	printf(" ");
	
    textbackground(olho); 
	printf(" ");
	
    print_color(5, 6, pele, "   ");
    textbackground(olho); 
	printf(" ");
	
    textbackground(pele); 
	printf(" ");
	
    textbackground(olho); 
	printf(" ");
    print_color(6, 7, pele, "     ");

    for (i = 1; i <= 2; i++) {
        print_color(4, 4, cabelo, " ");
    }
    for (i = 0; i <= 2; i++) {
        print_color(4, 5 + i, cabelo, " ");
        if (i == 2) {
            print_color(5, 5 + i, cabelo, " ");
        }
    }

    print_color(6, 8, pele, "    ");
    print_color(4, 9, camiseta, "  ");
    textbackground(manga_camiseta); 
	printf("    ");
	
    textbackground(camiseta); 
	printf("  ");

    print_color(4, 10, manga_camiseta, " ");
    textbackground(camiseta); 
	printf("      ");
	
    textbackground(manga_camiseta); 
	printf(" ");

    for (i = 11; i <= 13; i++) {
        print_color(4, i, pele, " ");
        textbackground(camiseta); 
		printf("      ");
        textbackground(pele); 
		printf(" ");
    }

    print_color(5, 14, camiseta, "      ");
    print_color(5, 15, shorts, "      ");
    print_color(5, 16, shorts, "      ");

    print_color(5, 17, shorts, "  ");
    print_color(9, 17, shorts, "  ");
    print_color(5, 18, pele, "  ");
    print_color(9, 18, pele, "  ");
    print_color(5, 19, pele, "  ");
    print_color(9, 19, pele, "  ");

    print_color(5, 20, sapato, "   ");
    print_color(9, 20, sapato, "   ");

    textbackground(0);
}

void personagem_feminino(int pele, int olho, int cabelo, int camiseta, int manga_camiseta, int shorts, int sapato, int boca) {
	int i;
	
    textbackground(14);
    print_color(5, 2, cabelo, "      ");
    print_color(4, 3, cabelo, "      ");
    textbackground(pele);
    printf(" ");
	print_color(5, 4, cabelo, "   ");

    textbackground(olho); 
	printf(" ");
    textbackground(pele); 
	printf(" ");
	textbackground(olho); 
	printf(" ");
	print_color(5, 5, cabelo, " ");
	print_color(6, 5, pele, "  ");
    textbackground(olho); 
	printf(" ");
	
    textbackground(pele); 
	printf(" ");
	
    textbackground(olho); 
	printf(" ");
	
    print_color(5, 6, pele, "      ");
    print_color(6, 7, pele, "   ");
    textbackground(boca);
    printf("  ");

    for (i = 1; i <= 2; i++) {
        print_color(4, 4, cabelo, " ");
    }
    for (i = 0; i <= 3; i++) {
        print_color(4, 5 + i, cabelo, " ");
        if (i == 2) {
            print_color(5, 5 + i, cabelo, " ");
        }
    }

    print_color(6, 8, pele, "    ");
    print_color(4, 9, camiseta, "  ");
    textbackground(manga_camiseta); 
	printf("    ");
	
    textbackground(camiseta); 
	printf("  ");

    print_color(4, 10, manga_camiseta, " ");
    textbackground(camiseta); 
	printf("      ");
	
    textbackground(manga_camiseta); 
	printf(" ");

    for (i = 11; i <= 13; i++) {
        print_color(4, i, pele, " ");
        textbackground(camiseta); 
		printf("      ");
        textbackground(pele); 
		printf(" ");
    }

    print_color(5, 14, camiseta, "      ");
    print_color(5, 15, shorts, "      ");
    print_color(5, 16, shorts, "      ");

    print_color(5, 17, shorts, "  ");
    print_color(9, 17, shorts, "  ");
    print_color(5, 18, pele, "  ");
    print_color(9, 18, pele, "  ");
    print_color(5, 19, pele, "  ");
    print_color(9, 19, pele, "  ");

    print_color(5, 20, sapato, "   ");
    print_color(9, 20, sapato, "   ");

    textbackground(0);
}

#endif
