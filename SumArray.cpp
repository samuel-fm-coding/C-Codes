#include <stdio.h>

main() {
    int arr[] = {5,5,5,5,5}; //example
    int soma = arr[0];
    
    //calcula tamanho do vetor/array
    int len = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = 1; i < len; i++){
        soma = soma + arr[i];
    }
    
    printf("%d", soma);
}
