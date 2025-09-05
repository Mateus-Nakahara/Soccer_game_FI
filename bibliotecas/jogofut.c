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
    int personagem_roupas[];
} Jogador;

// Lista de times disponíveis
Time times[] = {               // Escolhe time aleatório
    {"Flamengo", 98}, // Nome do time e a dificuldade de entrar (De 0 - 100)
	{"Palmeiras", 97},
	{"Corinthians", 95},
	{"São Paulo", 94},
	{"Fluminense", 92},
	{"Vasco da Gama", 90},
	{"Grêmio", 90},
	{"Internacional", 89},
	{"Atlético Mineiro", 88},
	{"Cruzeiro", 87},
	{"Athletico Paranaense", 86},
	{"Botafogo", 85},
	{"Santos", 84},
	{"Red Bull Bragantino", 82},
	{"Bahia", 80},
	{"Fortaleza", 78},
	{"Coritiba", 75},
	{"Goiás", 73},
	{"Sport Recife", 70},
	{"Ceará", 68},
	{"Vitória", 67},
	{"América Mineiro", 65},
	{"Juventude", 62},
	{"Avaí", 60},
	{"Ponte Preta", 58}
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
	    srand(time(NULL));
	    if (strcmp(j->posicao, "Atacante") == 0 || strcmp(j->posicao, "Meio") == 0 || strcmp(j->posicao, "Zagueiro") == 0 || strcmp(j->posicao, "Goleiro" == 0)){
	    	j->chute = 20 + rand() % 20;
	    	j->fisico = 20 + rand() % 20;
	    	j->moral = 20 + rand() % 20;
	    	j->passe = 20 + rand() % 20;
	    	j->penalti = 20 + rand() % 20;
	    	j->tatica = 20 + rand() % 20;
	    	j->energia = 100;
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
	
		create_person(j->gender);
		
		system("cls");
	
		char *text = "Jogador criado com sucesso!";
	
		gotoxy((120-strlen(text))/2, 10);
		
	    printf("%s%s%s", VERDE, text, RESET);
	    gotoxy((120-strlen(text) - 5)/2, 12);
	    printf("Nome: %s%s%s | Posição: %s%s%s\n",
        AZUL, j->nome, RESET, AMARELO, j->posicao, RESET);
        Sleep(3000);
        break;
	}
}

// Peneira em um time
int peneira(Jogador *j, Time t) {
	system("cls");
    carregamento("Fazendo peneira");
    int chance = rand() % 100;

    // Testa se o jogador passa na peneira
    if (chance > t.dificuldade) {
        j->contratado = 1;
        strcpy(j->time_atual, t.nome);
        j->salario = 1000 * 10;
        printf("\n%sParabéns! Você foi aprovado na peneira do %s!%s\n", VERDE, t.nome, RESET);
        printf("Salário inicial: %sR$ %.2f%s\n", VERDE, j->salario, RESET);
        Sleep(2000);
        return 1;
    } else {
        printf("\n%sInfelizmente, você não foi aprovado na peneira do %s.%s\n", VERMELHO, t.nome, RESET);
        Sleep(2000);
		return 0;
    }
}

// Solicitar transferência para outro time
int transferencia(Jogador *j, Time t) {
	system("cls");
    carregamento("Enviando proposta de transferência");
    int chance = rand() % 100;

    // Testa se a transferência é aceita
    if ((rand() % 100) > t.dificuldade) {
        strcpy(j->time_atual, t.nome);
        j->salario = 2000 * 15;
        printf("\n%sTransferência concluída!%s Você agora joga no %s.\n", VERDE, RESET, t.nome);
        printf("Novo salário: %sR$ %.2f%s\n", VERDE, j->salario, RESET);
        return 1;
    } else {
        printf("\n%sO %s recusou sua proposta de transferência.%s\n", VERMELHO, t.nome, RESET);
        return 0;
    }
    Sleep(2000);
}

