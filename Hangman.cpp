#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <time.h>
using namespace std;
int numatual, num, o, rodadas;
char letra, modo;
	HANDLE  hConsole;
// Declaração das estruturas
// Estrutura de cada jogador
typedef struct
{
	char nome[10];
	int pontos;
} Jogadores;

Jogadores *jogadores = (Jogadores*) malloc (5 * sizeof(Jogadores));

//Estrutura para armazenar todas as palavras e temas do jogo

typedef struct
{
	char nome[20];
	char tema[10];
} PalavrasStruct;

PalavrasStruct palavrasStruct[200];

void ThreadProc(void *);
                  /* y = linha de 0 a 24 , x = coluna de 0 a 80 */
void gotoxy_2(int x, int y){/*imprimir na linha e coluna desejada */
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//definir cor do loading

//int randint(int n) {
//	int RAND_MAX, end;
//  if ((n - 1) == RAND_MAX) {
//    return rand();
//  } else {
// 
//    assert (n <= RAND_MAX);
//
//    int end = RAND_MAX / n;
//    assert (end > 0);
//    end *= n;
//
//    int r;
//    while ((r = rand()) >= end);
//
//    return r % n;
//  }
//}

void SetConsoleColour(WORD* Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

// Função para limpar a linha desejada

void LimpaLinha(int x, int y){
	gotoxy_2(x,y);
	printf("                                            ");	
}

// Função redirecionada pela tela de menu, para escolher as opções do jogo

void NovoJogo(){
	int i;
	LimpaLinha(60,22);
	LimpaLinha(60,25);
	LimpaLinha(60,27);
	gotoxy_2(60,39);
	printf("            MAXIMO DE JOGADORES: 05");	
	gotoxy_2(70,22);
	printf("Numero de Jogadores: ");
	scanf("%d",&num);
// alocação dinâmica de acordo com a quantidade de jogadores escolhida
	jogadores = (Jogadores*) realloc (jogadores, num * sizeof(Jogadores));
	numatual = num;
	
	if(num>5 || num <= 0){
		LimpaLinha(60,22);
		gotoxy_2(60,22);
		printf("Opcao invalida, maximo de 05 jogadores");
		gotoxy_2(60,25);
		system("pause");
		NovoJogo();
	}
	else{
		do{
			gotoxy_2(70,24);
			printf("MODO:");
			gotoxy_2(70,26);
			printf("Pressione");
			gotoxy_2(70,28);
			printf("N - para Normal");
			gotoxy_2(70,29);
			printf("S - para Sobrevivencia");
			fflush(stdin);
			modo = tolower(getch());	
			switch(modo){
				case 'n':
					LimpaLinha(70,28);
					LimpaLinha(70,29);
					LimpaLinha(70,26);
					gotoxy_2(78,24);
					printf("Normal");
					gotoxy_2(60,39);
					printf("            INSIRA O NUMERO DE RODADAS                         ");
					gotoxy_2(70,28);
					printf("RODADAS: ");
					scanf("%d",&rodadas);
					break;
				
				case 's':
					LimpaLinha(70,28);
					LimpaLinha(70,29);
					LimpaLinha(70,26);
					gotoxy_2(78,24);
					printf("Sobrevivencia");
					rodadas = (num*2)-1;
					gotoxy_2(60,28);
					system("pause");
					break;
		
			default:
				
				LimpaLinha(70,24);
				LimpaLinha(70,26);
				LimpaLinha(70,28);
				LimpaLinha(70,29);
				gotoxy_2(60,25);
				printf("Opcao Invalida, digite uma opcao valida");
				LimpaLinha(70,27);
				gotoxy_2(60,27);			
				system("pause");
				LimpaLinha(60,25);
				LimpaLinha(60,27);			
				break;
			}
		}while(modo != 's' && modo != 'n');
		
		LimpaLinha(60,22);
		LimpaLinha(60,24);
		LimpaLinha(60,28);
		gotoxy_2(78,21);
		printf("Jogadores:");
		LimpaLinha(60,39);
		gotoxy_2(60,39);
		printf("            MAXIMO DE 10 CARACTERES");
		for(i=0;i<num;i++){
			gotoxy_2(70,24);
			printf("Jogador %d: ",i+1);
			scanf("%s",jogadores[i].nome);
			LimpaLinha(79,24);
		}
	}
	return;
}
// função da tela de menu

void Menu(){
	char op;
	
	system("cls");
	system("color f0");
	printf (
"\n\n\n\n\n\n\n\n\n\n\n\n\n"
"                                                                      __..--''.          .''--..__             \n"
"                                                               _..-``         \\        /         ``-.._       \n"
"                                                           _.-`           __/\\ \\      / /\\__           `-._   \n"
"                                                        .-`     __..---```    \\ \\    / /    ```---..__     `-.\n"
"                                                      .`  _.--``               \\ \\  / /               ``--._  `.\n"
"                                                     / .-`                      \\ \\/ /                      `-. \\\n"
"                                            ________/.`__________________________\\/ /__________________________`.\\_______\n"
"                                            ³      `                                                              `        ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                         Pressione:                                           ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                         A - para Iniciar jogo                                ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                         R - para ver as Regras                               ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            _______________________________________________________________________________\n"
                                                                                    
);
	gotoxy_2(92,27);
// CAPTURAR NUMERO DE JOGADORES
	fflush(stdin);
	op = tolower((getch()));
	switch(op){
		case 'a':
			NovoJogo();
			break;

// regras do jogo
			
		case 'r':
			LimpaLinha(70,22);
			LimpaLinha(70,25);
			LimpaLinha(70,27);
			gotoxy_2(80,19);
			printf("Regras");
			gotoxy_2(46,21);
			printf("O objetivo do jogo eh fazer mais pontos para vencer!");
			gotoxy_2(46,22);
			printf("Quando um jogador acertar a letra eh pontuado com 1 ponto para cada letra");
			gotoxy_2(46,23);
			printf("O jogador que acertar a palavra ganha dois pontos extras");
			gotoxy_2(46,25);
			printf("No modo normal, os jogadores escolhem o numero de rodadas e vence");
			gotoxy_2(46,26);
			printf("quem tiver mais ponto no final");
			gotoxy_2(46,28);
			printf("No modo sobrevivencia, de acordo com o numero de jogadores, a partir da");
			gotoxy_2(46,29);
			printf("rodada apos o numero de jogadores, o jogador com menos pontos sera eliminado");
			gotoxy_2(60,35);
			system("pause");
			Menu();
			break;
		
		default:
			LimpaLinha(70,22);
			LimpaLinha(70,25);
			gotoxy_2(60,25);
			printf("Opcao Invalida, digite uma opcao valida");
			LimpaLinha(70,27);
			gotoxy_2(60,27);			
			system("pause");
			Menu();
			break;
			
	}
	return;
}

int main(){
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	WORD Attributes = 0;
	int z, y, i, j, m = 0, a, fimTurno = 0, contpalavra = 0, p, acertos=0, tamanhoPalavra = 0, v = 3, erros = 0, contAcertos=0, vencedor[5], perdedor[5], cont = 1;
	int acertoPos[20], eliminar[5];
	char retornomodo;
	char modos;
// frase animada usada no jogo
	char* quote = "  NEM TUDO POSSUI UM GAMEOVER";
	char* loading = "                                                                                                      ";
	char* timer = "                              ";
	char palavra[20], nome[10];

// contador do tamanho da frase animada para usar em um For e Criar a animação
	z=strlen(loading);

//comando para deixar C em tela cheia
	system("MODE con cols=168 lines=63");
	keybd_event ( VK_MENU, 0x38, 0, 0 );
	keybd_event ( VK_SPACE, 0x39, 0, 0 );
	keybd_event(0x58,0,0,0);
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
	keybd_event ( VK_SPACE, 0x39, KEYEVENTF_KEYUP, 0 );
	keybd_event(0x58,0,KEYEVENTF_KEYUP,0);

//comando para mudar cor de fundo e das letras
	system("color fc");

//TELA INICIAL ------------------------------------------------------------------------------------------------------------------------------------------------------

//LINHA DE INTERFACE --------------------------------------------------------------------------------------------------------------------------------------------------	 		
	printf(" 1             0            1          1            0                      0          1         0         0      1  1          0        1           1    0    0 \n \n 0       0        1      1    0        1       1              1                1       0      0       1   1     0       0      1            1                0        0 \n 0         1      0             1                  0            1          0          0                   1         1                  0                1     \n\n\n\n\n\n    ");
	printf("                               88       8a   \n"                                                                
	"                                   88       8a \n"                                                                   
	"                                   88       8a \n"                                                                  
	"                                   88       8a ,adPPYYba, 8b,dPPYba,   ,adPPYb,d8   88,dPYba,,adPYba,    ,adPPYYba,  8b,dPPYba,   \n" 
	"                                   88       8a  99     Y8 88P      a8  a8      Y88  88P     88      8a   88      Y8  88P'     8a  \n"
	"                                   88PdPPYba8a         Y8 88P      a8  a8      Y88  88P     88      8a           Y8  88       88  \n"
	"                                   88       88 ,adPPPPP88 88       88  8b       88  88      88      88   ,adPPPPP88  88       88  \n"  
	"                                   88       88 88,    ,88 88       88  8a,    ,d88  88      88      88   88      88  88       88  \n"  
	"                                   88       88 `'8bbdPpY8 88       88   `'YbbdP'Y8  88      88      88    98bbdP'Y8  88       88  \n"
                                    "                                                                                88\n"        
								    "                                                           _   _         aa    ,88\n"                           
                                     "                                                          ³ ³ ³ ³        Y8bnnbdP\n"   ) ;

	printf(                               
	"                                                          ³ ³_³ ³__   ___        __ _   __ _ _ __ ___   ____ \n"  
	"                                                          ³ __³ '_ \\ / _ \\      / _` ³ / _` ³ '_ ` _ \\ / _  \\ \n"
	"                                                          ³ ³ ³ ³ ³ ³ ³_³³     ³ / ³ ³³ / ³ ³ ³ ³ ³ ³ ³  I_I ³\n"
	"                                                          ³ ³_³ ³ ³ ³  __/     ³ \\_³ ³³ \\_³ ³ ³ ³ ³ ³ ³  __ / \n "
	"                                                          \\__³_³ ³_³\\___³      \\__, ³ \\__,_³_³ ³_³ ³_³\\___³  \n "
	"                                                                                __/ ³ \n "
	"                                                                               ³___/  \n"
	);
	printf("\n \n \n ");
// </LINHA DE INTERFACE --------------------------------------------------------------------------------------------------------------------------------------------------
// LINHA DE INTERFACE --------------------------------------------------------------------------------------------------------------------------------------------------	 		

	printf("\n \n \n \n \n \n \n \n \n");          
	printf("\n    1             0            1          1            0                      0          1         0         0      1  1          0        1           1    0    0 \n \n 0       0        1      1    0        1       1              1                1       0      0       1   1     0       0      1            1                0        0 \n 0         1      0             1                  0            1          0          0                   1         1                  0                1         ");

// </LINHA DE INTERFACE --------------------------------------------------------------------------------------------------------------------------------------------------	 


	for(int y=0; y<=z; y++){
	
// retardo de meio segundo para iniciar e resetar o programa
		Sleep(50);


//ANIMAÇÃO DO SLOGAN (ESPAÇO NECESSARIO PARA CENTRALIZAR NA TELA)
		gotoxy_2(4,31);
		printf("                                                             %.*s\n \n", y, quote);
	
// ANIMAÇÃO DA BARRA DE CARREGAMENTO
		SetConsoleColour(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
		gotoxy_2(0,34);/* posiciona o cursor para imprimir nessas posições X coluna Y linha */
		printf("                                                                  %.*s", y, loading);
		ResetConsoleColour(Attributes);
		if(y!=z){
			printf("");
		} else {
			printf("\n                                                                   ________________________________                                 \n                                                                  /                                \\                                 \n                                                                 ³   PRESSIONE ENTER PARA COMECAR   ³                               \n                                                                  \\________________________________/   \n \n \n \n \n \n  ");
			gotoxy_2(97,38);
			getch();
		}
	} 
	
//TELA INICIAL ------------------------------------------------------------------------------------------------------------------------------------------------------
	do{
//salvando palavras do arquivo na struct	
		Menu();
		FILE *palavras;
		palavras = fopen("Palavras.txt","r");
		contpalavra = 0;
		while(fgets(palavra,20,palavras) != NULL){
			strcpy(palavrasStruct[contpalavra].nome ,palavra);
			if(contpalavra<18){
				strcpy(palavrasStruct[contpalavra].tema , "Pais");
			}
			else if(contpalavra<35){
				strcpy(palavrasStruct[contpalavra].tema , "Cursos");
			}
			else if(contpalavra<66){
				strcpy(palavrasStruct[contpalavra].tema , "Fruta");
			}
			else if(contpalavra<87){
				strcpy(palavrasStruct[contpalavra].tema , "Animal");
			}
			else{
				strcpy(palavrasStruct[contpalavra].tema , "Objeto");
			}
				contpalavra ++;
		}
		for(i=0;i<num;i++){
			jogadores[i].pontos = 0;
		}
		erros = 0;
//HORA DO JOGO---------------------------------------------------------------------------------------------------------------------------------------
		for(i=1;i<=rodadas;i++){
// erros
			if(erros!=0){
				gotoxy_2(66,23);
				printf("Acabaram todas as tentativas");
				_sleep(3000);
				erros = 0;
			}
			
			srand(time(NULL));
			
			v = rand() % 107;
			fimTurno = 0;
			contAcertos = 0;
			system("cls");
			gotoxy_2(30,8);
printf(
"\n \n \n \n \n"

"___________.._______\n"
"³ .__________))______³\n"
"³ ³ / /      ³³\n"
"³ ³/ /       ³³\n"
"³ ³ /        ³³\n"
"³ ³/         ³³     \n"
"³ ³          ³³  \n"
"³ ³          (\\\\`_\n"
"³ ³           `--'\n"
"³ ³     \n"
"³ ³     \n"
"³ ³     \n"
"³ ³     \n"
"³ ³     \n"
"³ ³     \n"
"³ ³     \n"
"³ ³     \n"
"³ ³     \n"
"---------- _      \n"
"³-³-------\\ \\            \n"
"³ ³        \\ \\           \n"
": :         \\ \\          \n"
". .          `'          \n"
 );
 			tamanhoPalavra = strlen(palavrasStruct[v].nome) - 1;
 			gotoxy_2(73,37);
 		    printf("ULTIMA LETRA : ");
			LimpaLinha(73,8);
			gotoxy_2(73,8);
			printf("Rodada : %d / %d",i,rodadas);
			gotoxy_2(73,10);
			printf("TEMA : %s",palavrasStruct[v].tema);
			// Letras da palavra
			gotoxy_2(74,42);
			for(j=0;j<tamanhoPalavra;j++){		
				printf("_ ");
			}
			for(j=0;j<20;j++)
				acertoPos[j] = 0;
			do{	
				
				while(modo == 's' && i>num && jogadores[o].pontos == NULL){
					o++;
				}
			
			if(o>=num){
				o=0;
			}
			LimpaLinha(70,12);
			gotoxy_2(70,12);
			printf("JOGANDO : %s",jogadores[o].nome);
			gotoxy_2(70,25);
//LOADING PARTE 1 ---------------------------------------------------------------------------------------------------------------------------------------

//SCOREBOARD ---------------------------------------------------------------------------------------------------------------------------------------------------------
			int h = 15;
			for(j=0;j<num;j++){
				gotoxy_2(130,h);
				printf("%d. %s\n",j+1,jogadores[j].nome);
				if(modo == 's' && i>num && jogadores[j].pontos == NULL){
					gotoxy_2(153,h);
					printf("Eliminado");
				}
				else{
					gotoxy_2(160,h);	
					printf("%d",jogadores[j].pontos);
				}
				h++;
				gotoxy_2(130,h);
				printf("--------------------------------\n");
				h++;		
			}
			
			int positionxtimer = 65;
			int positionytimer = 28;
			SetConsoleColour(&Attributes, BACKGROUND_INTENSITY | BACKGROUND_RED);
			gotoxy_2(positionxtimer,positionytimer);
			printf("%.*s", 30, timer);
		    DWORD waitCode;
			ResetConsoleColour(Attributes);
			
			letra = NULL;
			
			for(int y=30; y>=1; y--){
//criar thread
				if(y<2){
					o++;
					break;
				}
				gotoxy_2(70,37);	

   				DWORD waitCode;
   				DWORD ThreadID = 0;
    			HANDLE hThread = CreateThread(NULL, 0,
       	                 (LPTHREAD_START_ROUTINE)ThreadProc,
       	                 (LPVOID)&letra, 0, &ThreadID);
    			if(!hThread){
       				fprintf(stderr, "Failed to create a thread\n");
    			    return -1;
    			}
    			waitCode = WaitForSingleObject(hThread, 1000);   
    			CloseHandle(hThread);
    			if(letra != NULL ){

					for(p=0;p<tamanhoPalavra;p++){
						if(toupper(palavrasStruct[v].nome[p]) == letra){
							acertoPos[p] = 1;
							acertos++;
							gotoxy_2(74+p*2,41);	
							printf("%c",letra);
						}
					}
					if(acertos>0){
						contAcertos += acertos;
						jogadores[o].pontos += acertos;
						acertos = 0;
					}
					else{
						erros += 1;
						o++;
					}
					gotoxy_2(80,43);
					for(p=0;p<tamanhoPalavra;p++){
						if(acertoPos[p]!=0){
							palavrasStruct[v].nome[p] = 0;
						}
					}
					
					break;
				}

// ANIMAÇÃO DA BARRA DE CARREGAMENTO
				gotoxy_2(positionxtimer+y,positionytimer);
				printf("  ");
			}
// Personagem da forca aparecendo a cada erro
			if(erros==1){
				gotoxy_2(0,17);
				printf(
"³ ³ /        ³³.-''.\n"
"³ ³/         ³/  _  \\ \n"
"³ ³          ³³  `/,³\n"
"³ ³          (\\\\`_.'\n"
"³ ³         .-`--'.\n"
);				
			}
			else if(erros==2){
				gotoxy_2(0,22);
								printf(
"³ ³        /Y\n"
"³ ³       //\n"
"³ ³      //\n"
"³ ³     ')\n"
);				
			}
			else if(erros==3){
				gotoxy_2(0,22);
				printf(
"³ ³        /Y     Y\\\n"
"³ ³       //       \\\\\n"
"³ ³      //         \\\\\n"
"³ ³     ')           (`\n"
);				
			}
			else if(erros==4){
				gotoxy_2(0,22);
				printf(
"³ ³        /Y . . Y\\\n"
"³ ³       // ³   ³ \\\\\n"
"³ ³      //  ³ . ³  \\\\\n"
"³ ³     ')   ³   ³   (`\n"
);
			}
			else if(erros==5){
				gotoxy_2(0,26);
				printf(
"³ ³          ³³'  \n"
"³ ³          ³³   \n"
"³ ³          ³³   \n"
"³ ³          ³³   \n"
"³ ³         / ³    \n"
"----------³_`-'          \n"
);
			}
			else if(erros==6){
				gotoxy_2(0,26);
				printf(
"³ ³          ³³'³³\n"
"³ ³          ³³ ³³\n"
"³ ³          ³³ ³³\n"
"³ ³          ³³ ³³\n"
"³ ³         / ³ ³ \\\n"
"----------³_`-' `-'      \n"
);
// fim rodada
				fimTurno == 1;
				break;
			}
			
			if(contAcertos == tamanhoPalavra){
				fimTurno == 1;
				erros = 0;
				jogadores[o].pontos += 2;
				break;
			}
// Modo sobrevivencia, ver quem ta com menos pontos e zerar quem vai ser eliminado				
		}while(fimTurno!=1);
		if(i<=rodadas){
			if(modo == 's' && i>num){
				for(a=0;a<num;a++){
				perdedor[a] = 0;
					for(j=0;j<num;j++){
							if(jogadores[a].pontos<=jogadores[j].pontos){
								perdedor[a] += 1;
	
							}
					}
				}
				for(a=0;a<num;a++){
					if(perdedor[a]==numatual){
						jogadores[a].pontos = NULL;
					}
				}
							numatual--;
			}
		}
		}
			for(i=0;i<num;i++){
				vencedor[i] = 0;
				for(j=0;j<num;j++){
					if(jogadores[i].pontos>=jogadores[j].pontos){
						vencedor[i] += 1;
					}
				}
			}
	// tela fim de jogo
		system("cls");
	printf (
"\n\n\n\n\n\n\n\n\n\n\n\n\n"
"                                                                      __..--''.          .''--..__             \n"
"                                                               _..-``         \\        /         ``-.._       \n"
"                                                           _.-`           __/\\ \\      / /\\__           `-._   \n"
"                                                        .-`     __..---```    \\ \\    / /    ```---..__     `-.\n"
"                                                      .`  _.--``               \\ \\  / /               ``--._  `.\n"
"                                                     / .-`                      \\ \\/ /                      `-. \\\n"
"                                            ________/.`__________________________\\/ /__________________________`.\\_______\n"
"                                            ³      `                                                              `        ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                         O jogo acabou ! :)                                   ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³               Vencedor(es):                                                  ³\n"
"                                            ³               Pontos:                                                        ³\n"
"                                            ³                                                                              ³\n"
"                                            ³         Se deseja sair pressione S                                           ³\n"
"                                            ³         Caso contrario, pressioneo pressione C para continuar jogando        ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            ³                                                                              ³\n"
"                                            _______________________________________________________________________________\n"
                                                                                    
);
	int g = 74;
	for(i=0;i<num;i++){
		if(vencedor[i]==num){
			gotoxy_2(g,25);
			printf("%s ",jogadores[i].nome);
			gotoxy_2(74,26);
			printf("%d",jogadores[i].pontos);
			g+= strlen(jogadores[i].nome)+1;
		}
	}
		fflush(stdin);
		modo = tolower(getch());
		if(modo == 's'){
		
			break;
		}
	}while(1!=2);
//TELA FINAL ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	system("cls");
	gotoxy_2(70,20);
	printf("Obrigado por jogar Hangman! :D");
	fflush(stdin);
	getch();

	return 0;
}

//FUNÇÃO USADA NA THREAD ---------------------------------------------------------------------------------------------------------------------------------------
void ThreadProc(void *n){
    gotoxy_2(87,37);
    fflush(stdin);
	letra = toupper(getch());
	gotoxy_2(87,37);
    printf("%c",letra);
    
	ExitThread(0);
}
