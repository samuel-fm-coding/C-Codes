#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Carro {
    int ano;
    char modelo[20];
    char marca[20];
    char placa[8];
    char chassi[17];
    float valor;
};

int main() {
    setlocale(LC_ALL, "Portuguese");//Format strings to PT-BR
    
    struct Carro carro[250];
    int escolha = 1;
    int totalCarros = 0;  
    
    while (escolha == 1) {
        // Condition for continue the vehicles insert
        if(totalCarros != 0){
          printf("\n\nDigite 1 para cadastrar um veículo ou 0 para sair: ");
          scanf("%d", &escolha);

          if (escolha != 1) {
              break;
          }
        }
        
        
        printf("\nDigite o ano do Veículo: ");
        scanf("%d", &carro[totalCarros].ano);
        
        printf("Digite o modelo do Veículo: ");
        scanf("%s", &carro[totalCarros].modelo);
        
        printf("Digite a marca do Veículo: ");
        scanf("%s", &carro[totalCarros].marca);
        
        printf("Digite a placa do Veículo: ");
        scanf("%s", &carro[totalCarros].placa);

        printf("Digite o identificador do Chassi do Veículo: ");
        scanf("%s", &carro[totalCarros].chassi);

        printf("Digite o valor de venda do Veículo: ");
        scanf("%f", &carro[totalCarros].valor);

        totalCarros++;
    }

    // Show data
    printf("\nDados dos Carros:\n");
    for (int i = 0; i < totalCarros; i++) {
        printf("\n\nVeículo %d:\n\n", i + 1);
        printf("Ano: %d \n", carro[i].ano);
        printf("Modelo: %s \n", carro[i].modelo);
        printf("Marca: %s \n", carro[i].marca);
        printf("Placa: %s \n", carro[i].placa);
        printf("Chassi: %s \n", carro[i].chassi);
        printf("Valor: R$ %.2f \n", carro[i].valor);
    }

    return 0;
}
