#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define RESET   "\033[0m"
#define VERMELHO "\033[1;31m"
#define VERDE   "\033[1;32m"
#define AMARELO "\033[1;33m"
#define AZUL    "\033[1;34m"
#define ROXO    "\033[1;35m"
#define CIANO   "\033[1;36m"
#define BRANCO  "\033[1;37m"

typedef struct {
    char nome[32];
    int forca;
} Time;

typedef struct {
    char nome[32];
    char posicao[32];
    int habilidade;
    int contratado;
    char time_atual[32];
    float salario;
    int historico[10];  
    int jogos;
} Jogador;

Time times[] = {
    {"Corinthians", 70},
    {"Santos", 65},
    {"S�o Paulo", 75},
    {"Palmeiras", 80},
    {"Noroeste", 50}
};
int n_times = sizeof(times) / sizeof(times[0]);

void carregamento(const char *msg) {
    printf("\n%s%s%s", CIANO, msg, RESET);
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        for (volatile long j = 0; j < 50000000; j++);
    }
    printf("\n");
}

void criar_jogador(Jogador *j) {
    printf("\n%sCRIA��O DO JOGADOR%s\n", ROXO, RESET);
    printf("Digite seu nome: ");
    scanf(" %[^\n]", j->nome);
    printf("Escolha sua posi��o (%sAtacante%s / %sMeio%s / %sDefesa%s / %sGoleiro%s): ",
           AMARELO, RESET, AMARELO, RESET, AMARELO, RESET, AMARELO, RESET);
    scanf(" %[^\n]", j->posicao);

    srand(time(NULL));
    if (strcmp(j->posicao, "Atacante") == 0) j->habilidade = 60 + rand() % 20;
    else if (strcmp(j->posicao, "Meio") == 0) j->habilidade = 55 + rand() % 25;
    else if (strcmp(j->posicao, "Defesa") == 0) j->habilidade = 50 + rand() % 30;
    else j->habilidade = 45 + rand() % 35;

    j->contratado = 0;
    strcpy(j->time_atual, "Nenhum");
    j->salario = 0;
    j->jogos = 0;

    printf("\n%sJogador criado com sucesso!%s\n", VERDE, RESET);
    printf("Nome: %s%s%s | Posi��o: %s%s%s | Habilidade inicial: %s%d%s\n",
           AZUL, j->nome, RESET, AMARELO, j->posicao, RESET, VERDE, j->habilidade, RESET);
}

void treinar(Jogador *j) {
    carregamento("Treinando");
    int resultado = rand() % 100;
    if (resultado < 70) {
        int ganho = 1 + rand() % 5;
        j->habilidade += ganho;
        printf("\n%sVoc� treinou duro e ganhou +%d de habilidade!%s (Atual: %s%d%s)\n",
               VERDE, ganho, RESET, VERDE, j->habilidade, RESET);
    } else {
        printf("\n%sO treino foi cansativo e voc� n�o evoluiu desta vez.%s (Habilidade: %d)\n",
               AMARELO, RESET, j->habilidade);
    }
}

int peneira(Jogador *j, Time t) {
    carregamento("Fazendo peneira");
    int chance = rand() % 100;
    if (j->habilidade + (rand() % 30) > t.forca + chance) {
        j->contratado = 1;
        strcpy(j->time_atual, t.nome);
        j->salario = 1000 + j->habilidade * 10;
        printf("\n%sParab�ns! Voc� foi aprovado na peneira do %s!%s\n", VERDE, t.nome, RESET);
        printf("Sal�rio inicial: %sR$ %.2f%s\n", VERDE, j->salario, RESET);
        return 1;
    } else {
        printf("\n%sInfelizmente, voc� n�o foi aprovado na peneira do %s.%s\n", VERMELHO, t.nome, RESET);
        return 0;
    }
}

int transferencia(Jogador *j, Time t) {
    carregamento("Enviando proposta de transfer�ncia");
    int chance = rand() % 100;
    if (j->habilidade + (rand() % 30) > t.forca + chance) {
        strcpy(j->time_atual, t.nome);
        j->salario = 2000 + j->habilidade * 15;
        printf("\n%sTransfer�ncia conclu�da!%s Voc� agora joga no %s.\n", VERDE, RESET, t.nome);
        printf("Novo sal�rio: %sR$ %.2f%s\n", VERDE, j->salario, RESET);
        return 1;
    } else {
        printf("\n%sO %s recusou sua proposta de transfer�ncia.%s\n", VERMELHO, t.nome, RESET);
        return 0;
    }
}

