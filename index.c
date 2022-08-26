#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>

#define L_TAM 30
#define C_TAM 30
#define USLEEP_T 250
#define time_beep 20

char caracteresASCII[] = "!@#$%¨&*()!@#$(@!)#@!!#)@#@1239874556";
char vet[L_TAM][C_TAM];

int i,j; //Variáveis contadoras


void preencheLC(){
	for(i = 0;i < L_TAM;i++){
		for(j = 0;j < C_TAM;j++){
			vet[rand() % L_TAM][rand() % C_TAM] = caracteresASCII[rand() % (strlen(caracteresASCII) - 1)];
		}
	}
}

void desenhaMatriz(){
	for(i = 0;i < L_TAM;i++){
		for(j = 0;j < C_TAM;j++){
			printf("[%c]",vet[i][j]);
		}
		printf("\n");
	}
}
void animMatriz(){
	int x;
	do
	{	
		system("color 02");
		preencheLC();
		desenhaMatriz();
		usleep(USLEEP_T);
		system("cls");
	}
	while(x);
}

void som(){
	for(i = 100;i <= 10000;i = i  + 50){
		Beep(i,150);
		if(i == 10000){
			for(;i >= 150;i = i - 50){
				Beep(i,150);
			}
		}
	}
}

int main(){
	setlocale(LC_ALL,"");
	int op;
	srand(time(NULL));
	printf("\nEsse programa so vai fazer showzinhos no pc.\nPode olhar o código, n e virus!Para fechar o programa pressione ctrl + C!");
	printf("\n1-Terminal doente:\n2-Beepzinho Foda\n3-Matrix reloaded\n-:");
	scanf("%d",&op);

	switch(op){
		case 1:
			for(i = 0;;i++){
				system("color 00");
				system("color 10");
				system("color 20");
				system("color 30");
				system("color 30");
				system("color 25");
				system("color 10");
				system("color 03");
			}
			break;
		case 2:
			som();
			break;

		case 3:
			animMatriz();
			break;
		default:
			printf("\nEscolheu errado otario!\n");

	}
	system("pause");
	return 0;
}