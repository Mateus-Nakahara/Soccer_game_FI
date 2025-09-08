#ifndef JOGO_FUNCIONAL
#define JOGO_FUNCIONAL

// Cores
#define RESET   "\033[0m"
#define VERMELHO "\033[1;31m"
#define VERDE   "\033[1;32m"
#define AMARELO "\033[1;33m"
#define AZUL    "\033[1;34m"
#define ROXO    "\033[1;35m"
#define CIANO   "\033[1;36m"
#define BRANCO  "\033[1;37m"

#ifdef _WIN32
#include <windows.h>
#endif

// Função para habilitar cores no console do Windows
void habilitarCores() {
#ifdef _WIN32
    // Define a constante se ela não existir (para compiladores mais antigos)
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        return;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        return;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) {
        return;
    }
#endif
}

// Estrutura que representa um time
typedef struct{
    char nome[32];
    int dificuldade;
} Time;

// Estrutura que representa um jogador
typedef struct{
    char nome[32];
    char posicao[32];
    int gender;
    int contratado;
    char time_atual[32];
    float salario;
    int historico[10];
    int jogos;
    int energia, moral, chute, penalti, passe, fisico, tatica;
    int roupas[7];
    int acertos;
    int erros;
    int dinheiro;
    int saude;
} Jogador;

// Lista de times disponíveis
Time times[] = {               // Escolhe time aleatório
	{"Flamengo", 95}, // Nome do time e a dificuldade de entrar no time (De 0 - 100)
	{"Palmeiras", 95},
	{"Corinthians", 95},
	{"São Paulo", 95},
	{"Fluminense", 93},
	{"Internacional", 91},
	{"Grêmio", 91},
	{"Atlético Mineiro", 90},
	{"Vasco da Gama", 89},
	{"Athletico Paranaense", 88},
	{"Cruzeiro", 88},
	{"Botafogo", 87},
	{"Santos", 86},
	{"Red Bull Bragantino", 85},
	{"Bahia", 84},
	{"Fortaleza", 82},
	{"Coritiba", 80},
	{"Goiás", 79},
	{"Vitória", 78},
	{"Ceará", 77},
	{"Sport Recife", 76},
	{"América Mineiro", 75},
	{"Cuiabá", 74},
	{"Juventude", 73},
	{"Atlético Goianiense", 72},
	{"Guarani", 70},
	{"Ponte Preta", 69},
	{"Avaí", 68},
	{"Chapecoense", 67},
	{"CRB", 66},
	{"Vila Nova", 65},
	{"Mirassol", 64},
	{"Novorizontino", 63},
	{"Botafogo-SP", 62},
	{"Ituano", 61},
	{"Paysandu", 60},
	{"Remo", 59},
	{"Náutico", 58},
	{"Santa Cruz", 57},
	{"ABC", 56},
	{"Sampaio Corrêa", 55},
	{"Figueirense", 54},
	{"CSA", 53},
	{"Londrina", 52},
	{"Criciúma", 51},
	{"Brusque", 50},
	{"Ypiranga-RS", 49},
	{"Botafogo-PB", 48},
	{"Confiança", 47},
	{"Ferroviária", 46},
	{"Volta Redonda", 45},
	{"São Bernardo", 44},
	{"Amazonas FC", 43},
	{"Operário-PR", 42},
	{"Brasiliense", 41},
	{"Portuguesa", 40},
	{"Joinville", 39},
	{"América-RN", 38},
	{"Manaus FC", 37},
	{"Aparecidense", 36},
	{"Tombense", 35},
	{"São José-RS", 34},
	{"Altos-PI", 33},
	{"Campinense", 32},
	{"ASA", 31},
	{"Treze", 30},
	{"Brasil de Pelotas", 29},
	{"XV de Piracicaba", 28},
	{"Bangu", 27},
	{"Portuguesa-RJ", 26},
	{"Santo André", 25},
	{"Juazeirense", 24},
	{"Moto Club", 23},
	{"Jacuipense", 22},
	{"Ferroviário-CE", 21},
	{"Caxias", 20},
	{"Retrô FC", 19},
	{"Athletic Club-MG", 18},
	{"Tocantinópolis", 17},
	{"Ceilândia", 16},
	{"Real Noroeste", 15},
	{"Pouso Alegre", 14},
	{"Maringá FC", 13},
	{"Paraná Clube", 12},
	{"Hercílio Luz", 11},
	{"Sergipe", 10},
	{"Águia de Marabá", 9},
	{"Iguatu", 8},
	{"Potiguar de Mossoró", 7},
	{"Operário-MS", 6},
	{"Trem-AP", 5}
};
int n_times = sizeof(times) / sizeof(times[0]);  // Ela calcula quantos elementos existem no vetor times

// Função para simular carregamento (efeito visual)
void carregamento(const char *msg) {
	int i;
	volatile long j;
	
    printf("\n%s%s%s", CIANO, msg, RESET);
    for (i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        for (j = 0; j < 50000000; j++); // atraso
    }
    Sleep(1000);
    printf("\n");
}

