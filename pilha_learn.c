#include <stdio.h>
#include <stdlib.h>
# define max 5

int dado[max];
int topo = 0;
int op;

void exibir(void) {
	printf("\n");
	for(int temp = topo - 1; temp >= 0; temp--) {
		printf("Na posicao %d temos %d\n", temp, dado[temp]);
	}
	printf("\n");
	system("PAUSE");
}

void exibir_topo(void){
	system("cls");
	
	printf("TOPO -> %d", dado[topo -1 ]);
	
}

void inserir(void) {
	system("cls");
	if(topo == max) {
		printf("A pilha está cheia;\n");	
	} else {
		printf("Digite o valor para entrar na pilha: \n");
		scanf("%d", &dado[topo]);
		topo++;
	}
	exibir();
}

remover(void) {
	system("cls");
	if(topo == 0) {
		printf("\nA pilha esta vazia\n");
	} else {
		printf("\nRetirado o valor %d da pilha\n", dado[topo-1]);
		topo--;
	}
	exibir();
}

int menu() {
	system("cls");
	printf("-= Programa Pilha em C =-\n\n");
	printf("   Para inserir digite      1\n");
	printf("   Para remover digite      2\n");
	printf("   Para exibir digite       3\n");
	printf("   Para exibir o topo       4\n");
	printf("   Para sair                5\n");
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
			exibir_topo();
			break;
		case 5:
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
