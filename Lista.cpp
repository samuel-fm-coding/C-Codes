#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

# define max 3

int lista[max];
int esc = 0;
int op = 0;

void exibir() {
	int contador = 0;
	
	for(int j = 0; j < max; j++){
		if(lista[j] != NULL){
			contador++;
		}
	}
	
	if(contador == 0){
		printf("\nA fila está vazia");
	}
	
	printf("\n");
	
	for(int t = 0; t < max; t++) {
		if(lista[t] != NULL){
			printf("Na posição %d temos %d\n", t, lista[t]);
		}
	}
}

void inserir() {
	system("cls");
	
	int vet[max-1];
	
	for(int i = 0; i < max; i++){
		if(lista[i] == NULL){
			vet[i] = i;
			printf("\nA posição %d está vazia", vet[i]);
		}
	}
	
	printf("\n\nDigite a posição que deseja inserir um elemento: ");
	scanf("%d", &esc);
	
	if(lista[esc] != NULL){
		printf("\nPosição não disponível, tente novamente");
		printf("\n\n");
		system("PAUSE");
		inserir();
	}
	else{
		printf("\n\nDigite o valor para entrar na lista: \n");
		scanf("%d", &lista[esc]);
	}
}

void remover() {
	system("cls");
	int elemento = 0;
	int cont = 0;
	
	for(int j = 0; j < max; j++){
		if(lista[j] != NULL){
			cont++;
		}
	}
	
	if(cont == 0){
		printf("\nA fila está vazia");
	} else {
		exibir();
		printf("\n\nSelecione uma posição para ser removida: ");
		scanf("%d", &elemento);
		
		if(lista[elemento] != NULL){
			printf("\n\nO elemento (%d) foi removido", lista[elemento]);
			lista[elemento] = NULL;
		}
	}
}

int menu() {
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	
	printf("-= Programa Lista em C =-\n\n");
	
	printf("   Para inserir digite      1\n");
	printf("   Para remover digite      2\n");
	printf("   Para exibir digite       3\n");
	printf("   Para sair                4\n");
	scanf("%d", &op);
	switch(op) {
		case 1:
			inserir();
			printf("\n\n");
			system("PAUSE");
			break;
		case 2:
			remover();
			printf("\n\n");
			system("PAUSE");
			break;
		case 3:
			exibir();
			printf("\n\n");
			system("PAUSE");
			break;
		case 4:
			printf("\n\n-----FIM-----\n\n");
			exit(0);
			break;
		default:
			printf("\n\nOpção Inválida\n\n");
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
