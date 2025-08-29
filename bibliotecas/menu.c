#ifndef MENUS_H
#define MENUS_H

char *name;

void maquina_escrever(char *text){
	int tam = strlen(text);
	textcolor(15);
	int i;
	for (i = 0; i< tam;i++){
		printf("%c", text[i]);
		Sleep(50);
	}
	Sleep(1000);
}

void initialing(){
	gotoxy(42, 13);
	maquina_escrever("Não coloque o jogo em tela cheia!");
}

void letter_P(int x, int y){
	gotoxy(x, y-4);
	printf(" ");
	gotoxy(x + 1,y-4);
	printf(" ");
	gotoxy(x + 2,y-4);
	printf(" ");
	gotoxy(x + 2,y-3);
	printf(" ");
	gotoxy(x + 2,y-2);
	printf(" ");
	gotoxy(x,y-3);
	printf(" ");
	gotoxy(x,y-2);
	printf(" ");
	gotoxy(x,y-1);
	printf(" ");
	gotoxy(x,y);
	printf(" ");
	gotoxy(x + 1,y - 2);
	printf(" ");
}

void letter_R(int x, int y){
	gotoxy(x, y-4);
	printf(" ");
	gotoxy(x + 1,y-4);
	printf(" ");
	gotoxy(x + 2,y-4);
	printf(" ");
	gotoxy(x + 2,y-3);
	printf(" ");
	gotoxy(x,y-3);
	printf(" ");
	gotoxy(x,y-2);
	printf(" ");
	gotoxy(x,y-1);
	printf(" ");
	gotoxy(x,y);
	printf(" ");
	gotoxy(x + 1,y - 2);
	printf(" ");
	gotoxy(x + 2,y - 1);
	printf(" ");
	gotoxy(x + 2,y);
	printf(" ");
}

void letter_O(int x, int y){
	gotoxy(x, y-4);
	printf(" ");
	gotoxy(x + 1,y-4);
	printf(" ");
	gotoxy(x + 1,y);
	printf(" ");
	gotoxy(x + 2,y-4);
	printf(" ");
	gotoxy(x + 2,y-3);
	printf(" ");
	gotoxy(x + 2,y-2);
	printf(" ");
	gotoxy(x + 2,y-1);
	printf(" ");
	gotoxy(x + 2,y);
	printf(" ");
	gotoxy(x,y-3);
	printf(" ");
	gotoxy(x,y-2);
	printf(" ");
	gotoxy(x,y-1);
	printf(" ");
	gotoxy(x,y);
	printf(" ");
}

void letter_L(int x, int y){
	gotoxy(x,y-4);
	printf(" ");
	gotoxy(x,y-3);
	printf(" ");
	gotoxy(x,y-2);
	printf(" ");
	gotoxy(x,y-1);
	printf(" ");
	gotoxy(x,y);
	printf(" ");
	gotoxy(x+1,y);
	printf(" ");
	gotoxy(x+2,y);
	printf(" ");
}

void letter_E(int x, int y){
	gotoxy(x,y-4);
	printf(" ");
	gotoxy(x + 1,y-4);
	printf(" ");
	gotoxy(x,y-3);
	printf(" ");
	gotoxy(x,y-2);
	printf(" ");
	gotoxy(x + 1,y-2);
	printf(" ");
	gotoxy(x,y-1);
	printf(" ");
	gotoxy(x,y);
	printf(" ");
	gotoxy(x + 1,y);
	printf(" ");
}

void letter_G(int x, int y){
	gotoxy(x, y-4);
	printf(" ");
	gotoxy(x + 1,y-4);
	printf(" ");
	gotoxy(x + 1,y);
	printf(" ");
	gotoxy(x + 2,y-4);
	printf(" ");
	gotoxy(x + 2,y-1);
	printf(" ");
	gotoxy(x + 2,y);
	printf(" ");
	gotoxy(x,y-3);
	printf(" ");
	gotoxy(x,y-2);
	printf(" ");
	gotoxy(x,y-1);
	printf(" ");
	gotoxy(x,y);
	printf(" ");
}

void letter_A(int x, int y){
	gotoxy(x,y-4);
	printf(" ");
	gotoxy(x+1,y-4);
	printf(" ");
	gotoxy(x+2,y-4);
	printf(" ");
	gotoxy(x,y-3);
	printf(" ");
	gotoxy(x+1,y-2);
	printf(" ");
	gotoxy(x,y-2);
	printf(" ");
	gotoxy(x,y-1);
	printf(" ");
	gotoxy(x,y);
	printf(" ");
	gotoxy(x+1,y-4);
	printf(" ");
	gotoxy(x+2,y-4);
	printf(" ");
	gotoxy(x+2,y-3);
	printf(" ");
	gotoxy(x+2,y-2);
	printf(" ");
	gotoxy(x+2,y-1);
	printf(" ");
	gotoxy(x+2,y);
	printf(" ");
}

void letter_C(int x, int y){
	gotoxy(x, y-4);
	printf(" ");
	gotoxy(x + 1,y-4);
	printf(" ");
	gotoxy(x + 1,y);
	printf(" ");
	gotoxy(x + 2,y-4);
	printf(" ");
	gotoxy(x + 2,y);
	printf(" ");
	gotoxy(x,y-3);
	printf(" ");
	gotoxy(x,y-2);
	printf(" ");
	gotoxy(x,y-1);
	printf(" ");
	gotoxy(x,y);
	printf(" ");
}

