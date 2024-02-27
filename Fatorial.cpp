#include <stdio.h>

main() {
    int n = 0, aux=0;
    
    printf("Digite um número: ");
    scanf("%d", &n);

    aux = n;
    for(int x = n-1; x>0; x--){
        aux = aux * x;
    }
    
    printf("\n\nResultado: %d", aux);
}
