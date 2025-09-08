#ifndef TREINAR_HABILIDADES
#define TREINAR_HABILIDADES

#include "jogofut.h"

int lesionado=0;

// Função para animar mensagens
void animar(const char* msg, int linha, int cor){
    int i;
	
	gotoxy(5, linha);
    textcolor(cor);
    for(i=0; msg[i]!='\0'; i++){
        cprintf("%c", msg[i]);
        Sleep(50);
    }
    Sleep(300);
}

// Barra simples sem animação
void barra(int valor, int x, int y, const char* nome, int cor){
    int i;
	
	gotoxy(x, y);
    textcolor(cor);
    cprintf("%s: [", nome);
    int barras = valor/2;
    for(i=0;i<50;i++){
        if(i<barras) cprintf("=");
        else cprintf(" ");
    }
    cprintf("] %d", valor);
}

// Mostrar status
void mostrar_status(Jogador *j, int x, int y){
    clrscr();

    barra(j->energia, x, y, "Energia", 12);
    barra(j->moral, x, y + 1, "Moral", 11);
    barra(j->chute, x, y + 2, "Chute", 12);
    barra(j->passe, x, y + 3, "Passe", 13);
    barra(j->penalti, x, y + 4, "Penalti", 9);
    barra(j->fisico, x, y + 5, "Fisico", 10);
    barra(j->tatica, x, y + 6, "Tatica", 14);
    gotoxy(x, y + 8);
    printf("SALDO: %sR$%2d%s          SAUDE: %s%2d%s", VERDE, j->dinheiro, RESET, VERMELHO, j->saude, RESET);

    if(lesionado){
        gotoxy(x,y + 9); textcolor(12); cprintf("!! VOCE ESTA LESIONADO !!");
    }
}

// Evento aleatório
void evento_aleatorio(Jogador *j, const char* treino){
    int chance = rand()%100;

    // Reduz chance de lesão com base no físico
    int chance_lesao = 10 - (j->fisico/20); 
    if(chance_lesao < 2) chance_lesao = 2; // mínimo 2%

    if(chance < chance_lesao){
        lesionado=1; animar("Voce se machucou durante o treino!",16,12);
    }
    else if(chance<20){
        j->moral -= 2; if(j->moral<0) j->moral=0; animar("Treino dificil! Moral -2",16,13);
    }
    else if(chance<30){
        if(strcmp(treino,"Chute")==0) j->chute+=1;
        else if(strcmp(treino,"Passe")==0) j->passe+=1;
        else if(strcmp(treino,"Penalti")==0) j->penalti+=1;
        else if(strcmp(treino,"Fisico")==0) j->fisico+=1;
        else if(strcmp(treino,"Tatica")==0) j->tatica+=1;
        else if(strcmp(treino,"Falta")==0) j->chute+=1;
        animar("Treino perfeito! Bonus +1 habilidade",16,10);
    }
}