void receber_proposta(Jogador *j) {
    int chance = rand() % 100;
    if (chance < 30) {
        Time t = times[rand() % n_times];
        if (strcmp(j->time_atual, t.nome) != 0) {
            float novo_salario = 2500 + j->habilidade * 20;
            carregamento("Voc� recebeu uma proposta!");
            printf("\n%sO time %s fez uma proposta para voc�!%s\n", CIANO, t.nome, RESET);
            printf("Sal�rio oferecido: %sR$ %.2f%s\n", VERDE, novo_salario, RESET);
            printf("Deseja aceitar? (%s1 = Sim%s / %s0 = N�o%s): ", VERDE, RESET, VERMELHO, RESET);
            int op;
            scanf("%d", &op);
            if (op == 1) {
                strcpy(j->time_atual, t.nome);
                j->salario = novo_salario;
                j->contratado = 1;
                printf("\n%sContrato assinado com %s!%s Novo sal�rio: %sR$ %.2f%s\n",
                       VERDE, t.nome, RESET, VERDE, j->salario, RESET);
            } else {
                printf("\n%sVoc� recusou a proposta.%s\n", AMARELO, RESET);
            }
        }
    }
}

void status(Jogador j) {
    printf("\n%sSTATUS DO JOGADOR%s\n", ROXO, RESET);
    printf("Nome: %s%s%s\n", AZUL, j.nome, RESET);
    printf("Posi��o: %s%s%s\n", AMARELO, j.posicao, RESET);
    printf("Habilidade: %s%d%s\n", VERDE, j.habilidade, RESET);
    if (j.contratado) {
        printf("Time atual: %s%s%s\n", CIANO, j.time_atual, RESET);
        printf("Sal�rio: %sR$ %.2f%s\n", VERDE, j.salario, RESET);
    } else {
        printf("%sSem contrato.%s\n", VERMELHO, RESET);
    }
    printf("Jogos disputados: %s%d%s\n", BRANCO, j.jogos, RESET);
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    Jogador jogador;
    criar_jogador(&jogador);

    int opcao, escolha;

    while (1) {
        receber_proposta(&jogador);

        printf("        %sCARREIRA DO JOGADOR%s\n", AZUL, RESET);
        printf("%s1)%s Treinar\n", AMARELO, RESET);
        printf("%s2)%s Fazer peneira em um time\n", AMARELO, RESET);
        printf("%s3)%s Solicitar transfer�ncia\n", AMARELO, RESET);
        printf("%s4)%s Ver status\n", AMARELO, RESET);
        printf("%s5)%s Sair\n", AMARELO, RESET);
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            treinar(&jogador);
        } else if (opcao == 2) {
            printf("\n%sTIMES DISPON�VEIS%s\n", ROXO, RESET);
            for (int i = 0; i < n_times; i++) {
                printf("%d) %s%s%s (For�a: %s%d%s)\n", i + 1, AZUL, times[i].nome, RESET, VERDE, times[i].forca, RESET);
            }
            printf("Escolha o time: ");
            scanf("%d", &escolha);
            if (escolha >= 1 && escolha <= n_times) {
                peneira(&jogador, times[escolha - 1]);
            }
        } else if (opcao == 3) {
            if (!jogador.contratado) {
                printf("\n%sVoc� ainda n�o tem contrato!%s\n", VERMELHO, RESET);
            } else {
                printf("\n%sTIMES DISPON�VEIS%s\n", ROXO, RESET);
                for (int i = 0; i < n_times; i++) {
                    if (strcmp(jogador.time_atual, times[i].nome) != 0) {
                        printf("%d) %s%s%s (For�a: %s%d%s)\n", i + 1, AZUL, times[i].nome, RESET, VERDE, times[i].forca, RESET);
                    }
                }2
                printf("Escolha o time: ");
                scanf("%d", &escolha);
                if (escolha >= 1 && escolha <= n_times) {
                    transferencia(&jogador, times[escolha - 1]);
                }
            }
        } else if (opcao == 4) {
            status(jogador);
        } else if (opcao == 5) {
            printf("\n%sEncerrando sua carreira...%s\n", VERMELHO, RESET);
            break;
        } else {
            printf("%sOp��o inv�lida!%s\n", VERMELHO, RESET);
        }
    }

    return 0;
}
