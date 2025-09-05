#ifndef TREINAR_HABILIDADES
#define TREINAR_HABILIDADES

int energia, moral, chute, penalti, passe, fisico, tatica;
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
void barra(int valor, int linha, const char* nome, int cor){
    int i;
	
	gotoxy(5, linha);
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
void mostrar_status(){
    clrscr();
    gotoxy(5,1); textcolor(14); cprintf("=== STATUS DO JOGADOR ===");

    barra(energia,3,"Energia",12);
    barra(moral,4,"Moral",11);
    barra(chute,5,"Chute",12);
    barra(passe,6,"Passe",13);
    barra(penalti,7,"Penalti",9);
    barra(fisico,8,"Fisico",10);
    barra(tatica,9,"Tatica",14);

    if(lesionado){
        gotoxy(5,11); textcolor(12); cprintf("!! VOCE ESTA LESIONADO !!");
    }
}

// Evento aleatório
void evento_aleatorio(const char* treino){
    int chance = rand()%100;
    if(chance<10){
        lesionado=1; animar("Voce se machucou durante o treino!",16,12);
    }
    else if(chance<20){
        moral -= 2; if(moral<0) moral=0; animar("Treino dificil! Moral -2",16,13);}
    else if(chance<30){
        if(strcmp(treino,"Chute")==0) chute+=1;
        else if(strcmp(treino,"Passe")==0) passe+=1;
        else if(strcmp(treino,"Penalti")==0) penalti+=1;
        else if(strcmp(treino,"Fisico")==0) fisico+=1;
        else if(strcmp(treino,"Tatica")==0) tatica+=1;
        animar("Treino perfeito! Bonus +1 habilidade",16,10);
    }
}

// Treinos
void treinar_chute(){
    if(lesionado){ animar("Voce esta lesionado e nao pode treinar chute!",13,12); return; }
    clrscr();
    animar("Treinando CHUTE!",2,12);
    gotoxy(10,5); cprintf("      O");
    gotoxy(10,6); cprintf("     /|\\");
    gotoxy(10,7); cprintf("     / \\");
    gotoxy(10,8); cprintf("      o ---> GOL!!!");
    Sleep(1500);
    energia -=10;

    int goleiro = rand()%100;
    int chance_gol = chute + fisico/2;
    if(goleiro > chance_gol){
        animar("O goleiro defendeu! Habilidade diminuida",15,12);
        chute -= 1; if(chute<0) chute=0;
    } else {
        animar("GOL! Habilidade aumentada",15,10);
        chute += 3;
        moral += 1; if(moral>100) moral=100;
    }
    barra(chute,17,"Chute",12);
    evento_aleatorio("Chute");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

void treinar_penalti(){
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
    energia -=9;

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
        penalti -= 1; if(penalti<0) penalti=0;
    } else {
        animar("GOL de penalti! Habilidade aumentada",15,10);
        penalti += 3;
        moral += 1; if(moral>100) moral=100;
    }
    barra(penalti,17,"Penalti",9);
    evento_aleatorio("Penalti");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

void treinar_passe(){
    if(lesionado){ animar("Voce esta lesionado e nao pode treinar passe!",13,12); return; }
    clrscr();
    animar("Treinando PASSE!",2,13);
    gotoxy(10,5); cprintf("  O      ---> o");
    gotoxy(10,6); cprintf(" /|\\");
    gotoxy(10,7); cprintf(" / \\");
    Sleep(1500);
    energia -=8; passe +=2; moral +=1; if(moral>100) moral=100;
    animar("Passe melhorou! +2 de habilidade",15,10);
    barra(passe,17,"Passe",13);
    evento_aleatorio("Passe");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

void treinar_fisico(){
    if(lesionado){
        animar("Voce esta lesionado e nao pode treinar fisico!",13,12);
        return;
    }
    
    clrscr();
    animar("Treinando FISICO!",2,10);
    gotoxy(10,5); cprintf("   O");
    gotoxy(10,6); cprintf("  /|\\");
    gotoxy(10,7); cprintf("  / \\");
    gotoxy(10,8); cprintf(" Correndo...");
    Sleep(1500);

    energia -=12; 
    fisico +=4;
    moral +=1; if(moral>100) moral=100;
    animar("Fisico melhorou! +4 de habilidade",15,10);
    barra(fisico,17,"Fisico",10);
    evento_aleatorio("Fisico");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

void treinar_tatica(){
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
        case 1: tatica+=2; moral+=2; energia-=7; animar("Sistema 4-4-2 treinado! +2 de Tatica",15,10); break;
        case 2: tatica+=3; moral+=3; energia-=9; animar("Sistema 3-5-2 treinado! +3 de Tatica",15,10); break;
        case 3: tatica+=1; moral+=1; energia-=5; animar("Sistema 5-3-2 treinado! +1 de Tatica",15,10); break;
    }
    if(moral>100) moral=100;
    barra(tatica,17,"Tatica",14);
    evento_aleatorio("Tatica");

    gotoxy(5,19); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();
}

void treino_aleatorio(){
    int op = 1+rand()%5;
    switch(op){
        case 1: treinar_chute(); break;
        case 2: treinar_passe(); break;
        case 3: treinar_penalti(); break;
        case 4: treinar_fisico(); break;
        case 5: treinar_tatica(); break;
    }
}

// Descanso
void descansar_completo(){
    clrscr();
    animar("=== DESCANSO ===",2,14);

    energia +=10; if(energia>100) energia=100;
    if(chute>0) chute -=2; if(chute<0) chute=0;
    if(penalti>0) penalti -=2; if(penalti<0) penalti=0;
    if(passe>0) passe -=2; if(passe<0) passe=0;
    if(fisico>0) fisico -=2; if(fisico<0) fisico=0;
    if(tatica>0) tatica -=2; if(tatica<0) tatica=0;

    mostrar_status();

    gotoxy(5,12); textcolor(11); cprintf("Energia aumentou em +10!");
    gotoxy(5,13); textcolor(12); cprintf("Chute, Penalti, Passe, Fisico e Tatica diminuiram em -2!");
    gotoxy(5,14); textcolor(10); cprintf("Moral nao foi alterada.");

    gotoxy(5,16); textcolor(14); cprintf("Pressione ENTER para continuar...");
    fflush(stdin); getch();

    lesionado = 0; // libera treinos
}

void start_training(int energy, int morals, int kick, int penalty, int pass, int physical, int tactic){
	
	energia = energy, moral = morals, chute = kick, penalti = penalty, passe = pass, fisico = physical, tatica = tactic;
	
    srand(time(NULL));
    int opcao;
    
    system("cls");
    
    do{
        mostrar_status();

        if(!lesionado){
            gotoxy(5,17); textcolor(11); cprintf("Escolha um treino:");
            gotoxy(5,18); cprintf("1 - Chute");
            gotoxy(5,19); cprintf("2 - Passe");
            gotoxy(5,20); cprintf("3 - Penalti");
            gotoxy(5,21); cprintf("4 - Fisico");
            gotoxy(5,22); cprintf("5 - Tatica");
            gotoxy(5,23); cprintf("6 - Aleatorio");
            gotoxy(5,24); cprintf("7 - Descansar");
            gotoxy(5,25); cprintf("0 - Sair");
            gotoxy(5,26); textcolor(14); cprintf("Opcao: ");
            scanf("%d",&opcao);
            fflush(stdin);
        } else {
            do{
                gotoxy(5,24); cprintf("7 - Descansar (obrigatorio por lesao)");
                gotoxy(5,25); cprintf("0 - Sair");
                gotoxy(5,26); textcolor(12); cprintf("Voce esta lesionado! Somente descanso disponivel.");
                gotoxy(5,27); textcolor(14); cprintf("Opcao: ");
                scanf("%d",&opcao); fflush(stdin);
                if(opcao != 7 && opcao != 0){
                    gotoxy(5,28); textcolor(12); cprintf("Opcao invalida! Somente descanso disponivel.");
                }
            }while(opcao != 7 && opcao != 0);
        }

        switch(opcao){
            case 1: treinar_chute(); break;
            case 2: treinar_passe(); break;
            case 3: treinar_penalti(); break;
            case 4: treinar_fisico(); break;
            case 5: treinar_tatica(); break;
            case 6: treino_aleatorio(); break;
            case 7: descansar_completo(); break;
            case 0: animar("Fim dos treinos",28,11); break;
        }

        if(energia<=10 && !lesionado){
            animar("Energia muito baixa! Voce deve descansar.",28,12);
            descansar_completo();
        }

    }while(opcao!=0);
}

#endif
