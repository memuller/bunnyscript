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




// struct Livro livros[15];
// mesma coisa de declarar uma variável normal seguindo este modelo de struct e tal. mas é um array.
// cada elemento deste array vai ter um struct separado e tal. eg
// livros[0].name = "Tale"; livros[1].name = "She";
void main()
{
    FILE *books;
    
    struct Livro
    {
        char nome[40];
        char autor[40];
        char linguagem[20];
        int ano;
        int vendas;

    };
    
    int nlivros = qtd("bestsellers.csv");
    struct Livro livros[nlivros];
    
  
    
    
    
    books=fopen("bestsellers.csv", "r");
    fscanf(books, "%[^;]; %[^;]; %[^;]; %i; %i", Tale.nome, Tale.autor, Tale.linguagem, &Tale.ano, &Tale.vendas);
    fscanf(books, "%[^;]; %[^;]; %[^;]; %i; %i", She.nome, She.autor, She.linguagem, &She.ano, &She.vendas);
  
  
    
    printf("%s, do %s em %s lançado em %i e tem %i vendas\n", Tale.nome, Tale.autor, Tale.linguagem, Tale.ano, Tale.vendas);
    printf("%s, do %s em %s lançado em %i e tem %i vendas\n", She.nome, She.autor, She.linguagem, She.ano, She.vendas);
   
    



    fclose(books);

}

