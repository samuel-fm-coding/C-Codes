#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int *ponteiro;
	
	ponteiro = (int*)malloc(sizeof(int)); //alocando memória
	
	printf("Digite um número inteiro: "); //usuario digita um valor pra armazenar na memória
	scanf("%d", ponteiro);
	
	printf("\n\nValor %d armazenado no endereço %d", *ponteiro, ponteiro); //exibo valor(*) e endereço	

	return 0;
}
