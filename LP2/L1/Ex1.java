/* Exercício 1
O DNA humano tem 3 bilhões de bases pareadas, então laboratórios recortam esse DNA em pedaços menores e mais fáceis de ser computados, com menos bases. 
Esses recortes não são feitos no DNA original, são feitos em copias, por isso às vezes parte do DNA se encontra em dois recortes, o seu trabalho é criar um programa 
em Java que vai concatenar dois ou mais recortes de forma a não repetir as partes iguais, essa aplicação é encontrada em muitas outras áreas, então faça 
seu código funcionar com qualquer par de strings (N recortes).
Suas strings serão passadas por argumento na linha de comando.
Para este primeiro exercício, pode colocar o programa todo dentro do método main.

Um programa que receba via linha de comando N strings (sendo N um número par) de argumentos e as imprima concatenadas na ordem passada; 
eliminando, no ato da concatenação, quaisquer caracteres repetidos nas 'bordas' das strings concatenadas. 
Ou seja, ao concatenar string A com B, precisando comparar os últimos caracteres de A com os primeiros de B e eliminar sequências iguais */


class Ex1 {
    public static void main(String[] args){
        int i=0;
        int qtd=0;
        
        qtd = args.length;
        
        if (qtd%2!=0){
            System.out.println("Insira um número par de strings");
        }
        
        //imprime o resultado da função boba para testar
        System.out.println( retornaDuas("entalha","retalha") );
        
        // for (i=0; i<qtd; i++){
        //     if args[i]==args
        // }
        
    }

    public retornaDuas(String s1, String s2){
        int i=0, j=0, qt1=0, qt2=0;
        String[] s3;
        Boolean bool; 
        
        qt1=s1.length;
        qt2=s2.length;
        
        for (i=0; i<qt1; i++){
            if (s1.[i] == s2.[i]){
                s3[j]=s1[i];
                bool = True;
                j++;
            }
            if (bool == True){
                s1.substring(0,qt1-j);
                
                
            // mac é tão bom que eu to com as barras no ctrl v porque na última vez que eu digitei elas eu fechei todas as abas

            //.... hmmm string.substring(posicaoinicial,posicaofinal) retorna a string especifica entre estas posições. acho que ´eo jeito mais fácil
        }
        
        // não esquenta com palavras de tamanho diferentes por ora. faça funcionar com as duas de tamanho igual ali e a gente pensa
    }
}

/*  
    (1) função que receba duas strings como parâmetro (s1 e s2), retornando uma string
    (2) compare cada caracter da s1 com o na mesma posição em s2
    (3)     se for igual, guarda o caracter em um lugar e marca que achou char igual na última comparação
    (4)     se for diferente, limpa este lugar e marca que não achou char igual na última comparação
    (5) se tiver marcado que achou char iguais na última comparação
    (6)     checa o tamanho dos chars que guardou e apaga esta quantidade de caracteres no final de s1
    (7) concatena as strings
    (8) retorna esta string concatenada
*/