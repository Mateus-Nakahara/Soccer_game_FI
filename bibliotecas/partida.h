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
    int evento, escolha, chance, sucesso = 0;
    
    evento =  rand() % 3;
    
    if (evento == 0){ // Ataque adversário
	    textcolor(14); printf("\n[%d'] O Adversário esta atacando!\n", minuto); textcolor(15);
	    
		printf("1 - Dar o bote \n2 - Cercar \n3 - Recuar \n4 - Carrinho\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 120 + 1;
		    
		if (escolha == 1 && chance <= 50) sucesso = 1;
		else if (escolha == 2 && chance <= j->fisico) sucesso = 1;
		else if (escolha == 3 && chance <= j->tatica) sucesso = 1;
		else if (escolha == 3 && chance <= j->tatica ) sucesso = 1;
		else if (escolha == 0 || escolha > j->fisico ) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { textcolor(10); printf("Desarme perfeito!\n"); j->acertos++; }
		    
		else { textcolor(12); printf("O atacante passou e marcou gol!\n"); placarAdversario++; j->erros++; }
	}
	else if(evento == 1){
		textcolor(14); printf("\n[%d'] O Goleiro tocou a bola para você!\n", minuto); textcolor(15);
			
		printf("1 - Tocar para os laterais \n2 - Tocar para os meias \n3 - Devolver para o goleiro \n4 - Chutar a bola para frente\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 120 + 1;
		    
		if (escolha == 1 && chance <= j->passe) sucesso = 1;
		else if (escolha == 2 && chance <= j->passe ) sucesso = 1;
		else if (escolha == 3 && chance <= j->passe) sucesso = 1;
		else if (escolha == 4 && chance <= j->passe) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { 
			textcolor(10);
			printf("\nToque perfeito!\n");
			j->acertos++; 
		}
		    
		else { 
			textcolor(12); printf("\nO passe foi interceptado, e vocês tomaram 1 gol!\n");
			placarAdversario++;
			j->erros++; 
		}
	}
	else if(evento == 2){
		textcolor(14); printf("\n[%d'] O adversário cobrou um escanteio!\n", minuto); textcolor(15);
			
		printf("1 - Tentar afastar a bola \n2 - Subir para cabecear \n3 - Utilizar o corpo \n4 - Atrapalahar o atacante\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 120 + 1;
		    
		if (escolha == 1 && chance <= j->chute ) sucesso = 1;
		else if (escolha == 2 && chance <= j->fisico ) sucesso = 1;
		else if (escolha == 3 && chance <= j->fisico ) sucesso = 1;
		else if (escolha == 4 && chance <= j->fisico ) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { 
			textcolor(10);
			printf("\nAção efetuada com sucesso, nenhum gol marcado!\n");
			j->acertos++; 
		}
		    
		else { 
			textcolor(12); printf("\nNada deu certo, e vocês tomaram 1 gol!\n");
			placarAdversario++;
			j->erros++; 
		}
	}
    
    textcolor(15);
    mostrarPlacar();
    
}

void eventoAtacante(Jogador *j, int minuto) {
	int evento, escolha, chance, sucesso = 0;
    evento =  rand() % 2;
    
    if (evento == 0){
	    textcolor(14); printf("\n[%d'] Seu time esta no ataque!\n", minuto); textcolor(15);
	    
		printf("1 - Pedir a bola \n2 - Ir para área \n3 - Não avançar \n4 - Fazer facão\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 120 + 1;
		    
		if (escolha == 1 && chance <= 60) sucesso = 1;
		else if (escolha == 2 && chance <= 50) sucesso = 1;
		else if (escolha == 3 && chance <= 50) sucesso = 1;
		else if (escolha == 3 && chance <= 50) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) {
			textcolor(14); printf("\n[%d'] Você recebeu a bola!\n", minuto); textcolor(15);
			
			printf("1 - Tocar a bola \n2 - Driblar \n3 - Chutar \n4 - Cruzar a bola\n-> ");
			    
			scanf("%d", &escolha);
			    
			chance = rand() % 120 + 1;
			    
			if (escolha == 1 && chance <= 50) sucesso = 1;
			else if (escolha == 2 && chance <= 50) sucesso = 1;
			else if (escolha == 3 && chance <= 50) sucesso = 1;
			else if (escolha == 4 && chance <= 50) sucesso = 1;
			else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
			    
			if (sucesso) { 
				textcolor(10);
				printf("\nJogada perfeita!\n");
				printf("Gol marcado!\n");
				placarTime++;
				j->acertos++; 
			}
			    
			else { 
				textcolor(12); printf("\nA Jogada não deu em nada!\n");
				j->erros++; 
			}
		}
		    
		else { 
			textcolor(12); 
			printf("A Jogada não prosseguiu!\n"); 
			j->erros++; 
		}
	}
	else if(evento == 1){
		textcolor(14); printf("\n[%d'] Seu time cobrou um escanteio!\n", minuto); textcolor(15);
			
		printf("1 - Ficar na 1° trave \n2 - Ficar na 2° trave \n3 - Tentar cabecear \n4 - Aproximar do cobrador\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 120 + 1;
		    
		if (escolha == 1 && chance <= 50) sucesso = 1;
		else if (escolha == 2 && chance <= 50) sucesso = 1;
		else if (escolha == 3 && chance <= 50) sucesso = 1;
		else if (escolha == 4 && chance <= 50) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { 
			textcolor(10);
			printf("\nAção efetuada com sucesso!\n");
			printf("Gol marcado!\n");
			placarTime++;
			j->acertos++; 
		}
		    
		else { 
			textcolor(12); printf("\nO outro time pegou a bola!\n");
			j->erros++; 
		}
	}
    
    textcolor(15);
    mostrarPlacar();
}

void eventoGoleiro(Jogador *j, int minuto) {
	int evento, escolha, chance, sucesso = 0;
    evento =  rand() % 3;
    
    if (evento == 0){
	    textcolor(14); printf("\n[%d'] Você irá sair com a bola!\n", minuto); textcolor(15);
	    
		printf("1 - Tocar para os zagueiros \n2 - Chutar para frente \n3 - Tocar para os meias \n4 - Tocar no mais próximo\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 120 + 1;
		    
		if (escolha == 1 && chance <= j->passe ) sucesso = 1;
		else if (escolha == 2 && chance <= j->chute ) sucesso = 1;
		else if (escolha == 3 && chance <= j->passe ) sucesso = 1;
		else if (escolha == 3 && chance <= j->passe ) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { textcolor(10); printf("Passe efetuado com sucesso!\n"); j->acertos++; }
		    
		else { 
			textcolor(12); 
			printf("%sVocê errou o passe e tomou um gol!%s\n", VERMELHO, RESET); 
			placarAdversario++;
			j->erros++; 
		}
	}
	else if(evento == 1){
		textcolor(14); printf("\n[%d'] O atacante está indo em sua direção!\n", minuto); textcolor(15);
			
		printf("1 - Sair do gol \n2 - Esperar\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 120 + 1;
		    
		if (escolha == 1 && chance <= j->tatica ) sucesso = 1;
		else if (escolha == 2 && chance <= j->fisico ) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { 
			textcolor(10);
			printf("\nÓtima decisão! Defesa realizada.\n");
			j->acertos++; 
		}
		    
		else { 
			textcolor(12); printf("\nVocê não defendeu!\n");
			placarAdversario++;
			j->erros++; 
		}
	}
	else if(evento == 2){
		textcolor(14); printf("\n[%d'] Um Penalty foi marcado!\n", minuto); textcolor(15);
			
		printf("1 - Ir para a direita \n2 - Ir para a esquerda \n3 - Ficar no meio \n4 - Esperar o jogador chutar\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 140 + 1;
		    
		if (escolha == 1 && chance <= j->tatica) sucesso = 1;
		else if (escolha == 2 && chance <= j->tatica) sucesso = 1;
		else if (escolha == 3 && chance <= j->tatica) sucesso = 1;
		else if (escolha == 4 && chance <= j->tatica) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { 
			textcolor(10);
			printf("\nVocê decidiu corretamente e defendeu!\n");
			j->acertos++; 
		}
		    
		else { 
			textcolor(12); printf("\nO outro time marcou um gol!\n");
			placarAdversario++;
			j->erros++; 
		}
	}
    
    textcolor(15);
    mostrarPlacar();
}

void eventoMeia(Jogador *j, int minuto) {
    int evento, escolha, chance, sucesso = 0;
    evento =  rand() % 3;
    
    if (evento == 0){
	    textcolor(14); printf("\n[%d'] A bola está no meio campo!\n", minuto); textcolor(15);
	    
		printf("1 - Lançamento \n2 - Fazer tabela \n3 - Conduzir a bola \n4 - Tocar a bola\n-> ");
		
		scanf("%d", &escolha);
		
		chance = rand() % 100 + 1;
		    
		if (escolha == 1 && chance <= j->chute ) sucesso = 1;
		else if (escolha == 2 && chance <= j->passe ) sucesso = 1;
		else if (escolha == 3 && chance <= j->tatica ) sucesso = 1;
		else if (escolha == 3 && chance <= j->passe ) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { 
			textcolor(10); printf("Você tomou uma ótima decisão e um gol foi realizado!\n");
			placarTime++;
			j->acertos++; 
		}
		    
		else { 
			textcolor(12); 
			printf("%sVocê errou e tomou um gol de contra-ataque!%s\n", VERMELHO, RESET); 
			placarAdversario++;
			j->erros++; 
		}
	}
	else if(evento == 1){
		textcolor(14); printf("\n[%d'] Você recebeu a bola na entrada da área!\n", minuto); textcolor(15);
			
		printf("1 - Chutar de primeira \n2 - Ajeitar e chutar\n3- Passe em profundidade\n4- Driblar e chutar\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 120 + 1;
		    
		if (escolha == 1 && chance <= j->chute ) sucesso = 1;
		else if (escolha == 2 && chance <= j->chute) sucesso = 1;
		else if (escolha == 3 && chance <= j->passe ) sucesso = 1;
		else if (escolha == 4 && chance <= j->fisico ) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { 
			textcolor(10);
			printf("\nChute perfeito! Gol realizado\n");
			placarTime++;
			j->acertos++; 
		}
		    
		else { 
			textcolor(12); printf("\nO seu chute foi interceptado!\n");
			j->erros++; 
		}
	}
	else if(evento == 2){
		textcolor(14); printf("\n[%d'] Os adversários te cercaram!\n", minuto); textcolor(15);
			
		printf("1 - Driblar \n2 - Tocar para trás \n3 - Tentar lançamento \n4 - Segurar a bola\n-> ");
		    
		scanf("%d", &escolha);
		    
		chance = rand() % 120 + 1;
		    
		if (escolha == 1 && chance <= j->tatica ) sucesso = 1;
		else if (escolha == 2 && chance <= j->passe ) sucesso = 1;
		else if (escolha == 3 && chance <= j->chute ) sucesso = 1;
		else if (escolha == 4 && chance <= 80) sucesso = 1;
		else if (escolha == 0 || escolha > 4) printf("\n%sVocê não se decidiu!%s\n", VERMELHO, RESET);
		    
		if (sucesso) { 
			textcolor(10);
			printf("\nVocê decidiu corretamente e defendeu!\n");
			placarTime++;
			j->acertos++; 
		}
		    
		else { 
			textcolor(12); printf("\nVocê perdeu a bola e tomou um gol!\n");
			placarAdversario++;
			j->erros++; 
		}
	}
    
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
		printf("\n[%d'] O jogo segue...\n", tempo);
	    if (rand() % 30 == 0) {
	        if (strcmp(j->posicao, "zagueiro") == 0) eventoZagueiro(j, tempo);
	        else if (strcmp(j->posicao, "atacante") == 0) eventoAtacante(j, tempo);
	        else if (strcmp(j->posicao, "goleiro") == 0) eventoGoleiro(j, tempo);
	        else eventoMeia(j, tempo);
	    }
	    else if (rand() % 40 == 1){
	    	printf("\n%sSEU TIME MARCOU 1 GOL!%s\n", VERDE, RESET);
	    	placarTime++;
	    	mostrarPlacar();
		}
		else if (rand() % 40 == 1){
	    	printf("\n%sSEU TIME TOMOU 1 GOL!%s\n", VERDE, RESET);
	    	placarAdversario++;
	    	mostrarPlacar();
		}
	    delay(400);
	}
	
	textcolor(14); printf("\n FIM DE JOGO \n");
	textcolor(10); printf("Acertos: %d\n", j->acertos);
	textcolor(12); printf("Erros: %d\n", j->erros);
	textcolor(13); printf("PLACAR FINAL: Voce %d x %d Adversario\n", placarTime, placarAdversario);
	receber_salario(j);
}

void receber_salario(Jogador *j) {
	if (j->contratado){
		j->partidas_jogadas += 1;

	    if (j->partidas_jogadas % 5 == 0) {
			system("cls");
	        j->dinheiro += j->salario;
	        printf("%s completou %s%d%s partidas -> salário de %sR$ %.2f%s depositado!\n",
	            j->nome, VERDE, j->partidas_jogadas, RESET, VERDE, j->salario, RESET);
	            Sleep(2000);
	    }	
	}
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
	if (j->lesionado || j->energia <= 0){
		printf("Você não está em condições para jogar...");
		j->moral-=2;
	}
	else{
		placarTime = 0, placarAdversario = 0;
		if (j->contratado != 0){
			partida(j);
		}
		else{
			sem_time(j);
		}	
	}
	printf("\n\nPressione qualquer tecla para voltar ao inicio...");
	getch();
}

#endif
