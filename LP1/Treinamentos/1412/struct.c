/*
    Escreva um programa que leia informações de livros presentes no arquivo bestsellers.cvs, 
    organize-os na forma de um array de structs, e imprima uma tabela com o nome e autor dos livros.
    
    o arquivo possui um livro por linha, com cada campo separado por vírgulas, sendo os campos
    nome, autor, idioma, data, vendas
    
    use scanf para ler estas informações.
    fscanf(arquivo, "padrão de formatação com i% %s", &inteiro, &str);
    fscanf lê do arquivo em questão informações seguindo o formato especificado, colocando-as
    nas variáveis cujos endereços você passar. lembrando que pode usar &variavél para representar
    o endereço delas.
    
    lembre que struct é algo parecido com classes e objetos. você define um struct como se definisse uma classe,
    depois pode criar N objetos dela.
    
    struct person {
        char[50] name;
        int age;
    } #cria a estrutura de structs chamados person - as variáveis/propriedades que ficam dentro dele

    struct person Alline; #declara uma variável com nome Alline cujo tipo é o struct person
    
    quando você declara um struct, ele não "tem" nada. ele é só um modelo, você nunca vai lidar com ele diretamente.
    depois de ter a declaração de um struct, daí você cria uma variável específica, do tipo struct, seguindo aquele modelo, e usa como quiser.
   
*/

#include <stdio.h>
#include <stdlib.h>

int qtd(char nomearquivo[])
{
    FILE *books2;
    int cont=0;
    char lala[100];
    
    books2=fopen(nomearquivo, "r");
    while (fgets(lala, 100, books2) != NULL)
    {
        cont++;
    }
    
    fclose(books2);
    return cont;
}





void main()
{
    FILE *books;
    
    // esta é uma declaração do modelo/classe de structs, chamado Livro.
    // não pode usar diretamente; não é uma variável.
    struct Livro
    {
        char nome[40];
        char autor[40];
        char linguagem[20];
        int ano;
        int vendas;

    };
    
    books=fopen("bestsellers.csv", "r");
    
    // declaração de duas variáveis - chamadas Tale e She, do tipo struct, que seguem o modelo Livro.
    struct Livro Tale, She;
    // aqui as duas primeiras linhas do arquivo são lidas e colocadas em respectivos structs.
    
    fscanf(books, "%[^;]; %[^;]; %[^;]; %i; %i", Tale.nome, Tale.autor, Tale.linguagem, &Tale.ano, &Tale.vendas);
    fscanf(books, "%[^;]; %[^;]; %[^;]; %i; %i", She.nome, She.autor, She.linguagem, &She.ano, &She.vendas);
    
    
    
    
    // um array de structs do tipo Livro.
    // um array de structs funciona como demais arrays, no sentido de que cada posição
    // é uma variável completamente separada.
    // livros[0].nome = "Tale"; livros[1].nome = "She";
    struct Livro livros[14];
    
    
    // sabendo que arrays de structs se comportam assim (ou seja, como qualquer outro array),
    // podemos criar loops com eles.
    
    for(i = 0; i < 13; i++){
        fscanf(books, "%[^ ]; %[^;]; %[^;]; %i; %i", 
            books[i].nome, books[i].autor, books[i].linguagem, &books[i].ano, &books[i].vendas
        );
    }


    fclose(books);

}

for(i = 0; i < 10; i++){
    fscanf(nov, "%13[^/]%f", Pagamentos[i].matricula, &Pagamentos[i].horas);
}