// Receber proposta de algum time 
void receber_proposta(Jogador *j) {
	system("cls");
    int chance = rand() % 100;

    // Apenas 10% de chance de aparecer uma proposta
    if (chance < 5) {
        Time t;

        // Garante que o time sorteado NÃO seja o mesmo do jogador
        do {
            t = times[rand() % n_times];
        } while (strcmp(j->time_atual, t.nome) == 0);

        float novo_salario = 2500 * 20;
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
    }
    system("cls");
}

// Mostrar status do jogador
void status(Jogador j) {
	system("cls");
	
	int i;
    
    textcolor(WHITE);
    textbackground(BLACK);

    // Exibe o título do painel
    textcolor(YELLOW);
    gotoxy(12, 2);
    cprintf("CARACTERISTICAS DO JOGADOR");
    gotoxy(80, 2);
    cprintf("ATRIBUTOS DO JOGADOR");
    
    gotoxy(10, 10);
    printf("%d", j.gender);
    
    if (j.gender == 0){
    	personagem_masculino(j.personagem_roupas);
	}
	else if (j.gender == 1){
		personagem_feminino(j.personagem_roupas);
	}

    // Exibe os atributos do jogador
    gotoxy(3, 25);
    cprintf("%sNome: %s%s%s", RESET, VERDE, j.nome, RESET);

    gotoxy(3, 26);
    cprintf("%sPosicao: %s%s%s", RESET, VERDE, j.posicao, RESET);

    gotoxy(3, 27);
    cprintf("%sTime: %s%s%s", RESET, VERDE, j.time_atual, RESET);

    // Posiciona o cursor fora do painel
    
    char *text = "Presione qualquer tecla para voltar ao inicio...";
    
    textcolor(14);
    gotoxy((120 - strlen(text)) / 2, 28);
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
  
   // Texto_inicial();
    
    system("cls");

    Jogador jogador;
    criar_jogador(&jogador);

    int opcao, escolha;
    
    system("cls");

    while (1) {
    	
        receber_proposta(&jogador); // Chance de receber proposta a cada rodada

        // Menu principal
        printf("        %sCARREIRA DO JOGADOR%s\n\n", AZUL, RESET);
        printf("%s1)%s Treinar\n", AMARELO, RESET);
        printf("%s2)%s Fazer peneira em um time\n", AMARELO, RESET);
        printf("%s3)%s Solicitar transferência\n", AMARELO, RESET);
        printf("%s4)%s Ver status\n", AMARELO, RESET);
        printf("%s5)%s Sair\n", AMARELO, RESET);
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        system("cls");

        if (opcao == 1) {
        	system("cls");
            start_training(jogador.energia, jogador.moral, jogador.chute, jogador.penalti, jogador.passe, jogador.fisico, jogador.tatica);
        } else if (opcao == 2) {
        	system("cls");
            printf("\n%sTIMES DISPONÍVEIS%s\n", ROXO, RESET);
            for (i = 0; i < n_times; i++) {
                printf("%d) %s%s%s\n", 
                       i + 1, AZUL, times[i].nome, RESET, VERDE, RESET);
            }
            printf("Escolha o time: ");
            scanf("%d", &escolha);
            if (escolha >= 1 && escolha <= n_times) {
                peneira(&jogador, times[escolha - 1]);
            }
        } else if (opcao == 3) {
        	system("cls");
            if (!jogador.contratado) {
                printf("\n%sVocê ainda não tem contrato!%s\n", VERMELHO, RESET);
                Sleep(1000);
            } else {
                printf("\n%sTIMES DISPONÍVEIS%s\n", ROXO, RESET);
                for (i = 0; i < n_times; i++) {
                    if (strcmp(jogador.time_atual, times[i].nome) != 0) {
                        printf("%d) %s%s%s\n", 
                               i + 1, AZUL, times[i].nome, RESET, VERDE, RESET);
                    }
                }
                printf("Escolha o time: ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= n_times) {
                    transferencia(&jogador, times[escolha - 1]);
                }
            }
        } else if (opcao == 4) {
        	system("cls");
            status(jogador);
        } else if (opcao == 5) {
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
