#ifndef PARTIDA_H
#define PARTIDA_H

#include "jogofut.h"

void delay(int ms) { Sleep(ms); }

int placarTime = 0, placarAdversario = 0;

void mostrarPlacar() {
    textcolor(14);
    printf("\nPLACAR: Voce %d x %d Adversario\n", placarTime, placarAdversario);
    textcolor(15);
}

void eventoZagueiro(Jogador *j, int minuto) {
    int escolha, chance, sucesso = 0;
    textcolor(14); printf("\n[%d'] O adversario esta atacando!\n", minuto);
    textcolor(15);
    printf("1 - Dar o bote \n2 - Cercar \n3 - Recuar \n-> ");
    scanf("%d", &escolha);
    chance = rand() % 100 + 1;
    if (escolha == 1 && chance <= 50) sucesso = 1;
    	else if (escolha == 2 && chance <= 70) sucesso = 1;
    	else if (escolha == 3 && chance <= 90) sucesso = 1;
    if (sucesso) { textcolor(10); printf("Desarme perfeito!\n"); j->acertos++; }
    	else { textcolor(12); printf("O atacante passou e marcou gol!\n"); placarAdversario++; j->erros++; }
    textcolor(15);
    mostrarPlacar();
}

void eventoAtacante(Jogador *j, int minuto) {
    int escolha, chance, sucesso = 0;
    textcolor(13); printf("\n[%d'] Seu time esta no ataque!\n", minuto);
    textcolor(15);
    printf("1 - Chutar \n2 - Driblar\n3 - Passar \n-> ");
    scanf("%d", &escolha);
    chance = rand() % 100 + 1;
    if (escolha == 1 && chance <= 40) sucesso = 1;
    	else if (escolha == 2 && chance <= 60) sucesso = 1;
    	else if (escolha == 3 && chance <= 80) sucesso = 1;
    if (sucesso) { textcolor(10); printf("Gol! Jogada perfeita!\n"); placarTime++; j->acertos++; }
    	else { textcolor(12); printf("Perdeu a bola.\n"); j->erros++; }
    textcolor(15);
    mostrarPlacar();
}

void eventoGoleiro(Jogador *j, int minuto) {
    int escolha, chance, sucesso = 0;
    textcolor(11); printf("\n[%d'] O atacante esta cara a cara!\n", minuto);
    textcolor(15);
    printf("1 - Sair do gol \n2 - Esperar \n3 - Adivinhar lado \n-> ");
    scanf("%d", &escolha);
    chance = rand() % 100 + 1;
    if (escolha == 1 && chance <= 60) sucesso = 1;
    	else if (escolha == 2 && chance <= 70) sucesso = 1;
    	else if (escolha == 3 && chance <= 50) sucesso = 1;
    if (sucesso) { textcolor(10); printf("Defesa espetacular!\n"); j->acertos++; }
    	else { textcolor(12); printf("Gol do adversario!\n"); placarAdversario++; j->erros++; }
    textcolor(15);
    mostrarPlacar();
}

void eventoMeia(Jogador *j, int minuto) {
    int escolha, chance, sucesso = 0;
    textcolor(9); printf("\n[%d'] A bola esta no meio de campo!\n", minuto);
    textcolor(15);
    printf("1 - Lancar \n2 - Segurar \n3 - Chutar \n-> ");
    scanf("%d", &escolha);
    chance = rand() % 100 + 1;
    if (escolha == 1 && chance <= 60) sucesso = 1;
    	else if (escolha == 2 && chance <= 80) sucesso = 1;
    	else if (escolha == 3 && chance <= 30) sucesso = 1;
    if (sucesso) { textcolor(10); printf("Boa jogada! Gol possivel!\n"); if(rand()%2==0){ placarTime++; printf("Gol marcado!\n"); } j->acertos++; }
    	else { textcolor(12); printf("Perdeu a bola.\n"); j->erros++; }
    textcolor(15);
    mostrarPlacar();
}

void partida(Jogador *j){
	srand(time(NULL));
	
	int tempo;
	j->acertos = 0; j->erros = 0;
	
	textcolor(14); printf("\n SIMULADOR DE PARTIDA \n");
	
	textcolor(11); printf("\nBem-vindo, %s! Posicao: %s \n\n", j->nome, j->posicao); textcolor(15);
	
	for (tempo = 1; tempo <= 90; tempo++) {
		printf("[%d'] O jogo segue...\n", tempo);
	    if (rand() % 12 == 0) {
	        if (strcmp(j->posicao, "zagueiro") == 0) eventoZagueiro(j, tempo);
	            else if (strcmp(j->posicao, "atacante") == 0) eventoAtacante(j, tempo);
	            else if (strcmp(j->posicao, "goleiro") == 0) eventoGoleiro(j, tempo);
	           	else eventoMeia(j, tempo);
	    }
	    delay(200);
	}
	
	textcolor(14); printf("\n FIM DE JOGO \n");
	textcolor(10); printf("Acertos: %d\n", j->acertos);
	textcolor(12); printf("Erros: %d\n", j->erros);
	textcolor(13); printf("PLACAR FINAL: Voce %d x %d Adversario\n", placarTime, placarAdversario);
}


void sem_time(Jogador *j){
	srand(time(NULL));
	int chance_partida_aparecer = rand() % 100;
	
	if (chance_partida_aparecer < 30){
		partida(j);
	}
	else{
		printf("%sVocê não possui partidas para jogar...%s", AMARELO, RESET);	
	}
}

void iniciar_partida(Jogador *j) {
	if (j->contratado != 0){
		partida(j);
	}
	else{
		sem_time(j);
	}
	printf("\n\nPressione qualquer tecla para voltar ao inicio...");
	getch();
}

#endif
