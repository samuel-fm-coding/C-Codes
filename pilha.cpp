#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define max 5

int cont = 0;
int valores[max] = {};

int main()
{
	setlocale(LC_ALL, "Portuguese");
	

	int escolha = 0;
	int len = sizeof(valores) / sizeof(valores[0]);
    
    system("cls");
    
    printf("--- MENU - PILHA ---");
    printf("\n\n1 - INSERIR ELEMENTO\n2 - RETIRAR ELEMENTO\n3 - EXIBIR PILHA\n\n4 - Sair\n\n");
    scanf("%d", &escolha);
    
    switch(escolha){
        case 1: 
        	if(cont < len){
        		system("cls");
        
	            printf("\nDigite um valor inteiro: ");
			    scanf("%d", &valores[cont]);
			    
			    printf("\nNúmero %d inserido na posição %d", valores[cont], cont);
			    cont++;
			    printf("\n\nInserido\n\n");	
			}
			else{
				printf("Pilha cheia\n\n");
			}
            system("PAUSE");
			getchar();
		    main();
		    break;
		case 2:
			system("cls");
			valores[cont-1] = NULL;
			cont--;
			printf("\n\nO último elemento da pilha foi removido\n\n");
			system("PAUSE");
			getchar();
			main();
			break;
        case 3:
			system("cls");
			for(int j = 4; j>=0; j--){
				if(valores[j] != NULL){
					printf("\nPosição %d -> %d", j, valores[j]);	
				}
			}
			system("PAUSE");
			getchar();
			main();
			break;
        case 4:
        	printf("\n\n-----FIM-----\n\n");
			exit(0);
			break;
		default:
			main();
			break;	
    }

    return 0;
}
