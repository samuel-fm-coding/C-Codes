#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <locale.h>

struct no{
	int valor;
	no *proximo;
};

no *inicio;
no *fim;
int option;

void enfileirar(int pvalor){
	no *novo;
	novo = (no*)malloc(sizeof(no));
	novo->valor = pvalor;
    novo->proximo = NULL; //estou inserindo um novo nó, logo, o proximo encadeamento é nulo(por enquanto)

    if (fim == NULL) { //com a fila vazia, o elemento é inserido no fim/inicio
        inicio = novo;
    } else {
        fim->proximo = novo; //pega o elemento final, aponta um proximo que será o valor inserido
    }

    fim = novo; //inserindo novo elemento no final da fila
    printf("Elemento %d inserido\n", novo->valor);
    
	getch();
	system("cls");
}

void mostra(){
	no *aux = inicio;
	
	if (aux == NULL) {
        printf("Fila vazia\n");
        return;
    }
	
	printf("Elementos na fila:\n");
    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
	getch();
	system("cls");
}

void excluir(){
	if (inicio == NULL) {
        printf("Fila vazia, nada para remover.\n");
        return;
    }
    struct no *aux = inicio;
    inicio = inicio->proximo;
    printf("Elemento %d excluído.\n", aux->valor);
    free(aux);
    
	getch();
	system("cls");
}

void mostra_inicio(){
	if (inicio == NULL) {
        printf("Fila vazia\n");
    } else {
        printf("Elemento no início da fila: %d\n", inicio->valor);
    }
    
	getch();
	system("cls");
}

void menu(){
	printf("1 - Inserir");
	printf("\n2 - Exibir");
	printf("\n3 - Remover");
	printf("\n4 - Exibir Início");
	printf("\n5 - Sair\n\n");
	scanf("%d", &option);
	switch(option){
		case 1:
			int val;
			system("cls");
			printf("Digite um valor para entrar na fila \n");
			scanf("%d", &val);
			enfileirar(val);
			break;
		case 2:
			mostra();
			break;
		case 3:
			excluir();
			break;
		case 4:
			mostra_inicio();
			break;
		case 5: 
			exit(0);
			break;
		default:
			printf("\n\nOpção Inválida");
			system("PAUSE");
			break;
	}	
}

main(){
	setlocale(LC_ALL, "Portuguese");
	
	while(option != 5) {
		system("cls");
		menu();
	}
}