// Criação do jogador
void criar_jogador(Jogador *j) {
	while(1){
		system("cls");
		char *title = "CRIAÇÃO DO JOGADOR";
		
		gotoxy((120-strlen(title)) / 2, 1);
	    printf("%s%s%s\n", ROXO, title, RESET);
	    
	    printf("\nDigite seu nome: ");
	    scanf(" %[^\n]", j->nome);                          // "->" Usado para acessar um campo de uma struct que está em um ponteiro.
	
	    // Jogador escolhe posição
	    printf("Escolha sua posição (%sAtacante%s / %sMeio%s / %sZagueiro%s / %sGoleiro%s): ",
	           AMARELO, RESET, AMARELO, RESET, AMARELO, RESET, AMARELO, RESET);
	    scanf(" %[^\n]", j->posicao);
		
	    // Atribui habilidade inicial dependendo da posição
	    
	    strlwr(j->posicao);
	    
	    if (strcmp(j->posicao, "atacante") == 0 || strcmp(j->posicao, "meio") == 0 || strcmp(j->posicao, "zagueiro") == 0 || strcmp(j->posicao, "goleiro") == 0){
	    	j->chute = 20 + rand() % 20;
	    	j->fisico = 20 + rand() % 20;
	    	j->moral = 20 + rand() % 20;
	    	j->passe = 20 + rand() % 20;
	    	j->penalti = 20 + rand() % 20;
	    	j->tatica = 20 + rand() % 20;
	    	j->dinheiro = 100 + rand() % 500;
	    	j->erros = 0;
	    	j->jogos = 0;
	    	j->acertos = 0;
	    	j->energia = 100;
	    	j->saude = 100;
		}
	    else
		{
	    	printf("%sPosição Inválida!", VERMELHO);
	    	Sleep(1000);
	    	continue;
		}
	
	    j->contratado = 0;
	    strcpy(j->time_atual, "Nenhum"); // Começa sem time
	    j->salario = 0;
	    j->jogos = 0;
	
		create_person(&j->gender, j->roupas);
		
		system("cls");
	
		char *text = "Jogador criado com sucesso!";
	
		gotoxy((120-strlen(text))/2, 10);
		
	    printf("%s%s%s", VERDE, text, RESET);
	    gotoxy((120-strlen(text) - 5)/2, 12);
	    printf("Nome: %s%s%s | Posição: %s%s%s \n",
        AZUL, j->nome, RESET, AMARELO, j->posicao, RESET);
        Sleep(1500);
        break;
	}
}

// Peneira em um time
int enviar_proposta(Jogador *j, Time t) {
	system("cls");
    carregamento("Realizando teste");
    int chance = rand() % 20;
    int media = (j->chute + j->penalti + j->passe + j->fisico + j->tatica) / 5;

    // Testa se o jogador passa na peneira
    if (chance + media > t.dificuldade + rand() % 20) {
        j->contratado = 1;
        strcpy(j->time_atual, t.nome);
        j->salario = 123 * t.dificuldade + (40 * media);
        printf("\n%sParabéns! Você foi aceito no %s!%s\n", VERDE, t.nome, RESET);
        printf("Salário inicial: %sR$ %.2f%s\n", VERDE, j->salario, RESET);
        Sleep(2000);
        return 1;
    } else {
        printf("\n%sInfelizmente, você não foi aprovado no time %s.%s\n", VERMELHO, t.nome, RESET);
        Sleep(2000);
		return 0;
    }
}

// Receber proposta de algum time 
void receber_proposta(Jogador *j) {
	system("cls");
    int chance = rand() % 100;
    int media = (j->chute + j->penalti + j->passe + j->fisico + j->tatica) / 5;

    if (chance < 4) {
        Time t;

        // Garante que o time sorteado NÃO seja o mesmo do jogador
        do {
            t = times[rand() % n_times];
        } while (strcmp(j->time_atual, t.nome) == 0);

        float novo_salario = (t.dificuldade * 100) + (media * 20) ;
        carregamento("Você recebeu uma proposta!");
        printf("\n%sO time %s fez uma proposta para você!%s\n", CIANO, t.nome, RESET);
        printf("Salário oferecido: %sR$ %.2f%s\n", VERDE, novo_salario, RESET);
        printf("Deseja aceitar? (%s1 = Sim%s / %s0 = Não%s): ", VERDE, RESET, VERMELHO, RESET);
        
        int op;
        scanf("%d", &op);

        if (op == 1) {
            strcpy(j->time_atual, t.nome);
            j->salario = novo_salario;
            j->contratado = 1;
            printf("\n%sContrato assinado com %s!%s Novo salário: %sR$ %.2f%s\n",
                   VERDE, t.nome, RESET, VERDE, j->salario, RESET);
        } else {
            printf("\n%sVocê recusou a proposta.%s\n", AMARELO, RESET);
        }
        printf("\nPressione qualquer tecla para continuar...");
    	getch();
    }
    system("cls");
}

