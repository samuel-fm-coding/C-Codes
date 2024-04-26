#include <conio.h>
#include <windows.h>
#include <stdio.h>

struct no{
	int valor;
	no *anterior;
};

no *topo;
int option;

void pilhavazia(){
	topo = NULL;
}

void empilha(int pvalor){
	no *novo;
	novo = (no*)malloc(sizeof(no));
	novo->valor=pvalor;
	novo->anterior=topo;
	topo=novo;
	printf("Elemento %d inserido", novo->valor);
	getch();
	system("cls");
}

void mostra(){
	no *aux=topo;
	while(aux!=NULL){
		printf("\n%d", aux->valor);
		aux=aux->anterior;
	}
	getch();
	system("cls");
}

void excluir(){
	no *aux = topo;
	topo=aux->anterior;
	free(aux);
	aux=topo;
	printf("Elemento excluido");
	getch();
	system("cls");
}

void mostra_topo(){
	no *aux = topo;
	printf("\n%d", aux->valor);
	getch();
	system("cls");
}

void exclui_pilha(){
	no *aux = topo;
	while(aux != NULL){
		topo=aux->anterior;
		free(aux);
		aux=topo;	
	}
	printf("Pilha excluida");
	getch();
	system("cls");
}

void menu(){
	printf("1 - Inserir");
	printf("\n2 - Exibir");
	printf("\n3 - Remover");
	printf("\n4 - Remover Pilha");
	printf("\n5 - Exibir Topo");
	printf("\n6 - Sair\n\n");
	scanf("%d", &option);
	switch(option){
		case 1:
			int val;
			system("cls");
			printf("Digite um valor para entrar na pilha \n");
			scanf("%d", &val);
			empilha(val);
			break;
		case 2:
			mostra();
			break;
		case 3:
			excluir();
			break;
		case 4:
			exclui_pilha();
			break;
		case 5:
			mostra_topo();
			break;
		case 6: 
			exit(0);
			break;
		default:
			printf("\n\nOpção Inválida");
			system("PAUSE");
			break;
	}	
}

main(){
	while(option != 6) {
		system("cls");
		menu();
	}
}