void letter_Y(int x, int y){
	gotoxy(x,y-4);
	printf(" ");
	gotoxy(x,y-3);
	printf(" ");
	gotoxy(x,y-2);
	printf(" ");
	gotoxy(x + 1,y-2);
	printf(" ");
	gotoxy(x+2,y-3);
	printf(" ");
	gotoxy(x+2,y-2);
	printf(" ");
	gotoxy(x+2,y-4);
	printf(" ");
	gotoxy(x+1,y-1);
	printf(" ");
	gotoxy(x+1,y);
	printf(" ");
	gotoxy(1, 30);
}

void text(int x, int y, int color){
	
	textbackground(color);
	letter_P(x, 6);
	letter_R(x + 5, 6);
	letter_O(x + 10, 6);
	letter_L(x + 20, 6);
	letter_E(x + 25, 6);
	letter_G(x + 30, 6);
	letter_A(x + 35, 6);
	letter_C(x + 40, 6);
	letter_Y(x + 45, 6);
	
}

void options(int x, int y){
	textbackground(1);
	textcolor(14);
	
	gotoxy(x, y);
	printf("1 - INICIO");
	gotoxy(x, y + 2);
	printf("2 - INSTRUÇÕES");
	gotoxy(x, y + 4);
	printf("3 - CRÉDITOS");
	gotoxy(x, y + 6);
	printf("4 - SAIR");
}

void draw_cloud_01(int posX, int posY){
	textbackground(15);
	
	gotoxy(posX + 3, posY-1); 
	cprintf("                ");
    gotoxy(posX, posY); 
	cprintf("                          ");
    gotoxy(posX + 2, posY+1); 
	cprintf("             ");
}

void draw_cloud_02(int posX, int posY){
	textbackground(15);
	
	gotoxy(posX, posY); 
	cprintf("      ");
    gotoxy(posX + 2, posY + 1); 
	cprintf("         ");
}

void first_screen(){
	textbackground(1);
	system("cls");

    textbackground(2);
    int x, y;
    
    for (y = 0; y <=5; y++){
    	gotoxy(1, y + 25);
    	for (x = 0; x <=119; x++){
    		printf(" ");	
		}
	}
	gotoxy(1, 23);
	printf("                     ");
	gotoxy(1, 24);
	printf("                                           ");
	gotoxy(65, 24);
	printf("                                                        ");
	gotoxy(80, 23);
	printf("                                          ");
	
	draw_cloud_01(6, 4);
	draw_cloud_02(18, 9);
	draw_cloud_02(24, 9);
	draw_cloud_01(85, 5);
	
	options(50, 12);
	
	gotoxy(1, 30);
}

void credits()
{
	system("cls");
	Sleep(500);
	char *titulo = "--- CREDITOS ---";
    
    char *functions[] = {
        "Designs",
        "Tudo o Que o mini timoteo fez",
        "Tudo que a luisa fez",
        "Tudo que a Livia Chevette fez",
        "Agradecimentos"
    };
    
    char *names[] = {
    	"Mateus (n30), Marcos (n28)",
    	"Marcos Vinicus Dunge Cassalati",
    	"Luisa",
    	"Livia",
    	"Jose junior"
	};

    int numero_de_funcoes = sizeof(functions) / sizeof(functions[0]);
    
    textcolor(14);
    gotoxy((120 - strlen(titulo)) / 2, 2);
    printf("%s", titulo);
    
    Sleep(500);
    
    int i;
    
    for (i = 0; i < numero_de_funcoes; i++){
        int y_pos = 6 + (i * 4); 
        int x_pos = (120 - strlen(functions[i])) / 2;
        int x_name = (120 - strlen(names[i])) / 2;

        gotoxy(x_pos, y_pos);
        textcolor(3);
        printf("%s", functions[i]);
        
        Sleep(500);
        
        gotoxy(x_name, y_pos + 2);
        textcolor(15);
        printf("%s", names[i]);
        
        Sleep(500);
    }
    
    gotoxy(44, 30);
    printf("Pressione qualquer tecla para sair...");
    getch();
    
    textcolor(15);
		
}

void teclas(){
	system("cls");
	printf("PALMEIRAS NÃO TEM MUNDIAL!");
	gotoxy(44, 30);
	printf("Pressione qualquer tecla para voltar...");
	getch();
}

void como_jogar(){
	system("cls");
	printf("PALMEIRAS NÃO TEM MUNDIAL!");
	gotoxy(44, 30);
	printf("Pressione qualquer tecla para voltar...");
	getch();
}

void instructions(){
	int escolha;
	
	
	char *text = "MANUAL";
	char *title1 = "Selecione uma página para ver as instruções";
		
	char *paginas[] = {
		"[0] - SAIR",
		"[1] - TECLAS",
		"[2] - COMO JOGAR"
	};
	
	while(escolha != 0){
		system("cls");
	
		textcolor(14);
		
		gotoxy((120-strlen(text)) / 2, 2);
		printf(text);
		
		textcolor(3);
		
		gotoxy((120-strlen(title1)) / 2, 4);
		printf(title1);
		
		int tamanho_textos = sizeof(paginas) / sizeof(paginas[0]);
		
		int i;
		
		textcolor(15);
		for(i = 0; i<tamanho_textos; i++){
			gotoxy(50, (30 - tamanho_textos) / 2 + i);
	    	printf("%s", paginas[i]);	
		}	
		
		gotoxy(50, 30);
		printf("Digite sua escolha: ");
		scanf("%d", &escolha);
		
		if (escolha == 1){
			teclas();
		}
		else if (escolha == 2){
			como_jogar();
		}
	}
}



#endif