// Mostrar status do jogador
void status(Jogador *j) {
	system("cls");
	
	int i;
    
    mostrar_status(j, 55, 8);
    
    textcolor(WHITE);
    textbackground(BLACK);

    // Exibe o título do painel
    textcolor(YELLOW);
    gotoxy(12, 2);
    cprintf("CARACTERISTICAS DO JOGADOR");
    gotoxy(80, 2);
    cprintf("ATRIBUTOS DO JOGADOR");
    
    gotoxy(10, 10);
    
    if (j->gender == 1){
    	personagem_masculino(j->roupas[0], j->roupas[1], j->roupas[2], j->roupas[3], j->roupas[4], j->roupas[5], j->roupas[6]);
	}
	else if (j->gender == 2){
		personagem_feminino(j->roupas[0], j->roupas[1], j->roupas[2], j->roupas[3], j->roupas[4], j->roupas[5], j->roupas[6]);
	}

    // Exibe os atributos do jogador
    gotoxy(3, 25);
    cprintf("%sNome: %s%s%s", RESET, VERDE, j->nome, RESET);

    gotoxy(3, 26);
    cprintf("%sPosicao: %s%s%s", RESET, VERDE, j->posicao, RESET);

    gotoxy(3, 27);
    cprintf("%sTime: %s%s%s", RESET, VERDE, j->time_atual, RESET);
    gotoxy(3, 28);
    cprintf("%sGenero: %s%s%s", RESET, VERDE, j->gender == 1 ? "Masculino": "Feminino", RESET);

    // Posiciona o cursor fora do painel
    
    char *text = "Presione qualquer tecla para voltar ao inicio...";
    
    textcolor(14);
    gotoxy((120 - strlen(text)) / 2, 29);
    printf("%s", text);
    getch();
}

void Texto_inicial(){
	char *textos[] = {
		"Seja bem vindo ao jogo!",
		"Seu objetivo final é chegar na Seleção Brasileira",
		"Durante o jogo você irá enfrentar alguns desafios em sua carreira",
		"Diversas experiências e mais de 1 final possível",
		"Aproveite o jogo, e que você tenha uma boa experiência!"
	};
	
	int qnt_textos = sizeof(textos) / sizeof(textos[0]);
	
	int i; 
	
	textcolor(15);
	system("cls");
	
	for (i = 0; i < qnt_textos; i++){
		int tam_texto = strlen(textos[i]);
		
		gotoxy((120 - tam_texto) / 2, 4 + (i*2));
		maquina_escrever(textos[i]);
		printf("\n\n");
	}
	
	char *text = "Pressione qualquer tecla para iniciar o jogo...";
	int tam_texto1 = strlen(text);
	
	gotoxy((120 - tam_texto1) / 2, 29);
	printf("%s", text);
	getch();
}

// Programa principal
void start_game() 
{
    int i;
    habilitarCores();
    setlocale(LC_ALL, "");
    srand(time(NULL));
  
	//Texto_inicial();
    
    system("cls");

    Jogador jogador;
    criar_jogador(&jogador);

    int opcao, escolha;
    
    system("cls");

    while (1) {
    	
        receber_proposta(&jogador); // Chance de receber proposta a cada rodada

        // Menu principal
        
        printf("        %sCARREIRA DO JOGADOR%s\n\n", AZUL, RESET);
        printf("%s1)%s Jogar partida\n", AMARELO, RESET);
        printf("%s2)%s Treinar\n", AMARELO, RESET);
        printf("%s3)%s %s\n", AMARELO, RESET, (jogador.contratado != 1 ? "Peneira" : "Pedir Transferência"));
        printf("%s4)%s Vizualizar status\n", AMARELO, RESET);
        printf("%s5)%s Loja\n", AMARELO, RESET);
        printf("%s6)%s Sair\n", AMARELO, RESET);
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        system("cls");

		if (opcao == 1){
			iniciar_partida(&jogador);
		}
        else if (opcao == 2) {
        	system("cls");
            start_training(&jogador);
        } else if (opcao == 3) {
        	system("cls");
        	gotoxy(1, 0);
            printf("\n%sTIMES DISPONÍVEIS%s\n", ROXO, RESET);
            for (i = 0; i < n_times; i++) {
            	gotoxy(1, 3 + i);
            	if (i > 25)
            		gotoxy(30, -23+i);
            	if (i > 51)
            		gotoxy(60, -49+i);
            	if (i > 77)
            		gotoxy(90, -75+i);
                printf("%d) %s%s%s\n", i + 1, AZUL, times[i].nome, RESET, VERDE, RESET);
            }
            gotoxy(1, 30);
            printf("Escolha o time: ");
            scanf("%d", &escolha);
            if (escolha >= 1 && escolha <= n_times) {
                enviar_proposta(&jogador, times[escolha - 1]);
            }
        } else if (opcao == 4) {
        	system("cls");
            status(&jogador);
        } else if (opcao == 5) {
        	system("cls");
        	open_shop(&jogador);
		}else if (opcao == 6) {
        	system("cls");
            printf("\n%sEncerrando sua carreira...%s\n", VERMELHO, RESET);
            break;
        } else {
            printf("%sOpção inválida!%s\n", VERMELHO, RESET);
            Sleep(1000);
        }
    }
}

#endif