// Treinos existentes
void treinar_chute(Jogador *j){
    if(lesionado){ animar("Voce esta lesionado e nao pode treinar chute!",13,12); return; }
    clrscr();
    animar("Treinando CHUTE!",2,12);
    gotoxy(10,5); cprintf("      O");
    gotoxy(10,6); cprintf("     /|\\");
    gotoxy(10,7); cprintf("     / \\");
    gotoxy(10,8); cprintf("      o ---> GOL!!!");
    Sleep(1500);

    j->energia -= 10;

    int goleiro = rand()%100;
    int chance_gol = j->chute + j->fisico/2;
    if(goleiro > chance_gol){
        animar("O goleiro defendeu! Habilidade diminuida",15,12);
        j->chute -= 1; if(j->chute<0) j->chute=0;
    } else {
        animar("GOL! Habilidade aumentada",15,10);
        j->chute += 3;
        j->moral += 1; if(j->moral>100) j->moral=100;
    }
    barra(j->chute, 5, 17,"Chute", 12);
    evento_aleatorio(j, "Chute");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

void treinar_penalti(Jogador *j){
    if(lesionado){
        animar("Voce esta lesionado e nao pode treinar penalti!",13,12);
        return;
    }

    clrscr();
    animar("Treinando PENALTI!",2,9);
    gotoxy(10,5); cprintf("      O");
    gotoxy(10,6); cprintf("     /|\\");
    gotoxy(10,7); cprintf("     / \\");
    gotoxy(10,8); cprintf("      o");
    gotoxy(10,9); cprintf("    [GOLEIRO]");
    Sleep(1500);
    j->energia -=9;

    char escolha;
    do{
        gotoxy(5,11); textcolor(14); cprintf("Escolha onde bater:");
        gotoxy(5,12); cprintf("E - Esquerda, M - Meio, D - Direita : ");
        scanf(" %c",&escolha);
        escolha = toupper(escolha);
    } while(escolha != 'E' && escolha != 'M' && escolha != 'D');

    char goleiro_dir;
    int g = rand()%3;
    if(g==0) goleiro_dir='E';
    else if(g==1) goleiro_dir='M';
    else goleiro_dir='D';

    if(escolha == goleiro_dir){
        animar("O goleiro defendeu! Habilidade diminuida",15,12);
        j->penalti -= 1; if(j->penalti<0) j->penalti=0;
    } else {
        animar("GOL de penalti! Habilidade aumentada",15,10);
        j->penalti += 3;
        j->moral += 1; if(j->moral>100) j->moral=100;
    }
    barra(j->penalti, 5, 17,"Penalti",9);
    evento_aleatorio(j, "Penalti");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

void treinar_passe(Jogador *j){
    if(lesionado){ animar("Voce esta lesionado e nao pode treinar passe!",13,12); return; }
    clrscr();
    animar("Treinando PASSE!",2,13);
    gotoxy(10,5); cprintf("  O      ---> o");
    gotoxy(10,6); cprintf(" /|\\");
    gotoxy(10,7); cprintf(" / \\");
    Sleep(1500);
    j->energia -=8; j->passe +=2; j->moral +=1; if(j->moral>100) j->moral=100;
    animar("Passe melhorou! +2 de habilidade",15,10);
    barra(j->passe, 5, 17,"Passe",13);
    evento_aleatorio(j, "Passe");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

void treinar_fisico(Jogador *j){
    if(lesionado){
        animar("Voce esta lesionado e nao pode treinar fisico!",13,12);
        return;
    }
    
    clrscr();
    animar("Treinando FISICO!",2,10);
    gotoxy(10,5); cprintf("   O");
    gotoxy(10,6); cprintf("  /|\\");
    gotoxy(10,7); cprintf("  / \\");
    gotoxy(10,8); cprintf("Correndo...");
    Sleep(1500);

    j->energia -=12; 
    j->fisico +=4;
    j->moral +=1; if(j->moral>100) j->moral=100;
    animar("Fisico melhorou! +4 de habilidade",15,10);
    barra(j->fisico, 5, 17, "Fisico",10);
    evento_aleatorio(j, "Fisico");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

void treinar_tatica(Jogador *j){
    if(lesionado){ animar("Voce esta lesionado e nao pode treinar tatica!",13,12); return; }
    clrscr();
    animar("Treinando TATICA!",2,14);
    int sistema;
    do{
        gotoxy(5,5); cprintf("Escolha o sistema tatico:");
        gotoxy(5,6); cprintf("1 - 4-4-2");
        gotoxy(5,7); cprintf("2 - 3-5-2");
        gotoxy(5,8); cprintf("3 - 5-3-2");
        gotoxy(5,9); cprintf("Opcao: ");
        scanf("%d",&sistema);
        fflush(stdin);
        if(sistema < 1 || sistema > 3){
            gotoxy(5,10); textcolor(12); cprintf("Opcao invalida! Tente novamente.");
        }
    } while(sistema < 1 || sistema > 3);

    switch(sistema){
        case 1: j->tatica+=2; j->moral+=2; j->energia-=7; animar("Sistema 4-4-2 treinado! +2 de Tatica",15,10); break;
        case 2: j->tatica+=3; j->moral+=3; j->energia-=9; animar("Sistema 3-5-2 treinado! +3 de Tatica",15,10); break;
        case 3: j->tatica+=1; j->moral+=1; j->energia-=5; animar("Sistema 5-3-2 treinado! +1 de Tatica",15,10); break;
    }
    if(j->moral>100) j->moral=100;
    barra(j->tatica, 5, 17,"Tatica",14);
    evento_aleatorio(j, "Tatica");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

// === NOVO TREINO: FALTAS ===
void treinar_falta(Jogador *j){
    if(lesionado){
        animar("Voce esta lesionado e nao pode treinar faltas!",13,12);
        return;
    }

    clrscr();
    animar("Treinando FALTAS!",2,14);

    int distancia = 5 + rand()%66; // 5 a 70m
    gotoxy(5,5); cprintf("Distancia da falta: %d metros", distancia);

    char escolha;
    do{
        gotoxy(5,7); textcolor(11); cprintf("Escolha o tipo de chute:");
        gotoxy(5,8); cprintf("C - Colocado");
        gotoxy(5,9); cprintf("T - Trivela");
        gotoxy(5,10); cprintf("F - Forca");
        gotoxy(5,11); cprintf("Opcao: ");
        scanf(" %c",&escolha);
        escolha = toupper(escolha);
    } while(escolha != 'C' && escolha != 'T' && escolha != 'F');

    j->energia -= 12;

    // Chance de acerto depende de chute + tatica + penalti + distancia
    int habilidade = (j->chute + j->penalti + j->tatica/2);
    int dificuldade = distancia + rand()%30;

    if(escolha=='C') habilidade += 5;   // mais preciso
    if(escolha=='T') habilidade += 3;   // equilibrado
    if(escolha=='F') habilidade += 1;   // força bruta mas menos controle

    if(habilidade > dificuldade){
        animar("GOOOL de falta! Habilidade aumentada",15,10);
        j->chute += 2;
        j->penalti += 1;
        j->moral += 2; if(j->moral>100) j->moral=100;
    } else {
        animar("A bola passou longe... Habilidade diminuiu!",15,12);
        if(j->chute>0) j->chute -= 1;
        if(j->penalti>0) j->penalti -= 1;
        j->moral -= 1; if(j->moral<0) j->moral=0;
    }

    barra(j->chute, 5, 17,"Chute",12);
    barra(j->penalti, 5, 18,"Penalti",9);

    evento_aleatorio(j, "Falta");

    gotoxy(5,20); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

// Treino aleatório atualizado (inclui Faltas)
void treino_aleatorio(Jogador *j){
    int op = 1+rand()%6; // agora vai de 1 a 6
    switch(op){
        case 1: treinar_chute(j); break;
        case 2: treinar_passe(j); break;
        case 3: treinar_penalti(j); break;
        case 4: treinar_fisico(j); break;
        case 5: treinar_tatica(j); break;
        case 6: treinar_falta(j); break;
    }
}

// Descanso
void descansar_completo(Jogador *j){
    clrscr();
    animar("=== DESCANSO ===",2,14);
    
    int ganho = rand()%30+10;

    j->energia += ganho; if(j->energia>100) j->energia=100;
    if(j->chute>0) j->chute -=1; if(j->chute<0) j->chute=0;
    if(j->penalti>0) j->penalti -=1; if(j->penalti<0) j->penalti=0;
    if(j->passe>0) j->passe -=1; if(j->passe<0) j->passe=0;
    if(j->fisico>0) j->fisico -=1; if(j->fisico<0) j->fisico=0;
    if(j->tatica>0) j->tatica -=1; if(j->tatica<0) j->tatica=0;

    mostrar_status(j, 5, 3);

    gotoxy(5,12); textcolor(11); cprintf("Energia aumentou em +%d!", ganho);
    gotoxy(5,13); textcolor(12); cprintf("Chute, Penalti, Passe, Fisico e Tatica diminuiram em -1!");
    gotoxy(5,14); textcolor(10); cprintf("Moral nao foi alterada.");

    gotoxy(5,16); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();

    lesionado = 0; // libera treinos
}

// Tela de treinos
void start_training(Jogador *j){
    srand(time(NULL));
    int opcao;
    
    system("cls");
    
    do{
        mostrar_status(j, 5, 3);

        if(!lesionado){
            gotoxy(5,17); textcolor(11); cprintf("Escolha um treino:");
            gotoxy(5,18); cprintf("1 - Chute");
            gotoxy(5,19); cprintf("2 - Passe");
            gotoxy(5,20); cprintf("3 - Penalti");
            gotoxy(5,21); cprintf("4 - Fisico");
            gotoxy(5,22); cprintf("5 - Tatica");
            gotoxy(5,23); cprintf("6 - Aleatorio");
            gotoxy(5,24); cprintf("7 - Falta");
            gotoxy(5,25); cprintf("8 - Decansar");
            gotoxy(5,26); cprintf("0 - Sair");
            gotoxy(5,27); textcolor(14); cprintf("Opcao: ");
            scanf("%d",&opcao);
            fflush(stdin);
        } else {
            do{
                gotoxy(5,24); cprintf("8 - Descansar (obrigatorio por lesao)");
                gotoxy(5,25); cprintf("0 - Sair");
                gotoxy(5,26); textcolor(12); cprintf("Voce esta lesionado! Somente descanso disponivel.");
                gotoxy(5,27); textcolor(14); cprintf("Opcao: ");
                scanf("%d",&opcao); fflush(stdin);
                if(opcao != 8 && opcao != 0){
                    gotoxy(5,28); textcolor(12); cprintf("Opcao invalida! Somente descanso disponivel.");
                }
            }while(opcao != 8 && opcao != 0);
        }

        switch(opcao){
            case 1: treinar_chute(j); break;
            case 2: treinar_passe(j); break;
            case 3: treinar_penalti(j); break;
            case 4: treinar_fisico(j); break;
            case 5: treinar_tatica(j); break;
            case 6: treino_aleatorio(j); break;
            case 7: treinar_falta(j); break;
            case 8: descansar_completo(j); break;
            case 0: break;
            default: gotoxy(5,29); textcolor(12); cprintf("Opcao invalida!"); Sleep(1000); break;
        }
    } while(opcao!=0);
}

#endif

