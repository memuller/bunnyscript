int aski(char pergunta[]){
    int valor; 
    printf("%s\n", pergunta);
    scanf("%i", &valor);
    return valor;
}

int * vet_of_ints(int tamanho){
    return malloc(sizeof(int)*tamanho);
}