#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

# define max 5

int dado[max];
int pointer = 1;
int inicio = 1;
int op;

void exibir(void) {
	printf("\n");
	for(int temp = pointer -1; temp >= 1; temp--) {
		printf("Em %d º lugar temos %d\n", temp, dado[temp]);
	}
	printf("\n");
	system("PAUSE");
}

void inserir(void) {
	system("cls");
	if(pointer == max) {
		printf("A fila está cheia;\n");	
	} else {
		printf("Digite o valor para entrar na fila: \n");
		scanf("%d", &dado[pointer]);
		pointer++;
	}
	exibir();
}

void remover(void) {
	system("cls");
	if(pointer == 1) {
		printf("\nA fila esta vazia\n");
	} else {
		printf("O primeiro elemento (%d) foi removido", dado[inicio]);
		for (int i = inicio; i < pointer - 1; i++) {
            dado[i] = dado[i + 1];
        }
        dado[pointer - 1] = 0; // Limpar o último elemento
        pointer--;
	}
	exibir();
}

int menu() {
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf("-= Programa Fila em C =-\n\n");
	printf("   Para inserir digite      1\n");
	printf("   Para remover digite      2\n");
	printf("   Para exibir digite       3\n");
	printf("   Para sair                4\n");
	scanf("%d", &op);
	switch(op) {
		case 1:
			inserir();
			break;
		case 2:
			remover();
			break;
		case 3:
			exibir();
			break;
		case 4:
			printf("\n\n-----FIM-----\n\n");
			exit(0);
			break;
		default:
			printf("\n\nOpção Inválida");
			system("PAUSE");
			break;
	}
	return 0;
}

int main() {
	while(op != 4) {
		system("cls");
		menu();
	}
	return 0;
}
